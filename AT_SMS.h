#pragma once

#include <iostream>
#include <string.h>
#include <windows.h>
#include <msports.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>


BOOL  StatusAlert1;
DWORD dwEventMaskAlert;
char  TempCharAlert;
char  SerialBufferAlert[256];
DWORD NoBytesReadAlert;
DWORD  dNoOFBytestoWriteAlert;
DWORD  dNoOfBytesWrittenAlert = 0;


void sendSMS(HANDLE hCommSMS, char phonNumber[20], char message[256])
{

	// Send AT sequence

	char lpBufferSMS[120] = "AT\r";

	dNoOFBytestoWriteAlert = sizeof(lpBufferSMS);

	StatusAlert1 = WriteFile(hCommSMS,					// Handle to the Serialport
		lpBufferSMS,								  // Data to be written to the port 
		dNoOFBytestoWriteAlert,						  // No of bytes to write into the port
		&dNoOfBytesWrittenAlert,						  // No of bytes written to the port
		NULL);

	Sleep(1000);

	//recive

	StatusAlert1 = WaitCommEvent(hCommSMS, &dwEventMaskAlert, NULL);

	if (StatusAlert1 == FALSE)
	{
		printf("\n    Error! in Setting WaitCommEvent()");
	}
	else
	{
		printf("\n\n    Characters Received");
		do
		{

			StatusAlert1 = ReadFile(hCommSMS, &TempCharAlert, sizeof(TempCharAlert), &NoBytesReadAlert, NULL);

			printf("%c", TempCharAlert);

		} while (NoBytesReadAlert > 0);

		printf("\n");

	}

	Sleep(1000);

	// Send AT+CMGF=1\r sequence

	strcpy(lpBufferSMS, "AT+CMGF=1\r");

	dNoOFBytestoWriteAlert = sizeof(lpBufferSMS);

	StatusAlert1 = WriteFile(hCommSMS,					// Handle to the Serialport
		lpBufferSMS,								  // Data to be written to the port 
		dNoOFBytestoWriteAlert,						  // No of bytes to write into the port
		&dNoOfBytesWrittenAlert,						  // No of bytes written to the port
		NULL);

	Sleep(1000);

	//recive

	StatusAlert1 = WaitCommEvent(hCommSMS, &dwEventMaskAlert, NULL);

	if (StatusAlert1 == FALSE)
	{
		printf("\n    Error! in Setting WaitCommEvent()");
	}
	else
	{
		printf("\n\n    Characters Received");
		do
		{

			StatusAlert1 = ReadFile(hCommSMS, &TempCharAlert, sizeof(TempCharAlert), &NoBytesReadAlert, NULL);

			printf("%c", TempCharAlert);

		} while (NoBytesReadAlert > 0);

		printf("\n");

	}

	Sleep(1000);

	// Phone Number

	strcpy(lpBufferSMS, "AT+CMGS=\"+");
	strcat(lpBufferSMS, phonNumber);

	dNoOFBytestoWriteAlert = sizeof(lpBufferSMS);

	StatusAlert1 = WriteFile(hCommSMS,					// Handle to the Serialport
		lpBufferSMS,								  // Data to be written to the port 
		dNoOFBytestoWriteAlert,						  // No of bytes to write into the port
		&dNoOfBytesWrittenAlert,						  // No of bytes written to the port
		NULL);

	Sleep(1000);

	//recive

	StatusAlert1 = WaitCommEvent(hCommSMS, &dwEventMaskAlert, NULL);

	if (StatusAlert1 == FALSE)
	{
		printf("\n    Error! in Setting WaitCommEvent()");
	}
	else
	{
		printf("\n\n    Characters Received");
		do
		{

			StatusAlert1 = ReadFile(hCommSMS, &TempCharAlert, sizeof(TempCharAlert), &NoBytesReadAlert, NULL);

			printf("%c", TempCharAlert);

		} while (NoBytesReadAlert > 0);

		printf("\n");

	}

	Sleep(1000);

	// Send Message

	strcpy(lpBufferSMS, message);

	dNoOFBytestoWriteAlert = sizeof(lpBufferSMS);

	StatusAlert1 = WriteFile(hCommSMS,					// Handle to the Serialport
		lpBufferSMS,								  // Data to be written to the port 
		dNoOFBytestoWriteAlert,						  // No of bytes to write into the port
		&dNoOfBytesWrittenAlert,						  // No of bytes written to the port
		NULL);

	Sleep(1000);

	//recive

	StatusAlert1 = WaitCommEvent(hCommSMS, &dwEventMaskAlert, NULL);

	if (StatusAlert1 == FALSE)
	{
		printf("\n    Error! in Setting WaitCommEvent()");
	}
	else
	{
		printf("\n\n    Characters Received");
		do
		{

			StatusAlert1 = ReadFile(hCommSMS, &TempCharAlert, sizeof(TempCharAlert), &NoBytesReadAlert, NULL);

			printf("%c", TempCharAlert);

		} while (NoBytesReadAlert > 0);

		printf("\n");

	}
}
