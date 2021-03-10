#include "ToPlayModeAction.h"


ToPlayModeAction::ToPlayModeAction(ApplicationManager* pApp) :Action(pApp)
{

}

void ToPlayModeAction::ReadActionParameters()
{

}

void ToPlayModeAction::Execute()
{
	Grid* Gptr = pManager->GetGrid();
	Output* Out = Gptr->GetOutput();
	Out->CreatePlayModeToolBar();
}
