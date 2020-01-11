#pragma once
#include "Action.h"
#include "../Components/Component.h"

class SwitchToSim : public Action 
{
protected:
	int flag_c;

public:
	SwitchToSim(ApplicationManager* App);
	void Execute();
	void Undo();
	void Redo();
	
};