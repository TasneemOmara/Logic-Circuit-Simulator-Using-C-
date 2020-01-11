#include "Load.h"
#include "..\ApplicationManager.h"
#include "../Components/AND2.h"
#include "../Components/BUFF.h"
#include "../Components/INV2.h"
#include "../Components/LED.h"
#include "../Components/NAND2.h"
#include "../Components/NOR2.h"
#include "../Components/OR2.h"
#include "../Components/Switch.h"
#include "../Components/XNOR2.h"
#include "../Components/XOR2.h"
#include "../Components/Connection.h"

Load::Load(ApplicationManager* pApp) : Action(pApp) {
}

Load::~Load(void) {

}

void Load::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Loading Last Saved File");
	fstream fileToLoad("SavedCircuit.txt", ios::in);

	if (fileToLoad.is_open())
	{
		string LineToLoad = "";    //line to store every component 
		getline(fileToLoad, LineToLoad); //getting the first line from the file
		int GatesCount = stoi(LineToLoad);   //converting the string of the first line into integer
		Component* pC = NULL;

		for (size_t i = 0; i < GatesCount; i++)   //looping for the number of components to get the rest of the lines
		{
			getline(fileToLoad, LineToLoad);   //for every component, get the line in string 
			string CompInfo[7];                //array of strings to store the loaded words in 

			string input = "";                 //string to store every input word in to be stored later in the array of strings
			int spaceCounts = 0;
			int j = 0;
			for (auto x : LineToLoad)          // looping for every input in the line
			{
				if (x == ' ' && spaceCounts == 2)
				{
					CompInfo[j++] = input;         //if the iterator is empty space, store the input in the array of strings then add one
					input = "";
					spaceCounts = 0;
				}
				else if (x == ' ' && spaceCounts < 3)
				{
					spaceCounts++;
				}
				else
				{
					input = input + x;
				}
			}
			CompInfo[j++] = input;

			string compType = CompInfo[0];
			string Label = CompInfo[2];
			int x1 = stoi(CompInfo[3]);
			int y1 = stoi(CompInfo[4]);
			int x2 = stoi(CompInfo[5]);
			int y2 = stoi(CompInfo[6]);

			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = x1;
			pGInfo->PointsList[0].y = y1;
			pGInfo->PointsList[1].x = x2;
			pGInfo->PointsList[1].y = y2;

			
			if (compType == "AND2")
			{
				pC = new AND2(pGInfo, AND2_FANOUT);
			}
			else if (compType == "BUFF")
			{
				pC = new BUFF(pGInfo, BUFF_FANOUT);
			}
			else if (compType == "INV2")
			{
				pC = new INV2(pGInfo, INV2_FANOUT);
				
			}
			else if (compType == "LED")
			{
				pC = new LED(pGInfo);
			}
			else if (compType == "NAND2")
			{
				pC = new NAND2(pGInfo, NAND2_FANOUT);
			}
			else if (compType == "NOR2")
			{
				pC = new NOR2(pGInfo, NOR2_FANOUT);
			}
			else if (compType == "OR2")
			{
				pC = new OR2(pGInfo, OR2_FANOUT);
			}
			else if (compType == "Switch")
			{
				pC = new Switch(pGInfo, Switch_FANOUT);
			}
			else if (compType == "XNOR2")
			{
				pC = new XNOR2(pGInfo, XNOR2_FANOUT);
			}
			else if (compType == "XOR2")
			{
				pC = new XOR2(pGInfo, XOR2_FANOUT);
			}

			pC->setLabel(Label);

			pManager->AddComponent(pC);
		}

		Component** CompList = pManager->GetComponentList();
		
		getline(fileToLoad, LineToLoad);
		getline(fileToLoad, LineToLoad);
		int ConectCount = stoi(LineToLoad);
		for (size_t i = 0; i < ConectCount; i++)
		{
			getline(fileToLoad, LineToLoad);   //for every component, get the line in string 
			string CompInfo[3];                //array of strings to store the loaded words in 

			string input = "";                 //string to store every input word in to be stored later in the array of strings
			int spaceCounts = 0;
			int j = 0;
			for (auto x : LineToLoad)          // looping for every input in the line
			{
				if (x == ' ' && spaceCounts == 2)
				{
					CompInfo[j++] = input;         //if the iterator is empty space, store the input in the array of strings then add one
					input = "";
					spaceCounts = 0;
				}
				else if (x == ' ' && spaceCounts < 3)
				{
					spaceCounts++;
				}
				else
				{
					input = input + x;
				}
			}
			CompInfo[j++] = input;

			int ID1 = stoi(CompInfo[0]);
			int ID2 = stoi(CompInfo[1]);
			int pin_num = stoi(CompInfo[2]);
			Component* Src = nullptr;
			Component* Trgt = nullptr;

			int CompCount = pManager->getCompCount();
			for (size_t i = 0; i < CompCount; i++)
			{
				if (CompList[i]->getID() == ID1)
				{
					Src = CompList[i];
				}

				else if (CompList[i]->getID() == ID2)
				{
					Trgt = CompList[i];
				}
			}

			Trgt->inc_last_pin_input_connected();
			//get the input pin of the second component and the output pin of the first one 
			InputPin* inpin = Src->getInput();

			//get the points of the two components to draw
			GraphicsInfo* Src_graphics = Src->getGraphics();
			GraphicsInfo* Trgt_graphics = Trgt->getGraphics();
			Point* C1_pts = Src_graphics->PointsList;
			Point* C2_pts = Trgt_graphics->PointsList;

			//create graphics info
			GraphicsInfo* pGInfo = new GraphicsInfo(2);

			pGInfo->PointsList[0].x = C1_pts[0].x;
			pGInfo->PointsList[0].y = C1_pts[0].y;
			pGInfo->PointsList[1].x = C2_pts[1].x;
			pGInfo->PointsList[1].y = C2_pts[1].y;


			//create the connection with the first point corresponding to the first component and the second point corresponding to the 
			//second one 
			Connection* pC = new Connection(pGInfo, inpin, Src, pin_num);
			pManager->AddComponent(pC);
		}

	}
	else
	{
		pUI->PrintMsg("Unable to open the file");
	}
	
	fileToLoad.close();
}


void Load::Undo() {};
void Load::Redo() {};