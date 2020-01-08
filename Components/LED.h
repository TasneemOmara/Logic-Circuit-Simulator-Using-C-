#pragma once
#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include <iostream>
#include <fstream>
using namespace std;

class LED :public Component
{
protected:
	InputPin* m_InputputPin;	//Led has only 1 inputputPin

public:
	LED(GraphicsInfo* r_pGfxInfo);
	void Operate();	//Calculates the output according to the inputs
	void Draw(UI*);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s);//set status of Inputpin # n, to be used by connection class.

	virtual void SaveComponent(int ID, fstream& fileToSave); //save function


};
