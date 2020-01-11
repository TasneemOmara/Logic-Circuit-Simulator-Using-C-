#pragma once
#include "Action.h"
#include "../Components/Component.h"

class Delete :public Action
{
private:


public:

	Delete(ApplicationManager* App);
	void Execute();
	void Undo();
	void Redo();
	virtual ~Delete();
};

