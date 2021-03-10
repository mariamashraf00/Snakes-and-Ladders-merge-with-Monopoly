#include "CardSeven.h"


CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 7;
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{

}


void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	pGrid->PrintErrorMessage("You have another dice roll. Click to continue ...");



}

void CardSeven::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);

	OutFile <<endl;
}
