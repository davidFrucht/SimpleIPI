#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "MyForm.h"
#include "Header.h"
#include "connectToCom.h"
#include "sendMail.h"
#include "json.h"
#include "DFSL_Protocol.h"
#include "base64.h"

#include <iostream>
#include <string.h>
#include <windows.h>
#include <msports.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <direct.h>
#include <filesystem>
#include <String>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <bitset>

using namespace cv;
using namespace Calc;
using namespace std;

HANDLE hCommPLS;														// Handle to the Serial port
wchar_t  ComPortNamePLS[] = L"\\\\.\\COM3";								// Name of the Serial port(May Change) to be opened,
BOOL  StatusPLS;														// Status of the various operations 
DWORD dwEventMaskPLS;													// Event mask to trigger
byte  TempCharPLS;														// Temperory Character
byte  SerialBufferPLS[1024];											// Buffer Containing Rxed Data
DWORD NoBytesReadPLS;													// Bytes read by ReadFile()
int cntMessagesPLS = 0;
char bufferPLS[256];
int checkSumPLS = 0;
char* ptrPLS;
int tempPLS;
int flagPLS = 0;


char tempCharBuffer[100];
char softwareVersion[100];


float Calc::azimuth;
float Calc::range;

int Calc::flagCellularAlert;
int Calc::flagEmailAlert;
int Calc::flagJSONAlert;

std::vector<char*> strArray;
char str[30];
FILE* fptrPLS;
FILE* fptrUserLog;
char picFile[50];

time_t t = time(NULL);
struct tm tm = *localtime(&t);

extern char* FromChar;
extern char* ToChar;
extern char* SMTPChar;
extern char* UserNameChar;
extern char* passwordChar;

extern int ptzProtocol;

extern char* JSONUrl;

char JSONUrlMessages[128];

int plsConnectedFlag;

float intrutdersAzimuth = -1;									// this var is for the timer to check if the var has changed. if so, it will print a message to the UI log
float intruderRange	= -1;										// this var is for the timer to check if the var has changed. if so, it will print a message to the UI log
string errorMessage = "OK";
string encoded64Pic;

unsigned char try1[1000];

// related to Hidden Zone - decleared in sensorSetup.cpp
extern float polyArrayX[126];
extern float polyArrayY[126];
extern int HZFlagChecked;
extern int polyCorners;
extern int numOfclicks;
extern char timeHZToBegin[16];
extern char timeHZToEnd[16];

BITMAPINFOHEADER createBitmapHeader(int width, int height)
{
	BITMAPINFOHEADER  bi;

	// create a bitmap
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = width;
	bi.biHeight = -height;  //this is the line that makes it draw upside down or not
	bi.biPlanes = 1;
	bi.biBitCount = 32;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;

	return bi;
}

Mat captureScreenMat(HWND hwnd)
{
	HWND hwndgg = FindWindow(NULL, TEXT("Simple IPI"));

	RECT Rect;
	GetWindowRect(hwndgg, &Rect);
	MapWindowPoints(HWND_DESKTOP, NULL, (LPPOINT)&Rect, 2);

	int screenx = Rect.left + 12 + 12;
	int screeny = Rect.top + 43 + 31;

	Mat src;

	HDC hwindowDC = GetDC(hwnd);
	HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
	SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

	int scale = 1;
	
	int width = 508;//GetSystemMetrics(SM_CXVIRTUALSCREEN);
	int height = 355;//GetSystemMetrics(SM_CYVIRTUALSCREEN);

	// create mat object
	src.create(height, width, CV_8UC4);

	// create a bitmap
	HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
	BITMAPINFOHEADER bi = createBitmapHeader(width, height);

	// use the previously created device context with the bitmap
	SelectObject(hwindowCompatibleDC, hbwindow);

	// copy from the window device context to the bitmap device context
	StretchBlt(hwindowCompatibleDC, 0, 0, width, height, hwindowDC, screenx, screeny, width, height, SRCCOPY);  //change SRCCOPY to NOTSRCCOPY for wacky colors !
	GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, src.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);            //copy from hwindowCompatibleDC to hbwindow

	// avoid memory leak
	DeleteObject(hbwindow);
	DeleteDC(hwindowCompatibleDC);
	ReleaseDC(hwnd, hwindowDC);

	return src;
}

DWORD WINAPI ThreadOpenCv(void* data)
{


	HWND hwnd = GetDesktopWindow();
	Mat src = captureScreenMat(hwnd);
	
	static char fileNumber[5] = { "0" };

	// encode result
	std::vector<uchar> buf;
	cv::imencode(".png", src, buf);

	// save img
	sprintf(picFile + strlen(picFile), "%d%d%d", tm.tm_hour,tm.tm_min,tm.tm_sec);
	
	sprintf(picFile + strlen(picFile), ".png");

	cv::imwrite(picFile, src);

	auto* enc_msg = reinterpret_cast<unsigned char*>(buf.data());
	encoded64Pic = base64_encode(enc_msg, buf.size());

	buf.clear();

	FILE* listOfpicTextFilePTR;

	listOfpicTextFilePTR = fopen("c:\\log\\temp.txt", "a");

	fprintf(listOfpicTextFilePTR, "%s,\n", picFile);
	fclose(listOfpicTextFilePTR);


	return 0;
}

/**/
void Calc::initatePls()

{
	hCommPLS = connectCom(3, 19200);
	while (1)
	{
		Sleep(500);
		stateMode();
	}
}

void Calc::stateMode()
{
	sendToSensor(CMD_STATE_2);

	if (SerialBufferPLS[REPLY_COMMAND_LOC] == CMD_STATE_2)
	{
		if (SerialBufferPLS[SIZE_LOC] == INTRUDER_DETECTED_SIZE && SerialBufferPLS[TYPE_LOC] == INTRUDER_DETECTED_NO_WIDTH)
			decipherMessageIntruderDetected();

		if (SerialBufferPLS[SIZE_LOC] == INTRUDER_DETECTE_WITH_WIDTH_SIZE && SerialBufferPLS[TYPE_LOC] == INTRUDER_DETECTED_WITH_WIDTH)
			decipherMessageIntruderDetected();

		if (SerialBufferPLS[SIZE_LOC] == SYSTEM_VISIBILTY_CHANGES_SIZE && SerialBufferPLS[TYPE_LOC] == SYSTEM_VISIBILTY_CHANGES)
			decipherMessageSystemVisibalityChanges();
		

		if (SerialBufferPLS[SIZE_LOC] == MAINTENANCE_NOTIFICATION_1_SIZE && SerialBufferPLS[TYPE_LOC] == MAINTENANCE_NOTIFICATION_1)
			decipherMessageSystemMaintenanceNotifcation1();
		

		if (SerialBufferPLS[SIZE_LOC] == MAINTENANCE_NOTIFICATION_LRF_SIZE && SerialBufferPLS[TYPE_LOC] == MAINTENANCE_NOTIFICATION_LRF)
			decipherMessageSystemMaintenanceNotifcationLRF();

		if (SerialBufferPLS[SIZE_LOC] == MAINTENANCE_NOTIFICATION_ERROR_ANGLE_SIZE && SerialBufferPLS[TYPE_LOC] == MAINTENANCE_NOTIFICATION_ERROR_ANGLE)
			decipherMessageSystemMaintenanceNotifcationErrorAngle();

	}
}



int integrityCheck()
{
	int i = 0;
	if (SerialBufferPLS[i++] == '\0')											//	reply starts with 2 - 0
		if (SerialBufferPLS[i++] == '\0')
			if (SerialBufferPLS[i++] == 55 + 30)								//	1st message will be 55 (in hex)
				if (SerialBufferPLS[i++] == cntMessagesPLS - 2 - 3)				//	-2 for 2 zeros at begining - 3
					return 1;

	return 0;
}


void Calc::decipherMessageIntruderDetected() {
	

	// this is for the main UI log timer for checking any change in the intrutdersAzimuth/intruderRange.
	// if values ahs changed -> timer will print in UI the relevant messages.

	intrutdersAzimuth = -1;
	intruderRange = -1;


	// this is for decpher the messages, as described in the protocol
	int range_b = SerialBufferPLS[9] << 8;
	range_b |= (SerialBufferPLS[11]);
	range_b &= ~0xF800;
	range = 100.0 / 2047.0 * range_b;

	
	int azimuth_b = SerialBufferPLS[9];
	azimuth_b &= ~0x07;
	azimuth_b <<= 5;
	azimuth_b |= (SerialBufferPLS[10]);

	azimuth = 359.94 / 5999.00 * (float)azimuth_b;

	// this is for panning the PTZ camera
	var = azimuth;											// var is in myform.cpp

	if (ptzProtocol == 0)
		sendPtzPan();
	if (ptzProtocol == 1)
		moveDirectionAbselute(var, 1);

	/*
	char hour_beg[2];
	sprintf(hour_beg, "%d%d", timeHZToBegin[0], timeHZToBegin[1]);
	char min_beg[2];
	sprintf(min_beg, "%d%d", timeHZToBegin[3], timeHZToBegin[4]);
	char sec_beg[2];
	sprintf(sec_beg, "%d%d", timeHZToBegin[6], timeHZToBegin[7]);
	*/


	// if an heidden zone was defined, then we will check if the intruder is inside the hidden zone. if yes, no alert will be issued

	if (hiddenZone(azimuth, range, polyArrayX, polyArrayY, polyCorners, numOfclicks))
		return;
	

	// this is for the main UI log timer for checking any change in the intrutdersAzimuth/intruderRange.
	// if values ahs changed -> timer will print in UI the relevant messages.

	intrutdersAzimuth = azimuth;
	intruderRange = range;

	// this is for creating log to the user

	char dateDir[50] = "c:\\SimpleIPI\\REPORT\\";
	char LogFile[50];
	
	strcpy(LogFile, dateDir);
	strcpy(picFile, dateDir);

	if (tm.tm_mon + 1 < 10 && tm.tm_mday < 10)
		sprintf(dateDir + strlen(dateDir), "0%d-0%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

	else if ((tm.tm_mon + 1 < 10 && tm.tm_mday >= 10))
		sprintf(dateDir + strlen(dateDir), "0%d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

	else if ((tm.tm_mon + 1 >= 10 && tm.tm_mday < 10))
		sprintf(dateDir + strlen(dateDir), "%d-0%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

	else 
		sprintf(dateDir + strlen(dateDir), "%d-%d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	
	strcpy(LogFile, dateDir);
	sprintf(LogFile + strlen(LogFile), "\\");
	strcpy(picFile, dateDir);
	sprintf(picFile + strlen(picFile), "\\");

	const char* f = dateDir;
	_mkdir(f);
	

	sprintf(LogFile + strlen(LogFile), "log.txt");
	fptrUserLog = fopen(LogFile, "a");

	fprintf(fptrUserLog, "%d-%d-%d\t%d:%d:%d\tazimuth = %.2f, range = %.2f\n", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec,
		azimuth, range);
	fclose(fptrUserLog);
			
	HANDLE thread = CreateThread(NULL, 0, ThreadOpenCv, NULL, 0, NULL);

	if (flagCellularAlert == 1)
		detecionCellAlert();
			
	if (flagEmailAlert == 1)
		sendMailSMTP(FromChar, ToChar, SMTPChar, UserNameChar, passwordChar, azimuth, range);

	if (flagJSONAlert == 1)
	{
		char buff[600000];
		sprintf(JSONUrlMessages, "%smessage_list.json", JSONUrl);
		//char *buff = (char*)malloc(encoded64Pic.length() + 256);;

		//int num = sizeof(encoded64Pic);

		//buff = (char*)malloc(encoded64Pic.length() + 256);

		//snprintf(buff, sizeof(buff), "{\"type\":\"Intruder Detected\",\"Range\":\"%.2f\",\"Azimuth\":\"%.2f\"}", range, azimuth);
		sprintf(buff, "{\"type\":\"Intruder Detected\",\"Range\":\"%.2f\",\"Azimuth\":\"%.2f\",\"Image\":\"%s\"}", range, azimuth, encoded64Pic.c_str());
		//sprintf(JSONUrl + strlen(JSONUrl), "message_list.json");
		sendJSON(buff, JSONUrlMessages);
	}


}

void Calc::decipherMessageSystemVisibalityChanges()
{
	byte reason = SerialBufferPLS[10];
	int state;

	if (reason & 1)
		state = APPEARS;
	if (reason & 1 == 0)
		state = DISAPPEARS;

	if (reason >> 1 == ICE_OR_DUST)
	{
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Visibilty Changes: Ice or Dust on sensor glass - %s", state == APPEARS ? "appears" : "disappeared");
		fclose(fptrPLS);
		*/
		//snprintf(errorMessage, 128, "Visibilty Changes: Ice or Dust on sensor glass - %s", state == APPEARS ? "appears" : "disappeared");
		
		std::ostringstream stringStream;
		stringStream << "Visibilty Changes: Ice or Dust on sensor glass - %s", state == APPEARS ? "appears" : "disappeared";
		errorMessage = stringStream.str();
	}

	if (reason >> 1 == SYSTEM_COVERED)
	{
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Visibilty Changes: System Covered - %s", state == APPEARS ? "appears" : "disappeared");
		fclose(fptrPLS);
		*/

		std::ostringstream stringStream;
		stringStream << "Visibilty Changes: System Covered - %s", state == APPEARS ? "appears" : "disappeared";
		errorMessage = stringStream.str();

	}

	if (reason >> 1 == FOG)
	{
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Visibilty Changes: Fog - %s", state == APPEARS ? "appears" : "disappeared");
		fclose(fptrPLS);
		*/


		std::ostringstream stringStream;
		stringStream << "Visibilty Changes: Fog - %s", state == APPEARS ? "appears" : "disappeared";
		errorMessage = stringStream.str();
	}
}

void Calc::decipherMessageSystemMaintenanceNotifcation1()
{
	byte reason = SerialBufferPLS[9];
	int state = 0;

	if (reason >> 3 & 1)
	{
		state = APPEARS;
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Maintainance Notification: Power Supply Voltage changed - %s", state == APPEARS ? "appears" : "disappeared");
		fclose(fptrPLS);
		*/

		std::ostringstream stringStream;
		stringStream << "Maintainance Notification: Power Supply Voltage changed - %s", state == APPEARS ? "appears" : "disappeared";
		errorMessage = stringStream.str();

	}

	state = 0;

	if (reason >> 5 & 1)
	{
		
		state = APPEARS;
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Maintainance Notification: No Zero Mask - %s", state == APPEARS ? "appears" : "disappeared");
		fclose(fptrPLS);
		*/

		std::ostringstream stringStream;
		stringStream << "Maintainance Notification: No Zero Mask - %s", state == APPEARS ? "appears" : "disappeared";
		errorMessage = stringStream.str();

	}

	state = 0;

	if (reason >> 6 & 1)
	{
		state = APPEARS;
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Maintainance Notification: No IRQ - %s", state == APPEARS ? "appears" : "disappeared");
		fclose(fptrPLS);
		*/

		std::ostringstream stringStream;
		stringStream << "Maintainance Notification: No IRQ - %s", state == APPEARS ? "appears" : "disappeared";
		errorMessage = stringStream.str();
	}
}

void Calc::decipherMessageSystemMaintenanceNotifcationLRF()
{
	byte lrf_id = SerialBufferPLS[9];

	if ((SerialBufferPLS[10] >> 6) & 1)
	{
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Maintainance Notification: SST Overflow - %s", lrf_id == 0x00 ? "LRF #1" : "LRF #2");
		fclose(fptrPLS);
		*/
		std::ostringstream stringStream;
		stringStream << "Maintainance Notification: SST Overflow - %s", lrf_id == 0x00 ? "LRF #1" : "LRF #2";
		errorMessage = stringStream.str();
	}

	if ((SerialBufferPLS[10] >> 7) & 1)
	{
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Maintainance Notification: Error Overflow (Too Many Targets)");
		fclose(fptrPLS);
		*/

		std::ostringstream stringStream;
		stringStream << "Maintainance Notification: Error Overflow (Too Many Targets)";
		errorMessage = stringStream.str();
	}

	if ((SerialBufferPLS[10] >> 8) & 1)
	{
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Maintainance Notification: Sun Bit Error");
		fclose(fptrPLS);
		*/

		std::ostringstream stringStream;
		stringStream << "Maintainance Notification: Sun Bit Error";
		errorMessage = stringStream.str();

	}

  }

void Calc::decipherMessageSystemMaintenanceNotifcationErrorAngle()
{
	SerialBufferPLS[9] &= 0x1F;
	SerialBufferPLS[9] >>= 5;

	SerialBufferPLS[9] |= SerialBufferPLS[10];

	char temp[10];
	sprintf(temp, "%x", SerialBufferPLS[9]);

	int errorAngle;
	std::stringstream ss_e;
	ss_e << std::hex << temp;
	ss_e >> errorAngle;

	if (errorAngle > 6060 || errorAngle < 5950)
	{
		/*
		fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
		fprintf(fptrPLS, "Maintainance alert 4 (Error angle): Call to technical support");
		fclose(fptrPLS);
		*/

		std::ostringstream stringStream;
		stringStream << "Maintainance alert 4 (Error angle): Call to technical support";
		errorMessage = stringStream.str();
	}
	  
}

void Calc::advancedSetup()
{
	CloseHandle(hCommPLS);
	//ExitThread(ThreadFunc2);
	Sleep(1500);
	system("c:\\singleIPI\\SingleIPI.exe setup");
	
}










