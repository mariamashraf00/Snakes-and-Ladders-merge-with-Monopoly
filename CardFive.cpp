#include "CardFive.h"


CardFive::CardFive(const CellPosition &pos) : Card(pos)
{
	cardNumber = 5;
	newcellposition = pos;
}
void CardFive::ReadCardParameters(Grid* pGrid) 
{
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer) 
{
	Card::Apply(pGrid, pPlayer);

	int x = pPlayer->GetjustRolledDiceNum();

	pPlayer->SetTurnCount(pPlayer->GetTurnCount()-1);

	pPlayer->Move(pGrid, x);
}
CardFive::~CardFive() {
}

void CardFive::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);

	OutFile <<endl;
}
