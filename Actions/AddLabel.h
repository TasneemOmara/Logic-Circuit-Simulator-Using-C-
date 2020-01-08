#pragma once
#include "Action.h"
#include "../Components/Component.h"

class AddLabel : public Action
{
private:
	int index;

public:
	AddLabel(ApplicationManager* App);
	~AddLabel(void);
	void Execute();

	void Undo();
	void Redo();


};

