


#include "alertSetup.h"
#include "Header.h"
#include "AT_SMS.h"
#include "connectToCom.h"
#include "sendMail.h"
#include "MyForm.h"
#include "json.h"

#include <iostream>
#include <string.h>
#include <windows.h>
#include <msports.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>

HANDLE hCommAlert;
BOOL  StatusAlert2;
DWORD dwEventMaskAlert2;
char  TempCharAlert2;
char  SerialBufferAlert2[256];
DWORD NoBytesReadAlert2;
int cntMessagesAlert = 0;
char bufferAlert[256];
int checkSumAlert = 0;
char* ptrAlert;
int tempAlert;
int flagAlert = 0;
int Calc::ComAlert;


char* FromChar;
char* ToChar;
char* SMTPChar;
char* UserNameChar;
char* passwordChar;

char* JSONUrl;


using namespace Calc;

std::string Calc::phoneNumberStr;

#define SEND_MAIL_OK 0

Calc::alertSetup::alertSetup(void) {
	InitializeComponent();
};

Calc::alertSetup::~alertSetup() {
	if (components) {
		delete components;
	}
};


System::Void Calc::alertSetup::btnCheckConCellPhone_Click(System::Object^ sender, System::EventArgs^ e)
{
	Calc::ComAlert = int::Parse(comboBoxCellPhone->SelectedItem->ToString());

	System::String^ phoneNumberManagedStr = this->txtPhoneNumber->Text;
	Calc::phoneNumberStr = static_cast<const char*>(Marshal::StringToHGlobalAnsi(phoneNumberManagedStr).ToPointer());

	if (checkConnectionCell() == 1) {
		lvlConnectionCell->Visible = true;
	}
	else {
		lvlConnectionCell->ForeColor = System::Drawing::Color::Red;
		lvlConnectionCell->Text = L"Connection Failed";
		lvlConnectionCell->Visible = true;
	}
};

System::Void Calc::alertSetup::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	groupBox1->Enabled = true;
	flagCellularAlert = 1;

	if (this->checkboxCellular->Checked == false) {
		this->groupBox1->Enabled = false;
		flagCellularAlert = 0;
	}
};

System::Void Calc::alertSetup::btnSaveTemplateJSONNotification_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Calc::alertSetup as;
	//File::WriteAllText(L"c:\\1\\jsonTemplate.txt", txtJSONNotificationTemplate->Text);
}

System::Void Calc::alertSetup::checkBoxEmailNotification_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	groupBox2->Enabled = true;
	flagEmailAlert = 1;

	if (this->checkBoxEmailNotification->Checked == false) {
		this->groupBox2->Enabled = false;
		flagEmailAlert = 0;
	}

}

System::Void Calc::alertSetup::checkBoxJSONNotification_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	groupBoxJSONNotifcation->Enabled = true;
	flagJSONAlert = 1;

	if (this->checkBoxJSONNotification->Checked == false) {
		this->groupBoxJSONNotifcation->Enabled = false;
		flagJSONAlert = 0;
	}

	System::String^ jsonURLstr = textBox1->Text;
	JSONUrl = (char*)(void*)Marshal::StringToHGlobalAnsi(jsonURLstr);
	
}

System::Void Calc::alertSetup::btnCheckEmailConnection_Click(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ FromStr = txtBoxFromEmailAddress->Text;
	System::String^ ToStr = txtBoxToEmailAddress->Text;
	System::String^ SMTPStr = txtBoxSMTPServer->Text;
	System::String^ userNameStr = TxtBoxUserName->Text;
	System::String^ passwordStr = txtBoxPasswordEmail->Text;
	
	FromChar = (char*)(void*)Marshal::StringToHGlobalAnsi(FromStr);
	ToChar = (char*)(void*)Marshal::StringToHGlobalAnsi(ToStr);
	SMTPChar = (char*)(void*)Marshal::StringToHGlobalAnsi(SMTPStr);
	UserNameChar = (char*)(void*)Marshal::StringToHGlobalAnsi(userNameStr);
	passwordChar = (char*)(void*)Marshal::StringToHGlobalAnsi(passwordStr);


	if (sendMailSMTP(FromChar, ToChar, SMTPChar, UserNameChar, passwordChar, 0, 0) == SEND_MAIL_OK)
		lblEmailConnectionSuccesful->Visible = true;

}

System::Void Calc::alertSetup::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	System::String^ jsonURLstr = textBox1->Text;
	JSONUrl = (char*)(void*)Marshal::StringToHGlobalAnsi(jsonURLstr);

}

System::Void Calc::alertSetup::btnJSONNotificationSendExpremintalMsg_Click(System::Object^ sender, System::EventArgs^ e) 
{
	sendJSON("{\"type\":\"Intruder Detected\",\"Range\":\"0\",\"Azimuth\":\"0\"}", JSONUrl);
}

void Calc::initCellPhone() {

	hCommAlert = connectCom(Calc::ComAlert, 19200);					// function is in ConnectToCom.h

}

int Calc::checkConnectionCell() {
	initCellPhone();

	char lpBufferAlert[] = { "AT\r" };

	flagAlert = 0;

	DWORD  dNoOFBytestoWriteAlert;
	DWORD  dNoOfBytesWrittenAlert = 0;

	dNoOFBytestoWriteAlert = sizeof(lpBufferAlert);

	StatusAlert2 = WriteFile(hCommAlert,               
		lpBufferAlert,								  
		dNoOFBytestoWriteAlert,						  
		&dNoOfBytesWrittenAlert,				      
		NULL);

	Sleep(1000);

	StatusAlert2 = WaitCommEvent(hCommAlert, &dwEventMaskAlert2, NULL);

	if (StatusAlert2 == FALSE)
	{
		printf("\n    Error! in Setting WaitCommEvent()");
	}
	else
	{
		cntMessagesAlert = 0;
		do
		{
			StatusAlert2 = ReadFile(hCommAlert, &TempCharAlert2, sizeof(TempCharAlert2), &NoBytesReadAlert, NULL);

			SerialBufferAlert2[cntMessagesAlert] = TempCharAlert2;

			cntMessagesAlert++;

		} while (NoBytesReadAlert > 0);

		CloseHandle(hCommAlert);

		if (strstr(SerialBufferAlert2, "OK") != NULL)
			return 1;

	}
	return 0;
}

void Calc::detecionCellAlert() {

	char pNumber[20];
	char message[120] = "Intruder Detected at ";

	strcpy(pNumber, phoneNumberStr.c_str());

	sprintf(message + strlen(message), "azimuth %.2f range %.2f \x1A", azimuth, range);


	initCellPhone();

	sendSMS(hCommAlert, pNumber, message);								// functoin is in AT_SMS.h

}





