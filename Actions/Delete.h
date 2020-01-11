#pragma once
#include "Action.h"
#include "../Components/Component.h"

class Delete :public Action
{
private:
	int Cx, Cy;
	string choice; //the key entered to take num of comps
	int comp_num_todelete; //number of components to delete in case multiple delete 
	int delete_number;
	string type_deleted;
	
public:

	Delete(ApplicationManager* App, int del = 0);
	void Execute();
	void Undo();
	void Redo();
	void setDeleteInfo(string s);
	string getDeleteInfo();
	virtual ~Delete();
};

