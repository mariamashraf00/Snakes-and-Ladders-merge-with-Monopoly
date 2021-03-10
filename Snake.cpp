#include "Snake.h"

Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{ if (startCellPos.VCell()>endCellPos.VCell() || endCellPos.HCell()!=startCellPos.HCell() || startCellPos.VCell() == NumVerticalCells-1) 
		return;
	this->endCellPos = endCellPos;

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	Output * pOut = pGrid->GetOutput();

	Input *pIn = pGrid->GetInput();

	int x,y;

	pOut->PrintMessage("You have reached a snake. Click to continue");

	pIn->GetPointClicked(x,y);

	pGrid->UpdatePlayerCell(pPlayer,this->GetEndPosition());
	
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream &OutFile, type t)
{
	OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

Snake::~Snake()
{
}
