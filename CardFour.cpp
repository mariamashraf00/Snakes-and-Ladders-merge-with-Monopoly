#include "CardFour.h"
#include "Snake.h"

CardFour::CardFour(const CellPosition& pos) :Card(pos)
{
	cardNumber = 4;
	newcellposition = pos.GetCellNum();
}

void CardFour::ReadCardParameters(Grid* pGrid)
{

}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	Snake *psnake = pGrid->GetNextSnake(newcellposition);

	if (psnake != NULL)
	{
		GameObject* Gptr = (GameObject*)psnake;

		newcellposition=Gptr->GetPosition();

		pGrid->UpdatePlayerCell(pPlayer,newcellposition);
	}
	else {}
}

void CardFour::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);

	OutFile << endl;
}


CardFour::~CardFour()
{

}
