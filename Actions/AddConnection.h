#pragma once
#include "action.h"
#include "..\Components\Connection.h"

class AddConnection :public Action
{
private:
	int cx1, cx2, cy1, cy2;

public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

