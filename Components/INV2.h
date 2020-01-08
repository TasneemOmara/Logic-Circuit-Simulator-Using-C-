#pragma once 

/*
  Class INV2
  -----------
  represent the 2-input INV2 gate
*/

#include "Gate.h"
#include "../Defs.H"

class INV2 :public Gate
{
public:

	INV2(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	void Operate();	//Calculates the output of the INV2 gate
	void Draw(UI*);	//Draws 2-input gate

	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual void SaveComponent(int ID, fstream& fileToSave);


};
