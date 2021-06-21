#pragma once
#include "Header.h"
//#include "json.h"
#include <string.h>
#include <iostream>
#include <msclr\marshal_cppstd.h>

//char phoneNumChar[20] = { "\0" };

extern int Calc::ComAlert;

namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;


	//std::string Calc::phoneNumberStr;

	public ref class alertSetup : public System::Windows::Forms::Form {
	public:
		alertSetup(void);
	protected:
		~alertSetup();
	private:
		System::Windows::Forms::GroupBox^ groupBox1;
		System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		System::Windows::Forms::ComboBox^ cmboBoxBaudCell;
		System::Windows::Forms::ComboBox^ comboBoxCellPhone;
		System::Windows::Forms::Button^ btnCheckConCellPhone;
		System::Windows::Forms::Label^ lblBaudCellPhone;
		System::Windows::Forms::Label^ lblCellphone;
		System::Windows::Forms::Label^ lvlConnectionCell;
		System::Windows::Forms::TextBox^ txtPhoneNumber;
		System::Windows::Forms::Label^ lblPhoneNumber;
		System::Windows::Forms::CheckBox^ checkboxCellular;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ txtBoxToEmailAddress;
	private: System::Windows::Forms::Label^ lblToMailAddress;
	private: System::Windows::Forms::TextBox^ txtBoxFromEmailAddress;
	private: System::Windows::Forms::Label^ lblFromMailAddress;
	private: System::Windows::Forms::TextBox^ txtBoxSMTPServer;
	private: System::Windows::Forms::Label^ lblSMTPServer;
	private: System::Windows::Forms::TextBox^ TxtBoxUserName;

	private: System::Windows::Forms::Label^ lblEmailUserName;
	private: System::Windows::Forms::TextBox^ txtBoxPasswordEmail;
	private: System::Windows::Forms::Label^ lblPasswordEmail;
	private: System::Windows::Forms::Label^ lblEmailConnectionSuccesful;
	private: System::Windows::Forms::Button^ btnCheckEmailConnection;
	private: System::Windows::Forms::CheckBox^ checkBoxEmailNotification;
	private: System::Windows::Forms::GroupBox^ groupBoxJSONNotifcation;

	private:



	private: System::Windows::Forms::Label^ lblJSONNotificationPassword;
	private: System::Windows::Forms::TextBox^ txtBoxJSONNotificationPassword;
	private: System::Windows::Forms::Label^ lblJSONNotificationUserName;
	private: System::Windows::Forms::TextBox^ txtBoxJsonNotificationUserName;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ lblJSONServer;
	private: System::Windows::Forms::CheckBox^ checkBoxJSONNotification;

	private: System::Windows::Forms::Button^ btnJSONNotificationSendExpremintalMsg;

		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->txtPhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->lblPhoneNumber = (gcnew System::Windows::Forms::Label());
			this->lvlConnectionCell = (gcnew System::Windows::Forms::Label());
			this->btnCheckConCellPhone = (gcnew System::Windows::Forms::Button());
			this->lblBaudCellPhone = (gcnew System::Windows::Forms::Label());
			this->lblCellphone = (gcnew System::Windows::Forms::Label());
			this->cmboBoxBaudCell = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxCellPhone = (gcnew System::Windows::Forms::ComboBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->checkboxCellular = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lblEmailConnectionSuccesful = (gcnew System::Windows::Forms::Label());
			this->btnCheckEmailConnection = (gcnew System::Windows::Forms::Button());
			this->txtBoxPasswordEmail = (gcnew System::Windows::Forms::TextBox());
			this->lblPasswordEmail = (gcnew System::Windows::Forms::Label());
			this->TxtBoxUserName = (gcnew System::Windows::Forms::TextBox());
			this->lblEmailUserName = (gcnew System::Windows::Forms::Label());
			this->txtBoxSMTPServer = (gcnew System::Windows::Forms::TextBox());
			this->lblSMTPServer = (gcnew System::Windows::Forms::Label());
			this->txtBoxToEmailAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblToMailAddress = (gcnew System::Windows::Forms::Label());
			this->txtBoxFromEmailAddress = (gcnew System::Windows::Forms::TextBox());
			this->lblFromMailAddress = (gcnew System::Windows::Forms::Label());
			this->checkBoxEmailNotification = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxJSONNotifcation = (gcnew System::Windows::Forms::GroupBox());
			this->btnJSONNotificationSendExpremintalMsg = (gcnew System::Windows::Forms::Button());
			this->lblJSONNotificationPassword = (gcnew System::Windows::Forms::Label());
			this->txtBoxJSONNotificationPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblJSONNotificationUserName = (gcnew System::Windows::Forms::Label());
			this->txtBoxJsonNotificationUserName = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->lblJSONServer = (gcnew System::Windows::Forms::Label());
			this->checkBoxJSONNotification = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBoxJSONNotifcation->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->txtPhoneNumber);
			this->groupBox1->Controls->Add(this->lblPhoneNumber);
			this->groupBox1->Controls->Add(this->lvlConnectionCell);
			this->groupBox1->Controls->Add(this->btnCheckConCellPhone);
			this->groupBox1->Controls->Add(this->lblBaudCellPhone);
			this->groupBox1->Controls->Add(this->lblCellphone);
			this->groupBox1->Controls->Add(this->cmboBoxBaudCell);
			this->groupBox1->Controls->Add(this->comboBoxCellPhone);
			this->groupBox1->Enabled = false;
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(219, 327);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Cellular Notification";
			// 
			// txtPhoneNumber
			// 
			this->txtPhoneNumber->Location = System::Drawing::Point(18, 139);
			this->txtPhoneNumber->Name = L"txtPhoneNumber";
			this->txtPhoneNumber->Size = System::Drawing::Size(181, 20);
			this->txtPhoneNumber->TabIndex = 12;
			this->txtPhoneNumber->Text = L"972544949525";
			// 
			// lblPhoneNumber
			// 
			this->lblPhoneNumber->AutoSize = true;
			this->lblPhoneNumber->Location = System::Drawing::Point(4, 114);
			this->lblPhoneNumber->Name = L"lblPhoneNumber";
			this->lblPhoneNumber->Size = System::Drawing::Size(81, 13);
			this->lblPhoneNumber->TabIndex = 11;
			this->lblPhoneNumber->Text = L"Phone Number:";
			// 
			// lvlConnectionCell
			// 
			this->lvlConnectionCell->AutoSize = true;
			this->lvlConnectionCell->ForeColor = System::Drawing::Color::Green;
			this->lvlConnectionCell->Location = System::Drawing::Point(49, 225);
			this->lvlConnectionCell->Name = L"lvlConnectionCell";
			this->lvlConnectionCell->Size = System::Drawing::Size(111, 13);
			this->lvlConnectionCell->TabIndex = 10;
			this->lvlConnectionCell->Text = L"Connection Succesful";
			this->lvlConnectionCell->Visible = false;
			// 
			// btnCheckConCellPhone
			// 
			this->btnCheckConCellPhone->Location = System::Drawing::Point(18, 174);
			this->btnCheckConCellPhone->Name = L"btnCheckConCellPhone";
			this->btnCheckConCellPhone->Size = System::Drawing::Size(181, 29);
			this->btnCheckConCellPhone->TabIndex = 8;
			this->btnCheckConCellPhone->Text = L"Check Connection";
			this->btnCheckConCellPhone->UseVisualStyleBackColor = true;
			this->btnCheckConCellPhone->Click += gcnew System::EventHandler(this, &alertSetup::btnCheckConCellPhone_Click);
			// 
			// lblBaudCellPhone
			// 
			this->lblBaudCellPhone->AutoSize = true;
			this->lblBaudCellPhone->Location = System::Drawing::Point(3, 79);
			this->lblBaudCellPhone->Name = L"lblBaudCellPhone";
			this->lblBaudCellPhone->Size = System::Drawing::Size(61, 13);
			this->lblBaudCellPhone->TabIndex = 7;
			this->lblBaudCellPhone->Text = L"Baud Rate:";
			// 
			// lblCellphone
			// 
			this->lblCellphone->AutoSize = true;
			this->lblCellphone->Location = System::Drawing::Point(27, 48);
			this->lblCellphone->Name = L"lblCellphone";
			this->lblCellphone->Size = System::Drawing::Size(34, 13);
			this->lblCellphone->TabIndex = 6;
			this->lblCellphone->Text = L"COM:";
			// 
			// cmboBoxBaudCell
			// 
			this->cmboBoxBaudCell->FormattingEnabled = true;
			this->cmboBoxBaudCell->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"2400", L"4800", L"9600", L"14400", L"19200",
					L"28800", L"38400", L"115200"
			});
			this->cmboBoxBaudCell->Location = System::Drawing::Point(78, 75);
			this->cmboBoxBaudCell->Name = L"cmboBoxBaudCell";
			this->cmboBoxBaudCell->Size = System::Drawing::Size(121, 21);
			this->cmboBoxBaudCell->TabIndex = 5;
			this->cmboBoxBaudCell->Text = L"19200";
			// 
			// comboBoxCellPhone
			// 
			this->comboBoxCellPhone->FormattingEnabled = true;
			this->comboBoxCellPhone->Items->AddRange(gcnew cli::array< System::Object^  >(23) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23"
			});
			this->comboBoxCellPhone->Location = System::Drawing::Point(78, 44);
			this->comboBoxCellPhone->Name = L"comboBoxCellPhone";
			this->comboBoxCellPhone->Size = System::Drawing::Size(121, 21);
			this->comboBoxCellPhone->TabIndex = 4;
			this->comboBoxCellPhone->Text = L"9";
			// 
			// checkboxCellular
			// 
			this->checkboxCellular->AutoSize = true;
			this->checkboxCellular->Location = System::Drawing::Point(109, 345);
			this->checkboxCellular->Name = L"checkboxCellular";
			this->checkboxCellular->Size = System::Drawing::Size(15, 14);
			this->checkboxCellular->TabIndex = 1;
			this->checkboxCellular->UseVisualStyleBackColor = true;
			this->checkboxCellular->CheckedChanged += gcnew System::EventHandler(this, &alertSetup::checkBox1_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->lblEmailConnectionSuccesful);
			this->groupBox2->Controls->Add(this->btnCheckEmailConnection);
			this->groupBox2->Controls->Add(this->txtBoxPasswordEmail);
			this->groupBox2->Controls->Add(this->lblPasswordEmail);
			this->groupBox2->Controls->Add(this->TxtBoxUserName);
			this->groupBox2->Controls->Add(this->lblEmailUserName);
			this->groupBox2->Controls->Add(this->txtBoxSMTPServer);
			this->groupBox2->Controls->Add(this->lblSMTPServer);
			this->groupBox2->Controls->Add(this->txtBoxToEmailAddress);
			this->groupBox2->Controls->Add(this->lblToMailAddress);
			this->groupBox2->Controls->Add(this->txtBoxFromEmailAddress);
			this->groupBox2->Controls->Add(this->lblFromMailAddress);
			this->groupBox2->Enabled = false;
			this->groupBox2->Location = System::Drawing::Point(253, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(283, 327);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"E-mail Notification";
			// 
			// lblEmailConnectionSuccesful
			// 
			this->lblEmailConnectionSuccesful->AutoSize = true;
			this->lblEmailConnectionSuccesful->ForeColor = System::Drawing::Color::Green;
			this->lblEmailConnectionSuccesful->Location = System::Drawing::Point(106, 259);
			this->lblEmailConnectionSuccesful->Name = L"lblEmailConnectionSuccesful";
			this->lblEmailConnectionSuccesful->Size = System::Drawing::Size(114, 13);
			this->lblEmailConnectionSuccesful->TabIndex = 11;
			this->lblEmailConnectionSuccesful->Text = L"Email Sent Succesfully";
			this->lblEmailConnectionSuccesful->Visible = false;
			// 
			// btnCheckEmailConnection
			// 
			this->btnCheckEmailConnection->Location = System::Drawing::Point(81, 215);
			this->btnCheckEmailConnection->Name = L"btnCheckEmailConnection";
			this->btnCheckEmailConnection->Size = System::Drawing::Size(175, 23);
			this->btnCheckEmailConnection->TabIndex = 10;
			this->btnCheckEmailConnection->Text = L"Send Expermintal Mail";
			this->btnCheckEmailConnection->UseVisualStyleBackColor = true;
			this->btnCheckEmailConnection->Click += gcnew System::EventHandler(this, &alertSetup::btnCheckEmailConnection_Click);
			// 
			// txtBoxPasswordEmail
			// 
			this->txtBoxPasswordEmail->Location = System::Drawing::Point(81, 183);
			this->txtBoxPasswordEmail->Name = L"txtBoxPasswordEmail";
			this->txtBoxPasswordEmail->Size = System::Drawing::Size(175, 20);
			this->txtBoxPasswordEmail->TabIndex = 9;
			this->txtBoxPasswordEmail->Text = L"frucht17";
			// 
			// lblPasswordEmail
			// 
			this->lblPasswordEmail->AutoSize = true;
			this->lblPasswordEmail->Location = System::Drawing::Point(19, 186);
			this->lblPasswordEmail->Name = L"lblPasswordEmail";
			this->lblPasswordEmail->Size = System::Drawing::Size(56, 13);
			this->lblPasswordEmail->TabIndex = 8;
			this->lblPasswordEmail->Text = L"Password:";
			// 
			// TxtBoxUserName
			// 
			this->TxtBoxUserName->Location = System::Drawing::Point(81, 149);
			this->TxtBoxUserName->Name = L"TxtBoxUserName";
			this->TxtBoxUserName->Size = System::Drawing::Size(175, 20);
			this->TxtBoxUserName->TabIndex = 7;
			this->TxtBoxUserName->Text = L"davidfruc@gmail.com";
			// 
			// lblEmailUserName
			// 
			this->lblEmailUserName->AutoSize = true;
			this->lblEmailUserName->Location = System::Drawing::Point(12, 152);
			this->lblEmailUserName->Name = L"lblEmailUserName";
			this->lblEmailUserName->Size = System::Drawing::Size(63, 13);
			this->lblEmailUserName->TabIndex = 6;
			this->lblEmailUserName->Text = L"User Name:";
			// 
			// txtBoxSMTPServer
			// 
			this->txtBoxSMTPServer->Location = System::Drawing::Point(81, 114);
			this->txtBoxSMTPServer->Name = L"txtBoxSMTPServer";
			this->txtBoxSMTPServer->Size = System::Drawing::Size(175, 20);
			this->txtBoxSMTPServer->TabIndex = 5;
			this->txtBoxSMTPServer->Text = L"smtps://smtp.gmail.com:465";
			// 
			// lblSMTPServer
			// 
			this->lblSMTPServer->AutoSize = true;
			this->lblSMTPServer->Location = System::Drawing::Point(33, 117);
			this->lblSMTPServer->Name = L"lblSMTPServer";
			this->lblSMTPServer->Size = System::Drawing::Size(40, 13);
			this->lblSMTPServer->TabIndex = 4;
			this->lblSMTPServer->Text = L"SMTP:";
			// 
			// txtBoxToEmailAddress
			// 
			this->txtBoxToEmailAddress->Location = System::Drawing::Point(81, 79);
			this->txtBoxToEmailAddress->Name = L"txtBoxToEmailAddress";
			this->txtBoxToEmailAddress->Size = System::Drawing::Size(175, 20);
			this->txtBoxToEmailAddress->TabIndex = 3;
			this->txtBoxToEmailAddress->Text = L"davidf@smartsecsystems.com";
			// 
			// lblToMailAddress
			// 
			this->lblToMailAddress->AutoSize = true;
			this->lblToMailAddress->Location = System::Drawing::Point(49, 83);
			this->lblToMailAddress->Name = L"lblToMailAddress";
			this->lblToMailAddress->Size = System::Drawing::Size(23, 13);
			this->lblToMailAddress->TabIndex = 2;
			this->lblToMailAddress->Text = L"To:";
			// 
			// txtBoxFromEmailAddress
			// 
			this->txtBoxFromEmailAddress->Location = System::Drawing::Point(81, 43);
			this->txtBoxFromEmailAddress->Name = L"txtBoxFromEmailAddress";
			this->txtBoxFromEmailAddress->Size = System::Drawing::Size(175, 20);
			this->txtBoxFromEmailAddress->TabIndex = 1;
			this->txtBoxFromEmailAddress->Text = L"davidfruc@gmail.com";
			// 
			// lblFromMailAddress
			// 
			this->lblFromMailAddress->AutoSize = true;
			this->lblFromMailAddress->Location = System::Drawing::Point(40, 46);
			this->lblFromMailAddress->Name = L"lblFromMailAddress";
			this->lblFromMailAddress->Size = System::Drawing::Size(36, 13);
			this->lblFromMailAddress->TabIndex = 0;
			this->lblFromMailAddress->Text = L"From: ";
			// 
			// checkBoxEmailNotification
			// 
			this->checkBoxEmailNotification->AutoSize = true;
			this->checkBoxEmailNotification->Location = System::Drawing::Point(389, 345);
			this->checkBoxEmailNotification->Name = L"checkBoxEmailNotification";
			this->checkBoxEmailNotification->Size = System::Drawing::Size(15, 14);
			this->checkBoxEmailNotification->TabIndex = 3;
			this->checkBoxEmailNotification->UseVisualStyleBackColor = true;
			this->checkBoxEmailNotification->CheckedChanged += gcnew System::EventHandler(this, &alertSetup::checkBoxEmailNotification_CheckedChanged);
			// 
			// groupBoxJSONNotifcation
			// 
			this->groupBoxJSONNotifcation->Controls->Add(this->btnJSONNotificationSendExpremintalMsg);
			this->groupBoxJSONNotifcation->Controls->Add(this->lblJSONNotificationPassword);
			this->groupBoxJSONNotifcation->Controls->Add(this->txtBoxJSONNotificationPassword);
			this->groupBoxJSONNotifcation->Controls->Add(this->lblJSONNotificationUserName);
			this->groupBoxJSONNotifcation->Controls->Add(this->txtBoxJsonNotificationUserName);
			this->groupBoxJSONNotifcation->Controls->Add(this->textBox1);
			this->groupBoxJSONNotifcation->Controls->Add(this->lblJSONServer);
			this->groupBoxJSONNotifcation->Enabled = false;
			this->groupBoxJSONNotifcation->Location = System::Drawing::Point(561, 12);
			this->groupBoxJSONNotifcation->Name = L"groupBoxJSONNotifcation";
			this->groupBoxJSONNotifcation->Size = System::Drawing::Size(288, 327);
			this->groupBoxJSONNotifcation->TabIndex = 4;
			this->groupBoxJSONNotifcation->TabStop = false;
			this->groupBoxJSONNotifcation->Text = L"JSON Notification";
			// 
			// btnJSONNotificationSendExpremintalMsg
			// 
			this->btnJSONNotificationSendExpremintalMsg->Location = System::Drawing::Point(82, 152);
			this->btnJSONNotificationSendExpremintalMsg->Name = L"btnJSONNotificationSendExpremintalMsg";
			this->btnJSONNotificationSendExpremintalMsg->Size = System::Drawing::Size(175, 26);
			this->btnJSONNotificationSendExpremintalMsg->TabIndex = 15;
			this->btnJSONNotificationSendExpremintalMsg->Text = L"Send Expermintal Message";
			this->btnJSONNotificationSendExpremintalMsg->UseVisualStyleBackColor = true;
			this->btnJSONNotificationSendExpremintalMsg->Click += gcnew System::EventHandler(this, &alertSetup::btnJSONNotificationSendExpremintalMsg_Click);
			// 
			// lblJSONNotificationPassword
			// 
			this->lblJSONNotificationPassword->AutoSize = true;
			this->lblJSONNotificationPassword->Location = System::Drawing::Point(20, 114);
			this->lblJSONNotificationPassword->Name = L"lblJSONNotificationPassword";
			this->lblJSONNotificationPassword->Size = System::Drawing::Size(56, 13);
			this->lblJSONNotificationPassword->TabIndex = 11;
			this->lblJSONNotificationPassword->Text = L"Password:";
			// 
			// txtBoxJSONNotificationPassword
			// 
			this->txtBoxJSONNotificationPassword->Location = System::Drawing::Point(82, 111);
			this->txtBoxJSONNotificationPassword->Name = L"txtBoxJSONNotificationPassword";
			this->txtBoxJSONNotificationPassword->Size = System::Drawing::Size(175, 20);
			this->txtBoxJSONNotificationPassword->TabIndex = 10;
			// 
			// lblJSONNotificationUserName
			// 
			this->lblJSONNotificationUserName->AutoSize = true;
			this->lblJSONNotificationUserName->Location = System::Drawing::Point(13, 78);
			this->lblJSONNotificationUserName->Name = L"lblJSONNotificationUserName";
			this->lblJSONNotificationUserName->Size = System::Drawing::Size(63, 13);
			this->lblJSONNotificationUserName->TabIndex = 9;
			this->lblJSONNotificationUserName->Text = L"User Name:";
			// 
			// txtBoxJsonNotificationUserName
			// 
			this->txtBoxJsonNotificationUserName->Location = System::Drawing::Point(82, 75);
			this->txtBoxJsonNotificationUserName->Name = L"txtBoxJsonNotificationUserName";
			this->txtBoxJsonNotificationUserName->Size = System::Drawing::Size(175, 20);
			this->txtBoxJsonNotificationUserName->TabIndex = 8;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(82, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(175, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"https://simpleipi-default-rtdb.firebaseio.com/";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &alertSetup::textBox1_TextChanged);
			// 
			// lblJSONServer
			// 
			this->lblJSONServer->AutoSize = true;
			this->lblJSONServer->Location = System::Drawing::Point(44, 43);
			this->lblJSONServer->Name = L"lblJSONServer";
			this->lblJSONServer->Size = System::Drawing::Size(32, 13);
			this->lblJSONServer->TabIndex = 2;
			this->lblJSONServer->Text = L"URL:";
			// 
			// checkBoxJSONNotification
			// 
			this->checkBoxJSONNotification->AutoSize = true;
			this->checkBoxJSONNotification->Location = System::Drawing::Point(698, 345);
			this->checkBoxJSONNotification->Name = L"checkBoxJSONNotification";
			this->checkBoxJSONNotification->Size = System::Drawing::Size(15, 14);
			this->checkBoxJSONNotification->TabIndex = 5;
			this->checkBoxJSONNotification->UseVisualStyleBackColor = true;
			this->checkBoxJSONNotification->CheckedChanged += gcnew System::EventHandler(this, &alertSetup::checkBoxJSONNotification_CheckedChanged);
			// 
			// alertSetup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(866, 376);
			this->Controls->Add(this->checkBoxJSONNotification);
			this->Controls->Add(this->groupBoxJSONNotifcation);
			this->Controls->Add(this->checkBoxEmailNotification);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->checkboxCellular);
			this->Controls->Add(this->groupBox1);
			this->Name = L"alertSetup";
			this->Text = L" ";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBoxJSONNotifcation->ResumeLayout(false);
			this->groupBoxJSONNotifcation->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Void btnCheckConCellPhone_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void checkBoxEmailNotification_CheckedChanged(System::Object^ sender, System::EventArgs^ e); 
		System::Void btnCheckEmailConnection_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void checkBoxJSONNotification_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSaveTemplateJSONNotification_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnJSONNotificationSendExpremintalMsg_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);

};
}
		
	