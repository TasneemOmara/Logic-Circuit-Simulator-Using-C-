#pragma once
#include "../Actions/Action.h"
#include "../Components/Component.h"

class ChangeSwitch : public Action
{
public:
	ChangeSwitch(ApplicationManager* pApp);
	void Execute();
	void Undo();
	void Redo();
};
