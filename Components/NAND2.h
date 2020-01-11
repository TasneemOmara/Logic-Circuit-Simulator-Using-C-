#pragma once
/*
  Class NAND2
  -----------
  represent the 2-input NAND gate
*/

#include "Gate.h"
#include "../Defs.H"

class NAND2 :public Gate
{
public:

	NAND2(GraphicsInfo* r_pGfxInfo, int r_FanOut);
	void Operate();	//Calculates the output of the AND gate
	void Draw(UI*);	//Draws 2-input gate

	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual void SaveComponent(fstream& fileToSave);


};
