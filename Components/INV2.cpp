#include "INV2.h"

INV2::INV2(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut, "INV2")
{
}


void INV2::Operate()
{
	//caclulate the output status as the INVerting of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input INV2 gate
void INV2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawINV(*m_pGfxInfo, is_selected);
}

//returns status of outputpin
int INV2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INV2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}


void INV2::SaveComponent(fstream& fileToSave)
{
	fileToSave << "INV2" << "   " << this->getID() << "   " << m_Label << "   " << m_pGfxInfo->PointsList[0].x << "   "
		<< m_pGfxInfo->PointsList[0].y << "   " << m_pGfxInfo->PointsList[1].x << "   " << m_pGfxInfo->PointsList[1].y << endl;
}
