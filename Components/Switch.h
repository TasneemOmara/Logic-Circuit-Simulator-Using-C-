#pragma once

#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include <iostream>
#include <fstream>
using namespace std;

class Switch :public Component
{
protected:
	OutputPin m_OutputPin;	//Switch has only 1 OutputPin
	Switch_State State;
public:
	Switch(GraphicsInfo* pGfxInfo, int r_FanOut);
	void Operate(); //Calculates the output of the AND gate
	void Draw(UI*);


	int GetOutPinStatus();//returns status of outputpin if LED, return -1
	int GetInputPinStatus(int n);//returns status of Inputpin # n if SWITCH, return -1

	void setInputPinStatus(int n, STATUS s);//set status of Inputpin # n, to be used by connection class.

	virtual void SaveComponent(int ID, fstream& fileToSave); //save function

	void setSwitchState(Switch_State state);
	Switch_State getSwitchState();






};

