#pragma once


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"
#include "Gate.h"

class BUFF :public Gate
{
protected:

public:
	//BUFF(GraphicsInfo* pGfxInfo);
	BUFF(GraphicsInfo* pGfxInfo, int r_FanOut);

	void Operate();	//Calculates the output of the AND gate
	void Draw(UI*);	//Draws 2-input gate

	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual void SaveComponent(fstream& fileToSave);



};