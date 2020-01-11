#include "XNOR2.h"

XNOR2::XNOR2(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut, "XNOR2")
{
}


void XNOR2::Operate()
{
	//caclulate the output status as the XNORing of the two input pins
	STATUS n0, n1;
	n0 = m_InputPins[0].getStatus();
	n1 = m_InputPins[1].getStatus();

	if ((n0 == 0 && n1 == 0) || (n0 == 1 && n1 == 1))
	{
		m_OutputPin.setStatus(HIGH);
		is_full_connect = true;
	}
	else if (n0 == 2 || n1 == 2)
	{
		m_OutputPin.setStatus(NCON);
		is_full_connect = false;
	}
	else {
		m_OutputPin.setStatus(LOW);
		is_full_connect = true;
	}

	//Add you code here
}


// Function Draw
// Draws 2-input XNOR2 gate
void XNOR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawXNOR2(*m_pGfxInfo, is_selected);
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}


void XNOR2::SaveComponent(fstream& fileToSave)
{
	fileToSave << "XNOR2" << "   " << this->getID() << "   " << m_Label << "   " << m_pGfxInfo->PointsList[0].x << "   "
		<< m_pGfxInfo->PointsList[0].y << "   " << m_pGfxInfo->PointsList[1].x << "   " << m_pGfxInfo->PointsList[1].y << endl;
}
