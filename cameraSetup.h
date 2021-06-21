#pragma once
#include <string.h>
#include <iostream>
#include "Header.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include <cstring>

#define PTZ_PELCO_D 0
#define PTZ_ONVIF 1
#define PTZ_DISABLED 2


namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace Calc;


	

	//std::string camHtmlAdress = { "http://" };



	/// <summary>
	/// Summary for cameraSetup
	/// </summary>
	public ref class cameraSetup : public System::Windows::Forms::Form {
	public:
		cameraSetup();
	protected:
		~cameraSetup();
	private:
		System::Windows::Forms::ComboBox^ comboBoxCom;
		System::Windows::Forms::Label^ lblComCamera;
		System::Windows::Forms::Label^ lblBaudCam;
		System::Windows::Forms::ComboBox^ cmboBoxBaudCam;
		System::Windows::Forms::Button^ btnConnectCam;
		System::Windows::Forms::GroupBox^ groupBoxPelcoCam;
		System::Windows::Forms::Button^ btnCheckConPelcoD;
		System::Windows::Forms::Button^ btnDisconnectPelcoCam;
		System::Windows::Forms::RadioButton^ radioBtnSerialCamera;
		System::Windows::Forms::RadioButton^ radioBtnLanCamera;
		System::Windows::Forms::ComboBox^ comboBoxEnablePtz;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::TextBox^ txbBoxCamURL;
		System::Windows::Forms::Button^ btnConnectPTZLan;
		System::ComponentModel::IContainer^ components;
		System::Windows::Forms::Label^ lblLink;
		System::Windows::Forms::GroupBox^ groupBoxVideoCameraFeed;
		System::Windows::Forms::Button^ btnDisconnectLanVideoFeed;
		System::Windows::Forms::Label^ label7;
		System::Windows::Forms::Button^ btnConnectVideoFeedLan;
		System::Windows::Forms::TextBox^ txtLanVideoFeedLink;
		System::Windows::Forms::RadioButton^ radioButradioButtonVideoFeedLan;
		System::Windows::Forms::RadioButton^ radioButtonVideoFeedSerial;
		System::Windows::Forms::Panel^ PanelRadioBoxPTZControl;
		System::Windows::Forms::Panel^ panelVideoFeenSerial;
		System::Windows::Forms::Panel^ panelVideoFeedLan;
		System::Windows::Forms::TextBox^ txtBoxUserNamePTZLAN;
		System::Windows::Forms::Label^ lblUserName;
		System::Windows::Forms::TextBox^ txtBoxProfileLanPTZ;
		System::Windows::Forms::Label^ lblProfile;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ lblPassWordPTZLAN;
		System::Windows::Forms::GroupBox^ groupBox1;
		System::Windows::Forms::GroupBox^ groupboxTargetCaptureParameters;
		System::Windows::Forms::Label^ label11;
		System::Windows::Forms::Label^ label10;
		System::Windows::Forms::Label^ label9;
		System::Windows::Forms::Label^ label8;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label14;
		System::Windows::Forms::Label^ label13;
		System::Windows::Forms::Label^ label12;
		System::Windows::Forms::TextBox^ txtBoxFocus8;
		System::Windows::Forms::TextBox^ txtBoxTilt8;
		System::Windows::Forms::TextBox^ txtBoxZoom8;
		System::Windows::Forms::TextBox^ txtBoxFocus7;
		System::Windows::Forms::TextBox^ txtBoxTilt7;
		System::Windows::Forms::TextBox^ txtBoxZoom7;
		System::Windows::Forms::TextBox^ txtBoxFocus6;
		System::Windows::Forms::TextBox^ txtBoxTilt6;
		System::Windows::Forms::TextBox^ txtBoxZoom6;
		System::Windows::Forms::TextBox^ txtBoxFocu5;
		System::Windows::Forms::TextBox^ txtBoxTilt5;
		System::Windows::Forms::TextBox^ txtBoxZoom5;
		System::Windows::Forms::TextBox^ txtBoxFocus4;



private: System::Windows::Forms::TextBox^ txtBoxTilt4;
private: System::Windows::Forms::TextBox^ txtBoxZoom4;
private: System::Windows::Forms::TextBox^ txtBoxFocus3;



private: System::Windows::Forms::TextBox^ txtBoxTilt3;
private: System::Windows::Forms::TextBox^ txtBoxZoom3;
private: System::Windows::Forms::TextBox^ txtBoxFocus2;




private: System::Windows::Forms::TextBox^ txtBoxTilt2;
private: System::Windows::Forms::TextBox^ txtBoxZoom2;
private: System::Windows::Forms::TextBox^ txtBoxFocus1;



private: System::Windows::Forms::TextBox^ txtBoxTilt1;
private: System::Windows::Forms::TextBox^ txtBoxZoom1;
private: System::Windows::Forms::TextBox^ txtBoxFocus0;



private: System::Windows::Forms::TextBox^ txtBoxTilt0;
private: System::Windows::Forms::TextBox^ txtBoxZoom0;
private: System::Windows::Forms::TextBox^ txtBoxFocus9;
private: System::Windows::Forms::TextBox^ txtBoxTilt9;
private: System::Windows::Forms::TextBox^ txtBoxZoom9;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::PictureBox^ pitureBoxchooseCamera;
private: System::Windows::Forms::Button^ btnCamera1;
private: System::Windows::Forms::Button^ btnCamera2;
private: System::Windows::Forms::Button^ btnCamera3;
private: System::Windows::Forms::Button^ btnCamera4;
private: System::Windows::Forms::Button^ btnCamera5;

private: System::Windows::Forms::Button^ btConnectCV;





#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		
		   
		   Calc::MyForm dsg;

		   void InitializeComponent(void)
		{
			   this->comboBoxCom = (gcnew System::Windows::Forms::ComboBox());
			   this->lblComCamera = (gcnew System::Windows::Forms::Label());
			   this->lblBaudCam = (gcnew System::Windows::Forms::Label());
			   this->cmboBoxBaudCam = (gcnew System::Windows::Forms::ComboBox());
			   this->btnConnectCam = (gcnew System::Windows::Forms::Button());
			   this->groupBoxPelcoCam = (gcnew System::Windows::Forms::GroupBox());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->lblPassWordPTZLAN = (gcnew System::Windows::Forms::Label());
			   this->txtBoxUserNamePTZLAN = (gcnew System::Windows::Forms::TextBox());
			   this->lblUserName = (gcnew System::Windows::Forms::Label());
			   this->txtBoxProfileLanPTZ = (gcnew System::Windows::Forms::TextBox());
			   this->lblProfile = (gcnew System::Windows::Forms::Label());
			   this->lblLink = (gcnew System::Windows::Forms::Label());
			   this->btnConnectPTZLan = (gcnew System::Windows::Forms::Button());
			   this->txbBoxCamURL = (gcnew System::Windows::Forms::TextBox());
			   this->btnDisconnectPelcoCam = (gcnew System::Windows::Forms::Button());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->comboBoxEnablePtz = (gcnew System::Windows::Forms::ComboBox());
			   this->btnCheckConPelcoD = (gcnew System::Windows::Forms::Button());
			   this->radioBtnSerialCamera = (gcnew System::Windows::Forms::RadioButton());
			   this->radioBtnLanCamera = (gcnew System::Windows::Forms::RadioButton());
			   this->groupBoxVideoCameraFeed = (gcnew System::Windows::Forms::GroupBox());
			   this->panelVideoFeedLan = (gcnew System::Windows::Forms::Panel());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->btnConnectVideoFeedLan = (gcnew System::Windows::Forms::Button());
			   this->txtLanVideoFeedLink = (gcnew System::Windows::Forms::TextBox());
			   this->panelVideoFeenSerial = (gcnew System::Windows::Forms::Panel());
			   this->btnCamera2 = (gcnew System::Windows::Forms::Button());
			   this->btnCamera1 = (gcnew System::Windows::Forms::Button());
			   this->btnCamera3 = (gcnew System::Windows::Forms::Button());
			   this->btConnectCV = (gcnew System::Windows::Forms::Button());
			   this->btnCamera4 = (gcnew System::Windows::Forms::Button());
			   this->btnCamera5 = (gcnew System::Windows::Forms::Button());
			   this->btnDisconnectLanVideoFeed = (gcnew System::Windows::Forms::Button());
			   this->radioButradioButtonVideoFeedLan = (gcnew System::Windows::Forms::RadioButton());
			   this->radioButtonVideoFeedSerial = (gcnew System::Windows::Forms::RadioButton());
			   this->PanelRadioBoxPTZControl = (gcnew System::Windows::Forms::Panel());
			   this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->groupboxTargetCaptureParameters = (gcnew System::Windows::Forms::GroupBox());
			   this->txtBoxFocus9 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt9 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom9 = (gcnew System::Windows::Forms::TextBox());
			   this->label15 = (gcnew System::Windows::Forms::Label());
			   this->txtBoxFocus8 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt8 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom8 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxFocus7 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt7 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom7 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxFocus6 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt6 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom6 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxFocu5 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt5 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom5 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxFocus4 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt4 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom4 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxFocus3 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt3 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom3 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxFocus2 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt2 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom2 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxFocus1 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt1 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom1 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxFocus0 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxTilt0 = (gcnew System::Windows::Forms::TextBox());
			   this->txtBoxZoom0 = (gcnew System::Windows::Forms::TextBox());
			   this->label14 = (gcnew System::Windows::Forms::Label());
			   this->label13 = (gcnew System::Windows::Forms::Label());
			   this->label12 = (gcnew System::Windows::Forms::Label());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->pitureBoxchooseCamera = (gcnew System::Windows::Forms::PictureBox());
			   this->groupBoxPelcoCam->SuspendLayout();
			   this->groupBoxVideoCameraFeed->SuspendLayout();
			   this->panelVideoFeedLan->SuspendLayout();
			   this->panelVideoFeenSerial->SuspendLayout();
			   this->PanelRadioBoxPTZControl->SuspendLayout();
			   this->groupBox1->SuspendLayout();
			   this->groupboxTargetCaptureParameters->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pitureBoxchooseCamera))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // comboBoxCom
			   // 
			   this->comboBoxCom->FormattingEnabled = true;
			   this->comboBoxCom->Items->AddRange(gcnew cli::array< System::Object^  >(23) {
				   L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					   L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			   });
			   this->comboBoxCom->Location = System::Drawing::Point(66, 26);
			   this->comboBoxCom->Name = L"comboBoxCom";
			   this->comboBoxCom->Size = System::Drawing::Size(121, 21);
			   this->comboBoxCom->TabIndex = 0;
			   this->comboBoxCom->Text = L"7";
			   // 
			   // lblComCamera
			   // 
			   this->lblComCamera->AutoSize = true;
			   this->lblComCamera->Location = System::Drawing::Point(26, 29);
			   this->lblComCamera->Name = L"lblComCamera";
			   this->lblComCamera->Size = System::Drawing::Size(34, 13);
			   this->lblComCamera->TabIndex = 1;
			   this->lblComCamera->Text = L"COM:";
			   // 
			   // lblBaudCam
			   // 
			   this->lblBaudCam->AutoSize = true;
			   this->lblBaudCam->Location = System::Drawing::Point(2, 60);
			   this->lblBaudCam->Name = L"lblBaudCam";
			   this->lblBaudCam->Size = System::Drawing::Size(61, 13);
			   this->lblBaudCam->TabIndex = 2;
			   this->lblBaudCam->Text = L"Baud Rate:";
			   // 
			   // cmboBoxBaudCam
			   // 
			   this->cmboBoxBaudCam->FormattingEnabled = true;
			   this->cmboBoxBaudCam->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				   L"2400", L"4800", L"9600", L"14400", L"19200",
					   L"28800", L"38400", L"115200"
			   });
			   this->cmboBoxBaudCam->Location = System::Drawing::Point(66, 57);
			   this->cmboBoxBaudCam->Name = L"cmboBoxBaudCam";
			   this->cmboBoxBaudCam->Size = System::Drawing::Size(121, 21);
			   this->cmboBoxBaudCam->TabIndex = 3;
			   this->cmboBoxBaudCam->Text = L"2400";
			   // 
			   // btnConnectCam
			   // 
			   this->btnConnectCam->Location = System::Drawing::Point(6, 101);
			   this->btnConnectCam->Name = L"btnConnectCam";
			   this->btnConnectCam->Size = System::Drawing::Size(181, 29);
			   this->btnConnectCam->TabIndex = 4;
			   this->btnConnectCam->Text = L"Connect";
			   this->btnConnectCam->UseVisualStyleBackColor = true;
			   this->btnConnectCam->Click += gcnew System::EventHandler(this, &cameraSetup::btnConnectCam_Click);
			   // 
			   // groupBoxPelcoCam
			   // 
			   this->groupBoxPelcoCam->Controls->Add(this->textBox1);
			   this->groupBoxPelcoCam->Controls->Add(this->lblPassWordPTZLAN);
			   this->groupBoxPelcoCam->Controls->Add(this->txtBoxUserNamePTZLAN);
			   this->groupBoxPelcoCam->Controls->Add(this->lblUserName);
			   this->groupBoxPelcoCam->Controls->Add(this->txtBoxProfileLanPTZ);
			   this->groupBoxPelcoCam->Controls->Add(this->lblProfile);
			   this->groupBoxPelcoCam->Controls->Add(this->lblLink);
			   this->groupBoxPelcoCam->Controls->Add(this->btnConnectPTZLan);
			   this->groupBoxPelcoCam->Controls->Add(this->txbBoxCamURL);
			   this->groupBoxPelcoCam->Controls->Add(this->btnDisconnectPelcoCam);
			   this->groupBoxPelcoCam->Controls->Add(this->label6);
			   this->groupBoxPelcoCam->Controls->Add(this->comboBoxEnablePtz);
			   this->groupBoxPelcoCam->Controls->Add(this->btnCheckConPelcoD);
			   this->groupBoxPelcoCam->Controls->Add(this->btnConnectCam);
			   this->groupBoxPelcoCam->Controls->Add(this->cmboBoxBaudCam);
			   this->groupBoxPelcoCam->Controls->Add(this->lblBaudCam);
			   this->groupBoxPelcoCam->Controls->Add(this->lblComCamera);
			   this->groupBoxPelcoCam->Controls->Add(this->comboBoxCom);
			   this->groupBoxPelcoCam->Location = System::Drawing::Point(12, 242);
			   this->groupBoxPelcoCam->Name = L"groupBoxPelcoCam";
			   this->groupBoxPelcoCam->Size = System::Drawing::Size(469, 271);
			   this->groupBoxPelcoCam->TabIndex = 5;
			   this->groupBoxPelcoCam->TabStop = false;
			   this->groupBoxPelcoCam->Text = L"PTZ Control";
			   // 
			   // textBox1
			   // 
			   this->textBox1->Enabled = false;
			   this->textBox1->Location = System::Drawing::Point(287, 120);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(170, 20);
			   this->textBox1->TabIndex = 16;
			   this->textBox1->Text = L"12345abc";
			   // 
			   // lblPassWordPTZLAN
			   // 
			   this->lblPassWordPTZLAN->AutoSize = true;
			   this->lblPassWordPTZLAN->Enabled = false;
			   this->lblPassWordPTZLAN->Location = System::Drawing::Point(224, 123);
			   this->lblPassWordPTZLAN->Name = L"lblPassWordPTZLAN";
			   this->lblPassWordPTZLAN->Size = System::Drawing::Size(56, 13);
			   this->lblPassWordPTZLAN->TabIndex = 15;
			   this->lblPassWordPTZLAN->Text = L"Password:";
			   // 
			   // txtBoxUserNamePTZLAN
			   // 
			   this->txtBoxUserNamePTZLAN->Enabled = false;
			   this->txtBoxUserNamePTZLAN->Location = System::Drawing::Point(286, 89);
			   this->txtBoxUserNamePTZLAN->Name = L"txtBoxUserNamePTZLAN";
			   this->txtBoxUserNamePTZLAN->Size = System::Drawing::Size(171, 20);
			   this->txtBoxUserNamePTZLAN->TabIndex = 14;
			   this->txtBoxUserNamePTZLAN->Text = L"admin";
			   // 
			   // lblUserName
			   // 
			   this->lblUserName->AutoSize = true;
			   this->lblUserName->Enabled = false;
			   this->lblUserName->Location = System::Drawing::Point(218, 92);
			   this->lblUserName->Name = L"lblUserName";
			   this->lblUserName->Size = System::Drawing::Size(63, 13);
			   this->lblUserName->TabIndex = 13;
			   this->lblUserName->Text = L"User Name:";
			   // 
			   // txtBoxProfileLanPTZ
			   // 
			   this->txtBoxProfileLanPTZ->Enabled = false;
			   this->txtBoxProfileLanPTZ->Location = System::Drawing::Point(286, 58);
			   this->txtBoxProfileLanPTZ->Name = L"txtBoxProfileLanPTZ";
			   this->txtBoxProfileLanPTZ->Size = System::Drawing::Size(171, 20);
			   this->txtBoxProfileLanPTZ->TabIndex = 12;
			   this->txtBoxProfileLanPTZ->Text = L"Profile_3";
			   // 
			   // lblProfile
			   // 
			   this->lblProfile->AutoSize = true;
			   this->lblProfile->Enabled = false;
			   this->lblProfile->Location = System::Drawing::Point(241, 60);
			   this->lblProfile->Name = L"lblProfile";
			   this->lblProfile->Size = System::Drawing::Size(39, 13);
			   this->lblProfile->TabIndex = 11;
			   this->lblProfile->Text = L"Profile:";
			   // 
			   // lblLink
			   // 
			   this->lblLink->AutoSize = true;
			   this->lblLink->Enabled = false;
			   this->lblLink->Location = System::Drawing::Point(251, 32);
			   this->lblLink->Name = L"lblLink";
			   this->lblLink->Size = System::Drawing::Size(29, 13);
			   this->lblLink->TabIndex = 9;
			   this->lblLink->Text = L"URI:";
			   // 
			   // btnConnectPTZLan
			   // 
			   this->btnConnectPTZLan->Enabled = false;
			   this->btnConnectPTZLan->Location = System::Drawing::Point(286, 156);
			   this->btnConnectPTZLan->Name = L"btnConnectPTZLan";
			   this->btnConnectPTZLan->Size = System::Drawing::Size(170, 29);
			   this->btnConnectPTZLan->TabIndex = 8;
			   this->btnConnectPTZLan->Text = L"Connect";
			   this->btnConnectPTZLan->UseVisualStyleBackColor = true;
			   this->btnConnectPTZLan->Click += gcnew System::EventHandler(this, &cameraSetup::button1_Click);
			   // 
			   // txbBoxCamURL
			   // 
			   this->txbBoxCamURL->Enabled = false;
			   this->txbBoxCamURL->Location = System::Drawing::Point(287, 29);
			   this->txbBoxCamURL->Name = L"txbBoxCamURL";
			   this->txbBoxCamURL->Size = System::Drawing::Size(170, 20);
			   this->txbBoxCamURL->TabIndex = 7;
			   this->txbBoxCamURL->Text = L"http://192.168.200.117/onvif/PTZ";
			   // 
			   // btnDisconnectPelcoCam
			   // 
			   this->btnDisconnectPelcoCam->Location = System::Drawing::Point(5, 185);
			   this->btnDisconnectPelcoCam->Name = L"btnDisconnectPelcoCam";
			   this->btnDisconnectPelcoCam->Size = System::Drawing::Size(181, 29);
			   this->btnDisconnectPelcoCam->TabIndex = 6;
			   this->btnDisconnectPelcoCam->Text = L"Disconnect";
			   this->btnDisconnectPelcoCam->UseVisualStyleBackColor = true;
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(135, 235);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(73, 13);
			   this->label6->TabIndex = 10;
			   this->label6->Text = L"PTZ Protocol:";
			   // 
			   // comboBoxEnablePtz
			   // 
			   this->comboBoxEnablePtz->FormattingEnabled = true;
			   this->comboBoxEnablePtz->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Pelco D", L"ONVIF", L"Disable" });
			   this->comboBoxEnablePtz->Location = System::Drawing::Point(211, 232);
			   this->comboBoxEnablePtz->Name = L"comboBoxEnablePtz";
			   this->comboBoxEnablePtz->Size = System::Drawing::Size(83, 21);
			   this->comboBoxEnablePtz->TabIndex = 9;
			   this->comboBoxEnablePtz->Text = L"Pelco D";
			   this->comboBoxEnablePtz->SelectedIndexChanged += gcnew System::EventHandler(this, &cameraSetup::comboBoxEnablePtz_SelectedIndexChanged);
			   // 
			   // btnCheckConPelcoD
			   // 
			   this->btnCheckConPelcoD->Enabled = false;
			   this->btnCheckConPelcoD->Location = System::Drawing::Point(5, 144);
			   this->btnCheckConPelcoD->Name = L"btnCheckConPelcoD";
			   this->btnCheckConPelcoD->Size = System::Drawing::Size(181, 29);
			   this->btnCheckConPelcoD->TabIndex = 5;
			   this->btnCheckConPelcoD->Text = L"Check Connection";
			   this->btnCheckConPelcoD->UseVisualStyleBackColor = true;
			   this->btnCheckConPelcoD->Click += gcnew System::EventHandler(this, &cameraSetup::btnCheckConPelcoD_Click);
			   // 
			   // radioBtnSerialCamera
			   // 
			   this->radioBtnSerialCamera->AutoSize = true;
			   this->radioBtnSerialCamera->Checked = true;
			   this->radioBtnSerialCamera->Location = System::Drawing::Point(3, 2);
			   this->radioBtnSerialCamera->Name = L"radioBtnSerialCamera";
			   this->radioBtnSerialCamera->Size = System::Drawing::Size(51, 17);
			   this->radioBtnSerialCamera->TabIndex = 7;
			   this->radioBtnSerialCamera->TabStop = true;
			   this->radioBtnSerialCamera->Text = L"Serial";
			   this->radioBtnSerialCamera->UseVisualStyleBackColor = true;
			   this->radioBtnSerialCamera->CheckedChanged += gcnew System::EventHandler(this, &cameraSetup::radioBtnSerialCamera_CheckedChanged);
			   // 
			   // radioBtnLanCamera
			   // 
			   this->radioBtnLanCamera->AutoSize = true;
			   this->radioBtnLanCamera->Location = System::Drawing::Point(281, 2);
			   this->radioBtnLanCamera->Name = L"radioBtnLanCamera";
			   this->radioBtnLanCamera->Size = System::Drawing::Size(46, 17);
			   this->radioBtnLanCamera->TabIndex = 8;
			   this->radioBtnLanCamera->Text = L"LAN";
			   this->radioBtnLanCamera->UseVisualStyleBackColor = true;
			   this->radioBtnLanCamera->CheckedChanged += gcnew System::EventHandler(this, &cameraSetup::radioBtnLanCamera_CheckedChanged);
			   // 
			   // groupBoxVideoCameraFeed
			   // 
			   this->groupBoxVideoCameraFeed->Controls->Add(this->panelVideoFeedLan);
			   this->groupBoxVideoCameraFeed->Controls->Add(this->panelVideoFeenSerial);
			   this->groupBoxVideoCameraFeed->Location = System::Drawing::Point(3, 12);
			   this->groupBoxVideoCameraFeed->Name = L"groupBoxVideoCameraFeed";
			   this->groupBoxVideoCameraFeed->Size = System::Drawing::Size(563, 192);
			   this->groupBoxVideoCameraFeed->TabIndex = 17;
			   this->groupBoxVideoCameraFeed->TabStop = false;
			   this->groupBoxVideoCameraFeed->Text = L"Video Feed";
			   // 
			   // panelVideoFeedLan
			   // 
			   this->panelVideoFeedLan->Controls->Add(this->label7);
			   this->panelVideoFeedLan->Controls->Add(this->btnConnectVideoFeedLan);
			   this->panelVideoFeedLan->Controls->Add(this->txtLanVideoFeedLink);
			   this->panelVideoFeedLan->Enabled = false;
			   this->panelVideoFeedLan->Location = System::Drawing::Point(318, 21);
			   this->panelVideoFeedLan->Name = L"panelVideoFeedLan";
			   this->panelVideoFeedLan->Size = System::Drawing::Size(229, 155);
			   this->panelVideoFeedLan->TabIndex = 17;
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(3, 26);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(30, 13);
			   this->label7->TabIndex = 15;
			   this->label7->Text = L"Link:";
			   // 
			   // btnConnectVideoFeedLan
			   // 
			   this->btnConnectVideoFeedLan->Location = System::Drawing::Point(22, 113);
			   this->btnConnectVideoFeedLan->Name = L"btnConnectVideoFeedLan";
			   this->btnConnectVideoFeedLan->Size = System::Drawing::Size(181, 29);
			   this->btnConnectVideoFeedLan->TabIndex = 14;
			   this->btnConnectVideoFeedLan->Text = L"Connect";
			   this->btnConnectVideoFeedLan->UseVisualStyleBackColor = true;
			   this->btnConnectVideoFeedLan->Click += gcnew System::EventHandler(this, &cameraSetup::btnConnectVideoFeedLan_Click);
			   // 
			   // txtLanVideoFeedLink
			   // 
			   this->txtLanVideoFeedLink->Location = System::Drawing::Point(39, 23);
			   this->txtLanVideoFeedLink->Name = L"txtLanVideoFeedLink";
			   this->txtLanVideoFeedLink->Size = System::Drawing::Size(170, 20);
			   this->txtLanVideoFeedLink->TabIndex = 13;
			   this->txtLanVideoFeedLink->Text = L"http://admin:12345abc@192.168.200.117/ISAPI/Streaming/channels/102/httpPreview";
			   // 
			   // panelVideoFeenSerial
			   // 
			   this->panelVideoFeenSerial->Controls->Add(this->btnCamera2);
			   this->panelVideoFeenSerial->Controls->Add(this->btnCamera1);
			   this->panelVideoFeenSerial->Controls->Add(this->btnCamera3);
			   this->panelVideoFeenSerial->Controls->Add(this->btConnectCV);
			   this->panelVideoFeenSerial->Controls->Add(this->btnCamera4);
			   this->panelVideoFeenSerial->Controls->Add(this->btnCamera5);
			   this->panelVideoFeenSerial->Location = System::Drawing::Point(6, 21);
			   this->panelVideoFeenSerial->Name = L"panelVideoFeenSerial";
			   this->panelVideoFeenSerial->Size = System::Drawing::Size(275, 155);
			   this->panelVideoFeenSerial->TabIndex = 18;
			   // 
			   // btnCamera2
			   // 
			   this->btnCamera2->Location = System::Drawing::Point(97, 20);
			   this->btnCamera2->Name = L"btnCamera2";
			   this->btnCamera2->Size = System::Drawing::Size(75, 23);
			   this->btnCamera2->TabIndex = 24;
			   this->btnCamera2->Text = L"2";
			   this->btnCamera2->UseVisualStyleBackColor = true;
			   this->btnCamera2->Click += gcnew System::EventHandler(this, &cameraSetup::btnCamera2_Click);
			   // 
			   // btnCamera1
			   // 
			   this->btnCamera1->Location = System::Drawing::Point(16, 20);
			   this->btnCamera1->Name = L"btnCamera1";
			   this->btnCamera1->Size = System::Drawing::Size(75, 23);
			   this->btnCamera1->TabIndex = 23;
			   this->btnCamera1->Text = L"1";
			   this->btnCamera1->UseVisualStyleBackColor = true;
			   this->btnCamera1->Click += gcnew System::EventHandler(this, &cameraSetup::btnCamera1_Click);
			   // 
			   // btnCamera3
			   // 
			   this->btnCamera3->Location = System::Drawing::Point(178, 20);
			   this->btnCamera3->Name = L"btnCamera3";
			   this->btnCamera3->Size = System::Drawing::Size(75, 23);
			   this->btnCamera3->TabIndex = 25;
			   this->btnCamera3->Text = L"3";
			   this->btnCamera3->UseVisualStyleBackColor = true;
			   this->btnCamera3->Click += gcnew System::EventHandler(this, &cameraSetup::btnCamera3_Click);
			   // 
			   // btConnectCV
			   // 
			   this->btConnectCV->Location = System::Drawing::Point(53, 113);
			   this->btConnectCV->Name = L"btConnectCV";
			   this->btConnectCV->Size = System::Drawing::Size(181, 29);
			   this->btConnectCV->TabIndex = 28;
			   this->btConnectCV->Text = L"Connect";
			   this->btConnectCV->UseVisualStyleBackColor = true;
			   this->btConnectCV->Click += gcnew System::EventHandler(this, &cameraSetup::btConnectCV_Click);
			   // 
			   // btnCamera4
			   // 
			   this->btnCamera4->Location = System::Drawing::Point(16, 58);
			   this->btnCamera4->Name = L"btnCamera4";
			   this->btnCamera4->Size = System::Drawing::Size(75, 23);
			   this->btnCamera4->TabIndex = 26;
			   this->btnCamera4->Text = L"4";
			   this->btnCamera4->UseVisualStyleBackColor = true;
			   this->btnCamera4->Click += gcnew System::EventHandler(this, &cameraSetup::btnCamera4_Click);
			   // 
			   // btnCamera5
			   // 
			   this->btnCamera5->Location = System::Drawing::Point(97, 58);
			   this->btnCamera5->Name = L"btnCamera5";
			   this->btnCamera5->Size = System::Drawing::Size(75, 23);
			   this->btnCamera5->TabIndex = 27;
			   this->btnCamera5->Text = L"5";
			   this->btnCamera5->UseVisualStyleBackColor = true;
			   this->btnCamera5->Click += gcnew System::EventHandler(this, &cameraSetup::btnCamera5_Click);
			   // 
			   // btnDisconnectLanVideoFeed
			   // 
			   this->btnDisconnectLanVideoFeed->Location = System::Drawing::Point(1041, 588);
			   this->btnDisconnectLanVideoFeed->Name = L"btnDisconnectLanVideoFeed";
			   this->btnDisconnectLanVideoFeed->Size = System::Drawing::Size(181, 29);
			   this->btnDisconnectLanVideoFeed->TabIndex = 16;
			   this->btnDisconnectLanVideoFeed->Text = L"Disconnect";
			   this->btnDisconnectLanVideoFeed->UseVisualStyleBackColor = true;
			   // 
			   // radioButradioButtonVideoFeedLan
			   // 
			   this->radioButradioButtonVideoFeedLan->AutoSize = true;
			   this->radioButradioButtonVideoFeedLan->Location = System::Drawing::Point(413, 210);
			   this->radioButradioButtonVideoFeedLan->Name = L"radioButradioButtonVideoFeedLan";
			   this->radioButradioButtonVideoFeedLan->Size = System::Drawing::Size(46, 17);
			   this->radioButradioButtonVideoFeedLan->TabIndex = 19;
			   this->radioButradioButtonVideoFeedLan->Text = L"LAN";
			   this->radioButradioButtonVideoFeedLan->UseVisualStyleBackColor = true;
			   // 
			   // radioButtonVideoFeedSerial
			   // 
			   this->radioButtonVideoFeedSerial->AutoSize = true;
			   this->radioButtonVideoFeedSerial->Checked = true;
			   this->radioButtonVideoFeedSerial->Location = System::Drawing::Point(106, 210);
			   this->radioButtonVideoFeedSerial->Name = L"radioButtonVideoFeedSerial";
			   this->radioButtonVideoFeedSerial->Size = System::Drawing::Size(51, 17);
			   this->radioButtonVideoFeedSerial->TabIndex = 18;
			   this->radioButtonVideoFeedSerial->TabStop = true;
			   this->radioButtonVideoFeedSerial->Text = L"Serial";
			   this->radioButtonVideoFeedSerial->UseVisualStyleBackColor = true;
			   this->radioButtonVideoFeedSerial->CheckedChanged += gcnew System::EventHandler(this, &cameraSetup::radioButtonVideoFeedSerial_CheckedChanged);
			   // 
			   // PanelRadioBoxPTZControl
			   // 
			   this->PanelRadioBoxPTZControl->Controls->Add(this->radioBtnLanCamera);
			   this->PanelRadioBoxPTZControl->Controls->Add(this->radioBtnSerialCamera);
			   this->PanelRadioBoxPTZControl->Location = System::Drawing::Point(78, 522);
			   this->PanelRadioBoxPTZControl->Name = L"PanelRadioBoxPTZControl";
			   this->PanelRadioBoxPTZControl->Size = System::Drawing::Size(354, 32);
			   this->PanelRadioBoxPTZControl->TabIndex = 20;
			   // 
			   // groupBox1
			   // 
			   this->groupBox1->Controls->Add(this->groupboxTargetCaptureParameters);
			   this->groupBox1->Location = System::Drawing::Point(983, 23);
			   this->groupBox1->Name = L"groupBox1";
			   this->groupBox1->Size = System::Drawing::Size(331, 404);
			   this->groupBox1->TabIndex = 21;
			   this->groupBox1->TabStop = false;
			   this->groupBox1->Text = L"Track Setup";
			   // 
			   // groupboxTargetCaptureParameters
			   // 
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocus9);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt9);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom9);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label15);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocus8);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt8);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom8);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocus7);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt7);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom7);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocus6);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt6);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom6);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocu5);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt5);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom5);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocus4);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt4);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom4);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocus3);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt3);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom3);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocus2);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt2);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom2);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocus1);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt1);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom1);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxFocus0);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxTilt0);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->txtBoxZoom0);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label14);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label13);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label12);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label11);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label10);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label9);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label8);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label5);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label4);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label3);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label2);
			   this->groupboxTargetCaptureParameters->Controls->Add(this->label1);
			   this->groupboxTargetCaptureParameters->Location = System::Drawing::Point(6, 21);
			   this->groupboxTargetCaptureParameters->Name = L"groupboxTargetCaptureParameters";
			   this->groupboxTargetCaptureParameters->Size = System::Drawing::Size(311, 367);
			   this->groupboxTargetCaptureParameters->TabIndex = 0;
			   this->groupboxTargetCaptureParameters->TabStop = false;
			   this->groupboxTargetCaptureParameters->Text = L"Target Capture Parameters";
			   // 
			   // txtBoxFocus9
			   // 
			   this->txtBoxFocus9->Location = System::Drawing::Point(222, 332);
			   this->txtBoxFocus9->Name = L"txtBoxFocus9";
			   this->txtBoxFocus9->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocus9->TabIndex = 42;
			   // 
			   // txtBoxTilt9
			   // 
			   this->txtBoxTilt9->Location = System::Drawing::Point(155, 332);
			   this->txtBoxTilt9->Name = L"txtBoxTilt9";
			   this->txtBoxTilt9->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt9->TabIndex = 41;
			   // 
			   // txtBoxZoom9
			   // 
			   this->txtBoxZoom9->Location = System::Drawing::Point(88, 332);
			   this->txtBoxZoom9->Name = L"txtBoxZoom9";
			   this->txtBoxZoom9->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom9->TabIndex = 40;
			   // 
			   // label15
			   // 
			   this->label15->AutoSize = true;
			   this->label15->Location = System::Drawing::Point(24, 335);
			   this->label15->Name = L"label15";
			   this->label15->Size = System::Drawing::Size(48, 13);
			   this->label15->TabIndex = 39;
			   this->label15->Text = L"90 - 99%";
			   // 
			   // txtBoxFocus8
			   // 
			   this->txtBoxFocus8->Location = System::Drawing::Point(222, 301);
			   this->txtBoxFocus8->Name = L"txtBoxFocus8";
			   this->txtBoxFocus8->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocus8->TabIndex = 38;
			   // 
			   // txtBoxTilt8
			   // 
			   this->txtBoxTilt8->Location = System::Drawing::Point(155, 301);
			   this->txtBoxTilt8->Name = L"txtBoxTilt8";
			   this->txtBoxTilt8->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt8->TabIndex = 37;
			   // 
			   // txtBoxZoom8
			   // 
			   this->txtBoxZoom8->Location = System::Drawing::Point(88, 301);
			   this->txtBoxZoom8->Name = L"txtBoxZoom8";
			   this->txtBoxZoom8->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom8->TabIndex = 36;
			   // 
			   // txtBoxFocus7
			   // 
			   this->txtBoxFocus7->Location = System::Drawing::Point(222, 271);
			   this->txtBoxFocus7->Name = L"txtBoxFocus7";
			   this->txtBoxFocus7->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocus7->TabIndex = 35;
			   // 
			   // txtBoxTilt7
			   // 
			   this->txtBoxTilt7->Location = System::Drawing::Point(155, 271);
			   this->txtBoxTilt7->Name = L"txtBoxTilt7";
			   this->txtBoxTilt7->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt7->TabIndex = 34;
			   // 
			   // txtBoxZoom7
			   // 
			   this->txtBoxZoom7->Location = System::Drawing::Point(88, 271);
			   this->txtBoxZoom7->Name = L"txtBoxZoom7";
			   this->txtBoxZoom7->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom7->TabIndex = 33;
			   // 
			   // txtBoxFocus6
			   // 
			   this->txtBoxFocus6->Location = System::Drawing::Point(222, 241);
			   this->txtBoxFocus6->Name = L"txtBoxFocus6";
			   this->txtBoxFocus6->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocus6->TabIndex = 32;
			   // 
			   // txtBoxTilt6
			   // 
			   this->txtBoxTilt6->Location = System::Drawing::Point(155, 241);
			   this->txtBoxTilt6->Name = L"txtBoxTilt6";
			   this->txtBoxTilt6->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt6->TabIndex = 31;
			   // 
			   // txtBoxZoom6
			   // 
			   this->txtBoxZoom6->Location = System::Drawing::Point(88, 241);
			   this->txtBoxZoom6->Name = L"txtBoxZoom6";
			   this->txtBoxZoom6->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom6->TabIndex = 30;
			   // 
			   // txtBoxFocu5
			   // 
			   this->txtBoxFocu5->Location = System::Drawing::Point(222, 209);
			   this->txtBoxFocu5->Name = L"txtBoxFocu5";
			   this->txtBoxFocu5->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocu5->TabIndex = 29;
			   // 
			   // txtBoxTilt5
			   // 
			   this->txtBoxTilt5->Location = System::Drawing::Point(155, 209);
			   this->txtBoxTilt5->Name = L"txtBoxTilt5";
			   this->txtBoxTilt5->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt5->TabIndex = 28;
			   // 
			   // txtBoxZoom5
			   // 
			   this->txtBoxZoom5->Location = System::Drawing::Point(88, 209);
			   this->txtBoxZoom5->Name = L"txtBoxZoom5";
			   this->txtBoxZoom5->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom5->TabIndex = 27;
			   // 
			   // txtBoxFocus4
			   // 
			   this->txtBoxFocus4->Location = System::Drawing::Point(222, 177);
			   this->txtBoxFocus4->Name = L"txtBoxFocus4";
			   this->txtBoxFocus4->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocus4->TabIndex = 26;
			   // 
			   // txtBoxTilt4
			   // 
			   this->txtBoxTilt4->Location = System::Drawing::Point(155, 177);
			   this->txtBoxTilt4->Name = L"txtBoxTilt4";
			   this->txtBoxTilt4->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt4->TabIndex = 25;
			   // 
			   // txtBoxZoom4
			   // 
			   this->txtBoxZoom4->Location = System::Drawing::Point(88, 177);
			   this->txtBoxZoom4->Name = L"txtBoxZoom4";
			   this->txtBoxZoom4->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom4->TabIndex = 24;
			   // 
			   // txtBoxFocus3
			   // 
			   this->txtBoxFocus3->Location = System::Drawing::Point(222, 141);
			   this->txtBoxFocus3->Name = L"txtBoxFocus3";
			   this->txtBoxFocus3->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocus3->TabIndex = 23;
			   // 
			   // txtBoxTilt3
			   // 
			   this->txtBoxTilt3->Location = System::Drawing::Point(155, 141);
			   this->txtBoxTilt3->Name = L"txtBoxTilt3";
			   this->txtBoxTilt3->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt3->TabIndex = 22;
			   // 
			   // txtBoxZoom3
			   // 
			   this->txtBoxZoom3->Location = System::Drawing::Point(88, 141);
			   this->txtBoxZoom3->Name = L"txtBoxZoom3";
			   this->txtBoxZoom3->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom3->TabIndex = 21;
			   // 
			   // txtBoxFocus2
			   // 
			   this->txtBoxFocus2->Location = System::Drawing::Point(222, 111);
			   this->txtBoxFocus2->Name = L"txtBoxFocus2";
			   this->txtBoxFocus2->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocus2->TabIndex = 20;
			   // 
			   // txtBoxTilt2
			   // 
			   this->txtBoxTilt2->Location = System::Drawing::Point(155, 111);
			   this->txtBoxTilt2->Name = L"txtBoxTilt2";
			   this->txtBoxTilt2->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt2->TabIndex = 19;
			   // 
			   // txtBoxZoom2
			   // 
			   this->txtBoxZoom2->Location = System::Drawing::Point(88, 111);
			   this->txtBoxZoom2->Name = L"txtBoxZoom2";
			   this->txtBoxZoom2->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom2->TabIndex = 18;
			   // 
			   // txtBoxFocus1
			   // 
			   this->txtBoxFocus1->Location = System::Drawing::Point(222, 80);
			   this->txtBoxFocus1->Name = L"txtBoxFocus1";
			   this->txtBoxFocus1->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocus1->TabIndex = 17;
			   // 
			   // txtBoxTilt1
			   // 
			   this->txtBoxTilt1->Location = System::Drawing::Point(155, 80);
			   this->txtBoxTilt1->Name = L"txtBoxTilt1";
			   this->txtBoxTilt1->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt1->TabIndex = 16;
			   // 
			   // txtBoxZoom1
			   // 
			   this->txtBoxZoom1->Location = System::Drawing::Point(88, 80);
			   this->txtBoxZoom1->Name = L"txtBoxZoom1";
			   this->txtBoxZoom1->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom1->TabIndex = 15;
			   // 
			   // txtBoxFocus0
			   // 
			   this->txtBoxFocus0->Location = System::Drawing::Point(222, 49);
			   this->txtBoxFocus0->Name = L"txtBoxFocus0";
			   this->txtBoxFocus0->Size = System::Drawing::Size(61, 20);
			   this->txtBoxFocus0->TabIndex = 14;
			   // 
			   // txtBoxTilt0
			   // 
			   this->txtBoxTilt0->Location = System::Drawing::Point(155, 49);
			   this->txtBoxTilt0->Name = L"txtBoxTilt0";
			   this->txtBoxTilt0->Size = System::Drawing::Size(61, 20);
			   this->txtBoxTilt0->TabIndex = 13;
			   // 
			   // txtBoxZoom0
			   // 
			   this->txtBoxZoom0->Location = System::Drawing::Point(88, 49);
			   this->txtBoxZoom0->Name = L"txtBoxZoom0";
			   this->txtBoxZoom0->Size = System::Drawing::Size(61, 20);
			   this->txtBoxZoom0->TabIndex = 12;
			   // 
			   // label14
			   // 
			   this->label14->AutoSize = true;
			   this->label14->Location = System::Drawing::Point(226, 28);
			   this->label14->Name = L"label14";
			   this->label14->Size = System::Drawing::Size(53, 13);
			   this->label14->TabIndex = 11;
			   this->label14->Text = L"Focus (%)";
			   // 
			   // label13
			   // 
			   this->label13->AutoSize = true;
			   this->label13->Location = System::Drawing::Point(172, 28);
			   this->label13->Name = L"label13";
			   this->label13->Size = System::Drawing::Size(34, 13);
			   this->label13->TabIndex = 10;
			   this->label13->Text = L"Tilt (°)";
			   // 
			   // label12
			   // 
			   this->label12->AutoSize = true;
			   this->label12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->label12->Location = System::Drawing::Point(98, 28);
			   this->label12->Name = L"label12";
			   this->label12->Size = System::Drawing::Size(51, 13);
			   this->label12->TabIndex = 9;
			   this->label12->Text = L"Zoom (%)";
			   // 
			   // label11
			   // 
			   this->label11->AutoSize = true;
			   this->label11->Location = System::Drawing::Point(24, 304);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(48, 13);
			   this->label11->TabIndex = 8;
			   this->label11->Text = L"80 - 89%";
			   // 
			   // label10
			   // 
			   this->label10->AutoSize = true;
			   this->label10->Location = System::Drawing::Point(24, 274);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(48, 13);
			   this->label10->TabIndex = 7;
			   this->label10->Text = L"70 - 79%";
			   // 
			   // label9
			   // 
			   this->label9->AutoSize = true;
			   this->label9->Location = System::Drawing::Point(24, 244);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(48, 13);
			   this->label9->TabIndex = 6;
			   this->label9->Text = L"60 - 69%";
			   // 
			   // label8
			   // 
			   this->label8->AutoSize = true;
			   this->label8->Location = System::Drawing::Point(24, 212);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(48, 13);
			   this->label8->TabIndex = 5;
			   this->label8->Text = L"50 - 59%";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(24, 180);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(48, 13);
			   this->label5->TabIndex = 4;
			   this->label5->Text = L"40 - 49%";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(24, 148);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(48, 13);
			   this->label4->TabIndex = 3;
			   this->label4->Text = L"30 - 39%";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(24, 116);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(48, 13);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"20 - 29%";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(24, 84);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(48, 13);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"10 - 19%";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(24, 52);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(48, 13);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"00 - 09%";
			   // 
			   // pitureBoxchooseCamera
			   // 
			   this->pitureBoxchooseCamera->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->pitureBoxchooseCamera->Location = System::Drawing::Point(572, 19);
			   this->pitureBoxchooseCamera->Name = L"pitureBoxchooseCamera";
			   this->pitureBoxchooseCamera->Size = System::Drawing::Size(405, 296);
			   this->pitureBoxchooseCamera->TabIndex = 22;
			   this->pitureBoxchooseCamera->TabStop = false;
			   // 
			   // cameraSetup
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1327, 566);
			   this->Controls->Add(this->btnDisconnectLanVideoFeed);
			   this->Controls->Add(this->pitureBoxchooseCamera);
			   this->Controls->Add(this->groupBox1);
			   this->Controls->Add(this->PanelRadioBoxPTZControl);
			   this->Controls->Add(this->radioButradioButtonVideoFeedLan);
			   this->Controls->Add(this->radioButtonVideoFeedSerial);
			   this->Controls->Add(this->groupBoxVideoCameraFeed);
			   this->Controls->Add(this->groupBoxPelcoCam);
			   this->Name = L"cameraSetup";
			   this->Text = L"Camera Setup";
			   this->Load += gcnew System::EventHandler(this, &cameraSetup::cameraSetup_Load);
			   this->groupBoxPelcoCam->ResumeLayout(false);
			   this->groupBoxPelcoCam->PerformLayout();
			   this->groupBoxVideoCameraFeed->ResumeLayout(false);
			   this->panelVideoFeedLan->ResumeLayout(false);
			   this->panelVideoFeedLan->PerformLayout();
			   this->panelVideoFeenSerial->ResumeLayout(false);
			   this->PanelRadioBoxPTZControl->ResumeLayout(false);
			   this->PanelRadioBoxPTZControl->PerformLayout();
			   this->groupBox1->ResumeLayout(false);
			   this->groupboxTargetCaptureParameters->ResumeLayout(false);
			   this->groupboxTargetCaptureParameters->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pitureBoxchooseCamera))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {};
		System::Void btnConnectCam_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCheckConPelcoD_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void cameraSetup_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void radioBtnSerialCamera_CheckedChanged(System::Object^ sender, System::EventArgs^ e) ;
		System::Void radioBtnLanCamera_CheckedChanged(System::Object^ sender, System::EventArgs^ e) ;
		System::Void radioBtnFixedCameraSerial_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {};
		System::Void comboBoxEnablePtz_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e); 
		System::Void radioButtonVideoFeedSerial_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void btnConnectVideoFeedLan_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCamera1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCamera2_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCamera3_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCamera4_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnCamera5_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btConnectCV_Click(System::Object^ sender, System::EventArgs^ e);
	
};
}



