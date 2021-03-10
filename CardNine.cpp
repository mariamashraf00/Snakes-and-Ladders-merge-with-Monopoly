#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos ) : Card(pos)
{
	cardNumber = 9;
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();

	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New CardNine: Click on the Cell to Move to");

	CellPosition cellpos = pIn->GetCellClicked();
	while(!cellpos.IsValidCell())
	{
		pOut->PrintMessage("Invalid! Click on the Cell to Move to");
		cellpos = pIn->GetCellClicked();
	}
	CellToMoveto = cellpos;

	pOut->ClearStatusBar();


}


void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	
	pGrid->PrintErrorMessage("You will Move to Cell Num " + to_string(CellToMoveto.GetCellNum())+". Click to continue ...");

	int newposition = CellToMoveto.GetCellNum() - (pPlayer->GetCell()->GetCellPosition().GetCellNum());

	pPlayer->Move(pGrid,newposition);

	pPlayer->SetTurnCount((pPlayer->GetTurnCount())-1);


}
int CardNine::getinfo1()
{

	return int(CellToMoveto.GetCellNum());
}

void CardNine::setinfo1(int w)
{
	CellToMoveto = CellPosition(w);
}

void CardNine::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);

	OutFile <<CellToMoveto.GetCellNum()<<endl;
}

void CardNine::Read(ifstream &InFile){
	int z;
	InFile>>z;
	CellPosition poss (z);
	CellToMoveto = poss;
}
