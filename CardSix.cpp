#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6 ;
	newcellposition = pos;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{

}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	int x = -pPlayer->GetjustRolledDiceNum();

	pPlayer->SetTurnCount(pPlayer->GetTurnCount()-1);

	pPlayer->Move(pGrid, x);
}

CardSix::~CardSix()
{

}

void CardSix::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);

	OutFile <<endl;
}
