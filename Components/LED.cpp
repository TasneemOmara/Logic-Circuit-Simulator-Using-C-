#include "LED.h"


//r_FanOut: Fan out of the Switch's output pin
LED::LED(GraphicsInfo* pGfxInfo) :Gate(pGfxInfo, 1, 0, "LED")
{
	InputPin* m_InputputPin = new InputPin;
	m_InputputPin->setComponent(this);
}

void  LED::Operate() {

}	//Calculates the output according to the inputs


void LED::Draw(UI* pUI) {
	pUI->DrawLED(*m_pGfxInfo, is_selected);
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}



//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}

void LED::SaveComponent(fstream& fileToSave)
{
	fileToSave << "LED" << "   " << this->getID() << "   " << m_Label << "   " << m_pGfxInfo->PointsList[0].x << "   "
		<< m_pGfxInfo->PointsList[0].y << "   " << m_pGfxInfo->PointsList[1].x << "   " << m_pGfxInfo->PointsList[1].y << endl;
}


//InputPin* Led :: getInput()
//{
	//return m_InputputPin;
//}

//OutputPin* getOutput() {
	//return nullptr;}

