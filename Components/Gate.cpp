#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin

int Gate::GatesCount = 0;

Gate::Gate(GraphicsInfo* pGfxInfo, int r_Inputs, int r_FanOut, string type) :Component(pGfxInfo, (Gate::GetGatesCount()), type), m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate

	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++)
		m_InputPins[i].setComponent(this);
	
	GatesCount += 1;
	last_pin_input_connected = 0;
}



InputPin* Gate::getInput() {
	return m_InputPins;
}

OutputPin& Gate::getOutput() {
	return m_OutputPin;
}

int Gate::GetGatesCount() {
	return GatesCount;
}

void Gate::inc_last_pin_input_connected()
{
	last_pin_input_connected++;
}

int Gate::get_last_pin_input_connected()
{
	return last_pin_input_connected;
}

int Gate::get_max_Inputs()
{
	return m_Inputs;
}