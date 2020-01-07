#include "Component.h"
#include "Component.h"

Component::Component(GraphicsInfo* r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;
	m_Label = "Default";
	is_selected = false;
}

Component::~Component()
{}
/*string Component::getLabel() {
	return m_Label;
}
void Component::setLabel(string L) {
	m_Label = L;
}

InputPin* Component::getInput() {
	return nullptr;
}
OutputPin* Component::getOutput() {
	return nullptr;

}*/

