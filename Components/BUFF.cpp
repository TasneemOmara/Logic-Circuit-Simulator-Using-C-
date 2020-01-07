#include "BUFF.h"
BUFF::BUFF(GraphicsInfo* r_pGfxInfo, int r_FanOut) :Gate(r_pGfxInfo, 2, r_FanOut) {
	//InputPin* m_InputputPin = new InputPin;
   // m_InputputPin->setComponent(this);
}


//BUFF::BUFF(GraphicsInfo* pGfxInfo) :Component(pGfxInfo)
//{
	//InputPin* m_InputPin = new InputPin;
	//m_InputPin->setComponent(this);
//}


/*void BUFF::SaveComponent(int ID, fstream& fileToSave)
{
	fileToSave << "BUFF" << "	" << ID << "	" << m_Label << "		" << m_pGfxInfo->PointsList[0].x << "		"
		<< m_pGfxInfo->PointsList[0].y << "		" << m_pGfxInfo->PointsList[1].x << "		 " << m_pGfxInfo->PointsList[1].y
		<< endl;
}*/

GraphicsInfo* BUFF::getGraphics()
{
	return m_pGfxInfo;
}
void BUFF::Operate() {



}	//Calculates the output of the AND gate

void BUFF::Draw(UI* pUI) {
	pUI->DrawBuffer(*m_pGfxInfo, is_selected);
}
