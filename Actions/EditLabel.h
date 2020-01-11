#pragma once
#include "Action.h"
#include "../Components/Component.h"

class EditLabel : public Action
{
private:
	int index;

public:
	EditLabel(ApplicationManager* App);
	~EditLabel(void);
	void Execute();

	void Undo();
	void Redo();


};

