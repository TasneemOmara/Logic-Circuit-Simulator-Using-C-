
#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include <iostream>
#include <fstream>

using namespace std;

class Gate :public Component
{
protected:
	//
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin

	int m_Inputs;		//No. of input pins of that Gate.
	static int GatesCount;
	int last_pin_input_connected; //variable to store the last input pin connected, initially it will be zero

public:
	Gate(GraphicsInfo* pGfxInfo, int r_Inputs, int r_FanOut, string type);

	
	virtual InputPin* getInput();
	virtual OutputPin& getOutput();

	static int GetGatesCount();

	virtual void inc_last_pin_input_connected();
	virtual int get_last_pin_input_connected();

	int get_max_Inputs();   //to get the maximum number of input pins

};

#endif
