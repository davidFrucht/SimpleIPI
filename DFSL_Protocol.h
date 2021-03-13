#pragma once
#include "connectToCom.h"


extern HANDLE hCommPLS;														// Handle to the Serial port
extern BOOL  StatusPLS;														// Status of the various operations 
extern DWORD dwEventMaskPLS;													// Event mask to trigger
extern byte  TempCharPLS;														// Temperory Character
extern byte  SerialBufferPLS[1024];											// Buffer Containing Rxed Data
extern DWORD NoBytesReadPLS;													// Bytes read by ReadFile()
extern int cntMessagesPLS;
extern int checkSumPLS;

#define HEADER 0x55

// commands
#define CMD_RESET							0x02
#define	CMD_PARAMETERS						0x07
#define CMD_GET_SERIAL_NUMBER				0x08
#define CMD_GET_SOFTWARE_VERSION			0x0A
#define CMD_FULL_RESET						0x0E
#define CMD_STATE_2							0x18
#define CMD_GET_ZOOM_TABLE					0x24
#define CMD_GET_TILT_TABLE					0x26

//replys - size (bytes length) of subpacket
#define INTRUDER_DETECTED_SIZE						0x04
#define INTRUDER_DETECTE_WITH_WIDTH_SIZE			0x08
#define SYSTEM_VISIBILTY_CHANGES_SIZE				0x02
#define MAINTENANCE_NOTIFICATION_1_SIZE				0X01	
#define MAINTENANCE_NOTIFICATION_LRF_SIZE			0x02
#define MAINTENANCE_NOTIFICATION_ERROR_ANGLE_SIZE	0x02

//replys - type of reply
#define INTRUDER_DETECTED_NO_WIDTH					0x00
#define INTRUDER_DETECTED_WITH_WIDTH				0x07
#define SYSTEM_VISIBILTY_CHANGES					0x06
#define MAINTENANCE_NOTIFICATION_1					0X02	
#define MAINTENANCE_NOTIFICATION_LRF				0x03
#define MAINTENANCE_NOTIFICATION_ERROR_ANGLE		0x04

//location of relevant data in sub-packets
#define REPLY_COMMAND_LOC					3 + 2
#define SIZE_LOC							4 + 2
#define TYPE_LOC							4 + 3

//System Visiblty Changes
#define APPEARS								0
#define DISAPPEARS							1
#define ICE_OR_DUST							0x01
#define SYSTEM_COVERED						0x02
#define FOG									0x03

//Maintancnce Notification LRF
#define LRF1								0x00
#define LRF2								0x01

//fast draw mode
#define SET_MODE_CMD						0x04
#define SET_FAST_DRAW_MODE					0x82
#define SET_DETECTION_MODE					0x81
#define GET_FAST_DRAW_DATA					0x03

 

void reciveMessageFromSensor();
inline void sendToSensorFastDraw(byte command1, byte command2);
void sendToSensorFastDraw(byte command, byte byte1, byte byte2);

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;





inline void sendToSensor(byte command)
{
	byte checksum = 0x00;

	byte lpBufferSensor[] = { HEADER,0x83,0x00,command,0x00, checksum };				// header,Master&length -3, command, subCommand, checksum

	int i;

	for (i = 0; i < sizeof(lpBufferSensor) - 1; i++)
		checksum += lpBufferSensor[i];

	lpBufferSensor[i] = checksum;


	DWORD  dNoOFBytestoWriteSensor;
	DWORD  dNoOfBytesWrittenSensor = 0;

	dNoOFBytestoWriteSensor = sizeof(lpBufferSensor);

	StatusPLS = WriteFile(hCommPLS,               // Handle to the Serialport
		lpBufferSensor,								  // Data to be written to the port 
		dNoOFBytestoWriteSensor,						  // No of bytes to write into the port
		&dNoOfBytesWrittenSensor,						  // No of bytes written to the port
		NULL);

	memset(SerialBufferPLS, 0, sizeof(SerialBufferPLS));
	
	reciveMessageFromSensor();

}


inline void sendToSensorHZ(byte hiddenZone)
{
	byte checksum = 0x00;

	byte lpBufferSensor[] = { HEADER,0x83,0x00,0x29,hiddenZone,0x00,0x00,0x00,checksum };				// header,Master&length -3, command, subCommand, checksum

	int i;

	for (i = 0; i < sizeof(lpBufferSensor) - 1; i++)
		checksum += lpBufferSensor[i];

	lpBufferSensor[i] = checksum;


	DWORD  dNoOFBytestoWriteSensor;
	DWORD  dNoOfBytesWrittenSensor = 0;

	dNoOFBytestoWriteSensor = sizeof(lpBufferSensor);

	StatusPLS = WriteFile(hCommPLS,               // Handle to the Serialport
		lpBufferSensor,								  // Data to be written to the port 
		dNoOFBytestoWriteSensor,						  // No of bytes to write into the port
		&dNoOfBytesWrittenSensor,						  // No of bytes written to the port
		NULL);

	memset(SerialBufferPLS, 0, sizeof(SerialBufferPLS));

	reciveMessageFromSensor();

}

inline void fastDraw()
{

	float fastDrawArrayLRF1[359];
	float fastDrawArrayLRF2[359];

	//hCommPLS = connectCom(6, 115200);
	


	sendToSensorFastDraw(0x04, SET_FAST_DRAW_MODE);
	Sleep(100);

	if (SerialBufferPLS[5] == 0x04 && SerialBufferPLS[6] == 0x02)
	{
		for (int i = 0; i < 360; i++)
			{
				byte indexByte = i;
				if (i <= 255)
					sendToSensorFastDraw(0x03, 0x00, indexByte);
				else
					sendToSensorFastDraw(0x03, 0x10, (indexByte - 0xFF));

				Sleep(100);

				if (SerialBufferPLS[REPLY_COMMAND_LOC] == 0x03)
				{
					if (SerialBufferPLS[REPLY_COMMAND_LOC + 1] == 0x40)
					{
						int errorAngle = SerialBufferPLS[REPLY_COMMAND_LOC + 2] << 8;
						errorAngle |= SerialBufferPLS[REPLY_COMMAND_LOC + 3];

						FILE* fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
						fprintf(fptrPLS, "\nFast Draw Error: angle %f", 359.94 / 5999.00 * (float)errorAngle);
						fclose(fptrPLS);
					}
					else
					{
						fastDrawArrayLRF1[i] = 100.0 / 1024.0 * SerialBufferPLS[REPLY_COMMAND_LOC + 3];
						fastDrawArrayLRF2[i] = 100.0 / 1024.0 * SerialBufferPLS[REPLY_COMMAND_LOC + 4];
					}
				}
			}
	}
	
	
	FILE* fptrPLS = fopen("c:\\1\\eventLog.txt", "w");
	for (int i = 0; i < 359; i++)
	{
		fprintf(fptrPLS, "\nangle: %d starting range: %f ending range: %f", i, fastDrawArrayLRF1[i], fastDrawArrayLRF2[i]);
	}
	fclose(fptrPLS);

	int x = 11;

}
	
inline void sendToSensorFastDraw(byte command1, byte command2)
{
	byte checksum = 0x00;

	byte lpBufferSensor[] = { HEADER,0x83,0x00,command1,command2,checksum };				// header,Master&length -3, command, subCommand, checksum

	int i;

	for (i = 0; i < sizeof(lpBufferSensor) - 1; i++)
		checksum += lpBufferSensor[i];

	lpBufferSensor[i] = checksum;


	DWORD  dNoOFBytestoWriteSensor;
	DWORD  dNoOfBytesWrittenSensor = 0;

	dNoOFBytestoWriteSensor = sizeof(lpBufferSensor);

	StatusPLS = WriteFile(hCommPLS,               // Handle to the Serialport
		lpBufferSensor,								  // Data to be written to the port 
		dNoOFBytestoWriteSensor,						  // No of bytes to write into the port
		&dNoOfBytesWrittenSensor,						  // No of bytes written to the port
		NULL);

	memset(SerialBufferPLS, 0, sizeof(SerialBufferPLS));

	reciveMessageFromSensor();

}

// this is the 3rd stage in getting the draw informatiom. command == 0x03, byte1 is relevant only when angle > then 255.
inline void sendToSensorFastDraw(byte command, byte byte1, byte byte2)
{
	byte checksum = 0x00;

	byte lpBufferSensor[] = { HEADER,0x86,0x00,command ,byte1,byte2, 0x00, 0x00, checksum };				// header,Master&length -3, command, subCommand, checksum

	int i;

	for (i = 0; i < sizeof(lpBufferSensor) - 1; i++)
		checksum += lpBufferSensor[i];

	lpBufferSensor[i] = checksum;


	DWORD  dNoOFBytestoWriteSensor;
	DWORD  dNoOfBytesWrittenSensor = 0;

	dNoOFBytestoWriteSensor = sizeof(lpBufferSensor);

	StatusPLS = WriteFile(hCommPLS,               // Handle to the Serialport
		lpBufferSensor,								  // Data to be written to the port 
		dNoOFBytestoWriteSensor,						  // No of bytes to write into the port
		&dNoOfBytesWrittenSensor,						  // No of bytes written to the port
		NULL);

	memset(SerialBufferPLS, 0, sizeof(SerialBufferPLS));

	reciveMessageFromSensor();

}

inline void reciveMessageFromSensor()
{
	cntMessagesPLS = 0;
	StatusPLS = WaitCommEvent(hCommPLS, &dwEventMaskPLS, NULL);

	if (StatusPLS == FALSE)
	{
		printf("\n    Error! in Setting WaitCommEvent()");
	}
	else
	{
		printf("\n\n    Characters Received");
		do
		{

			StatusPLS = ReadFile(hCommPLS, &TempCharPLS, sizeof(TempCharPLS), &NoBytesReadPLS, NULL);
			SerialBufferPLS[cntMessagesPLS] = TempCharPLS;
			cntMessagesPLS++;

		} while (NoBytesReadPLS > 0);
	}
	
}

inline int hiddenZone(float intruderRange, float intrutdersAzimuth, float polyArrayX[], float polyArrayY[], int polyCorners, int numOfClicks)			// x = range y = azimuth
{
	int x = 175 + (intruderRange * cos(intrutdersAzimuth));			// pixel size of picturebox is 351x351. radiu is 351/2 = 175
	int y = 175 - (intruderRange * sin(intrutdersAzimuth));

	polyCorners = numOfClicks / 2;
	int   i, j = polyCorners - 1;
	bool  oddNodes = false;

	for (i = 0; i < polyCorners; i++) {
		if (polyArrayY[i] < y && polyArrayY[j] >= y
			|| polyArrayY[j] < y && polyArrayY[i] >= y) {
			if (polyArrayX[i] + (y - polyArrayY[i]) / (polyArrayY[j] - polyArrayY[i]) * (polyArrayX[j] - polyArrayX[i]) < x) {
				oddNodes = !oddNodes;
			}
		}
		j = i;
	}

	return oddNodes;
}






