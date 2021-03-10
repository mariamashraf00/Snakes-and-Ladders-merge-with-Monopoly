#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> 

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	
}

void RollDiceAction::Execute()
{
	
	Grid *Gptr=Action::pManager->GetGrid();

	if (Gptr->GetEndGame())
	{
		return;
	}


	else
	{

		srand((int)time(NULL)); 

		unsigned int diceNumber = 1 + rand() % 6;


		Player* Pptr = Gptr->GetCurrentPlayer();



		Pptr->Move(Gptr,diceNumber);



		Gptr->AdvanceCurrentPlayer();


	}
	
}

RollDiceAction::~RollDiceAction()
{
}
