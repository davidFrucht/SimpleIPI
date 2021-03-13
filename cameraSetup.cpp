
#include "cameraSetup.h"
#include "Header.h"
#include "MyForm.h"
#include "DFSL_Protocol.h"
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Windows.h>

#define SERIAL 0
#define LAN 1

int ptzProtocol = 0;
int PTZEnabledFlag = 0;

extern int com;

extern char* urlOnvifCamera;
extern char* userNameOnVif;
extern char* passwordOnVif;

extern std::string profileOnVif;
std::string camHtmlAdress;


gcroot<Bitmap^> gCameraToCheck;
HBITMAP hBitCameraToCheck;

int cameraToConnect;
char cameraUrlAddress[256];
int camSerialOrLan;

using namespace cv;


/*
public ref class formms 
{	
	Calc::MyForm f3;
	Calc::MyForm^ frm = gcnew Calc::MyForm();
};
*/


Calc::cameraSetup::cameraSetup(){
	InitializeComponent();

	//Calc::MyForm dsg;
	
};

Calc::cameraSetup::~cameraSetup(){
	if (components){
		delete components;
	};
};


System::Void Calc::cameraSetup::btnConnectCam_Click(System::Object^ sender, System::EventArgs^ e){			// connecting to serial PTZ
	
	var = int::Parse(cmboBoxBaudCam->SelectedItem->ToString());
	int i = int::Parse(comboBoxCom->SelectedItem->ToString());

	com = int::Parse(comboBoxCom->SelectedItem->ToString());

	ptzInit();
	if (connectionFlag == 1){
		btnConnectCam->Enabled = false;
		btnCheckConPelcoD->Enabled = true;
	};
}
System::Void Calc::cameraSetup::btnCheckConPelcoD_Click(System::Object^ sender, System::EventArgs^ e) {
	if (PTZEnabledFlag)
	{
		var = 100;
		sendPtzPan();
	}
};

System::Void Calc::cameraSetup::radioBtnSerialCamera_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	groupBoxPelcoCam->Enabled = true;		
}

System::Void Calc::cameraSetup::radioBtnLanCamera_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{

	if (radioBtnLanCamera->Checked == true)
	{
		comboBoxCom->Enabled = false;
		lblComCamera->Enabled = false;
		lblBaudCam->Enabled = false;
		btnConnectCam->Enabled = false;
		cmboBoxBaudCam->Enabled = false;
		btnDisconnectPelcoCam->Enabled = false;
		btnCheckConPelcoD->Enabled = false;

	
		txbBoxCamURL->Enabled = true;
		lblLink->Enabled = true;
		btnConnectPTZLan->Enabled = true;
		lblLink->Enabled = true;
		lblProfile->Enabled = true;
		txtBoxProfileLanPTZ->Enabled = true;
		lblUserName->Enabled = true;
		txtBoxUserNamePTZLAN->Enabled = true;
		lblPassWordPTZLAN->Enabled = true;
		textBox1->Enabled = true;

	}

	if (radioBtnSerialCamera->Checked == true)
	{
		txbBoxCamURL->Enabled = false;
		lblLink->Enabled = false;
		btnConnectPTZLan->Enabled = false;
		lblLink->Enabled = false;
		lblProfile->Enabled = false;
		txtBoxProfileLanPTZ->Enabled = false;
		lblUserName->Enabled = false;
		txtBoxUserNamePTZLAN->Enabled = false;
		lblPassWordPTZLAN->Enabled = false;
		textBox1->Enabled = false;
	
		comboBoxCom->Enabled = true;
		lblComCamera->Enabled = true;
		lblBaudCam->Enabled = true;
		btnConnectCam->Enabled = true;
		cmboBoxBaudCam->Enabled = true;
		btnDisconnectPelcoCam->Enabled = true;
		btnCheckConPelcoD->Enabled = true;
	}
}

System::Void Calc::cameraSetup::radioButtonVideoFeedSerial_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	
	if (radioButradioButtonVideoFeedLan->Checked == true)
	{
		panelVideoFeenSerial->Enabled = false;
		panelVideoFeedLan->Enabled = true;
	}

	if (radioButtonVideoFeedSerial->Checked == true)
	{
		panelVideoFeedLan->Enabled = false;
		panelVideoFeenSerial->Enabled = true;
	}

}

System::Void Calc::cameraSetup::btnConnectVideoFeedLan_Click(System::Object^ sender, System::EventArgs^ e)
{
	sprintf(cameraUrlAddress, "%s", this->txtLanVideoFeedLink->Text);
	camSerialOrLan = LAN;
}

System::Void Calc::cameraSetup::comboBoxEnablePtz_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
{
	
	if (comboBoxEnablePtz->SelectedItem == "Pelco D")
		ptzProtocol = PTZ_PELCO_D;

	if (comboBoxEnablePtz->SelectedItem == "ONVIF")
		ptzProtocol = PTZ_ONVIF;

	if (comboBoxEnablePtz->SelectedItem == "Diabled")
		ptzProtocol = PTZ_DISABLED;
}

System::Void Calc::cameraSetup::button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	System::String^ temp = txbBoxCamURL->Text;
	urlOnvifCamera = (char*)(void*)Marshal::StringToHGlobalAnsi(temp);

	temp = txtBoxUserNamePTZLAN->Text;
	userNameOnVif = (char*)(void*)Marshal::StringToHGlobalAnsi(temp);
	
	temp = textBox1->Text;
	passwordOnVif = (char*)(void*)Marshal::StringToHGlobalAnsi(temp);
	
	temp = txtBoxProfileLanPTZ->Text;
	msclr::interop::marshal_context context;
	profileOnVif = context.marshal_as<std::string>(temp);
}

System::Void Calc::cameraSetup::cameraSetup_Load(System::Object^ sender, System::EventArgs^ e)
{
	sendToSensor(CMD_GET_TILT_TABLE);

	array<TextBox^>^ txtArray = gcnew array<TextBox^>{
		txtBoxTilt0, txtBoxTilt1, txtBoxTilt2, txtBoxTilt3, txtBoxTilt4, txtBoxTilt5, txtBoxTilt6, txtBoxTilt7, txtBoxTilt8, txtBoxTilt9
	};
	//TextBox^ txt;
	char temp[100];
	System::String^ tempStr;

	for (int i = 0, j = 7; i < 10; i++, j++)
	{
		sprintf(temp, "%u", SerialBufferPLS[j]);

		System::String^ tempStr = gcnew System::String(temp);
		txtArray[i]->Text = tempStr;
		//txtArray[i + 7]->Text = tempStr;
		memset(temp, 0, strlen(temp));
	}

	//checking how many cameras are connected to the pc and can be used with OpenCV - max number will be 5 to check;

	int cnt = 0;

	for (int i = 0; i < 5; i++)
	{
		VideoCapture cap(i);

		if (cap.isOpened())
			cnt++;
		
		cap.release();
	}

	array<Button^>^ btnArray = gcnew array<Button^>{
		btnCamera1,btnCamera2,btnCamera3,btnCamera4,btnCamera5
	};

	for (int j = cnt; j < 5; j++)
		btnArray[j]->Enabled = false;

}

System::Void Calc::cameraSetup::btnCamera1_Click(System::Object^ sender, System::EventArgs^ e) {

	VideoCapture cap(0);
	Mat frame;

	cap >> frame;

	cvtColor(frame, frame, 0);
	hBitCameraToCheck = CreateBitmap(frame.cols, frame.rows, 1, 32, frame.data);
	gCameraToCheck = Bitmap::FromHbitmap((IntPtr)hBitCameraToCheck);
	DeleteObject(hBitCameraToCheck);

	this->pitureBoxchooseCamera->SizeMode = PictureBoxSizeMode::StretchImage;
	this->pitureBoxchooseCamera->Image = gCameraToCheck;

	cameraToConnect = 0;
	cap.release();
}
	

System::Void Calc::cameraSetup::btnCamera2_Click(System::Object^ sender, System::EventArgs^ e) {
	VideoCapture cap(1);
	Mat frame;

	Sleep(2000);

	cap >> frame;

	cvtColor(frame, frame, 0);
	hBitCameraToCheck = CreateBitmap(frame.cols, frame.rows, 1, 32, frame.data);
	gCameraToCheck = Bitmap::FromHbitmap((IntPtr)hBitCameraToCheck);
	DeleteObject(hBitCameraToCheck);

	this->pitureBoxchooseCamera->SizeMode = PictureBoxSizeMode::StretchImage;
	this->pitureBoxchooseCamera->Image = gCameraToCheck;
	
	cameraToConnect = 1;
	cap.release();

}

System::Void Calc::cameraSetup::btnCamera3_Click(System::Object^ sender, System::EventArgs^ e) {
	VideoCapture cap(2);
	Mat frame;

	cap >> frame;

	cvtColor(frame, frame, 0);
	hBitCameraToCheck = CreateBitmap(frame.cols, frame.rows, 1, 32, frame.data);
	gCameraToCheck = Bitmap::FromHbitmap((IntPtr)hBitCameraToCheck);
	DeleteObject(hBitCameraToCheck);

	this->pitureBoxchooseCamera->SizeMode = PictureBoxSizeMode::StretchImage;
	this->pitureBoxchooseCamera->Image = gCameraToCheck;

	cameraToConnect = 2;
	cap.release();
}

System::Void Calc::cameraSetup::btnCamera4_Click(System::Object^ sender, System::EventArgs^ e) {
	VideoCapture cap(3);
	Mat frame;

	cap >> frame;

	cvtColor(frame, frame, 0);
	hBitCameraToCheck = CreateBitmap(frame.cols, frame.rows, 1, 32, frame.data);
	gCameraToCheck = Bitmap::FromHbitmap((IntPtr)hBitCameraToCheck);
	DeleteObject(hBitCameraToCheck);

	this->pitureBoxchooseCamera->SizeMode = PictureBoxSizeMode::StretchImage;
	this->pitureBoxchooseCamera->Image = gCameraToCheck;

	cameraToConnect = 3;
	cap.release();
}

System::Void Calc::cameraSetup::btnCamera5_Click(System::Object^ sender, System::EventArgs^ e) {
	VideoCapture cap(4);
	Mat frame;

	cap >> frame;

	cvtColor(frame, frame, 0);
	hBitCameraToCheck = CreateBitmap(frame.cols, frame.rows, 1, 32, frame.data);
	gCameraToCheck = Bitmap::FromHbitmap((IntPtr)hBitCameraToCheck);
	DeleteObject(hBitCameraToCheck);

	this->pitureBoxchooseCamera->SizeMode = PictureBoxSizeMode::StretchImage;
	this->pitureBoxchooseCamera->Image = gCameraToCheck;

	cameraToConnect = 4;
	cap.release();
}

System::Void Calc::cameraSetup::btConnectCV_Click(System::Object^ sender, System::EventArgs^ e) {
	camSerialOrLan = SERIAL;
}




