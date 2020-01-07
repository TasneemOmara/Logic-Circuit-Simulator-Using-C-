#pragma once
#include "Action.h"
#include "../Components/Component.h"
class Select : public Action
{
private:
	int index;

public:
	Select(ApplicationManager* App);
	void Execute();
	int getIndex();
	void Undo();
	void Redo();


};

