#include "InputDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include "Input.h"
#include "Output.h"

InputDiceAction::InputDiceAction(ApplicationManager* pApp) : Action(pApp)
{
	Gptr = pApp->GetGrid();
	pIn = Gptr->GetInput();
	pOut = Gptr->GetOutput();
	Execute();
}

void InputDiceAction::ReadActionParameters() 
{
	pOut->PrintMessage("Input dice value between 1 and 6");
	diceNum = pIn->GetInteger(pOut);
	if (diceNum >= 1 && diceNum <= 6)
		diceNum = diceNum;
	else {
		diceNum = 0;
		Grid* Gptr = Action::pManager->GetGrid();
		Gptr->PrintErrorMessage("Invalid input of Dice number,please input another value");
		ReadActionParameters();
	}
}

void InputDiceAction::Execute()
{
	if (Gptr->GetEndGame())
	{
		Gptr->PrintErrorMessage("Click New Game to restart the game ...");
		return;
	}

	ReadActionParameters();
	Player *pPlayer=Gptr->GetCurrentPlayer();
	pPlayer->Move(Gptr, diceNum);
	Gptr->UpdateInterface();
	pOut->ClearStatusBar();
	Gptr->AdvanceCurrentPlayer();
}

InputDiceAction::~InputDiceAction()
{

}

