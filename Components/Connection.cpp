#include "Connection.h"
int Connection::ConnectionCount = 0;

Connection::Connection(GraphicsInfo* r_pGfxInfo, InputPin *pDstPin, Component* SrcCmpnt_val, int pin_number_val): Component(r_pGfxInfo, (Connection::getConnCount()), "Connection" , true)
{
	DstPin = pDstPin;
	SrcCmpnt = SrcCmpnt_val;
	ConnectionCount += 1;
	pin_number = pin_number_val;
	SrcPin = &(SrcCmpnt->getOutput());
	SrcPin->ConnectTo(this);
}

void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
	if (DstPin->getStatus() == NCON)
	{
		is_full_connect = false;
	}
	else {
		is_full_connect = true;
	}
	
}

void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*m_pGfxInfo, is_selected);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::SaveComponent(fstream& fileToSave)
{
	fileToSave << SrcCmpnt->getID() << "   " << (DstPin->getComponent())->getID() << "   " << pin_number  << endl;
}

InputPin* Connection::getInput()
{
	return DstPin;
}

OutputPin& Connection::getOutput()
{
	return *SrcPin;
}

void Connection::setSrcCmpnt(Component* SrcCmpnt_val)
{
	SrcCmpnt = SrcCmpnt_val;
	SrcPin = &(SrcCmpnt->getOutput());
	SrcPin->ConnectTo(this);
}

Component* Connection::getSrcCmpnt()
{
	return SrcCmpnt;
}

int Connection::getConnCount() {
	return ConnectionCount;
}

void Connection::setPinNumber(int n) {
	pin_number = n;
}
//virtual functions that has only meaning in gates, so it's an empty here because it's pure virtual function in Component
void Connection::inc_last_pin_input_connected(int n)
{

}
int Connection::get_last_pin_input_connected()
{
	return -1;   //because it has no meaning
}
int Connection::get_max_Inputs()
{
	return -1;  //because it has no meaning
}

