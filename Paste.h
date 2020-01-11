#pragma once
#include "Action.h"
#include "../Components/Component.h"
class Paste
{
private:
	Component* mComp;		// Pointer to the pasted component
	Action* mAct;			// Add component action

public:
	/* Constructor */
	Paste(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual bool ReadActionParameters();

	/* Executes action */
	virtual bool Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~Paste();
};










};

