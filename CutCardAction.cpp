#include "CutCardAction.h"
#include "Output.h"
#include "Input.h"
#include"Grid.h"
#include "Card.h"
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

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Select the card you wish to cut");
	cardPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();

}

void CutCardAction::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	ReadActionParameters();

	if (cardPosition.IsValidCell() == false)
	{
		pOut->PrintMessage("Invalid Cell");
		return;
	}

	Cell* pCell = pGrid->getCellPointer(cardPosition);
	Card* existingcard = pCell->HasCard();
	if (existingcard == NULL)
	{
		pOut->PrintMessage("Cell has no card");
		return;
	}

	Card* newcard;
	
	int cardnum= existingcard->GetCardNumber();
	
	switch (cardnum)
	{
	case 1:
		newcard = new CardOne(-1);
		
		
		break;

	case 2:
		newcard = new CardTwo(-1);

		break;

	case 3:
		newcard = new CardThree(-1);

		break;

	case 4:
		newcard = new CardFour(-1);

		break;

	case 5:
		newcard = new CardFive(-1);

		break;

	case 6:
		newcard = new CardSix(-1);
	
		break;

	case 7:
		newcard = new CardSeven(-1);
		
		break;

	case 8:
		newcard = new CardEight(-1);
		
		break;

	case 9:
		newcard = new CardNine(-1);
		
		break;
	case 10:
		newcard = new CardTen(-1);
		
		break;

	case 11:
		newcard = new CardEleven(-1);
		
		break;

	case 12:
		newcard = new CardTwelve(-1);
		
		break;

	case 13:
		newcard = new CardThirteen(-1);
		
		break;

	case 14:
		newcard = new CardFourteen(-1);
		
		break;
	}
	
	newcard->setinfo1(existingcard->getinfo1());




	pGrid->SetClipboard(newcard);
	pGrid->RemoveObjectFromCell(cardPosition);
	pOut->PrintMessage("Clipboard now carries the selected card");

	pOut->ClearStatusBar();

	
}
