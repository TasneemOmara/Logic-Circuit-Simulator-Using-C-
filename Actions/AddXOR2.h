#pragma once
#include "Action.h"
#include "..\Components\XOR2.h"

class AddXOR2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddXOR2(ApplicationManager* pApp);
	~AddXOR2(void);

	//Execute action (code depends on action type)
	void Execute();

	void Undo();
	void Redo();


};