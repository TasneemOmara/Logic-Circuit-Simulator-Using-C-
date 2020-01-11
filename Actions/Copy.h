#pragma once
#include "Action.h"
#include "../Components/Component.h"
class Copy :public Action
{public:

	Copy(ApplicationManager* App);
	void Execute();
	void Undo();
	void Redo();
	~Copy();

private:
	//Component*Comp;


};