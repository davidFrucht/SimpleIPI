#pragma once

#define  _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include "Header.h"
#include <windows.h>
#include <experimental/filesystem>
#include <list>


namespace Calc {
	//static char temppp[30];



	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace std::experimental::filesystem::v1;
	using namespace std;
	


	/// <summary>
	/// Summary for report
	/// </summary>
	public ref class report : public System::Windows::Forms::Form
	{
	public:
		report(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		
		}

	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~report()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MonthCalendar^ monthCalendar1;
	private: System::Windows::Forms::Label^ lblNoEventsFound;
	private: System::Windows::Forms::TextBox^ txtUserLog;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ btnEventPictureForward;
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->lblNoEventsFound = (gcnew System::Windows::Forms::Label());
			this->txtUserLog = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnEventPictureForward = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->btnBack = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(539, 18);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 1;
			//this->monthCalendar1->DateChanged += gcnew System::Windows::Forms::DateRangeEventHandler(this, &report::monthCalendar1_DateChanged);
			this->monthCalendar1->DateSelected += gcnew System::Windows::Forms::DateRangeEventHandler(this, &report::monthCalendar1_DateSelected);
			// 
			// lblNoEventsFound
			// 
			this->lblNoEventsFound->AutoSize = true;
			this->lblNoEventsFound->ForeColor = System::Drawing::Color::Red;
			this->lblNoEventsFound->Location = System::Drawing::Point(560, 189);
			this->lblNoEventsFound->Name = L"lblNoEventsFound";
			this->lblNoEventsFound->Size = System::Drawing::Size(179, 13);
			this->lblNoEventsFound->TabIndex = 2;
			this->lblNoEventsFound->Text = L"No Events found at the chosen date";
			this->lblNoEventsFound->Visible = false;
			// 
			// txtUserLog
			// 
			this->txtUserLog->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->txtUserLog->Location = System::Drawing::Point(12, 410);
			this->txtUserLog->Multiline = true;
			this->txtUserLog->Name = L"txtUserLog";
			this->txtUserLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtUserLog->Size = System::Drawing::Size(515, 250);
			this->txtUserLog->TabIndex = 3;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(515, 351);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->InitialDirectory = L"c:\\\\log\\\\";
			// 
			// btnEventPictureForward
			// 
			this->btnEventPictureForward->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(177)));
			this->btnEventPictureForward->Location = System::Drawing::Point(452, 369);
			this->btnEventPictureForward->Name = L"btnEventPictureForward";
			this->btnEventPictureForward->Size = System::Drawing::Size(75, 23);
			this->btnEventPictureForward->TabIndex = 5;
			this->btnEventPictureForward->Text = L">";
			this->btnEventPictureForward->UseVisualStyleBackColor = true;
			this->btnEventPictureForward->Click += gcnew System::EventHandler(this, &report::btnEventPictureForward_Click);
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(256, 256);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// btnBack
			// 
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->btnBack->Location = System::Drawing::Point(371, 369);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(75, 23);
			this->btnBack->TabIndex = 7;
			this->btnBack->Text = L"<";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &report::btnBack_Click);
			// 
			// report
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(783, 672);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnEventPictureForward);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->txtUserLog);
			this->Controls->Add(this->lblNoEventsFound);
			this->Controls->Add(this->monthCalendar1);
			this->Name = L"report";
			this->Text = L"report";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		System::Void monthCalendar1_DateSelected(System::Object^ sender, System::Windows::Forms::DateRangeEventArgs^ e);
		System::Void btnEventPictureForward_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e); 
};
}