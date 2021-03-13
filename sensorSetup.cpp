#include "sensorSetup.h"
#include "DFSL_Protocol.h"

#include <sstream>


bool pointInPolygon(float x, float y);

extern char softwareVersion[100];

float polyArrayX[126];
float polyArrayY[126];

int polyCorners;

byte HZAllFlag;
int flag;
int HZCreatedFlag = 0;
int sizeOfArray = 0;
int numOfclicks;
int HZFlagChecked = 0;
char timeHZToBegin[16];
char timeHZToEnd[16];

Calc::sensorSetup::sensorSetup() {
	InitializeComponent();

};

Calc::sensorSetup::~sensorSetup() {
	if (components) {
		delete components;
	};
};



System::Void Calc::sensorSetup::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Calc::advancedSetup();
}

System::Void Calc::sensorSetup::btnGetSensorData_Click(System::Object^ sender, System::EventArgs^ e)
{
	sendToSensor(CMD_GET_SOFTWARE_VERSION);

	sprintf(softwareVersion, "%s", SerialBufferPLS + 7);
	softwareVersion[strlen(softwareVersion) - 2] = '\0';					// deleting checksum.
	System::String^ temp = gcnew System::String(softwareVersion);
	this->txtBoxSoftwareVersion->Text = temp;

	memset(softwareVersion, 0, strlen(softwareVersion));					// clean all string

	sendToSensor(CMD_GET_SERIAL_NUMBER);

	sprintf(softwareVersion, "%s", SerialBufferPLS + 8);
	softwareVersion[strlen(softwareVersion) - 2] = '\0';					// deleting checksum.
	temp = gcnew System::String(softwareVersion);
	this->txtBoxSensorSeialNumber->Text = temp;

	memset(softwareVersion, 0, strlen(softwareVersion));

	sendToSensor(CMD_PARAMETERS);

	array<TextBox^>^ txtArray = gcnew array<TextBox^>{
		textBox0, textBox1, textBox2, textBox3, textBox4, textBox5, textBox6, textBox7, textBox8, textBox9, textBox10, textBox11, textBox12, textBox13
	};
	//TextBox^ txt;

	for (int i = 0, j = 8; i < 7; i++, j+=2)
	{
		if (i == 3)
		{
			sprintf(softwareVersion, "%x%x", SerialBufferPLS[j-1], SerialBufferPLS[j]);
			int x;
			std::stringstream ss;
			ss << std::hex << softwareVersion;
			ss >> x;
			memset(softwareVersion, 0, strlen(softwareVersion));
			sprintf(softwareVersion, "%d", x);
		}
		
		else
		{
			if (j == 20)
				sprintf(softwareVersion, "%u", SerialBufferPLS[j-1]);
			else
				sprintf(softwareVersion, "%u", SerialBufferPLS[j]);
		}
	
		temp = gcnew System::String(softwareVersion);
		txtArray[i]->Text = temp;
		txtArray[i+7]->Text = temp;
		memset(softwareVersion, 0, strlen(softwareVersion));
	}

}

System::Void Calc::sensorSetup::btnResetSensor_Click(System::Object^ sender, System::EventArgs^ e)
{
	sendToSensor(CMD_RESET);
	
	if (SerialBufferPLS[5] == CMD_RESET)
		lblResetOk->Visible = true;

}

System::Void Calc::sensorSetup::btnFullResetSensor_Click(System::Object^ sender, System::EventArgs^ e)
{
	sendToSensor(CMD_FULL_RESET);
	if (SerialBufferPLS[5] == CMD_FULL_RESET)
		lblFullResetOK->Visible = true;
}

System::Void Calc::sensorSetup::sensorSetup_Load(System::Object^ sender, System::EventArgs^ e)
{
	sendToSensor(CMD_GET_SOFTWARE_VERSION);

	sprintf(softwareVersion, "%s", SerialBufferPLS + 7);
	softwareVersion[strlen(softwareVersion) - 2] = '\0';					// deleting checksum.
	System::String^ temp = gcnew System::String(softwareVersion);
	this->txtBoxSoftwareVersion->Text = temp;

	memset(softwareVersion, 0, strlen(softwareVersion));					// clean all string

	sendToSensor(CMD_GET_SERIAL_NUMBER);

	sprintf(softwareVersion, "%s", SerialBufferPLS + 8);
	softwareVersion[strlen(softwareVersion) - 2] = '\0';					// deleting checksum.
	temp = gcnew System::String(softwareVersion);
	this->txtBoxSensorSeialNumber->Text = temp;

	memset(softwareVersion, 0, strlen(softwareVersion));

	sendToSensor(CMD_PARAMETERS);

	array<TextBox^>^ txtArray = gcnew array<TextBox^>{
		textBox0, textBox1, textBox2, textBox3, textBox4, textBox5, textBox6, textBox7, textBox8, textBox9, textBox10, textBox11, textBox12, textBox13
	};
	
	for (int i = 0, j = 8; i < 7; i++, j += 2)
	{
		if (i == 3)
		{
			sprintf(softwareVersion, "%x%x", SerialBufferPLS[j - 1], SerialBufferPLS[j]);
			int x;
			std::stringstream ss;
			ss << std::hex << softwareVersion;
			ss >> x;
			memset(softwareVersion, 0, strlen(softwareVersion));
			sprintf(softwareVersion, "%d", x);
		}

		else
		{
			if (j == 20)
				sprintf(softwareVersion, "%u", SerialBufferPLS[j - 1]);
			else
				sprintf(softwareVersion, "%u", SerialBufferPLS[j]);
		}

		temp = gcnew System::String(softwareVersion);
		txtArray[i]->Text = temp;
		txtArray[i + 7]->Text = temp;
		memset(softwareVersion, 0, strlen(softwareVersion));
	}

}

System::Void Calc::sensorSetup::picBoxRadarHZ_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	
	//static int numOfclicks = 0;
	static int startX, startY, beginsX, beginsY;
	int endX, endY;

	static int i = 0;
	

	if (HZCreatedFlag == 0)
	{
		sizeOfArray++;

		Graphics^ g = picBoxRadarHZ->CreateGraphics();
		numOfclicks++;

		if (numOfclicks % 2 != 0)
		{

			startX = e->X;
			startY = e->Y;
			
			
			if (numOfclicks == 1)
			{
				beginsX = startX;
				beginsY = startY;
			}
		
			polyArrayX[i] = startX;
			polyArrayY[i] = startY;
			i++;
		}

		else
		{
			endX = e->X;
			endY = e->Y;

			g->DrawLine(Pens::OrangeRed, Point(startX, startY), Point(endX, endY));


		}

		if (beginsX - endX <= 3 && beginsX - endX >= -3)
			if (beginsY - endY <= 3 && beginsY - endY >= -3)
			{
				this->checkBoxHZ1->Enabled = true;
				HZCreatedFlag = 1;
			}
	}
}

System::Void picBoxRadarHZ_Click(System::Object^ sender, System::EventArgs^ e)
{
	
}

System::Void Calc::sensorSetup::picBoxRadarHZ_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (HZCreatedFlag == 1)
		pointInPolygon(e->X, e->Y) ? this->lblHZIndicator->Visible = true : this->lblHZIndicator->Visible = false;		
}

bool pointInPolygon(float x, float y) {

	polyCorners = numOfclicks / 2;
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

System::Void Calc::sensorSetup::checkBoxHZ1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->checkBoxHZ1->Checked == true)
		HZFlagChecked = 1;
	else
		HZFlagChecked = 0;
}



