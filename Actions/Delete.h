#pragma once
#include "Action.h"
#include "../Components/Component.h"

class Delete :public Action
{
private:
	int Cx, Cy;
	string choice; //the key entered to take num of comps
	int comp_num_todelete; //number of components to delete in case multiple delete 
	
public:

	Delete(ApplicationManager* App);
	void Execute();
	void Undo();
	void Redo();
	virtual ~Delete();
};

