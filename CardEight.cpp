#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{

}


void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	if (pPlayer->getpreventP() == 0)
	{
		Card::Apply(pGrid, pPlayer);

		pPlayer->setpreventP(1);
	}
	
	

	
	
}

void CardEight::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);

	OutFile <<endl;
}
