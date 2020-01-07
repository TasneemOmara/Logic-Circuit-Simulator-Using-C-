#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(GraphicsInfo* pGfxInfo, int r_Inputs, int r_FanOut) :Component(pGfxInfo), m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate

	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

bool Gate::selected(Point k) {
	int x_min = m_pGfxInfo->PointsList[0].x;
	int x_max = m_pGfxInfo->PointsList[1].x;
	int y_min = m_pGfxInfo->PointsList[0].y;
	int y_max = m_pGfxInfo->PointsList[1].y;
	if (k.x > x_min && k.x < x_max && k.y>y_min && k.y < y_max) {
		is_selected = true;
		return true;
	}
	else
	{
		is_selected = false;
		return false;
	}
}


//	InputPin* Gate::getInput()
	//{
//		return m_InputPins[0];
	//}

	//OutputPin* Gate::getoutput()
	//{
		//return m_OutputPin;
	//}
