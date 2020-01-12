#include"AddConnection.h"
#include "..\ApplicationManager.h"
#include "Select.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp) {
}

AddConnection::~AddConnection(void) {

}

void AddConnection::Execute() {
    //Get a Pointer to the user Interfaces
    UI* pUI = pManager->GetUI();

    pUI->PrintMsg("To edit a connection, type 'E', to add a connection, type 'A' ");
    string choice = pUI->GetSrting(); // get user choice

    if (choice == "A" || choice == "a")
    {
        //get selected
        int selected_index1 = -1;
        int selected_index2 = -1;


        // Initialize two components 
        Component* Comp1 = NULL;
        Component* Comp2 = NULL;

        // create select ptr and execute it to get the first component
        pUI->PrintMsg("Select the first Component");
        int Cx, Cy;
        pUI->GetPointClicked(Cx, Cy);
        Point SelectedP;
        SelectedP.x = Cx;
        SelectedP.y = Cy;
        pUI->setlast_point_clicked(SelectedP);

        Select* pAct = new Select(pManager);
        pAct->Execute();
        selected_index1 = pAct->getIndex();

        //keep asking the user to select if he clicked on the empty space 
        if (selected_index1 == -1)
        {
            pUI->PrintMsg("Please select again the first component");
            pAct->Execute();
            selected_index1 = pAct->getIndex();
        }

        //create select ptr and execute it to get the second component
        pUI->PrintMsg("Select the second Component");

        pUI->GetPointClicked(Cx, Cy);
        SelectedP.x = Cx;
        SelectedP.y = Cy;
        pUI->setlast_point_clicked(SelectedP);

        pAct->Execute();
        selected_index2 = pAct->getIndex();

        //keep asking the user to select if he clicked on the empty space 
        if (selected_index2 == -1)
        {
            pUI->PrintMsg("Please select again the second component");
            pAct->Execute();
            selected_index2 = pAct->getIndex();
        }
        if (selected_index2 != selected_index1)
        {
            // ge the component list and its count
            Component** CompList = pManager->GetComponentList();
            int CompCount = pManager->getCompCount();

            // get the two components
            Comp1 = CompList[selected_index1];
            Comp2 = CompList[selected_index2];


            //get the fanout
            int fanOut = Comp1->getOutput().get_m_FanOut();   //getting the maximum number 
            int actualOut = Comp1->getOutput().get_m_Conn();

            if (actualOut == fanOut)
            {
                pUI->PrintMsg("You exceeded the maximum number of connections to the output of this component, delete a connection then try again");
            }
            else
            {
                //get the input pin number
                int pin_num = Comp2->get_last_pin_input_connected();
                if (pin_num == Comp2->get_max_Inputs())
                {
                    pUI->PrintMsg("This component has maximum number of connections, delete a connection and try again");
                }
                else
                {
                    pin_num += 1;
                    Comp2->inc_last_pin_input_connected();

                    //get the input pin of the second component and the output pin of the first one 
                    InputPin* inpin = Comp2->getInput();

                    //get the points of the two components to draw
                    GraphicsInfo* Comp1_graphics = Comp1->getGraphics();
                    GraphicsInfo* Comp2_graphics = Comp2->getGraphics();
                    Point* C1_pts = Comp1_graphics->PointsList;
                    Point* C2_pts = Comp2_graphics->PointsList;

                    //create graphics info
                    GraphicsInfo* pGInfo = new GraphicsInfo(2);

                    pGInfo->PointsList[0].x = C1_pts[1].x;
                    pGInfo->PointsList[0].y = C1_pts[1].y;
                    pGInfo->PointsList[1].x = C2_pts[0].x;
                    pGInfo->PointsList[1].y = C2_pts[0].y;


                    //create the connection with the first point corresponding to the first component and the second point corresponding to the 
                    //second one 
                    
                    Connection* pC = new Connection(pGInfo, inpin, Comp1, pin_num);
                    pC->setSrcCmpnt(Comp1);
                   
                    //Clear Status Bar
                    pUI->ClearStatusBar();

                    // add the component 
                    pManager->AddComponent(pC);

                }
            }
            delete pAct;
        }
        else
        {
            pUI->PrintMsg("Invalid: You selected the same component, please try again");
        }

    }
    else if (choice == "E" || choice == "e")
    {
        pUI->PrintMsg("Select the connection you want to edit");

        int Cx, Cy;
        pUI->GetPointClicked(Cx, Cy);
        Point SelectedP;
        SelectedP.x = Cx;
        SelectedP.y = Cy;
        pUI->setlast_point_clicked(SelectedP);

        Select* pAct = new Select(pManager);
        pAct->Execute();
        int indx = pAct->getIndex();

        if (indx == -1)
        {
            pUI->PrintMsg("Please select again the connection you want to edit");
            pAct->Execute();
            indx = pAct->getIndex();
        }

        Component** CompList = pManager->GetComponentList();
        int CompCount = pManager->getCompCount();

        Component* ToBeEdited = CompList[indx];

        pUI->PrintMsg("Select the new source component");

        Cx, Cy;
        pUI->GetPointClicked(Cx, Cy);
        SelectedP;
        SelectedP.x = Cx;
        SelectedP.y = Cy;
        pUI->setlast_point_clicked(SelectedP);
        pAct->Execute();

        int indx_src = pAct->getIndex();

        if (indx_src == -1)
        {
            pUI->PrintMsg("Please select again the source component");
            pAct->Execute();
            indx_src = pAct->getIndex();
        }

        Component* source = CompList[indx_src];

        pUI->PrintMsg("Select the destination component");

        Cx, Cy;
        pUI->GetPointClicked(Cx, Cy);
        SelectedP;
        SelectedP.x = Cx;
        SelectedP.y = Cy;
        pUI->setlast_point_clicked(SelectedP);
        pAct->Execute();

        int indx_dst = pAct->getIndex();
        if (indx_dst == -1)
        {
            pUI->PrintMsg("Please select again the destination component");
            pAct->Execute();
            indx_dst = pAct->getIndex();
        }

        if (indx_dst != indx_src)
        {
            ToBeEdited->getInput()->getComponent()->inc_last_pin_input_connected(-1);
            GraphicsInfo* oldInfo = ToBeEdited->getGraphics();
            Component* dst = CompList[indx_dst];
            int pin_num = dst->get_last_pin_input_connected();
            if (pin_num == dst->get_max_Inputs())
            {
                pUI->PrintMsg("This component has maximum number of connections, delete a connection and try again");
            }
            else
            {
                ToBeEdited->setSrcCmpnt(source);
                ToBeEdited->setDestPin(dst->getInput());
                pin_num++;
                ToBeEdited->setPinNumber(pin_num);

                //get the points of the two components to draw
                GraphicsInfo* Src_graphics = source->getGraphics();
                GraphicsInfo* Dst_graphics = dst->getGraphics();
                Point* src_pts = Src_graphics->PointsList;
                Point* dst_pts = Dst_graphics->PointsList;

                //create graphics info
                GraphicsInfo* pGInfo = new GraphicsInfo(2);

                pGInfo->PointsList[0].x = src_pts[1].x;
                pGInfo->PointsList[0].y = src_pts[1].y;
                pGInfo->PointsList[1].x = dst_pts[0].x;
                pGInfo->PointsList[1].y = dst_pts[0].y;

                ToBeEdited->setGraphics(pGInfo);
                pUI->DeleteConnection(*oldInfo);

            }

        }
        else
        {
            pUI->PrintMsg("Invalid: You selected the same component, please try again");   
        }
    }
    else
    {
        pUI->PrintMsg("Your choice is invalid, try again");
    }
 }

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

