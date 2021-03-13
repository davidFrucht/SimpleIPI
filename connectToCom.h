#pragma once

#include <iostream>
#include <string.h>
#include <windows.h>
#include <msports.h>
#include <stdlib.h>
#include <stdio.h>
//#include <vector>
#include <string.h>

//extern HANDLE hCommPTZ;


inline HANDLE connectCom(int com, int baudRate)
{

	HANDLE handle;
	wchar_t  ComPortNameAlert[] = L"\\\\.\\COM";
	BOOL  StatusAlert;
	DWORD dwEventMaskAlert;
	char  TempCharAlert;
	char  SerialBufferAlert[256];
	DWORD NoBytesReadAlert;
	int cntMessagesAlert = 0;
	char bufferAlert[256];
	int checkSumAlert = 0;
	char* ptrAlert;
	int tempAlert;
	int flagAlert = 0;


	swprintf((ComPortNameAlert)+7, sizeof(ComPortNameAlert) - 1, L"%d", com);


	handle = CreateFile(ComPortNameAlert,
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);

	if (handle == INVALID_HANDLE_VALUE)
		return 0;


	DCB dcbSerialParamsAlert = { 0 };
	dcbSerialParamsAlert.DCBlength = sizeof(dcbSerialParamsAlert);

	StatusAlert = GetCommState(handle, &dcbSerialParamsAlert);

	if (StatusAlert == FALSE)
		return 0;

	dcbSerialParamsAlert.BaudRate = baudRate;
	dcbSerialParamsAlert.ByteSize = 8;
	dcbSerialParamsAlert.StopBits = ONESTOPBIT;
	dcbSerialParamsAlert.Parity = NOPARITY;

	StatusAlert = SetCommState(handle, &dcbSerialParamsAlert);


	COMMTIMEOUTS timeoutsAlert = { 0 };
	timeoutsAlert.ReadIntervalTimeout = 50;
	timeoutsAlert.ReadTotalTimeoutConstant = 50;
	timeoutsAlert.ReadTotalTimeoutMultiplier = 10;
	timeoutsAlert.WriteTotalTimeoutConstant = 50;
	timeoutsAlert.WriteTotalTimeoutMultiplier = 10;

	if (SetCommTimeouts(handle, &timeoutsAlert) == FALSE)
		return 0;
	

	StatusAlert = SetCommMask(handle, EV_RXCHAR);

	if (StatusAlert == FALSE)
		return 0;
	
	return handle;
}



