#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
// Tasks to do
// baudrate, telephone number
#include "alertSetup.h"
#include "AT_SMS.h"
#include "connectToCom.h"
#include "MyForm.h"
#include "Header.h"




#include <iostream>
#include <string.h>
#include <windows.h>
#include <msports.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>

HANDLE hCommAlert;														
//wchar_t  Calc::ComPortNameAlert1[] = L"\\\\.\\COM";
BOOL  StatusAlert2;														 
DWORD dwEventMaskAlert2;													
char  TempCharAlert2;														
char  SerialBufferAlert2[256];												
DWORD NoBytesReadAlert2;													
int cntMessagesAlert = 0;
char bufferAlert[256];
int checkSumAlert = 0;
char* ptrAlert;
int tempAlert;
int flagAlert = 0;
int Calc::ComAlert;

using namespace Calc;

extern std::string Calc::phoneNumberStr;
*/

/*
//extern std::string phoneNumberStr;
//extern char phoneNumChar;


void Calc::initCellPhone(){

	hCommAlert = connectCom(Calc::ComAlert, 19200);

}

int Calc::checkConnectionCell(){
	initCellPhone();


	
	char lpBufferAlert[] = { "AT\r" };

	flagAlert = 0;

	DWORD  dNoOFBytestoWriteAlert;
	DWORD  dNoOfBytesWrittenAlert = 0;

	dNoOFBytestoWriteAlert = sizeof(lpBufferAlert);

	StatusAlert2 = WriteFile(hCommAlert,               // Handle to the Serialport
		lpBufferAlert,								  // Data to be written to the port 
		dNoOFBytestoWriteAlert,						  // No of bytes to write into the port
		&dNoOfBytesWrittenAlert,				      // No of bytes written to the port
		NULL);

	Sleep(1000);

	StatusAlert2 = WaitCommEvent(hCommAlert, &dwEventMaskAlert2, NULL);

	if (StatusAlert2 == FALSE)
	{
		printf("\n    Error! in Setting WaitCommEvent()");
	}
	else
	{
		cntMessagesAlert = 0;
		do
		{
			StatusAlert2 = ReadFile(hCommAlert, &TempCharAlert2, sizeof(TempCharAlert2), &NoBytesReadAlert, NULL);

			SerialBufferAlert2[cntMessagesAlert] = TempCharAlert2;
			
			cntMessagesAlert++;

		} while (NoBytesReadAlert > 0);

		CloseHandle(hCommAlert);
		
		if (strstr(SerialBufferAlert2, "OK") != NULL)
			return 1;
		
	}
	return 0;
}

void Calc::detecionCellAlert(){

	char pNumber[20];
	char message[120] = "Intruder Detected at ";

	strcpy(pNumber, phoneNumberStr.c_str());

	sprintf(message + strlen(message), "azimuth %.2f range %.2f \x1A", azimuth, range);


	initCellPhone();

	sendSMS(hCommAlert, pNumber, message);
	*/


	/*

	char lpBufferAlert[4][120] = { "AT\r", "AT+CMGF=1\r", "AT+CMGS=\"+972544949525\"\r", "Intruder Detected at " };
	int i_alert;


	flagAlert = 0;

	for (i_alert = 0; i_alert < 3; i_alert++)
	{
		DWORD  dNoOFBytestoWriteAlert;
		DWORD  dNoOfBytesWrittenAlert = 0;
		
		dNoOFBytestoWriteAlert = sizeof(lpBufferAlert[i_alert]);
	
		StatusAlert1 = WriteFile(hCommAlert,               // Handle to the Serialport
			lpBufferAlert[i_alert],								  // Data to be written to the port 
			dNoOFBytestoWriteAlert,						  // No of bytes to write into the port
			&dNoOfBytesWrittenAlert,						  // No of bytes written to the port
			NULL);



		Sleep(1000);

		//recive

		StatusAlert1 = WaitCommEvent(hCommAlert, &dwEventMaskAlert, NULL);

		if (StatusAlert1 == FALSE)
		{
			printf("\n    Error! in Setting WaitCommEvent()");
		}
		else
		{
			printf("\n\n    Characters Received");
			do
			{

				StatusAlert1 = ReadFile(hCommAlert, &TempCharAlert, sizeof(TempCharAlert), &NoBytesReadAlert, NULL);
				
				printf("%c", TempCharAlert);

			} while (NoBytesReadAlert > 0);
			
			printf("\n");
			
		}
	
		Sleep(1000);
	}

	// Actual message 

	DWORD  dNoOFBytestoWriteAlert;
	DWORD  dNoOfBytesWrittenAlert = 0;

	char lpBufferAlertMessage[70] = "Intruder Detected at ";
	sprintf(lpBufferAlertMessage + strlen(lpBufferAlertMessage), "azimuth %.2f range %.2f \x1A", azimuth, range);
	dNoOfBytesWrittenAlert = 0;

	dNoOFBytestoWriteAlert = sizeof(lpBufferAlert);

	StatusAlert1 = WriteFile(hCommAlert,               // Handle to the Serialport
		lpBufferAlertMessage,								  // Data to be written to the port 
		dNoOFBytestoWriteAlert,						  // No of bytes to write into the port
		&dNoOfBytesWrittenAlert,						  // No of bytes written to the port
		NULL);



	//return 0;
	*/
//}