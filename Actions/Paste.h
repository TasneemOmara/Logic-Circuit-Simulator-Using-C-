#include "Action.h"
#include "../Components/Component.h"

class Paste :public Action {
private:
	Component* Comp;		// Pointer to the pasted component
	Action* Act;			// Add component action

public:
	Paste(ApplicationManager* pAppMan);
 void Execute();
 void Undo();
 void Redo();
	 ~Paste();
};






