#include "alertsSetup.h"
#include "Header.h"

Calc::alertsSetup::alertsSetup(void){
	InitializeComponent();
};

Calc::alertsSetup::~alertsSetup(){
	if (components){
		delete components;
	}
};

System::Void Calc::alertsSetup::btnCheckConCellPhone_Click(System::Object^ sender, System::EventArgs^ e){
	if(checkConnectionCell() == 1){
		lvlConnectionCell->Visible = true;
	} else {
		lvlConnectionCell->ForeColor = System::Drawing::Color::Red;
		lvlConnectionCell->Text = L"Connection Failed";
		lvlConnectionCell->Visible = true;
	};
};

System::Void Calc::alertsSetup::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e){
		groupBox1->Enabled = true;
		flagCellularAlert = 1;
		int i = int::Parse(comboBoxCellPhone->SelectedItem->ToString());;
		swprintf((ComPortNameAlert) + 7, sizeof(ComPortNameAlert) - 1, L"%d", i);
		//swprintf((ComPortName)+7, sizeof(ComPortName) - 1, L"%d", i);
		/*
		i = int::Parse(cmboBoxBaudCell->SelectedItem->ToString());;
		sprintf(ComPortNameAlert + strlen(ComPortNameAlert), "%d", i);
		*/
		//comboBoxCellPhone
	if( this->checkboxCellular->Checked == false ){
		this->groupBox1->Enabled = false;
		flagCellularAlert = 0;
	}
};
