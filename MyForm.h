#pragma once
//#include "alertSetup.h"
//#include "cameraSetup.h"
//#include "sensorSetup.h"
#include "Header.h"
//#include "connectToCom.h"

#include "DFSL_Protocol.h"

#include <fstream>
#include <cstdlib>
#include <Windowsx.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


//#include<Windows.h>


#include <msclr\marshal_cppstd.h>

#define SLOW 0x0A
#define MEDIUM 0x20
#define FAST_ 0x3F

#define WM_MOUSEMOVE                    0x0200

//extern float azimuth;
//extern float range;
using namespace System;
using namespace System::IO;
using namespace System::Threading;
using namespace System::Collections;
using namespace System::Device::Location;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;


extern int var;



namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class MyForm : public System::Windows::Forms::Form {



	public:
		MyForm();
	protected:
		~MyForm();
	private:
		System::Windows::Forms::Button^ btnUp;
		System::Windows::Forms::Button^ btnDown;
		System::Windows::Forms::Button^ btnLeft;
		System::Windows::Forms::Button^ btnRight;
		System::Windows::Forms::Button^ btnStop;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ txtPanGoto;
		System::Windows::Forms::TextBox^ txtTiltGoto;
		System::Windows::Forms::Label^ lblGoToTilt;
		System::Windows::Forms::Button^ btnReturn0;
		System::Windows::Forms::Button^ btnMovePan;
		System::Windows::Forms::Button^ btnTiltMov;
		System::Windows::Forms::Button^ btnSlow;
		System::Windows::Forms::Button^ btnMedium;
		System::Windows::Forms::Button^ btnFast;
		System::Windows::Forms::Button^ btnZoomIn;
		System::Windows::Forms::Button^ btnZoomOut;

		System::Windows::Forms::Button^ btnSetZero;
	public: Microsoft::Web::WebView2::WinForms::WebView2^ webView21;
	private:

		System::DirectoryServices::DirectorySearcher^ directorySearcher1;
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ setupToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ sensorToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ cameraToolStripMenuItem;
		System::Windows::Forms::PictureBox^ picBoxRadar;
		System::Windows::Forms::PictureBox^ pictureBox1;


		System::Windows::Forms::PictureBox^ googleEarthBox;



		System::Windows::Forms::ToolStripMenuItem^ alertsToolStripMenuItem;
		//System::IO::FileSystemWatcher^ fileSystemWatcher1;
	public: System::Windows::Forms::TextBox^ txtBoxLogText;
	private:

		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		System::ComponentModel::BackgroundWorker^ backgroundWorker2;
		System::Windows::Forms::Label^ radarMousePos;
		System::Windows::Forms::Label^ coordLbl;

		System::Windows::Forms::Label^ DMScoord;
		Microsoft::Web::WebView2::WinForms::WebView2^ webView22;
		System::Windows::Forms::Button^ btNavigateToLatLon;
		System::Windows::Forms::TextBox^ txtLon;
		System::Windows::Forms::TextBox^ txtLat;
		System::Windows::Forms::Label^ lblLon;
		System::Windows::Forms::Label^ lblLongitude;
		System::Windows::Forms::ToolStripMenuItem^ reportToolStripMenuItem;
		System::Windows::Forms::Button^ btnMakeStatic;
		System::Windows::Forms::PictureBox^ mapPictureBox;
		System::Windows::Forms::Button^ btnUnFixMapPicture;
	//private: System::IO::FileSystemWatcher^ fileSystemWatcher2;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::Button^ btnTakePicture;
	private: System::Windows::Forms::PictureBox^ pictureBoxPhotoFlash;
	private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem;

	private: System::Windows::Forms::Button^ btnFastDraw;

	private: System::Windows::Forms::CheckBox^ checkBoxRemoteConnection;
	private: System::Windows::Forms::Label^ lblClock;
	private: System::Windows::Forms::Timer^ clocklTmer;
	private: System::Windows::Forms::Timer^ timerLog;

	private: System::Windows::Forms::PictureBox^ picBoxCamera;
	private: System::Windows::Forms::Timer^ timerVideo;
	private: System::Windows::Forms::CheckBox^ checkBoxInitateSensor;
	public: System::Windows::Forms::Timer^ timerHZ;
	private:






	private: System::ComponentModel::IContainer^ components;















#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>

		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			   this->btnUp = (gcnew System::Windows::Forms::Button());
			   this->btnDown = (gcnew System::Windows::Forms::Button());
			   this->btnLeft = (gcnew System::Windows::Forms::Button());
			   this->btnRight = (gcnew System::Windows::Forms::Button());
			   this->btnStop = (gcnew System::Windows::Forms::Button());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->txtPanGoto = (gcnew System::Windows::Forms::TextBox());
			   this->txtTiltGoto = (gcnew System::Windows::Forms::TextBox());
			   this->lblGoToTilt = (gcnew System::Windows::Forms::Label());
			   this->btnReturn0 = (gcnew System::Windows::Forms::Button());
			   this->btnMovePan = (gcnew System::Windows::Forms::Button());
			   this->btnTiltMov = (gcnew System::Windows::Forms::Button());
			   this->btnSlow = (gcnew System::Windows::Forms::Button());
			   this->btnMedium = (gcnew System::Windows::Forms::Button());
			   this->btnFast = (gcnew System::Windows::Forms::Button());
			   this->btnZoomIn = (gcnew System::Windows::Forms::Button());
			   this->btnZoomOut = (gcnew System::Windows::Forms::Button());
			   this->btnSetZero = (gcnew System::Windows::Forms::Button());
			   this->webView21 = (gcnew Microsoft::Web::WebView2::WinForms::WebView2());
			   this->directorySearcher1 = (gcnew System::DirectoryServices::DirectorySearcher());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->reportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->setupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->sensorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->cameraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->alertsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->picBoxRadar = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->googleEarthBox = (gcnew System::Windows::Forms::PictureBox());
			   this->txtBoxLogText = (gcnew System::Windows::Forms::TextBox());
			   this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			   this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			   this->radarMousePos = (gcnew System::Windows::Forms::Label());
			   this->coordLbl = (gcnew System::Windows::Forms::Label());
			   this->DMScoord = (gcnew System::Windows::Forms::Label());
			   this->webView22 = (gcnew Microsoft::Web::WebView2::WinForms::WebView2());
			   this->btNavigateToLatLon = (gcnew System::Windows::Forms::Button());
			   this->lblLongitude = (gcnew System::Windows::Forms::Label());
			   this->lblLon = (gcnew System::Windows::Forms::Label());
			   this->txtLat = (gcnew System::Windows::Forms::TextBox());
			   this->txtLon = (gcnew System::Windows::Forms::TextBox());
			   this->btnMakeStatic = (gcnew System::Windows::Forms::Button());
			   this->mapPictureBox = (gcnew System::Windows::Forms::PictureBox());
			   this->btnUnFixMapPicture = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->btnTakePicture = (gcnew System::Windows::Forms::Button());
			   this->pictureBoxPhotoFlash = (gcnew System::Windows::Forms::PictureBox());
			   this->btnFastDraw = (gcnew System::Windows::Forms::Button());
			   this->checkBoxRemoteConnection = (gcnew System::Windows::Forms::CheckBox());
			   this->clocklTmer = (gcnew System::Windows::Forms::Timer(this->components));
			   this->lblClock = (gcnew System::Windows::Forms::Label());
			   this->timerLog = (gcnew System::Windows::Forms::Timer(this->components));
			   this->picBoxCamera = (gcnew System::Windows::Forms::PictureBox());
			   this->timerVideo = (gcnew System::Windows::Forms::Timer(this->components));
			   this->checkBoxInitateSensor = (gcnew System::Windows::Forms::CheckBox());
			   this->timerHZ = (gcnew System::Windows::Forms::Timer(this->components));
			   this->menuStrip1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxRadar))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->googleEarthBox))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapPictureBox))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPhotoFlash))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxCamera))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // btnUp
			   // 
			   this->btnUp->Location = System::Drawing::Point(97, 455);
			   this->btnUp->Name = L"btnUp";
			   this->btnUp->Size = System::Drawing::Size(75, 45);
			   this->btnUp->TabIndex = 2;
			   this->btnUp->Text = L"Up";
			   this->btnUp->UseVisualStyleBackColor = true;
			   this->btnUp->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			   // 
			   // btnDown
			   // 
			   this->btnDown->Location = System::Drawing::Point(97, 556);
			   this->btnDown->Name = L"btnDown";
			   this->btnDown->Size = System::Drawing::Size(75, 45);
			   this->btnDown->TabIndex = 3;
			   this->btnDown->Text = L"Down";
			   this->btnDown->UseVisualStyleBackColor = true;
			   this->btnDown->Click += gcnew System::EventHandler(this, &MyForm::BtnDown_Click);
			   // 
			   // btnLeft
			   // 
			   this->btnLeft->Location = System::Drawing::Point(18, 504);
			   this->btnLeft->Name = L"btnLeft";
			   this->btnLeft->Size = System::Drawing::Size(75, 45);
			   this->btnLeft->TabIndex = 4;
			   this->btnLeft->Text = L"Left";
			   this->btnLeft->UseVisualStyleBackColor = true;
			   this->btnLeft->Click += gcnew System::EventHandler(this, &MyForm::BtnLeft_Click);
			   // 
			   // btnRight
			   // 
			   this->btnRight->Location = System::Drawing::Point(175, 504);
			   this->btnRight->Name = L"btnRight";
			   this->btnRight->Size = System::Drawing::Size(75, 45);
			   this->btnRight->TabIndex = 5;
			   this->btnRight->Text = L"Right";
			   this->btnRight->UseVisualStyleBackColor = true;
			   this->btnRight->Click += gcnew System::EventHandler(this, &MyForm::BtnRight_Click);
			   // 
			   // btnStop
			   // 
			   this->btnStop->Location = System::Drawing::Point(105, 507);
			   this->btnStop->Name = L"btnStop";
			   this->btnStop->Size = System::Drawing::Size(59, 41);
			   this->btnStop->TabIndex = 6;
			   this->btnStop->Text = L"STOP";
			   this->btnStop->UseVisualStyleBackColor = true;
			   this->btnStop->Click += gcnew System::EventHandler(this, &MyForm::BtnStop_Click);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(22, 655);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(41, 13);
			   this->label2->TabIndex = 12;
			   this->label2->Text = L"Pan to:";
			   // 
			   // txtPanGoto
			   // 
			   this->txtPanGoto->Location = System::Drawing::Point(69, 652);
			   this->txtPanGoto->Name = L"txtPanGoto";
			   this->txtPanGoto->Size = System::Drawing::Size(100, 20);
			   this->txtPanGoto->TabIndex = 13;
			   // 
			   // txtTiltGoto
			   // 
			   this->txtTiltGoto->Location = System::Drawing::Point(69, 678);
			   this->txtTiltGoto->Name = L"txtTiltGoto";
			   this->txtTiltGoto->Size = System::Drawing::Size(100, 20);
			   this->txtTiltGoto->TabIndex = 15;
			   // 
			   // lblGoToTilt
			   // 
			   this->lblGoToTilt->AutoSize = true;
			   this->lblGoToTilt->Location = System::Drawing::Point(22, 681);
			   this->lblGoToTilt->Name = L"lblGoToTilt";
			   this->lblGoToTilt->Size = System::Drawing::Size(36, 13);
			   this->lblGoToTilt->TabIndex = 14;
			   this->lblGoToTilt->Text = L"Tilt to:";
			   // 
			   // btnReturn0
			   // 
			   this->btnReturn0->Location = System::Drawing::Point(23, 714);
			   this->btnReturn0->Name = L"btnReturn0";
			   this->btnReturn0->Size = System::Drawing::Size(141, 23);
			   this->btnReturn0->TabIndex = 16;
			   this->btnReturn0->Text = L"Return to 0";
			   this->btnReturn0->UseVisualStyleBackColor = true;
			   this->btnReturn0->Click += gcnew System::EventHandler(this, &MyForm::BtnReturn0_Click);
			   // 
			   // btnMovePan
			   // 
			   this->btnMovePan->Location = System::Drawing::Point(175, 652);
			   this->btnMovePan->Name = L"btnMovePan";
			   this->btnMovePan->Size = System::Drawing::Size(75, 20);
			   this->btnMovePan->TabIndex = 20;
			   this->btnMovePan->Text = L"Move";
			   this->btnMovePan->UseVisualStyleBackColor = true;
			   this->btnMovePan->Click += gcnew System::EventHandler(this, &MyForm::BtnMove_Click);
			   // 
			   // btnTiltMov
			   // 
			   this->btnTiltMov->Location = System::Drawing::Point(175, 678);
			   this->btnTiltMov->Name = L"btnTiltMov";
			   this->btnTiltMov->Size = System::Drawing::Size(75, 20);
			   this->btnTiltMov->TabIndex = 21;
			   this->btnTiltMov->Text = L"Move";
			   this->btnTiltMov->UseVisualStyleBackColor = true;
			   this->btnTiltMov->Click += gcnew System::EventHandler(this, &MyForm::BtnTiltMov_Click);
			   // 
			   // btnSlow
			   // 
			   this->btnSlow->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnSlow->Location = System::Drawing::Point(18, 614);
			   this->btnSlow->Name = L"btnSlow";
			   this->btnSlow->Size = System::Drawing::Size(75, 23);
			   this->btnSlow->TabIndex = 22;
			   this->btnSlow->Text = L"Slow";
			   this->btnSlow->UseVisualStyleBackColor = true;
			   this->btnSlow->Click += gcnew System::EventHandler(this, &MyForm::BtnSlow_Click);
			   // 
			   // btnMedium
			   // 
			   this->btnMedium->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnMedium->Location = System::Drawing::Point(97, 614);
			   this->btnMedium->Name = L"btnMedium";
			   this->btnMedium->Size = System::Drawing::Size(75, 23);
			   this->btnMedium->TabIndex = 23;
			   this->btnMedium->Text = L"Medium";
			   this->btnMedium->UseVisualStyleBackColor = true;
			   this->btnMedium->Click += gcnew System::EventHandler(this, &MyForm::BtnMedium_Click);
			   // 
			   // btnFast
			   // 
			   this->btnFast->Enabled = false;
			   this->btnFast->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->btnFast->Location = System::Drawing::Point(175, 614);
			   this->btnFast->Name = L"btnFast";
			   this->btnFast->Size = System::Drawing::Size(75, 23);
			   this->btnFast->TabIndex = 24;
			   this->btnFast->Text = L"Fast";
			   this->btnFast->UseVisualStyleBackColor = true;
			   this->btnFast->Click += gcnew System::EventHandler(this, &MyForm::BtnFast_Click);
			   // 
			   // btnZoomIn
			   // 
			   this->btnZoomIn->Location = System::Drawing::Point(16, 466);
			   this->btnZoomIn->Name = L"btnZoomIn";
			   this->btnZoomIn->Size = System::Drawing::Size(75, 23);
			   this->btnZoomIn->TabIndex = 25;
			   this->btnZoomIn->Text = L"Zoom In";
			   this->btnZoomIn->UseVisualStyleBackColor = true;
			   this->btnZoomIn->Click += gcnew System::EventHandler(this, &MyForm::BtnZoomIn_Click);
			   // 
			   // btnZoomOut
			   // 
			   this->btnZoomOut->Location = System::Drawing::Point(178, 466);
			   this->btnZoomOut->Name = L"btnZoomOut";
			   this->btnZoomOut->Size = System::Drawing::Size(75, 23);
			   this->btnZoomOut->TabIndex = 26;
			   this->btnZoomOut->Text = L"Zoom Out";
			   this->btnZoomOut->UseVisualStyleBackColor = true;
			   this->btnZoomOut->Click += gcnew System::EventHandler(this, &MyForm::BtnZoomOut_Click);
			   // 
			   // btnSetZero
			   // 
			   this->btnSetZero->Location = System::Drawing::Point(176, 713);
			   this->btnSetZero->Name = L"btnSetZero";
			   this->btnSetZero->Size = System::Drawing::Size(75, 23);
			   this->btnSetZero->TabIndex = 29;
			   this->btnSetZero->Text = L"Set New 0";
			   this->btnSetZero->UseVisualStyleBackColor = true;
			   this->btnSetZero->Click += gcnew System::EventHandler(this, &MyForm::BtnSetZero_Click);
			   // 
			   // webView21
			   // 
			   this->webView21->BackColor = System::Drawing::SystemColors::ControlDark;
			   this->webView21->Location = System::Drawing::Point(12, 43);
			   this->webView21->Name = L"webView21";
			   this->webView21->Size = System::Drawing::Size(515, 351);
			   this->webView21->Source = (gcnew System::Uri(L"http://192.166.0.1", System::UriKind::Absolute));
			   this->webView21->TabIndex = 30;
			   this->webView21->Text = L"webCameraStreem";
			   this->webView21->ZoomFactor = 1;
			   this->webView21->CoreWebView2Ready += gcnew System::EventHandler<System::EventArgs^ >(this, &MyForm::MyForm_Load);
			   this->webView21->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   // 
			   // directorySearcher1
			   // 
			   this->directorySearcher1->ClientTimeout = System::TimeSpan::Parse(L"-00:00:01");
			   this->directorySearcher1->ServerPageTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			   this->directorySearcher1->ServerTimeLimit = System::TimeSpan::Parse(L"-00:00:01");
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->BackColor = System::Drawing::SystemColors::ButtonFace;
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->fileToolStripMenuItem,
					   this->setupToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1255, 24);
			   this->menuStrip1->TabIndex = 31;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->reportToolStripMenuItem,
					   this->clearToolStripMenuItem, this->exitToolStripMenuItem
			   });
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // reportToolStripMenuItem
			   // 
			   this->reportToolStripMenuItem->Name = L"reportToolStripMenuItem";
			   this->reportToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			   this->reportToolStripMenuItem->Text = L"Report";
			   this->reportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::reportToolStripMenuItem_Click);
			   // 
			   // clearToolStripMenuItem
			   // 
			   this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			   this->clearToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			   this->clearToolStripMenuItem->Text = L"Clear";
			   this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearToolStripMenuItem_Click);
			   // 
			   // exitToolStripMenuItem
			   // 
			   this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			   this->exitToolStripMenuItem->Size = System::Drawing::Size(109, 22);
			   this->exitToolStripMenuItem->Text = L"Exit";
			   this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			   // 
			   // setupToolStripMenuItem
			   // 
			   this->setupToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->sensorToolStripMenuItem,
					   this->cameraToolStripMenuItem, this->alertsToolStripMenuItem
			   });
			   this->setupToolStripMenuItem->Name = L"setupToolStripMenuItem";
			   this->setupToolStripMenuItem->Size = System::Drawing::Size(49, 20);
			   this->setupToolStripMenuItem->Text = L"Setup";
			   // 
			   // sensorToolStripMenuItem
			   // 
			   this->sensorToolStripMenuItem->Name = L"sensorToolStripMenuItem";
			   this->sensorToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			   this->sensorToolStripMenuItem->Text = L"Sensor";
			   this->sensorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sensorToolStripMenuItem_Click);
			   this->timerHZ->Enabled = true;
			   // 
			   // cameraToolStripMenuItem
			   // 
			   this->cameraToolStripMenuItem->Name = L"cameraToolStripMenuItem";
			   this->cameraToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			   this->cameraToolStripMenuItem->Text = L"Camera";
			   this->cameraToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cameraToolStripMenuItem_Click);
			   // 
			   // alertsToolStripMenuItem
			   // 
			   this->alertsToolStripMenuItem->Name = L"alertsToolStripMenuItem";
			   this->alertsToolStripMenuItem->Size = System::Drawing::Size(115, 22);
			   this->alertsToolStripMenuItem->Text = L"Alerts";
			   this->alertsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::alertsToolStripMenuItem_Click);
			   // 
			   // picBoxRadar
			   // 
			   this->picBoxRadar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBoxRadar.Image")));
			   this->picBoxRadar->ImageLocation = L"";
			   this->picBoxRadar->Location = System::Drawing::Point(533, 43);
			   this->picBoxRadar->Name = L"picBoxRadar";
			   this->picBoxRadar->Size = System::Drawing::Size(351, 351);
			   this->picBoxRadar->TabIndex = 32;
			   this->picBoxRadar->TabStop = false;
			   this->picBoxRadar->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::picBoxRadar_MouseClick);
			   this->picBoxRadar->MouseLeave += gcnew System::EventHandler(this, &MyForm::picBoxRadar_MouseLeave);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->Location = System::Drawing::Point(1056, 643);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(199, 117);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->pictureBox1->TabIndex = 33;
			   this->pictureBox1->TabStop = false;
			   // 
			   // googleEarthBox
			   // 
			   this->googleEarthBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->googleEarthBox->ImageLocation = L"";
			   this->googleEarthBox->Location = System::Drawing::Point(878, 43);
			   this->googleEarthBox->Name = L"googleEarthBox";
			   this->googleEarthBox->Size = System::Drawing::Size(351, 351);
			   this->googleEarthBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			   this->googleEarthBox->TabIndex = 35;
			   this->googleEarthBox->TabStop = false;
			   // 
			   // txtBoxLogText
			   // 
			   this->txtBoxLogText->AcceptsReturn = true;
			   this->txtBoxLogText->Location = System::Drawing::Point(288, 448);
			   this->txtBoxLogText->Multiline = true;
			   this->txtBoxLogText->Name = L"txtBoxLogText";
			   this->txtBoxLogText->Size = System::Drawing::Size(580, 300);
			   this->txtBoxLogText->TabIndex = 37;
			   // 
			   // radarMousePos
			   // 
			   this->radarMousePos->Location = System::Drawing::Point(810, 52);
			   this->radarMousePos->Name = L"radarMousePos";
			   this->radarMousePos->Size = System::Drawing::Size(70, 19);
			   this->radarMousePos->TabIndex = 38;
			   this->radarMousePos->Text = L"posDegMeter";
			   this->radarMousePos->Visible = false;
			   // 
			   // coordLbl
			   // 
			   this->coordLbl->AutoSize = true;
			   this->coordLbl->Location = System::Drawing::Point(804, 360);
			   this->coordLbl->Name = L"coordLbl";
			   this->coordLbl->Size = System::Drawing::Size(72, 13);
			   this->coordLbl->TabIndex = 40;
			   this->coordLbl->Text = L"posDecCoord";
			   this->coordLbl->Visible = false;
			   // 
			   // DMScoord
			   // 
			   this->DMScoord->AutoSize = true;
			   this->DMScoord->Location = System::Drawing::Point(535, 360);
			   this->DMScoord->Name = L"DMScoord";
			   this->DMScoord->Size = System::Drawing::Size(48, 13);
			   this->DMScoord->TabIndex = 41;
			   this->DMScoord->Text = L"posDMS";
			   this->DMScoord->Visible = false;
			   // 
			   // webView22
			   // 
			   this->webView22->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			   this->webView22->Location = System::Drawing::Point(878, 43);
			   this->webView22->Name = L"webView22";
			   this->webView22->Size = System::Drawing::Size(351, 351);
			   this->webView22->Source = (gcnew System::Uri(L"c:\\bing.html", System::UriKind::Absolute));
			   this->webView22->TabIndex = 42;
			   this->webView22->Text = L"webView22";
			   this->webView22->ZoomFactor = 1;
			   // 
			   // btNavigateToLatLon
			   // 
			   this->btNavigateToLatLon->Location = System::Drawing::Point(1117, 410);
			   this->btNavigateToLatLon->Name = L"btNavigateToLatLon";
			   this->btNavigateToLatLon->Size = System::Drawing::Size(112, 23);
			   this->btNavigateToLatLon->TabIndex = 43;
			   this->btNavigateToLatLon->Text = L"Navigate";
			   this->btNavigateToLatLon->UseVisualStyleBackColor = true;
			   this->btNavigateToLatLon->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_2);
			   // 
			   // lblLongitude
			   // 
			   this->lblLongitude->AutoSize = true;
			   this->lblLongitude->Location = System::Drawing::Point(944, 416);
			   this->lblLongitude->Name = L"lblLongitude";
			   this->lblLongitude->Size = System::Drawing::Size(48, 13);
			   this->lblLongitude->TabIndex = 44;
			   this->lblLongitude->Text = L"Latitude:";
			   // 
			   // lblLon
			   // 
			   this->lblLon->AutoSize = true;
			   this->lblLon->Location = System::Drawing::Point(943, 449);
			   this->lblLon->Name = L"lblLon";
			   this->lblLon->Size = System::Drawing::Size(57, 13);
			   this->lblLon->TabIndex = 45;
			   this->lblLon->Text = L"Longitude:";
			   // 
			   // txtLat
			   // 
			   this->txtLat->Location = System::Drawing::Point(999, 413);
			   this->txtLat->Name = L"txtLat";
			   this->txtLat->Size = System::Drawing::Size(112, 20);
			   this->txtLat->TabIndex = 46;
			   // 
			   // txtLon
			   // 
			   this->txtLon->Location = System::Drawing::Point(999, 446);
			   this->txtLon->Name = L"txtLon";
			   this->txtLon->Size = System::Drawing::Size(112, 20);
			   this->txtLon->TabIndex = 47;
			   // 
			   // btnMakeStatic
			   // 
			   this->btnMakeStatic->Location = System::Drawing::Point(1117, 444);
			   this->btnMakeStatic->Name = L"btnMakeStatic";
			   this->btnMakeStatic->Size = System::Drawing::Size(112, 23);
			   this->btnMakeStatic->TabIndex = 48;
			   this->btnMakeStatic->Text = L"Make Map Static";
			   this->btnMakeStatic->UseVisualStyleBackColor = true;
			   this->btnMakeStatic->Click += gcnew System::EventHandler(this, &MyForm::btnMakeStatic_Click);
			   // 
			   // mapPictureBox
			   // 
			   this->mapPictureBox->Location = System::Drawing::Point(878, 43);
			   this->mapPictureBox->Margin = System::Windows::Forms::Padding(0);
			   this->mapPictureBox->Name = L"mapPictureBox";
			   this->mapPictureBox->Padding = System::Windows::Forms::Padding(3);
			   this->mapPictureBox->Size = System::Drawing::Size(351, 351);
			   this->mapPictureBox->TabIndex = 49;
			   this->mapPictureBox->TabStop = false;
			   this->mapPictureBox->Visible = false;
			   // 
			   // btnUnFixMapPicture
			   // 
			   this->btnUnFixMapPicture->Location = System::Drawing::Point(1117, 443);
			   this->btnUnFixMapPicture->Name = L"btnUnFixMapPicture";
			   this->btnUnFixMapPicture->Size = System::Drawing::Size(112, 23);
			   this->btnUnFixMapPicture->TabIndex = 50;
			   this->btnUnFixMapPicture->Text = L"New Map ";
			   this->btnUnFixMapPicture->UseVisualStyleBackColor = true;
			   this->btnUnFixMapPicture->Visible = false;
			   this->btnUnFixMapPicture->Click += gcnew System::EventHandler(this, &MyForm::btnUnFixMapPicture_Click);
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(12, 400);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(84, 23);
			   this->button1->TabIndex = 51;
			   this->button1->Text = L"View Video";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_3);
			   // 
			   // btnTakePicture
			   // 
			   this->btnTakePicture->Location = System::Drawing::Point(102, 400);
			   this->btnTakePicture->Name = L"btnTakePicture";
			   this->btnTakePicture->Size = System::Drawing::Size(84, 23);
			   this->btnTakePicture->TabIndex = 53;
			   this->btnTakePicture->Text = L"Take Picture";
			   this->btnTakePicture->UseVisualStyleBackColor = true;
			   this->btnTakePicture->Click += gcnew System::EventHandler(this, &MyForm::btnTakePicture_Click);
			   // 
			   // pictureBoxPhotoFlash
			   // 
			   this->pictureBoxPhotoFlash->BackColor = System::Drawing::SystemColors::HighlightText;
			   this->pictureBoxPhotoFlash->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxPhotoFlash.Image")));
			   this->pictureBoxPhotoFlash->Location = System::Drawing::Point(12, 43);
			   this->pictureBoxPhotoFlash->Name = L"pictureBoxPhotoFlash";
			   this->pictureBoxPhotoFlash->Size = System::Drawing::Size(515, 351);
			   this->pictureBoxPhotoFlash->TabIndex = 54;
			   this->pictureBoxPhotoFlash->TabStop = false;
			   this->pictureBoxPhotoFlash->Visible = false;
			   // 
			   // btnFastDraw
			   // 
			   this->btnFastDraw->Enabled = false;
			   this->btnFastDraw->Location = System::Drawing::Point(408, 405);
			   this->btnFastDraw->Name = L"btnFastDraw";
			   this->btnFastDraw->Size = System::Drawing::Size(114, 37);
			   this->btnFastDraw->TabIndex = 56;
			   this->btnFastDraw->Text = L"Draw Map";
			   this->btnFastDraw->UseVisualStyleBackColor = true;
			   this->btnFastDraw->Click += gcnew System::EventHandler(this, &MyForm::btnFastDraw_Click);
			   // 
			   // checkBoxRemoteConnection
			   // 
			   this->checkBoxRemoteConnection->Appearance = System::Windows::Forms::Appearance::Button;
			   this->checkBoxRemoteConnection->Enabled = false;
			   this->checkBoxRemoteConnection->Location = System::Drawing::Point(528, 405);
			   this->checkBoxRemoteConnection->Name = L"checkBoxRemoteConnection";
			   this->checkBoxRemoteConnection->Size = System::Drawing::Size(114, 37);
			   this->checkBoxRemoteConnection->TabIndex = 58;
			   this->checkBoxRemoteConnection->Text = L"Remote Connection";
			   this->checkBoxRemoteConnection->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->checkBoxRemoteConnection->UseVisualStyleBackColor = true;
			   this->checkBoxRemoteConnection->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxRemoteConnection_CheckedChanged);
			   // 
			   // clocklTmer
			   // 
			   this->clocklTmer->Enabled = true;
			   this->clocklTmer->Interval = 1000;
			   this->clocklTmer->Tick += gcnew System::EventHandler(this, &MyForm::clocklTmer_Tick);
			   // 
			   // lblClock
			   // 
			   this->lblClock->AutoSize = true;
			   this->lblClock->Font = (gcnew System::Drawing::Font(L"Aharoni", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(177)));
			   this->lblClock->Location = System::Drawing::Point(1094, 20);
			   this->lblClock->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lblClock->Name = L"lblClock";
			   this->lblClock->Size = System::Drawing::Size(0, 19);
			   this->lblClock->TabIndex = 59;
			   // 
			   // timerLog
			   // 
			   this->timerLog->Enabled = true;
			   this->timerLog->Interval = 500;
			   this->timerLog->Tick += gcnew System::EventHandler(this, &MyForm::timerLog_Tick);
			   // 
			   // picBoxCamera
			   // 
			   this->picBoxCamera->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->picBoxCamera->Location = System::Drawing::Point(12, 43);
			   this->picBoxCamera->Name = L"picBoxCamera";
			   this->picBoxCamera->Size = System::Drawing::Size(515, 351);
			   this->picBoxCamera->TabIndex = 60;
			   this->picBoxCamera->TabStop = false;
			   // 
			   // timerVideo
			   // 
			   this->timerVideo->Interval = 24;
			   this->timerVideo->Tick += gcnew System::EventHandler(this, &MyForm::timerVideo_Tick);
			   // 
			   // checkBoxInitateSensor
			   // 
			   this->checkBoxInitateSensor->Appearance = System::Windows::Forms::Appearance::Button;
			   this->checkBoxInitateSensor->Location = System::Drawing::Point(288, 405);
			   this->checkBoxInitateSensor->Name = L"checkBoxInitateSensor";
			   this->checkBoxInitateSensor->Size = System::Drawing::Size(114, 37);
			   this->checkBoxInitateSensor->TabIndex = 61;
			   this->checkBoxInitateSensor->Text = L"Initate Sensor";
			   this->checkBoxInitateSensor->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			   this->checkBoxInitateSensor->UseVisualStyleBackColor = true;
			   this->checkBoxInitateSensor->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxInitateSensor_CheckedChanged);
			   // 
			   // timerHZ
			   // 
			   this->timerHZ->Interval = 300;
			   this->timerHZ->Tick += gcnew System::EventHandler(this, &MyForm::timerHZ_Tick);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(1255, 761);
			   this->Controls->Add(this->checkBoxInitateSensor);
			   this->Controls->Add(this->picBoxCamera);
			   this->Controls->Add(this->lblClock);
			   this->Controls->Add(this->checkBoxRemoteConnection);
			   this->Controls->Add(this->btnFastDraw);
			   this->Controls->Add(this->pictureBoxPhotoFlash);
			   this->Controls->Add(this->btnTakePicture);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->btnUnFixMapPicture);
			   this->Controls->Add(this->mapPictureBox);
			   this->Controls->Add(this->btnMakeStatic);
			   this->Controls->Add(this->txtLon);
			   this->Controls->Add(this->txtLat);
			   this->Controls->Add(this->lblLon);
			   this->Controls->Add(this->lblLongitude);
			   this->Controls->Add(this->btNavigateToLatLon);
			   this->Controls->Add(this->webView22);
			   this->Controls->Add(this->DMScoord);
			   this->Controls->Add(this->coordLbl);
			   this->Controls->Add(this->radarMousePos);
			   this->Controls->Add(this->txtBoxLogText);
			   this->Controls->Add(this->googleEarthBox);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->picBoxRadar);
			   this->Controls->Add(this->webView21);
			   this->Controls->Add(this->btnSetZero);
			   this->Controls->Add(this->btnZoomOut);
			   this->Controls->Add(this->btnZoomIn);
			   this->Controls->Add(this->btnFast);
			   this->Controls->Add(this->btnMedium);
			   this->Controls->Add(this->btnSlow);
			   this->Controls->Add(this->btnTiltMov);
			   this->Controls->Add(this->btnMovePan);
			   this->Controls->Add(this->btnReturn0);
			   this->Controls->Add(this->txtTiltGoto);
			   this->Controls->Add(this->lblGoToTilt);
			   this->Controls->Add(this->txtPanGoto);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->btnStop);
			   this->Controls->Add(this->btnRight);
			   this->Controls->Add(this->btnLeft);
			   this->Controls->Add(this->btnDown);
			   this->Controls->Add(this->btnUp);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Simple IPI";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxRadar))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->googleEarthBox))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapPictureBox))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxPhotoFlash))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxCamera))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
		   
#pragma endregion
		   System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {};
		   System::Void Label2_Click(System::Object^ sender, System::EventArgs^ e) {};
		   System::Void TextComNum_TextChanged(System::Object^ sender, System::EventArgs^ e) {};
		   System::Void btnConnect_Click_1(System::Object^ sender, System::EventArgs^ e) {};
		   System::Void BtnReturn0_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnExit_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnDown_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnLeft_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnRight_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnStop_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnMove_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnTiltMov_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void ComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {};
		   System::Void BtnSlow_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnMedium_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnFast_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void WebBrowser1_DocumentCompleted(System::Object^ sender, System::Windows::Forms::WebBrowserDocumentCompletedEventArgs^ e) {};
		   System::Void BtnZoomIn_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnZoomOut_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void logText_TextChanged(System::Object^ sender, System::EventArgs^ e) {};
		   System::Void BtnPlsConnect_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void BtnSetZero_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void webView21_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void cameraToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void sensorToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {};
		   System::Void alertsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		   //System::Void alertToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		   //System::Void aditionalVerifcationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		  // System::Void fileSystemWatcher1_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e);
		   System::Void reportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void btnMakeStatic_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void btnUnFixMapPicture_Click(System::Object^ sender, System::EventArgs^ e);
		   //System::Void picBoxRadar_DoubleClick(System::Object^ sender, System::EventArgs^ e);
		   System::Void picBoxRadar_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		   System::Void btnChoosePicture_Click(System::Object^ sender, System::EventArgs^ e);
		   //System::Void picBoxRadar_MouseHover(System::Object^ sender, System::EventArgs^ e);
		   System::Void picBoxRadar_MouseLeave(System::Object^ sender, System::EventArgs^ e);
		   System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e);
		   //System::Void fileSystemWatcher2_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e);
		   //System::Void fileSystemWatcher2_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e);
		   System::Void button1_Click_3(System::Object^ sender, System::EventArgs^ e);
		   System::Void btnTakePicture_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void btnConnecToSensor_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void btnFastDraw_Click(System::Object^ sender, System::EventArgs^ e);
		   //System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void checkBoxRemoteConnection_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		   System::Void clocklTmer_Tick(System::Object^ sender, System::EventArgs^ e);
		   System::Void timerLog_Tick(System::Object^ sender, System::EventArgs^ e);
		   System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		   System::Void timerVideo_Tick(System::Object^ sender, System::EventArgs^ e);
		   System::Void checkBoxInitateSensor_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		   System::Void timerHZ_Tick(System::Object^ sender, System::EventArgs^ e);

		   
private: System::Void radWebCam1_SnapshotTaken(System::Object^ sender, Telerik::WinControls::UI::SnapshotTakenEventArgs^ e) {
}
	   


private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {

}

private: 
};




}





