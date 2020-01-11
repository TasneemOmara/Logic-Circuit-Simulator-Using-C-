#pragma once

/*
  Class XNOR2
  -----------
  represent the 2-input XNOR2 gate
*/

#include "Gate.h"
#include "../Defs.H"

class XNOR2 :public Gate
{
public:

	XNOR2(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	void Operate();	//Calculates the output of the XNOR2 gate
	void Draw(UI*);	//Draws 2-input gate

	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual void SaveComponent(fstream& fileToSave);


};

