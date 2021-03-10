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

AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters() 
{	
	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	
	pOut->PrintMessage( "Enter card number :");
	int number =pIn->GetInteger(pOut);
	if(number>0 && number<15)
		cardNumber = number;
	else
	{
		pOut->PrintMessage( "Invalid card number");
		cardNumber = 0;
		return ;
	}
	
	pOut->PrintMessage( "Select cell");
	cardPosition =pIn->GetCellClicked();

	pOut-> ClearStatusBar();
}

void AddCardAction::Execute() 
{
	ReadActionParameters();

	Card * pCard = NULL; 
	switch (cardNumber)
	{
	case 0:
		pCard = NULL;
		break;
	case 1:
		pCard = new CardOne(cardPosition);
		break;
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
	case 3:
		pCard = new CardThree(cardPosition);
		break;
	case 4:
		pCard = new CardFour(cardPosition);
		break;
	case 5:
		pCard = new CardFive(cardPosition);
		break;
	case 6:
		pCard = new CardSix(cardPosition);
		break;
	case 7:
		pCard = new CardSeven(cardPosition);
		break;
	case 8:
		pCard = new CardEight(cardPosition);
		break;
	case 9:
		pCard = new CardNine(cardPosition);
		break;
	case 10:
		pCard = new CardTen(cardPosition);
		break;
	case 11:
		pCard = new CardEleven(cardPosition);
		break;
	case 12:
		pCard = new CardTwelve(cardPosition);
		break;
	case 13:
		pCard = new CardThirteen(cardPosition);
		break;
	case 14:
		pCard = new CardFourteen(cardPosition);
		break;

	}

	if (pCard)
	{
		Grid* pGrid = pManager->GetGrid();
	
		pCard->ReadCardParameters(pGrid);
		
		bool add = pGrid->AddObjectToCell(pCard);
		
		if(!add)
		{
			Output* pOut = pGrid->GetOutput();
			pOut->PrintMessage( "Error adding card");}
	}

}