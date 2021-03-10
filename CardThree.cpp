#include "CardThree.h"
#include "Ladder.h"

CardThree::CardThree(const CellPosition &pos) : Card(pos)
{
	cardNumber = 3;
	newcellposition = pos;
}

void CardThree::ReadCardParameters(Grid* pGrid)
{

}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);

	 Ladder *pladder=pGrid->GetNextLadder(newcellposition);

	if (pladder != NULL) 
	{
		
		GameObject* Gptr = (GameObject*)pladder;
		newcellposition = Gptr->GetPosition();
		pGrid->UpdatePlayerCell(pPlayer,newcellposition);

	}
	else {}
}

void CardThree::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);

	OutFile << endl;
}

CardThree::~CardThree()
{

}
