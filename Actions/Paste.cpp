#include "Paste.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "Select.h"

Paste::Paste(ApplicationManager* pApp): Action(pApp) {

}


void Paste::Execute() {
	Comp = pManager->GetCopiedComp();
	//Act = new AddGate(pManager, Comp->GetAddActionType());
	Act->Execute();
}

void Paste::Undo() {
	
}
void Paste::Redo() {
	
}

Paste::~Paste() {
}