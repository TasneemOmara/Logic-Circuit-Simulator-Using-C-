#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "InputPin.h"
#include "OutputPin.h"
#include <iostream>
#include <String>
using namespace std;

//Base class for classes Gate, Switch, and LED.
class Component
{
	
protected:
	bool is_selected;
	bool is_full_connect;
	bool is_switch;
	Switch_State State;

	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component
	string m_Label;
	int ID;
	bool isConnection;
	string CompType;

public:
	bool selected(Point k);
	Component(GraphicsInfo *r_GfxInfo, int ID_val, string type, bool isConnection_val = false);

	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(UI* ) = 0;	//for each component to Draw itself
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	//Destructor must be virtual
	virtual ~Component();

	virtual void SaveComponent(fstream& fileToSave) = 0; //outputs the line defining the saved component 

	virtual InputPin* getInput() = 0;
	virtual OutputPin &getOutput() = 0;

	virtual GraphicsInfo* getGraphics();
	virtual void setGraphics(GraphicsInfo* Gp);

	string getLabel();
	void setLabel(string L);

	string GetAddActionType() const;
	void set_selected(bool val);
	bool get_connect_state();
	bool get_switch();

	int getID();

	virtual Component* getSrcCmpnt(); //used for connection only
	virtual void setSourcePin(OutputPin* pSrcPin); //used for connection only
	virtual void setDestPin(InputPin* pDstPin); //used for connection only
	virtual void setSrcCmpnt(Component* SrcCmpnt_val); //used for connection only
	virtual void setPinNumber(int n); //used for connection only

	virtual void inc_last_pin_input_connected(int n = 1) = 0;
	virtual int get_last_pin_input_connected() = 0;

	virtual int get_max_Inputs() = 0;

	bool is_Connection();
};

#endif
