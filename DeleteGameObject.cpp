#include "DeleteGameObject.h"
#include "Grid.h"
#include "Player.h"
#include "Input.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) :Action(pApp)
{
	
}

void DeleteGameObject::ReadActionParameters()
{
	
}

void DeleteGameObject::Execute()
{
	Grid* Gptr = pManager->GetGrid();
	Input* pIn = Gptr->GetInput();
	Output* pOut = Gptr->GetOutput();
	pOut->PrintMessage("Select Cell");
	CellPosition pos = pIn->GetCellClicked();
	Player* Pptr = Gptr->GetCurrentPlayer();
	Cell* Cptr = Pptr->GetCell();
	Gptr->RemoveObjectFromCell(pos);
	Gptr->UpdateInterface();
	pOut->ClearStatusBar();
}

DeleteGameObject::~DeleteGameObject()
{

}