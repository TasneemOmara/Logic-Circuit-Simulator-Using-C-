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
		int CompCount = stoi(LineToLoad);   //converting the string of the first line into integer

		for (size_t i = 0; i < CompCount; i++)   //looping for the number of components to get the rest of the lines
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
			string Label = CompInfo[1];
			int x1 = stoi(CompInfo[3]);
			int y1 = stoi(CompInfo[4]);
			int x2 = stoi(CompInfo[5]);
			int y2 = stoi(CompInfo[6]);

			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = x1;
			pGInfo->PointsList[0].y = y1;
			pGInfo->PointsList[1].x = x2;
			pGInfo->PointsList[1].y = y2;

			Component* pC = NULL;
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