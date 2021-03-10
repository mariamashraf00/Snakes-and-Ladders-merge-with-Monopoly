#include "PasteCardAction.h"

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

PasteCardAction::PasteCardAction(ApplicationManager *pApp) : Action(pApp)
{
}

PasteCardAction::~PasteCardAction()
{
}

void PasteCardAction::ReadActionParameters() 
{	
	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	
	pOut->PrintMessage( "Select the cell you wish to paste the card to");
	cardPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();

}

void PasteCardAction::Execute() 
{

	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	ReadActionParameters();

	Card* copiedcard = pGrid->GetClipboard();
	Cell* pCell=pGrid->getCellPointer(cardPosition);



	if (pGrid->GetClipboard()==NULL)
	{
		pOut->PrintMessage( "Choose a card to copy first");
		return;
	}
	if (cardPosition.IsValidCell()==false)
	{
		pOut->PrintMessage( "Invalid Cell");
		return;
	}

	if (pCell->GetGameObject())
	{
		pOut->PrintMessage( "Cell already has an object");
		return;
	}


	this->cardNumber=(copiedcard->GetCardNumber());

	Card* newcard=NULL;
	switch (cardNumber)
	{
	case 1:
		newcard = new CardOne(cardPosition);


		break;

	case 2:
		newcard = new CardTwo(cardPosition);

		break;

	case 3:
		newcard = new CardThree(cardPosition);

		break;

	case 4:
		newcard = new CardFour(cardPosition);

		break;

	case 5:
		newcard = new CardFive(cardPosition);

		break;

	case 6:
		newcard = new CardSix(cardPosition);

		break;

	case 7:
		newcard = new CardSeven(cardPosition);

		break;

	case 8:
		newcard = new CardEight(cardPosition);

		break;

	case 9:
		newcard = new CardNine(cardPosition);

		break;
	case 10:
		newcard = new CardTen(cardPosition);

		break;

	case 11:
		newcard = new CardEleven(cardPosition);

		break;

	case 12:
		newcard = new CardTwelve(cardPosition);

		break;

	case 13:
		newcard = new CardThirteen(cardPosition);

		break;

	case 14:
		newcard = new CardFourteen(cardPosition);

		break;
	}

	newcard->setinfo1(copiedcard->getinfo1());

	pGrid->AddObjectToCell (newcard);

	if (!((copiedcard->GetPosition()).IsValidCell()))
		pGrid->SetClipboard( NULL);
}
