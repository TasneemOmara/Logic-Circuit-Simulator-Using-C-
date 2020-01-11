#include "BUFF.h"

BUFF::BUFF(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut, "BUFF" ) {

}



void BUFF::Operate() {
	//Calculates the output of the BUFFER gate
	STATUS n0;
	n0 = m_InputPins[0].getStatus();

	if (n0 == 0)
	{
		m_OutputPin.setStatus(LOW);
		is_full_connect = true;
	}
	else if (n0 == 1)
	{
		m_OutputPin.setStatus(HIGH);
		is_full_connect = true;

	}
	else {
		is_full_connect = false;
	}
	

}	


void BUFF::Draw(UI* pUI) {
	pUI->DrawBuffer(*m_pGfxInfo, is_selected);
}

//returns status of outputpin
int BUFF::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFF::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void BUFF::SaveComponent(fstream& fileToSave)
{
	fileToSave << "BUFF" << "   " << this->getID() << "   " << m_Label << "   " << m_pGfxInfo->PointsList[0].x << "   "
		<< m_pGfxInfo->PointsList[0].y << "   " << m_pGfxInfo->PointsList[1].x << "   " << m_pGfxInfo->PointsList[1].y << endl;
}
