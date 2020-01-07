#pragma once
#include "Action.h"
#include <iostream>
#include <fstream>

using namespace std;

class Load : public Action
{

public:
	Load(ApplicationManager* pApp);
	virtual ~Load(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
