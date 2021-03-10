#include "Ladder.h"
#include <fstream>
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)

{ 
	if (endCellPos.VCell()>startCellPos.VCell() || endCellPos.HCell()!=startCellPos.HCell()|| startCellPos.VCell()==0) 
		return;
	this->endCellPos = endCellPos;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	Output * pOut = pGrid->GetOutput();

	Input *pIn = pGrid->GetInput();

	int x,y;

	pOut->PrintMessage("You have reached a ladder. Click to continue");

	pIn->GetPointClicked(x,y);

	pGrid->UpdatePlayerCell(pPlayer,this->GetEndPosition());
	
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream &OutFile,type t )
{
	OutFile <<position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	
}

Ladder::~Ladder()
{
}
