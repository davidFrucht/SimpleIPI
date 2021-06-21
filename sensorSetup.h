#pragma once
#include "Header.h"

namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for sensorSetup
	/// </summary>
	public ref class sensorSetup : public System::Windows::Forms::Form {

	public:
		sensorSetup(void);

	protected:
		~sensorSetup();

	

	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Label^ lblSoftwareVersion;
	private: System::Windows::Forms::TextBox^ txtBoxSoftwareVersion;

	private: System::Windows::Forms::TextBox^ txtBoxSensorSeialNumber;
	private: System::Windows::Forms::Label^ lblSensorSeialNumber;
	private: System::Windows::Forms::Button^ btnResetSensor;
	private: System::Windows::Forms::GroupBox^ groupBoxSensorParameters;
	private: System::Windows::Forms::GroupBox^ groupBoxSlave;


	private: System::Windows::Forms::Label^ lblSunSlave;


	private: System::Windows::Forms::Label^ lblFlipSlave;


	private: System::Windows::Forms::Label^ lblSSTSlave;


	private: System::Windows::Forms::Label^ lblOrderSlave;


	private: System::Windows::Forms::Label^ lblWidthSlave;


	private: System::Windows::Forms::Label^ lblDeltaSlave;


	private: System::Windows::Forms::Label^ lblSlaveOffset;
	private: System::Windows::Forms::GroupBox^ groupBoxMaster;


	private: System::Windows::Forms::Label^ lblSUNMaster;


	private: System::Windows::Forms::Label^ lblFlipMaster;


	private: System::Windows::Forms::Label^ lblSSTMaster;


	private: System::Windows::Forms::Label^ lblOrderMaster;


	private: System::Windows::Forms::Label^ lblWidthMaster;


	private: System::Windows::Forms::Label^ lblDeltAMaster;


	private: System::Windows::Forms::Label^ lblOffsetMaster;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox0;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Button^ btnFullResetSensor;
	private: System::Windows::Forms::Label^ lblResetOk;
	private: System::Windows::Forms::Label^ lblFullResetOK;
	private: System::Windows::Forms::GroupBox^ groupBoxHiddenZones;




	private: System::Windows::Forms::CheckBox^ checkBoxHZ1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;



	private: System::Windows::Forms::PictureBox^ picBoxRadarHZ;
	private: System::Windows::Forms::Label^ lblHZIndicator;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(sensorSetup::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->lblSoftwareVersion = (gcnew System::Windows::Forms::Label());
			this->txtBoxSoftwareVersion = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxSensorSeialNumber = (gcnew System::Windows::Forms::TextBox());
			this->lblSensorSeialNumber = (gcnew System::Windows::Forms::Label());
			this->btnResetSensor = (gcnew System::Windows::Forms::Button());
			this->groupBoxSensorParameters = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxSlave = (gcnew System::Windows::Forms::GroupBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->lblSunSlave = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->lblOrderSlave = (gcnew System::Windows::Forms::Label());
			this->lblSSTSlave = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->lblSlaveOffset = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->lblFlipSlave = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->lblDeltaSlave = (gcnew System::Windows::Forms::Label());
			this->lblWidthSlave = (gcnew System::Windows::Forms::Label());
			this->groupBoxMaster = (gcnew System::Windows::Forms::GroupBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox0 = (gcnew System::Windows::Forms::TextBox());
			this->lblOrderMaster = (gcnew System::Windows::Forms::Label());
			this->lblSUNMaster = (gcnew System::Windows::Forms::Label());
			this->lblSSTMaster = (gcnew System::Windows::Forms::Label());
			this->lblOffsetMaster = (gcnew System::Windows::Forms::Label());
			this->lblFlipMaster = (gcnew System::Windows::Forms::Label());
			this->lblDeltAMaster = (gcnew System::Windows::Forms::Label());
			this->lblWidthMaster = (gcnew System::Windows::Forms::Label());
			this->btnFullResetSensor = (gcnew System::Windows::Forms::Button());
			this->lblResetOk = (gcnew System::Windows::Forms::Label());
			this->lblFullResetOK = (gcnew System::Windows::Forms::Label());
			this->groupBoxHiddenZones = (gcnew System::Windows::Forms::GroupBox());
			this->lblHZIndicator = (gcnew System::Windows::Forms::Label());
			this->checkBoxHZ1 = (gcnew System::Windows::Forms::CheckBox());
			this->picBoxRadarHZ = (gcnew System::Windows::Forms::PictureBox());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBoxSensorParameters->SuspendLayout();
			this->groupBoxSlave->SuspendLayout();
			this->groupBoxMaster->SuspendLayout();
			this->groupBoxHiddenZones->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxRadarHZ))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(837, 447);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Advanced Setup";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &sensorSetup::button1_Click);
			// 
			// lblSoftwareVersion
			// 
			this->lblSoftwareVersion->AutoSize = true;
			this->lblSoftwareVersion->Location = System::Drawing::Point(12, 447);
			this->lblSoftwareVersion->Name = L"lblSoftwareVersion";
			this->lblSoftwareVersion->Size = System::Drawing::Size(93, 13);
			this->lblSoftwareVersion->TabIndex = 2;
			this->lblSoftwareVersion->Text = L"Software Version: ";
			// 
			// txtBoxSoftwareVersion
			// 
			this->txtBoxSoftwareVersion->Location = System::Drawing::Point(127, 444);
			this->txtBoxSoftwareVersion->Name = L"txtBoxSoftwareVersion";
			this->txtBoxSoftwareVersion->Size = System::Drawing::Size(326, 20);
			this->txtBoxSoftwareVersion->TabIndex = 3;
			// 
			// txtBoxSensorSeialNumber
			// 
			this->txtBoxSensorSeialNumber->Location = System::Drawing::Point(127, 470);
			this->txtBoxSensorSeialNumber->Name = L"txtBoxSensorSeialNumber";
			this->txtBoxSensorSeialNumber->Size = System::Drawing::Size(326, 20);
			this->txtBoxSensorSeialNumber->TabIndex = 6;
			// 
			// lblSensorSeialNumber
			// 
			this->lblSensorSeialNumber->AutoSize = true;
			this->lblSensorSeialNumber->Location = System::Drawing::Point(12, 473);
			this->lblSensorSeialNumber->Name = L"lblSensorSeialNumber";
			this->lblSensorSeialNumber->Size = System::Drawing::Size(109, 13);
			this->lblSensorSeialNumber->TabIndex = 5;
			this->lblSensorSeialNumber->Text = L"Sensor Serial Number";
			// 
			// btnResetSensor
			// 
			this->btnResetSensor->Location = System::Drawing::Point(459, 441);
			this->btnResetSensor->Name = L"btnResetSensor";
			this->btnResetSensor->Size = System::Drawing::Size(110, 23);
			this->btnResetSensor->TabIndex = 7;
			this->btnResetSensor->Text = L"Reset Sensor ";
			this->btnResetSensor->UseVisualStyleBackColor = true;
			this->btnResetSensor->Click += gcnew System::EventHandler(this, &sensorSetup::btnResetSensor_Click);
			// 
			// groupBoxSensorParameters
			// 
			this->groupBoxSensorParameters->Controls->Add(this->groupBoxSlave);
			this->groupBoxSensorParameters->Controls->Add(this->groupBoxMaster);
			this->groupBoxSensorParameters->Location = System::Drawing::Point(12, 12);
			this->groupBoxSensorParameters->Name = L"groupBoxSensorParameters";
			this->groupBoxSensorParameters->Size = System::Drawing::Size(334, 267);
			this->groupBoxSensorParameters->TabIndex = 8;
			this->groupBoxSensorParameters->TabStop = false;
			this->groupBoxSensorParameters->Text = L"Sensor Parameters";
			// 
			// groupBoxSlave
			// 
			this->groupBoxSlave->Controls->Add(this->textBox10);
			this->groupBoxSlave->Controls->Add(this->textBox7);
			this->groupBoxSlave->Controls->Add(this->textBox8);
			this->groupBoxSlave->Controls->Add(this->lblSunSlave);
			this->groupBoxSlave->Controls->Add(this->textBox9);
			this->groupBoxSlave->Controls->Add(this->lblOrderSlave);
			this->groupBoxSlave->Controls->Add(this->lblSSTSlave);
			this->groupBoxSlave->Controls->Add(this->textBox11);
			this->groupBoxSlave->Controls->Add(this->lblSlaveOffset);
			this->groupBoxSlave->Controls->Add(this->textBox12);
			this->groupBoxSlave->Controls->Add(this->lblFlipSlave);
			this->groupBoxSlave->Controls->Add(this->textBox13);
			this->groupBoxSlave->Controls->Add(this->lblDeltaSlave);
			this->groupBoxSlave->Controls->Add(this->lblWidthSlave);
			this->groupBoxSlave->Location = System::Drawing::Point(178, 19);
			this->groupBoxSlave->Name = L"groupBoxSlave";
			this->groupBoxSlave->Size = System::Drawing::Size(140, 209);
			this->groupBoxSlave->TabIndex = 1;
			this->groupBoxSlave->TabStop = false;
			this->groupBoxSlave->Text = L"Slave Laser";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(77, 102);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(57, 20);
			this->textBox10->TabIndex = 23;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(77, 24);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(57, 20);
			this->textBox7->TabIndex = 26;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(77, 50);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(57, 20);
			this->textBox8->TabIndex = 25;
			// 
			// lblSunSlave
			// 
			this->lblSunSlave->AutoSize = true;
			this->lblSunSlave->Location = System::Drawing::Point(12, 158);
			this->lblSunSlave->Name = L"lblSunSlave";
			this->lblSunSlave->Size = System::Drawing::Size(30, 13);
			this->lblSunSlave->TabIndex = 13;
			this->lblSunSlave->Text = L"SUN";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(77, 77);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(57, 20);
			this->textBox9->TabIndex = 24;
			// 
			// lblOrderSlave
			// 
			this->lblOrderSlave->AutoSize = true;
			this->lblOrderSlave->Location = System::Drawing::Point(12, 28);
			this->lblOrderSlave->Name = L"lblOrderSlave";
			this->lblOrderSlave->Size = System::Drawing::Size(46, 13);
			this->lblOrderSlave->TabIndex = 7;
			this->lblOrderSlave->Text = L"ORDER";
			// 
			// lblSSTSlave
			// 
			this->lblSSTSlave->AutoSize = true;
			this->lblSSTSlave->Location = System::Drawing::Point(12, 184);
			this->lblSSTSlave->Name = L"lblSSTSlave";
			this->lblSSTSlave->Size = System::Drawing::Size(28, 13);
			this->lblSSTSlave->TabIndex = 9;
			this->lblSSTSlave->Text = L"SST";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(77, 128);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(57, 20);
			this->textBox11->TabIndex = 22;
			// 
			// lblSlaveOffset
			// 
			this->lblSlaveOffset->AutoSize = true;
			this->lblSlaveOffset->Location = System::Drawing::Point(12, 54);
			this->lblSlaveOffset->Name = L"lblSlaveOffset";
			this->lblSlaveOffset->Size = System::Drawing::Size(48, 13);
			this->lblSlaveOffset->TabIndex = 0;
			this->lblSlaveOffset->Text = L"OFFSET";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(77, 157);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(57, 20);
			this->textBox12->TabIndex = 21;
			// 
			// lblFlipSlave
			// 
			this->lblFlipSlave->AutoSize = true;
			this->lblFlipSlave->Location = System::Drawing::Point(12, 132);
			this->lblFlipSlave->Name = L"lblFlipSlave";
			this->lblFlipSlave->Size = System::Drawing::Size(29, 13);
			this->lblFlipSlave->TabIndex = 11;
			this->lblFlipSlave->Text = L"FLIP";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(77, 181);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(57, 20);
			this->textBox13->TabIndex = 20;
			// 
			// lblDeltaSlave
			// 
			this->lblDeltaSlave->AutoSize = true;
			this->lblDeltaSlave->Location = System::Drawing::Point(12, 80);
			this->lblDeltaSlave->Name = L"lblDeltaSlave";
			this->lblDeltaSlave->Size = System::Drawing::Size(42, 13);
			this->lblDeltaSlave->TabIndex = 3;
			this->lblDeltaSlave->Text = L"DELTA";
			// 
			// lblWidthSlave
			// 
			this->lblWidthSlave->AutoSize = true;
			this->lblWidthSlave->Location = System::Drawing::Point(12, 106);
			this->lblWidthSlave->Name = L"lblWidthSlave";
			this->lblWidthSlave->Size = System::Drawing::Size(44, 13);
			this->lblWidthSlave->TabIndex = 5;
			this->lblWidthSlave->Text = L"WIDTH";
			// 
			// groupBoxMaster
			// 
			this->groupBoxMaster->Controls->Add(this->textBox6);
			this->groupBoxMaster->Controls->Add(this->textBox5);
			this->groupBoxMaster->Controls->Add(this->textBox4);
			this->groupBoxMaster->Controls->Add(this->textBox3);
			this->groupBoxMaster->Controls->Add(this->textBox2);
			this->groupBoxMaster->Controls->Add(this->textBox1);
			this->groupBoxMaster->Controls->Add(this->textBox0);
			this->groupBoxMaster->Controls->Add(this->lblOrderMaster);
			this->groupBoxMaster->Controls->Add(this->lblSUNMaster);
			this->groupBoxMaster->Controls->Add(this->lblSSTMaster);
			this->groupBoxMaster->Controls->Add(this->lblOffsetMaster);
			this->groupBoxMaster->Controls->Add(this->lblFlipMaster);
			this->groupBoxMaster->Controls->Add(this->lblDeltAMaster);
			this->groupBoxMaster->Controls->Add(this->lblWidthMaster);
			this->groupBoxMaster->Location = System::Drawing::Point(19, 19);
			this->groupBoxMaster->Name = L"groupBoxMaster";
			this->groupBoxMaster->Size = System::Drawing::Size(140, 209);
			this->groupBoxMaster->TabIndex = 0;
			this->groupBoxMaster->TabStop = false;
			this->groupBoxMaster->Text = L"Master Laser";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(77, 181);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(57, 20);
			this->textBox6->TabIndex = 19;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(77, 157);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(57, 20);
			this->textBox5->TabIndex = 18;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(77, 128);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(57, 20);
			this->textBox4->TabIndex = 17;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(77, 102);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(57, 20);
			this->textBox3->TabIndex = 16;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(77, 77);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(57, 20);
			this->textBox2->TabIndex = 15;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(77, 50);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(57, 20);
			this->textBox1->TabIndex = 14;
			// 
			// textBox0
			// 
			this->textBox0->Location = System::Drawing::Point(77, 24);
			this->textBox0->Name = L"textBox0";
			this->textBox0->Size = System::Drawing::Size(57, 20);
			this->textBox0->TabIndex = 9;
			// 
			// lblOrderMaster
			// 
			this->lblOrderMaster->AutoSize = true;
			this->lblOrderMaster->Location = System::Drawing::Point(12, 27);
			this->lblOrderMaster->Name = L"lblOrderMaster";
			this->lblOrderMaster->Size = System::Drawing::Size(46, 13);
			this->lblOrderMaster->TabIndex = 7;
			this->lblOrderMaster->Text = L"ORDER";
			// 
			// lblSUNMaster
			// 
			this->lblSUNMaster->AutoSize = true;
			this->lblSUNMaster->Location = System::Drawing::Point(12, 158);
			this->lblSUNMaster->Name = L"lblSUNMaster";
			this->lblSUNMaster->Size = System::Drawing::Size(30, 13);
			this->lblSUNMaster->TabIndex = 13;
			this->lblSUNMaster->Text = L"SUN";
			// 
			// lblSSTMaster
			// 
			this->lblSSTMaster->AutoSize = true;
			this->lblSSTMaster->Location = System::Drawing::Point(12, 184);
			this->lblSSTMaster->Name = L"lblSSTMaster";
			this->lblSSTMaster->Size = System::Drawing::Size(28, 13);
			this->lblSSTMaster->TabIndex = 9;
			this->lblSSTMaster->Text = L"SST";
			// 
			// lblOffsetMaster
			// 
			this->lblOffsetMaster->AutoSize = true;
			this->lblOffsetMaster->Location = System::Drawing::Point(12, 53);
			this->lblOffsetMaster->Name = L"lblOffsetMaster";
			this->lblOffsetMaster->Size = System::Drawing::Size(48, 13);
			this->lblOffsetMaster->TabIndex = 0;
			this->lblOffsetMaster->Text = L"OFFSET";
			// 
			// lblFlipMaster
			// 
			this->lblFlipMaster->AutoSize = true;
			this->lblFlipMaster->Location = System::Drawing::Point(13, 132);
			this->lblFlipMaster->Name = L"lblFlipMaster";
			this->lblFlipMaster->Size = System::Drawing::Size(29, 13);
			this->lblFlipMaster->TabIndex = 11;
			this->lblFlipMaster->Text = L"FLIP";
			// 
			// lblDeltAMaster
			// 
			this->lblDeltAMaster->AutoSize = true;
			this->lblDeltAMaster->Location = System::Drawing::Point(12, 80);
			this->lblDeltAMaster->Name = L"lblDeltAMaster";
			this->lblDeltAMaster->Size = System::Drawing::Size(42, 13);
			this->lblDeltAMaster->TabIndex = 3;
			this->lblDeltAMaster->Text = L"DELTA";
			// 
			// lblWidthMaster
			// 
			this->lblWidthMaster->AutoSize = true;
			this->lblWidthMaster->Location = System::Drawing::Point(13, 106);
			this->lblWidthMaster->Name = L"lblWidthMaster";
			this->lblWidthMaster->Size = System::Drawing::Size(44, 13);
			this->lblWidthMaster->TabIndex = 5;
			this->lblWidthMaster->Text = L"WIDTH";
			// 
			// btnFullResetSensor
			// 
			this->btnFullResetSensor->Location = System::Drawing::Point(459, 470);
			this->btnFullResetSensor->Name = L"btnFullResetSensor";
			this->btnFullResetSensor->Size = System::Drawing::Size(110, 23);
			this->btnFullResetSensor->TabIndex = 9;
			this->btnFullResetSensor->Text = L"Full Reset Sensor";
			this->btnFullResetSensor->UseVisualStyleBackColor = true;
			this->btnFullResetSensor->Click += gcnew System::EventHandler(this, &sensorSetup::btnFullResetSensor_Click);
			// 
			// lblResetOk
			// 
			this->lblResetOk->AutoSize = true;
			this->lblResetOk->ForeColor = System::Drawing::Color::Green;
			this->lblResetOk->Location = System::Drawing::Point(575, 446);
			this->lblResetOk->Name = L"lblResetOk";
			this->lblResetOk->Size = System::Drawing::Size(85, 13);
			this->lblResetOk->TabIndex = 10;
			this->lblResetOk->Text = L"Reset Succesful";
			this->lblResetOk->Visible = false;
			// 
			// lblFullResetOK
			// 
			this->lblFullResetOK->AutoSize = true;
			this->lblFullResetOK->ForeColor = System::Drawing::Color::Green;
			this->lblFullResetOK->Location = System::Drawing::Point(575, 475);
			this->lblFullResetOK->Name = L"lblFullResetOK";
			this->lblFullResetOK->Size = System::Drawing::Size(104, 13);
			this->lblFullResetOK->TabIndex = 11;
			this->lblFullResetOK->Text = L"Full Reset Succesful";
			this->lblFullResetOK->Visible = false;
			// 
			// groupBoxHiddenZones
			// 
			this->groupBoxHiddenZones->Controls->Add(this->lblHZIndicator);
			this->groupBoxHiddenZones->Controls->Add(this->checkBoxHZ1);
			this->groupBoxHiddenZones->Controls->Add(this->picBoxRadarHZ);
			this->groupBoxHiddenZones->Location = System::Drawing::Point(352, 12);
			this->groupBoxHiddenZones->Name = L"groupBoxHiddenZones";
			this->groupBoxHiddenZones->Size = System::Drawing::Size(491, 372);
			this->groupBoxHiddenZones->TabIndex = 12;
			this->groupBoxHiddenZones->TabStop = false;
			this->groupBoxHiddenZones->Text = L"Hidden Zones";
			// 
			// lblHZIndicator
			// 
			this->lblHZIndicator->AutoSize = true;
			this->lblHZIndicator->ForeColor = System::Drawing::Color::Red;
			this->lblHZIndicator->Location = System::Drawing::Point(134, 26);
			this->lblHZIndicator->Name = L"lblHZIndicator";
			this->lblHZIndicator->Size = System::Drawing::Size(69, 13);
			this->lblHZIndicator->TabIndex = 34;
			this->lblHZIndicator->Text = L"Hidden Zone";
			this->lblHZIndicator->Visible = false;
			// 
			// checkBoxHZ1
			// 
			this->checkBoxHZ1->AutoSize = true;
			this->checkBoxHZ1->Enabled = false;
			this->checkBoxHZ1->Location = System::Drawing::Point(19, 26);
			this->checkBoxHZ1->Name = L"checkBoxHZ1";
			this->checkBoxHZ1->Size = System::Drawing::Size(97, 17);
			this->checkBoxHZ1->TabIndex = 0;
			this->checkBoxHZ1->Text = L"Hidden Zone 1";
			this->checkBoxHZ1->UseVisualStyleBackColor = true;
			this->checkBoxHZ1->CheckedChanged += gcnew System::EventHandler(this, &sensorSetup::checkBoxHZ1_CheckedChanged);
			// 
			// picBoxRadarHZ
			// 
			this->picBoxRadarHZ->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBoxRadarHZ.Image")));
			this->picBoxRadarHZ->ImageLocation = L"";
			this->picBoxRadarHZ->Location = System::Drawing::Point(122, 15);
			this->picBoxRadarHZ->Name = L"picBoxRadarHZ";
			this->picBoxRadarHZ->Size = System::Drawing::Size(351, 351);
			this->picBoxRadarHZ->TabIndex = 33;
			this->picBoxRadarHZ->TabStop = false;
			this->picBoxRadarHZ->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &sensorSetup::picBoxRadarHZ_MouseClick);
			this->picBoxRadarHZ->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &sensorSetup::picBoxRadarHZ_MouseUp);
			// 
			// sensorSetup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1013, 498);
			this->Controls->Add(this->groupBoxHiddenZones);
			this->Controls->Add(this->lblFullResetOK);
			this->Controls->Add(this->lblResetOk);
			this->Controls->Add(this->btnFullResetSensor);
			this->Controls->Add(this->groupBoxSensorParameters);
			this->Controls->Add(this->btnResetSensor);
			this->Controls->Add(this->txtBoxSensorSeialNumber);
			this->Controls->Add(this->lblSensorSeialNumber);
			this->Controls->Add(this->txtBoxSoftwareVersion);
			this->Controls->Add(this->lblSoftwareVersion);
			this->Controls->Add(this->button1);
			this->Name = L"sensorSetup";
			this->Text = L" ";
			this->Load += gcnew System::EventHandler(this, &sensorSetup::sensorSetup_Load);
			this->groupBoxSensorParameters->ResumeLayout(false);
			this->groupBoxSlave->ResumeLayout(false);
			this->groupBoxSlave->PerformLayout();
			this->groupBoxMaster->ResumeLayout(false);
			this->groupBoxMaster->PerformLayout();
			this->groupBoxHiddenZones->ResumeLayout(false);
			this->groupBoxHiddenZones->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxRadarHZ))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnGetSensorData_Click(System::Object^ sender, System::EventArgs^ e);

        System::Void btnResetSensor_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnFullResetSensor_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void sensorSetup_Load(System::Object^ sender, System::EventArgs^ e);
		//System::Void btnSelectAllHZ_Click(System::Object^ sender, System::EventArgs^ e); 
		//System::Void btnClearAll_Click(System::Object^ sender, System::EventArgs^ e);
		//System::Void btnUpdateHZ_Click(System::Object^ sender, System::EventArgs^ e);
		//System::Void picBoxRadarHZ_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void picBoxRadarHZ_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

		System::Void picBoxRadarHZ_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

		//System::Void picBoxRadarHZ_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void checkBoxHZ1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
};
}
