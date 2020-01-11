#pragma once
#include "Action.h"
#include "../Components/Component.h"

class ExitProgram : public Action
{
private:
	int index;

public:
	ExitProgram(ApplicationManager* App);
	~ExitProgram(void);
	void Execute();

	void Undo();
	void Redo();


};

