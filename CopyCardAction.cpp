#include "CopyCardAction.h"

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

CopyCardAction::CopyCardAction(ApplicationManager *pApp) : Action(pApp)
{
}

CopyCardAction::~CopyCardAction()
{
}

void CopyCardAction::ReadActionParameters() 
{	
	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	
	pOut->PrintMessage( "Select the card you wish to copy");
	cardPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();

}

void CopyCardAction::Execute() 
{

	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	ReadActionParameters();

	if (cardPosition.IsValidCell()==false)
	{
	pOut->PrintMessage( "Invalid Cell");
	return;
	}

	Cell* pCell=pGrid->getCellPointer(cardPosition);
	Card* existingcard = pCell->HasCard();
	if (existingcard == NULL)
	{
		pOut->PrintMessage("Cell has no card");
		return;
	}

	pGrid->SetClipboard(existingcard);
	pOut->PrintMessage( "Clipboard now carries the selected card");

	pOut->ClearStatusBar();
}
