#pragma once
#include "Action.h"
#include <iostream>
#include <fstream>
using namespace std;

class Save : public Action
{

public:
	Save(ApplicationManager* pApp);
	virtual ~Save(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};
