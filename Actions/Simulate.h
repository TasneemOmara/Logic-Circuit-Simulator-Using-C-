#pragma once
#include "Action.h"
#include "../Components/Component.h"

class Simulate : public Action
{
protected:


public:
	Simulate(ApplicationManager* App);
	void Execute();
	void Undo();
	void Redo();

};