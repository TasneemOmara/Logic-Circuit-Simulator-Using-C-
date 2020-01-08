#pragma once
#include "Action.h"
#include "..\Components\Switch.h"

class AddSwitch : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddSwitch(ApplicationManager* pApp);
	~AddSwitch(void);

	//Execute action (code depends on action type)
	void Execute();

	void Undo();
	void Redo();


};