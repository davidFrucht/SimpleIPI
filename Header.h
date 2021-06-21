#pragma once
#include "MyForm.h"
#include "onvif.h"
#include "json.h"

#include <string>
#include <opencv2/opencv.hpp>


namespace Calc {
	
	
	// PTZ
	void setLog(System::Windows::Forms::RichTextBox^% ptr);
	void ptzInit();
	void sendPtzPan();
	void sendPtzTilt();
	void exitPro();
	void move();
	void setNewZero();
	void stateMode();

	// PLS
	void initatePls();
	int integrityCheck();
	void decipherMessageIntruderDetected();
	void advancedSetup();
	void decipherMessageSystemVisibalityChanges();
	void decipherMessageSystemMaintenanceNotifcation1();
	void decipherMessageSystemMaintenanceNotifcationLRF();
	void decipherMessageSystemMaintenanceNotifcationErrorAngle();

	// Alerts

	void initCellPhone();
	int checkConnectionCell();
	void detecionCellAlert();

	extern int temp;
	extern int var;

	extern float azimuth, range;
	extern int flagCellularAlert;
	extern int flagEmailAlert;
	extern int flagJSONAlert;
	extern wchar_t ComPortNameAlert1[12];

	

	
	extern wchar_t ComPortName[12];
	extern int com;
	extern int ComAlert;

	extern int connectionFlag;
	extern unsigned char speed;

	extern int videoAnalyticFlag;
	

	extern std::string phoneNumberStr;

	
}
