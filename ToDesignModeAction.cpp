#include "ToDesignModeAction.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) :Action(pApp)
{

}

void ToDesignModeAction::ReadActionParameters()
{

}

void ToDesignModeAction::Execute()
{
	Grid* Gptr = pManager->GetGrid();
	Output* Out = Gptr->GetOutput();
	Out->CreateDesignModeToolBar();
}