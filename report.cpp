#define  _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING


#include "report.h"
#include "Header.h"
#include "sendMail.h"

using namespace Calc;

int pictureNumber;

ref class ManagedGlobals {
public:
	static cli::array <System::String^>^ GalleryArray = nullptr;
};


System::Void Calc::report::monthCalendar1_DateSelected(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e) {

	this->txtUserLog->Text = "";
	this->btnEventPictureForward->Enabled = true;
	System::String^ date = this->monthCalendar1->SelectionRange->Start.ToString();
	std::string dateStr = static_cast<const char*>(Marshal::StringToHGlobalAnsi(date).ToPointer());
	char dateChar[128] = "c:\\SimpleIPI\\REPORT\\";
	sprintf(dateChar + strlen(dateChar), dateStr.c_str());

	// deleting the time

	for (int i = 0; dateChar[i] != '\0'; i++)
		if (dateChar[i] == ' ')
			dateChar[i] = '\0';

	for (int i = 0; dateChar[i] != '\0'; i++)
		if (dateChar[i] == '/')
			dateChar[i] = '-';

	//char temp[128];

	//strcpy(temp, dateChar);
	//strcpy(temp2, dateChar);

	const char* dir = dateChar;

	// check if an event happend at the requested day by checking if an event directory exsist

	DWORD ftyp = GetFileAttributesA(dir);
	if (ftyp != INVALID_FILE_ATTRIBUTES && ftyp & FILE_ATTRIBUTE_DIRECTORY)
	{
		//strcpy(temp2, dir);
		this->lblNoEventsFound->Visible = false;
		System::String^ directory = gcnew System::String(dir);

		// loadong log.txt to the userLog text box

		sprintf(dateChar + strlen(dateChar), "\\log.txt");
		System::String^ textStr = gcnew System::String(dir);
		this->openFileDialog1->FileName = textStr;
		this->txtUserLog->Text += (System::IO::File::ReadAllText(openFileDialog1->FileName));

		// loading pictures to the picturebox
		
		ManagedGlobals::GalleryArray = System::IO::Directory::GetFiles(directory, "*.png");
		
		pictureNumber = 0;
		pictureBox1->Load(ManagedGlobals::GalleryArray[pictureNumber]);
	}
	
	else
	{
		this->lblNoEventsFound->Visible = true;
	}

}

System::Void Calc::report::btnEventPictureForward_Click(System::Object^ sender, System::EventArgs^ e)
{
	pictureNumber++;

	if (pictureNumber == ManagedGlobals::GalleryArray->Length)
	{
		this->btnBack->Enabled = true;
		this->btnEventPictureForward->Enabled = false;
	}

	if (pictureNumber < ManagedGlobals::GalleryArray->Length)
	{
		this->btnEventPictureForward->Enabled = true;
		pictureBox1->Load(ManagedGlobals::GalleryArray[pictureNumber]);
	}

}

System::Void Calc::report::btnBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	pictureNumber--;

	if (pictureNumber == 0)
	{
		this->btnEventPictureForward->Enabled = true;
		this->btnBack->Enabled = false;
	}

	if (pictureNumber > 0)
	{
		this->btnBack->Enabled = true;
		pictureBox1->Load(ManagedGlobals::GalleryArray[pictureNumber]);
	}

	if (pictureNumber < ManagedGlobals::GalleryArray->Length)
	{
		this->btnEventPictureForward->Enabled = true;
		pictureBox1->Load(ManagedGlobals::GalleryArray[pictureNumber]);
	}
	
}

