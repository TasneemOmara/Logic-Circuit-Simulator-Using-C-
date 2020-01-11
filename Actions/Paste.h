#include "Action.h"
#include "../Components/Component.h"

class Paste :public Action {
private:
	Component* Comp;		// Pointer to the pasted component
	
public:
	Paste(ApplicationManager* pAppMan);
 void Execute();
 void Undo();
 void Redo();
	 ~Paste();
};






