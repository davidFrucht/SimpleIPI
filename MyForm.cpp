#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Header.h"
#include "MyForm.h"
#include "report.h"
#include "alertSetup.h"
#include "cameraSetup.h"
#include "sensorSetup.h"
#include "connectToCom.h"
#include "pelcoD.h"
#include "onvif.h"
#include "DFSL_Protocol.h"
#include "json.h"


#include <iostream>
#include <string.h>
#include <windows.h>
#include <msports.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <WebView2.h>
#include <cmath>
#include <fstream>
#include <filesystem>
#include <direct.h>

#include "curl/curl.h"


extern HANDLE hCommPLS;

#define MILIRAD_TO_DEGREE 0.057296
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP_MOVEMENT 5
#define ZOOM_IN 6
#define ZOOM_OUT 7

#define PELCOD_PROTOCOL 0
#define ONVIF_PROTOCOL 1

#define TILT 0
#define PAN 1

using namespace std;
using namespace Calc;
using namespace System;
using namespace System::Windows::Forms;
using namespace cv;
using namespace System::Threading;
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

extern int ptzProtocol;
extern float intrutdersAzimuth;
extern float intruderRange;
extern string errorMessage;
extern int cameraToConnect;
extern int camSerialOrLan;
extern char cameraUrlAddress[256];

extern int numOfclicks;
extern float polyArrayX[126];
extern float polyArrayY[126];
extern int HZFlagChecked;

extern char* JSONUrl;


gcroot<Bitmap^> g;
HBITMAP hBit;

Mat frame;

DWORD WINAPI ThreadSensor(void* data)
{

	initatePls();
	return 0;
}

DWORD WINAPI RemoteControl(void* data)
{
	
	IPAddress^ listenInterface = IPAddress::Any;
	unsigned short listenPort = 5150;
	int bufferSize = 4096;


	TcpListener^ tcpServer = nullptr;
	TcpClient^ tcpClient = nullptr;
	NetworkStream^ tcpStream = nullptr;
	cli::array<Byte>^ sendBuffer = gcnew cli::array<Byte>(bufferSize);
	cli::array<Byte>^ receiveBuffer = gcnew cli::array<Byte>(bufferSize);
	cli::array<Byte>^ byteCount;
	int bytesToRead = 0, nextReadCount, rc;

	for (int i = 0; i < sendBuffer->Length; i++)
		sendBuffer[i] = (Byte)'Y';

	// Create the TCP server
	tcpServer = gcnew TcpListener(listenInterface, (int)listenPort);
	tcpServer->Start();
	tcpClient = nullptr;
		// Wait for a client connection
	for (;;) 
	{
		tcpClient = tcpServer->AcceptTcpClient();
		
		if (tcpClient != nullptr)
		{
			// Get the NetworkStream so we can do Read and Write on the client connection
			tcpStream = tcpClient->GetStream();
			byteCount = BitConverter::GetBytes(bytesToRead);

			// First read the number of bytes the client is sending
			tcpStream->Read(byteCount, 0, byteCount->Length);
			bytesToRead = BitConverter::ToInt32(byteCount, 0);

			// Receive the data
			while (bytesToRead > 0)
			{
				// Make sure we don't read beyond what the first message indicates
				//    This is important if the client is sending multiple "messages" --
				//    but in this sample it sends only one
				if (bytesToRead < receiveBuffer->Length)
					nextReadCount = bytesToRead;
				else
					nextReadCount = receiveBuffer->Length;

				// Read some data
				if (nextReadCount != 0)
					rc = tcpStream->Read(receiveBuffer, 0, nextReadCount);

				// Display what we read
				System::String^ readText = System::Text::Encoding::ASCII->GetString(receiveBuffer, 0, rc);

				if (readText->IndexOf("left", 0) != -1)
				{
					moveDirection(LEFT);
					System::String^ readText = "";
				}
				if (readText->IndexOf("right", 0) != -1)
				{
					moveDirection(RIGHT);
					System::String^ readText = "";
				}

				if (readText->IndexOf("up", 0) != -1)
				{
					moveDirection(UP);
					System::String^ readText = "";
				}

				if (readText->IndexOf("down", 0) != -1)
				{
					moveDirection(DOWN);
					System::String^ readText = "";
				}
				
				if (readText->IndexOf("stop", 0) != -1)
				{
					moveDirection(STOP_MOVEMENT);
					System::String^ readText = "";
				}
				//	bytesToRead -= rc;
				//	tcpStream->Close();
				//	tcpStream = nullptr;
				//	tcpClient->Close();
				//	tcpClient = nullptr;
				//	break;
				bytesToRead = 0;
				nextReadCount = 0;

				byteCount = BitConverter::GetBytes(sendBuffer->Length);
				tcpStream->Write(byteCount, 0, byteCount->Length);
				// Send the actual data
				tcpStream->Write(sendBuffer, 0, sendBuffer->Length);

			}	
		}
		//bytesToRead -= rc;
		//tcpStream->Close();
		//tcpStream = nullptr;
		//tcpClient->Close();
		//tcpClient = nullptr;
	}
	
		

	// First send the number of bytes the server is responding with
	
	

	// Close up the client
	//Console::WriteLine("TCP Listener: Closing client tcp stream...");
	//tcpStream->Close();
	//tcpStream = nullptr;
	//tcpClient->Close();
	//tcpClient = nullptr;
	//Sleep(200);

	/*
	finally
	{

		// Close any remaining open resources
		if (tcpServer != nullptr)
			tcpServer->Stop();
		if (tcpStream != nullptr)
			tcpStream->Close();
		if (tcpClient != nullptr)
			tcpClient->Close();

	}
	*/

	return 0;
}

		
DWORD WINAPI openCvCamera(void* data)
{
	//VideoCapture cap(cameraToConnect);

	//VideoCapture cap;

	if (camSerialOrLan == 0)
	{
		VideoCapture cap(cameraToConnect);
		if (!cap.isOpened())
			return -1;

		for (;;)
		{
			cap.grab();																					// with out this - there was a lag from the IP Camera

			cap >> frame;

			cvtColor(frame, frame, 0);
			hBit = CreateBitmap(frame.cols, frame.rows, 1, 32, frame.data);
			g = Bitmap::FromHbitmap((IntPtr)hBit);
			DeleteObject(hBit);
			if (waitKey(30) >= 0)
				break;

		}
	}

	if (camSerialOrLan == 1)
	{
		VideoCapture cap(cameraUrlAddress);
		if (!cap.isOpened())
			return -1;

		for (;;)
		{
			cap.grab();																					// with out this - there was a lag from the IP Camera

			cap >> frame;

			cvtColor(frame, frame, 0);
			hBit = CreateBitmap(frame.cols, frame.rows, 1, 32, frame.data);
			g = Bitmap::FromHbitmap((IntPtr)hBit);
			DeleteObject(hBit);
			if (waitKey(30) >= 0)
				break;

		}
	}
	

}


BITMAPINFOHEADER createBitmapHeaderMap(int width, int height)
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

Mat captureScreenMatMap(HWND hwnd, int screenx, int screeny, int width, int height)
{
	Mat src;

	HDC hwindowDC = GetDC(hwnd);
	HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
	SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

	int scale = 1;

	//int width = 530;//GetSystemMetrics(SM_CXVIRTUALSCREEN);
	//int height = 365;//GetSystemMetrics(SM_CYVIRTUALSCREEN);

	// create mat object
	src.create(height, width, CV_8UC4);

	// create a bitmap
	HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
	BITMAPINFOHEADER bi = createBitmapHeaderMap(width, height);

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

Calc::MyForm::MyForm(){
	
	InitializeComponent();

};

Calc::MyForm::~MyForm(){
	if (components){
		delete components;
	};
};




System::Void Calc::MyForm::BtnReturn0_Click(System::Object^ sender, System::EventArgs^ e) {
	var = 0;
	sendPtzPan();
	sendPtzTilt();
};

System::Void Calc::MyForm::BtnExit_Click(System::Object^ sender, System::EventArgs^ e) {
	exitPro();
};  

System::Void Calc::MyForm::Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	 var = UP;
	 if (ptzProtocol == PELCOD_PROTOCOL)
		 move();
	 if (ptzProtocol == 1)
		 moveDirection(UP);
};

System::Void Calc::MyForm::BtnDown_Click(System::Object^ sender, System::EventArgs^ e) {

	 var = DOWN;
	 if (ptzProtocol == PELCOD_PROTOCOL)
		 move();
	 if (ptzProtocol == ONVIF_PROTOCOL)
		 moveDirection(DOWN);
};

System::Void Calc::MyForm::BtnLeft_Click(System::Object^ sender, System::EventArgs^ e) {
	var = LEFT;
	if (ptzProtocol == PELCOD_PROTOCOL)
		move();
	if (ptzProtocol == ONVIF_PROTOCOL)
		moveDirection(LEFT);
}

System::Void Calc::MyForm::BtnRight_Click(System::Object^ sender, System::EventArgs^ e) {
	var = RIGHT;
	if (ptzProtocol == PELCOD_PROTOCOL)
		move();
	if (ptzProtocol == ONVIF_PROTOCOL)
		moveDirection(RIGHT);
};

System::Void Calc::MyForm::BtnStop_Click(System::Object^ sender, System::EventArgs^ e) {
	var = STOP_MOVEMENT;
	if (ptzProtocol == PELCOD_PROTOCOL)
		move();
	if (ptzProtocol == ONVIF_PROTOCOL)
		moveDirection(STOP_MOVEMENT);
};

System::Void Calc::MyForm::BtnMove_Click(System::Object^ sender, System::EventArgs^ e) {
	var = int::Parse(txtPanGoto->Text);
	if (ptzProtocol == PELCOD_PROTOCOL)
		sendPtzPan();
	if (ptzProtocol == ONVIF_PROTOCOL)
		moveDirectionAbselute(var, PAN);
		
};
		 
System::Void Calc::MyForm::BtnTiltMov_Click(System::Object^ sender, System::EventArgs^ e) {
	var = int::Parse(txtTiltGoto->Text);
	if (ptzProtocol == PELCOD_PROTOCOL)
		sendPtzTilt();
	if (ptzProtocol == ONVIF_PROTOCOL)
		moveDirectionAbselute(var, TILT);
};

System::Void Calc::MyForm::BtnSlow_Click(System::Object^ sender, System::EventArgs^ e) {
	speed = SLOW;
	this->btnSlow->Enabled = false;
	this->btnMedium->Enabled = true;
	this->btnFast->Enabled = true;
};

System::Void Calc::MyForm::BtnMedium_Click(System::Object^ sender, System::EventArgs^ e) {
	speed = MEDIUM;
	this->btnMedium->Enabled = false;
	this->btnSlow->Enabled = true;
	this->btnFast->Enabled = true;
};

System::Void Calc::MyForm::BtnFast_Click(System::Object^ sender, System::EventArgs^ e) {
	speed = FAST_;
	this->btnFast->Enabled = false;
	this->btnSlow->Enabled = true;
	this->btnMedium->Enabled = true;
};

System::Void Calc::MyForm::BtnZoomIn_Click(System::Object^ sender, System::EventArgs^ e) {
	var = ZOOM_IN;
	if (ptzProtocol == PELCOD_PROTOCOL)
		move();
	if (ptzProtocol == ONVIF_PROTOCOL)
		moveDirection(ZOOM_IN);
};

System::Void Calc::MyForm::BtnZoomOut_Click(System::Object^ sender, System::EventArgs^ e) {
	var = ZOOM_OUT;
	if (ptzProtocol == PELCOD_PROTOCOL)
		move();
	if (ptzProtocol == ONVIF_PROTOCOL)
		moveDirection(ZOOM_OUT);
};

System::Void Calc::MyForm::BtnPlsConnect_Click(System::Object^ sender, System::EventArgs^ e) {
//	initatePls();
};

System::Void Calc::MyForm::BtnSetZero_Click(System::Object^ sender, System::EventArgs^ e) {
	setNewZero();
};

System::Void Calc::MyForm::webView21_Click(System::Object^ sender, System::EventArgs^ e) {
	//webView21->NavigateToString("<html><body><h1>test</h1></body></html>");
};

System::Void Calc::MyForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	exitPro();
};

System::Void Calc::MyForm::cameraToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	cameraSetup object_name_second;
	object_name_second.ShowDialog();
	Show();
};

System::Void Calc::MyForm::sensorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	sensorSetup object_name_third;
	object_name_third.ShowDialog();
	Show();
};

System::Void Calc::MyForm::alertsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	alertSetup object_name_forth;
	object_name_forth.ShowDialog();
	Show();
}

System::Void Calc::MyForm::reportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	report object_name_fifth;
	object_name_fifth.ShowDialog();
	Show();

}
System::Void Calc::MyForm::btnUnFixMapPicture_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->mapPictureBox->Load("c:\\log\\g2.jpg");
	this->mapPictureBox->Visible = false;
	this->mapPictureBox->Enabled = false;
	this->btnUnFixMapPicture->Visible = false;
	remove("c:\\log\\map.png");
}

System::Void Calc::MyForm::button1_Click_2(System::Object^ sender, System::EventArgs^ e) {



	remove("c:\\1\\maps.html");

	double lat = 0, lon = 0;
	
	GeoCoordinateWatcher^ watcher = gcnew GeoCoordinateWatcher();
	watcher->TryStart(true, System::TimeSpan(System::TimeSpan::FromMilliseconds(2000)));
	watcher->Start();


	double x = watcher->Position->Location->HorizontalAccuracy;
	

	lat = watcher->Position->Location->Latitude;
	lon = watcher->Position->Location->Longitude;
		
	if (lat && lon)
	{
		txtLat->Text = "" + lat.ToString("##.######");
		txtLon->Text = "" + lon.ToString("##.######");
	}
	else
	{
		lat = Double::Parse(txtLat->Text->ToString());
		lon = Double::Parse(txtLon->Text->ToString());
	}
		
	FILE* MapsHtml;

	MapsHtml = fopen("c:\\1\\maps.html", "w");

	char JSONUrlInit[128];
	sprintf(JSONUrlInit, "%sgeo.json", JSONUrl);

	fprintf(MapsHtml, "<HTML> <HEAD> <META NAME = \"GENERATOR\" Content = \"Microsoft Visual Studio\"> <TITLE></TITLE> </HEAD> <BODY> <div> <iframe width = \"333\" height = \"333\" frameBorder = \"0\" src = \"https://www.bing.com/maps/embed?h=340&w=340&cp=%lf~%lf&lvl=18&typ=d&sty=a&src=SHELL&FORM=MBEDV8\" scrolling = \"no\"> </iframe> </div> </BODY> </HTML>", lat, lon);

	fclose(MapsHtml);

	this->webView22->CoreWebView2->Navigate("c:\\1\\maps.html");
	//watcher->Stop();
	char buff[128];

	sprintf(buff, "{\"lat\":\"%.6f\",\"lon\":\"%.6f\"}", lat, lon);

	sendJSON(buff, JSONUrlInit);
}

/*
System::Void Calc::MyForm::fileSystemWatcher1_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e)
{
	Sleep(700);

	static float tempAzimuth = 0;
	static float tempRange = 0;

	if (tempAzimuth != azimuth && tempRange != range)

	tempAzimuth = azimuth;
	tempRange = range;

	int x = 175 + (range * cos(azimuth));			// pixel size of picturebox is 351x351. radiu is 351/2 = 175
	int y = 175 - (range * sin(azimuth));

	Graphics^ g = picBoxRadar->CreateGraphics();
	g->DrawEllipse(Pens::Red, x, y, 3, 3);

	Graphics^ gMaps = mapPictureBox->CreateGraphics();
	gMaps->DrawEllipse(Pens::Red, x, y, 3, 3);

	txtBoxLogText->Text += (System::IO::File::ReadAllText("c:\\1\\eventLog.txt") + "\r\n");
	txtBoxLogText->Update();
}
*/

System::Void Calc::MyForm::btnMakeStatic_Click(System::Object^ sender, System::EventArgs^ e) {

	HWND hwndgg = FindWindow(NULL, TEXT("Simple IPI"));

	RECT Rect;
	GetWindowRect(hwndgg, &Rect);
	MapWindowPoints(HWND_DESKTOP, NULL, (LPPOINT)&Rect, 2);

	int screenx = Rect.left + 878 + 12;
	int screeny = Rect.top + 43 + 31;
	//int screenx = 1210;
	//int screeny = 215;
	int width = 354;//screenx - (Rect.right - 878);
	int height = 354;//(Rect.bottom - 43) - screeny;



	HWND hwnd = GetDesktopWindow();
	Mat src = captureScreenMatMap(hwnd, screenx, screeny, width, height);

	static char fileNumber[5] = { "0" };

	// encode result
	std::vector<uchar> buf;
	cv::imencode(".png", src, buf);

	// save img
	cv::imwrite("c:\\log\\map.png", src);

	buf.clear();

	this->mapPictureBox->Visible = true;
	this->mapPictureBox->Load("c:\\log\\map.png");
	this->btnUnFixMapPicture->Visible = true;
}

System::Void Calc::MyForm::btnChoosePicture_Click(System::Object^ sender, System::EventArgs^ e) {

	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;


	openFileDialog1->Title = "Select a Image File";

	openFileDialog1->ShowHelp = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		googleEarthBox->Image = Image::FromFile(openFileDialog1->FileName);
	}

}

System::Void Calc::MyForm::picBoxRadar_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	this->radarMousePos->Visible = false;
	this->coordLbl->Visible = false;
	this->DMScoord->Visible = false;
}

System::Void Calc::MyForm::picBoxRadar_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	this->radarMousePos->Visible = true;
	int tempX;
	int tempY;


	// calculation of degrees and range

	POINT p;

	GetCursorPos(&p);
	p.x -= 863;
	p.y -= 192;//208;

	int deg = (atan2(p.y - 175, p.x - 175) * 180 / 3.14159265) - 270;

	if (deg < 0)
		deg += 360;

	if (deg >= -90 && deg < 0)
		deg += 360;

	int radius = pow((p.x - 175), 2) + pow((p.y - 175), 2);
	radius = sqrt(radius);

	radarMousePos->Text = deg + "° " + radius + "m";


	this->coordLbl->Visible = true;


	double lat;
	double lon;

	if (txtLat->Text == "" || txtLat->Text == "")
	{
		lat = 31.809218;
		lon = 34.768687;
	}
	else
	{
		lat = Double::Parse(txtLat->Text->ToString());
		lon = Double::Parse(txtLon->Text->ToString());
	}

	double R = 6378137;
	double PI = 3.14159265359;

	float latO;
	float lonO;

	if (deg >= 0 && deg <= 90)
	{
		double directionX = radius / tan(deg);
		double dirextionY = radius;

		double dLat = directionX / R;
		double dLon = dirextionY / (R * cos(PI * lat / 180));

		latO = lat + dLat * 180 / PI;
		lonO = lon + dLon * 180 / PI;

	}

	if (deg >= 90 && deg <= 180)
	{
		double directionX = radius / tan(deg - 90);
		double dirextionY = radius;

		double dLat = directionX / R;
		double dLon = dirextionY / (R * cos(PI * lat / 180));

		latO = lat - dLat * 180 / PI;
		lonO = lon + dLon * 180 / PI;
	}

	if (deg >= 180 && deg <= 270)
	{
		double directionX = radius / tan(deg - 180);
		double dirextionY = radius;

		double dLat = directionX / R;
		double dLon = dirextionY / (R * cos(PI * lat / 180));

		latO = lat - dLat * 180 / PI;
		lonO = lon - dLon * 180 / PI;
	}

	if (deg >= 270 && deg <= 360)
	{
		double directionX = radius / tan(deg - 270);
		double dirextionY = radius;

		double dLat = directionX / R;
		double dLon = dirextionY / (R * cos(PI * lat / 180));

		latO = lat + dLat * 180 / PI;
		lonO = lon - dLon * 180 / PI;
	}

	this->coordLbl->Text = latO.ToString("#.######") + ",\r\n" + lonO.ToString("#.######");

	this->DMScoord->Visible = true;

	int latDegreesDMS = latO;
	double latMinDMS = (latO - latDegreesDMS) * 60;
	double latSecDMS = (latMinDMS - (int)latMinDMS) * 60;

	int lonDegreesDMS = lonO;
	double lonMinDMS = (lonO - lonDegreesDMS) * 60;
	double lonSecDMS = (lonMinDMS - (int)lonMinDMS) * 60;

	this->DMScoord->Text = latDegreesDMS + "°" + latMinDMS.ToString("#.##") + "'" + latSecDMS.ToString("#.##") + "\r\n"
		+ lonDegreesDMS + "°" + lonMinDMS.ToString("#.##") + "'" + lonSecDMS.ToString("#.##");
}

System::Void Calc::MyForm::button1_Click_3(System::Object^ sender, System::EventArgs^ e) {

	HANDLE thread5 = CreateThread(NULL, 0, openCvCamera, NULL, 0, NULL);
	//Sleep(1000);
	this->timerVideo->Enabled = true;
	/*
	//	remove("c:\\1\\cameraUrl.txt");
	Sleep(700);
	std::fstream f("c:\\1\\cameraUrl.txt");
	std::string content((std::istreambuf_iterator<char>(f)),
		(std::istreambuf_iterator<char>()));

	System::String^ urlStr = gcnew System::String(content.c_str());
	
	this->webView21->CoreWebView2->Navigate(urlStr);
	*/

}

System::Void Calc::MyForm::btnTakePicture_Click(System::Object^ sender, System::EventArgs^ e)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	static int fileNum = 0;
	char destenation[128] = "c:\\SimpleIPI\\REPORT\\";
	sprintf(destenation + strlen(destenation), "%d-%d-%d\\", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
	const char* f = destenation;
	_mkdir(f);
	
	sprintf(destenation + strlen(destenation), "%d.png", fileNum);
	imwrite(destenation, frame);
	fileNum++;
}

System::Void Calc::MyForm::clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->txtBoxLogText->Text = "";
}

System::Void Calc::MyForm::btnConnecToSensor_Click(System::Object^ sender, System::EventArgs^ e)
{
	// TODO : Delete
}

System::Void Calc::MyForm::btnFastDraw_Click(System::Object^ sender, System::EventArgs^ e)
{
	fastDraw();

	
	/*
	for (int i = 0; i < 359; i++)
	{
		int x = 175 + (fastDrawArrayLRF1[i] * cos(i));			// pixel size of picturebox is 351x351. radiu is 351/2 = 175
		int y = 175 - (fastDrawArrayLRF2[i] * sin(i));

		Graphics^ g = picBoxRadar->CreateGraphics();
		g->DrawEllipse(Pens::Red, x, y, 3, 3);
	}
	*/
	


	/*
	HANDLE hCommPLS = connectCom(6, 115200);

	sendToSensorFastDraw(0x04, SET_FAST_DRAW_MODE);
	Sleep(100);
	
	if (SerialBufferPLS[3] == 0x04 && SerialBufferPLS[4] == 0x02)
	{
		Sleep(100);
		sendToSensorFastDraw(0x04, SET_DETECTION_MODE);
		{
			Sleep(100);
			if (SerialBufferPLS[3] == 0x04 && SerialBufferPLS[4] == 0x01)
			{
				for (int i = 0; i < 360; i++)
				{
					byte indexByte = i;
					if (i <= 255)
						sendToSensorFastDraw(0x03, 0x00, indexByte);
					else
						sendToSensorFastDraw(0x03, 0x10, (indexByte - 0xFF));

					do
					{
						Sleep(100);
					} while (SerialBufferPLS[4] == 0x80);

					if (SerialBufferPLS[REPLY_COMMAND_LOC] == 0x03)
					{
						if (SerialBufferPLS[REPLY_COMMAND_LOC + 1] == 0x40)
						{
							int errorAngle = SerialBufferPLS[REPLY_COMMAND_LOC + 2] << 8;
							errorAngle |= SerialBufferPLS[REPLY_COMMAND_LOC + 3];

							FILE* fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
							fprintf(fptrPLS, "Fast Draw Error: angle %f", 359.94 / 5999.00 * (float)errorAngle);
							fclose(fptrPLS);
						}
					}
					else
					{
						fastDrawArrayLRF1[i] = 100.0 / 2047.0 * SerialBufferPLS[REPLY_COMMAND_LOC + 3];
						fastDrawArrayLRF2[i] = 100.0 / 2047.0 * SerialBufferPLS[REPLY_COMMAND_LOC + 4];
						FILE* fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
						fprintf(fptrPLS, "angle: %d starting range: %d ending range: %d", i, fastDrawArrayLRF1[i], fastDrawArrayLRF2[i]);
						fclose(fptrPLS);
						
					}
						
				}
			}
		}
		
	}

	CloseHandle(hCommPLS);
	*/
}

System::Void Calc::MyForm::checkBoxRemoteConnection_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	
	HANDLE thread3 = CreateThread(NULL, 0, RemoteControl, NULL, 0, NULL);

	
}

System::Void Calc::MyForm::clocklTmer_Tick(System::Object^ sender, System::EventArgs^ e) {

	time_t t2 = time(NULL);
	struct tm tm2 = *localtime(&t2);

	lblClock->Text = "" + (tm2.tm_mon + 1) + "-" + tm2.tm_mday + "-" + (tm2.tm_year + 1900) + " " + tm2.tm_hour + ":" + tm2.tm_min + ":" + tm2.tm_sec;
}

System::Void Calc::MyForm::timerLog_Tick(System::Object^ sender, System::EventArgs^ e)
{
	if (intrutdersAzimuth != -1 && intruderRange != -1)
	{
		this->txtBoxLogText->Text += "Intruder Detected at Azimuth " + intrutdersAzimuth.ToString("#") + " Range " + intruderRange.ToString("#") + "\r\n";
		txtBoxLogText->Update();

		static float tempAzimuth = 0;
		static float tempRange = 0;

		if (tempAzimuth != intrutdersAzimuth && tempRange != intruderRange)

		tempAzimuth = azimuth;
		tempRange = range;

		int x = 175 + (intruderRange * cos(intrutdersAzimuth));			// pixel size of picturebox is 351x351. radiu is 351/2 = 175
		int y = 175 - (intruderRange * sin(intrutdersAzimuth));

		Graphics^ g = picBoxRadar->CreateGraphics();
		g->DrawEllipse(Pens::Red, x, y, 3, 3);

		Graphics^ gMaps = mapPictureBox->CreateGraphics();
		gMaps->DrawEllipse(Pens::Red, x, y, 3, 3);

	}

	if (errorMessage.find("OK") == string::npos)
	{
		this->txtBoxLogText->Text += "Error Message: {0}\r\n", errorMessage;
		txtBoxLogText->Update();
	}


	intrutdersAzimuth = -1;
	intruderRange = -1;
	errorMessage = "OK";

}

System::Void Calc::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	HANDLE thread5 = CreateThread(NULL, 0, openCvCamera, NULL, 0, NULL);
	//Sleep(1000);
	this->timerVideo->Enabled = true;

}

System::Void Calc::MyForm::timerVideo_Tick(System::Object^ sender, System::EventArgs^ e)
{
	this->picBoxCamera->SizeMode = PictureBoxSizeMode::StretchImage;
	this->picBoxCamera->Image = g;
}

System::Void Calc::MyForm::checkBoxInitateSensor_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	this->btnFastDraw->Enabled = true;
	this->checkBoxRemoteConnection->Enabled = true;

	HANDLE thread2 = CreateThread(NULL, 0, ThreadSensor, NULL, 0, NULL);
}


HANDLE hComm;										
int Calc::com;
FILE* fptr;
int Calc::connectionFlag = 0;
unsigned char Calc::speed = 0x3F;
int Calc::var;
extern std::string camHtmlAdress;

[STAThread]
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{	
	//HANDLE thread = CreateThread(NULL, 0, ThreadOpenCv, NULL, 0, NULL);
	
	//HANDLE thread3 = CreateThread(NULL, 0, ThreadLog, NULL, 0, NULL);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MyForm form;
	Application::Run(% form);

}


System::Void Calc::MyForm::timerHZ_Tick(System::Object^ sender, System::EventArgs^ e)
{
	int i;
	if (HZFlagChecked == 1)
	{
		Graphics^ g = picBoxRadar->CreateGraphics();
		Graphics^ gMaps = mapPictureBox->CreateGraphics();

		for (i = 0; i < numOfclicks / 2 -1; i++)
		{
			
			g->DrawLine(Pens::OrangeRed, System::Drawing::Point(polyArrayX[i], polyArrayY[i]), System::Drawing::Point(polyArrayX[i + 1], polyArrayY[i + 1]));

			
			gMaps->DrawLine(Pens::OrangeRed, System::Drawing::Point(polyArrayX[i], polyArrayY[i]), System::Drawing::Point(polyArrayX[i + 1], polyArrayY[i + 1]));
		}

		g->DrawLine(Pens::OrangeRed, System::Drawing::Point(polyArrayX[i], polyArrayY[i]), System::Drawing::Point(polyArrayX[0], polyArrayY[0]));

		gMaps->DrawLine(Pens::OrangeRed, System::Drawing::Point(polyArrayX[i], polyArrayY[i]), System::Drawing::Point(polyArrayX[0], polyArrayY[0]));

		

		this->timerHZ->Enabled = false;
	}

}


void Calc::ptzInit(){

	if (hComm = connectCom(com, var))					//  connectCom is in ConnectToCom.h
		connectionFlag = 1;
}

void Calc::sendPtzPan()
{
	sendPtzPanPelcoHeader(hComm, var);					// function in pelcoD.h

}

void Calc::sendPtzTilt()
{
	sendPtzTiltPelcoHeader(hComm, var);					// function in pelcoD.h
}

void Calc::move()
{
	movePelcoHeader(hComm, var, speed);					// function in pelcoD.h
}
void Calc::setNewZero()
{
	setNewZeroPelcoDHeader(hComm);						// function in pelcoD.h
}

void Calc::exitPro()
{
	cv::waitKey(30) == 1;
//	fclose(fptr);
	if (connectionFlag == 1)
		CloseHandle    (hComm);      //Closing the Serial Port
	exit(EXIT_SUCCESS);
	
}






