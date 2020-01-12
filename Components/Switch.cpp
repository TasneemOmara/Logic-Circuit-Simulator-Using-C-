#include "Switch.h"
#include "../UI/UI.h"


//r_FanOut: Fan out of the Switch's output pin
Switch::Switch(GraphicsInfo* pGfxInfo, int r_FanOut) :Gate(pGfxInfo, 0 , r_FanOut, "Switch")
{
	is_switch = true;
	State = OFF;
	m_OutputPin.setStatus(HIGH);
}


void Switch::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	if (pUI->AppMode == SIMULATION)
	{ 
		pUI->DrawSwitch(*m_pGfxInfo, is_selected, State);
	}
	else
	{
		pUI->DrawSwitch(*m_pGfxInfo, is_selected);
	}
}

void Switch::Operate() {
	//Calculates the output according to the inputs
	
	if (State == ON)
	{
		m_OutputPin.setStatus(HIGH);
		this->setLabel("ON");
	}
	else
	{
		m_OutputPin.setStatus(LOW);
		this->setLabel("OFF");
	}
}	


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


void Switch::SaveComponent(fstream& fileToSave)
{
	fileToSave << "Switch" << "   " << this->getID() << "   " << m_Label << "   " << m_pGfxInfo->PointsList[0].x << "   "
		<< m_pGfxInfo->PointsList[0].y << "   " << m_pGfxInfo->PointsList[1].x << "   " << m_pGfxInfo->PointsList[1].y << endl;
}


void Switch::setSwitchState(Switch_State state)
{
	State = state;
}
Switch_State Switch::getSwitchState()
{
	return State;
}

//InputPin* Switch::getInput() {
   //return nullptr;
//}

 //OutputPin* Switch::getOutput() {

//}

