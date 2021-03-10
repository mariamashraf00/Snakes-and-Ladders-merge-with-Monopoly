#include "NewGame.h"
#include "Grid.h"
#include "Player.h"


NewGame::NewGame(ApplicationManager* pApp) :Action(pApp)
{

}

void NewGame::ReadActionParameters()
{

}

void NewGame::Execute()
{
	Grid* Gptr = pManager->GetGrid();
	Output * pOut = Gptr->GetOutput();
	Gptr->ResetPlayers();
	Gptr->UpdateInterface();
	pOut->ClearStatusBar();

}

NewGame::~NewGame()
{

}