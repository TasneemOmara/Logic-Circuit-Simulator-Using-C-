#pragma once
#include "Action.h"
#include "../Components/Component.h"

class SwitchToDsn : public Action
{	

public:
	SwitchToDsn(ApplicationManager* App);
	void Execute();
	void Undo();
	void Redo();

};
