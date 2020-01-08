#include "Switch.h"


//r_FanOut: Fan out of the Switch's output pin
Switch::Switch(GraphicsInfo* pGfxInfo, int r_FanOut) :Component(pGfxInfo), m_OutputPin(r_FanOut)
{

}


void Switch::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, is_selected);
}

void Switch::Operate() {

}	//Calculates the output according to the inputs


//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
}


void Switch::SaveComponent(int ID, fstream& fileToSave)
{
	fileToSave << "Switch" << "   " << ID << "   " << m_Label << "   " << m_pGfxInfo->PointsList[0].x << "   "
		<< m_pGfxInfo->PointsList[0].y << "   " << m_pGfxInfo->PointsList[1].x << "   " << m_pGfxInfo->PointsList[1].y << endl;
}


//InputPin* Switch::getInput() {
   //return nullptr;
//}

 //OutputPin* Switch::getOutput() {

//}

