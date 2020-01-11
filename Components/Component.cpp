#include"../Components/Component.h"


Component::Component(GraphicsInfo* r_GfxInfo, int ID_val, string type , bool isConnection_val)
{
	m_pGfxInfo = r_GfxInfo;
	m_Label = "Default";
	is_selected = false;
	is_full_connect = true;
	is_switch = false;
	State = NotValid;
	ID = ID_val;
	isConnection = isConnection_val;
	CompType = type;
}

Component::~Component()
{}


string Component::GetAddActionType() const
{
	return CompType;
}

GraphicsInfo* Component::getGraphics()
{
	return m_pGfxInfo;
}

void Component::setGraphics(GraphicsInfo* Gp)
{
	m_pGfxInfo = Gp;
}

string Component::getLabel() {
	return m_Label;
}

void Component::setLabel(string L) {
	m_Label = L;
}

void Component::set_selected(bool val)
{
	is_selected = val;
}

/*InputPin* Component::getInput() {
	return nullptr;
}
OutputPin* Component::getOutput() {
	return nullptr;

}*/


bool Component::selected(Point k) {
	int x_min = m_pGfxInfo->PointsList[0].x;
	int x_max = m_pGfxInfo->PointsList[1].x;
	int y_min = m_pGfxInfo->PointsList[0].y;
	int y_max = m_pGfxInfo->PointsList[1].y;
	if (this->isConnection == false)
	{
		if (k.x > x_min&& k.x < x_max && k.y > y_min&& k.y < y_max) {
			is_selected = true;
			return true;
		}
		else
		{
			is_selected = false;
			return false;
		}
	}
	else
	{
		if (k.x > x_min&& k.x < x_max || k.y > y_min&& k.y < y_max) {
			is_selected = true;
			return true;
		}
		else
		{
			is_selected = false;
			return false;
		}
	}
}

bool Component::get_connect_state() {
	return is_full_connect;
}

bool Component::get_switch()
{
	return is_switch;
	
}

int Component::getID()
{
	return ID;
}

bool Component::is_Connection() {
	return isConnection;
}

Component* Component::getSrcCmpnt()
{
	return nullptr; //has no meaning except for connection
}

void Component::setSourcePin(OutputPin* pSrcPin)
{

}
void Component::setDestPin(InputPin* pDstPin)
{

}
void Component::setSrcCmpnt(Component* SrcCmpnt_val)
{

}
void Component::setPinNumber(int n)
{

}

void Component::setSwitchState(Switch_State state)
{

}
Switch_State Component:: getSwitchState()
{
	return NotValid;
}