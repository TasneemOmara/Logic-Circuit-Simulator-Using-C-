#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"
#include <fstream>
using namespace std;

class Connection :	public Component
{
	Component*	SrcCmpnt;	//Connection source component
	//Component*	DstCmpnt;	//Connection Destination component
	//int		DstPin;		//The Input pin to which this connection is linked
	
	OutputPin* SrcPin;
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	
	int pin_number;    //the input pin number of the gates that require more than one input, default is one

	static int ConnectionCount; //static variable to store the number of connections to be used in ID declaration


public:
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(GraphicsInfo* r_pGfxInfo,InputPin *pDstPin, Component* SrcCmpnt_val, int pin_number_val);

	void Operate() ;	//Calculates the output according to the inputs
	void Draw(UI* );	//for each component to Draw itself

	
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	void setSrcCmpnt(Component* SrcCmpnt_val);
	OutputPin* getSourcePin();
	InputPin* getDestPin();
	Component* getSrcCmpnt();


	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void SaveComponent(fstream& fileToSave);

	virtual InputPin* getInput();
	virtual OutputPin &getOutput();

	int getConnCount(); //used to set the ID and count the number of created objects

	//virtual functions that has only meaning in gates, so it's an empty here because it's pure virtual function in Component
	virtual void inc_last_pin_input_connected();
	virtual int get_last_pin_input_connected();
	virtual int get_max_Inputs();
};
