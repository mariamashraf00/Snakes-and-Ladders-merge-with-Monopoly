#include "EditCardAction.h"
#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"

#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

EditCardAction::EditCardAction(ApplicationManager *pApp) : Action(pApp), pCard(NULL)
{
}

EditCardAction::~EditCardAction()
{
}

void EditCardAction::ReadActionParameters() 
{	
	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	pOut->PrintMessage( "Select card");
	cardPosition =pIn->GetCellClicked();

	Cell * cellp = pGrid->getCellPointer(cardPosition);

	bool exist = cellp->HasCard();
	if(exist)
	{
		pCard = dynamic_cast<Card*>(cellp->GetGameObject());
		int cardNumber = pCard->GetCardNumber();
	}
	else
	{
		cardNumber=0;
		pOut->PrintMessage( "No card in this cell");
	}
}

void EditCardAction::Execute() 
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if(cardNumber != 0)
	{pCard ->ReadCardParameters(pGrid);
	Output * pOut = pGrid->GetOutput();
	pOut->PrintMessage( "Done!");}
}
