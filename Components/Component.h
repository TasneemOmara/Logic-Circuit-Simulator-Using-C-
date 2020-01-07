#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
	
protected:
	bool is_selected;
	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component
	string m_Label;

public:
	virtual bool selected(Point k) = 0;
	Component(GraphicsInfo *r_GfxInfo);

	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(UI* ) = 0;	//for each component to Draw itself
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	//Destructor must be virtual
	virtual ~Component();

	virtual void SaveComponent(int ID, fstream& fileToSave) = 0; //outputs the line defining the saved component 

	//InputPin* getInput();
	//OutputPin* getOutput();

	GraphicsInfo* getGraphics();

	string getLabel();
	void setLabel(string L);


	void set_selected(bool val);

};

#endif
