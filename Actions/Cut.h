#pragma once
#include "Action.h"
#include "../Components/Component.h"
class Cut:public Action
{
private:
	Component* Comp;		// Pointer to the cut component
	Action* mDeleteAct;		// Delete action to delete cut component

public:

	Cut(ApplicationManager* App);
	void Execute();
	 void Undo();
     void Redo();
	virtual ~Cut();
};

