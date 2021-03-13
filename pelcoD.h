#pragma once

#include <iostream>
#include <string.h>
#include <windows.h>
#include <msports.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP_MOVEMENT 5
#define ZOOM_IN 6
#define ZOOM_OUT 7




//HANDLE hComm;										// Handle to the Serial port
//wchar_t Calc::ComPortName[12] = L"\\\\.\\COM";		// Name of the Serial port(May Change) to be opened,
BOOL  Status1;										// Status of the various operations 
DWORD dwEventMask;									// Event mask to trigger
char  TempChar1;										// Temperory Character
char  SerialBuffer[256];							// Buffer Containing Rxed Data
DWORD NoBytesRead;									// Bytes read by ReadFile()
int i1 = 0;


void sendPtzPanPelcoHeader(HANDLE hComm, int var)
{


	byte address = 0x02;				// camera address
	const byte cmnd1 = 0x00;			// fixed value for paning to specific point
	const byte cmnd2 = 0x4B;			// fixed value for paning to specific point
	int pelcoDegreesToPan = 35999 / 359 * var;

	unsigned char b, c;
	b = (pelcoDegreesToPan >> 8) & 0xFF;
	c = pelcoDegreesToPan & 0xFF;

	byte lsbTry = c;
	byte msbTry = b;

	byte checkSum = address + cmnd1 + cmnd2 + lsbTry + msbTry;

	byte lpBuffer[] = { 0xFF,address,cmnd1,cmnd2,msbTry,lsbTry,checkSum };

	DWORD  dNoOFBytestoWrite;              // No of bytes to write into the port
	DWORD  dNoOfBytesWritten = 0;          // No of bytes written to the port


	dNoOFBytestoWrite = sizeof(lpBuffer); // Calculating the no of bytes to write into the port

	Status1 = WriteFile(hComm,               // Handle to the Serialport
		lpBuffer,            // Data to be written to the port 
		dNoOFBytestoWrite,   // No of bytes to write into the port
		&dNoOfBytesWritten,  // No of bytes written to the port
		NULL);

}

void sendPtzTiltPelcoHeader(HANDLE hComm, int var)
{
	byte address = 0x02;				// camera address
	const byte cmnd1 = 0x00;			// fixed value for paning to specific point
	const byte cmnd2 = 0x4D;			// fixed value for paning to specific point
	int pelcoDegreesToPan = 35999 / 359 * var;

	unsigned char b, c;
	b = (pelcoDegreesToPan >> 8) & 0xFF;
	c = pelcoDegreesToPan & 0xFF;

	byte lsbTry = c;
	byte msbTry = b;

	byte checkSum = address + cmnd1 + cmnd2 + lsbTry + msbTry;

	byte lpBuffer[] = { 0xFF,address,cmnd1,cmnd2,msbTry,lsbTry,checkSum };

	DWORD  dNoOFBytestoWrite;              // No of bytes to write into the port
	DWORD  dNoOfBytesWritten = 0;          // No of bytes written to the port


	dNoOFBytestoWrite = sizeof(lpBuffer); // Calculating the no of bytes to write into the port

	Status1 = WriteFile(hComm,               // Handle to the Serialport
		lpBuffer,            // Data to be written to the port 
		dNoOFBytestoWrite,   // No of bytes to write into the port
		&dNoOfBytesWritten,  // No of bytes written to the port
		NULL);
}

void movePelcoHeader(HANDLE hComm, int var, unsigned char speed)
{
	byte address;
	byte cmnd1;			// fixed value for paning to specific point
	byte cmnd2;			// fixed value for paning to specific point
	byte data1;
	byte data2;

	switch (var)
	{
	case UP:

		address = 0x02;				// camera address
		cmnd1 = 0x00;			// fixed value for paning to specific point
		cmnd2 = 0x08;			// fixed value for paning to specific point
		data1 = 0x00;
		data2 = speed;
		break;

	case DOWN:
		address = 0x02;				// camera address
		cmnd1 = 0x00;			// fixed value for paning to specific point
		cmnd2 = 0x10;			// fixed value for paning to specific point
		data1 = 0x00;
		data2 = speed;
		break;

	case LEFT:
		address = 0x02;				// camera address
		cmnd1 = 0x00;			// fixed value for paning to specific point
		cmnd2 = 0x04;			// fixed value for paning to specific point
		data1 = speed;
		data2 = 0x00;
		break;

	case RIGHT:
		address = 0x02;				// camera address
		cmnd1 = 0x00;			// fixed value for paning to specific point
		cmnd2 = 0x02;			// fixed value for paning to specific point
		data1 = speed;
		data2 = 0x00;
		break;

	case STOP_MOVEMENT:
		address = 0x02;				// camera address
		cmnd1 = 0x00;			// fixed value for paning to specific point
		cmnd2 = 0x00;			// fixed value for paning to specific point
		data1 = 0x00;
		data2 = 0x01;
		break;

	case ZOOM_IN:
		address = 0x02;
		cmnd1 = 0x00;
		cmnd2 = 0x20;
		data1 = 0x00;
		data2 = 0x00;
		break;

	case ZOOM_OUT:
		address = 0x02;
		cmnd1 = 0x00;
		cmnd2 = 0x40;
		data1 = 0x00;
		data2 = 0x00;
		break;
	}


	byte checkSum = address + cmnd1 + cmnd2 + data1 + data2;

	byte lpBuffer[] = { 0xFF,address,cmnd1,cmnd2,data1,data2,checkSum };

	DWORD  dNoOFBytestoWrite;              // No of bytes to write into the port
	DWORD  dNoOfBytesWritten = 0;          // No of bytes written to the port


	dNoOFBytestoWrite = sizeof(lpBuffer); // Calculating the no of bytes to write into the port

	Status1 = WriteFile(hComm,               // Handle to the Serialport
		lpBuffer,            // Data to be written to the port 
		dNoOFBytestoWrite,   // No of bytes to write into the port
		&dNoOfBytesWritten,  // No of bytes written to the port
		NULL);


}

void setNewZeroPelcoDHeader(HANDLE hComm)
{
	byte address = 0x02;
	byte cmnd1 = 0x00;			// fixed value for paning to specific point
	byte cmnd2 = 0x49;			// fixed value for paning to specific point
	byte data1 = 0x00;
	byte data2 = 0x00;

	byte checkSum = address + cmnd1 + cmnd2 + data1 + data2;

	byte lpBuffer[] = { 0xFF,address,cmnd1,cmnd2,data1,data2,checkSum };

	DWORD  dNoOFBytestoWrite;              // No of bytes to write into the port
	DWORD  dNoOfBytesWritten = 0;          // No of bytes written to the port


	dNoOFBytestoWrite = sizeof(lpBuffer); // Calculating the no of bytes to write into the port

	Status1 = WriteFile(hComm,               // Handle to the Serialport
		lpBuffer,            // Data to be written to the port 
		dNoOFBytestoWrite,   // No of bytes to write into the port
		&dNoOfBytesWritten,  // No of bytes written to the port
		NULL);
}


