#include "CellPosition.h"
#include "UI_Info.h"
CellPosition::CellPosition () 
{
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); 
}

bool CellPosition::SetVCell(int v)
{
	if (v >= 0 && v < 9)
	{	vCell = v;
	return true;
}
	else 
	return false; 
}

bool CellPosition::SetHCell(int h) 
{

	if (h >= 0 && h <11 )
	{
		hCell = h;
		return true;
	}
	else
	return false; 
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	if (vCell < 9 && vCell >= 0 && hCell >= 0 && hCell < 11)
		return true;
	else 
	return false;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); 
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	int hori = cellPosition.HCell();
	int ver = cellPosition.VCell(); 
	int cellnum = ((9 - ver) * 11) + (hori-10);


	return cellnum; 
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{


	CellPosition position;


	int x = cellNum % 11;
	int y;
	if (cellNum%11 ==0)
    y = 9-cellNum/11;
	else y= 8-cellNum/11;
	position.SetVCell((int)y);
	if (x == 0)
		position.SetHCell(10);
	else
		position.SetHCell(x - 1);


	return position;
}

void CellPosition::AddCellNum( int addedNum)
{

	CellPosition pos;
	int newposition;
	newposition = this->GetCellNum() + addedNum;
	if (newposition < 99)
			pos=this->GetCellPositionFromNum(newposition);
	else
		pos=this->GetCellPositionFromNum(99);
	this->SetHCell(pos.HCell());
	this->SetVCell(pos.VCell());

}