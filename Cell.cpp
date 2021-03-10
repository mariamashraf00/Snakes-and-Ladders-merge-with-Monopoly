#include "Cell.h"

#include "Grid.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include "Snake.h"

Cell::Cell(const CellPosition & pos) : position(pos)
{
	pGameObject = NULL;
}

Cell::Cell(int v, int h) : position(v, h)
{
	pGameObject = NULL;
}


CellPosition Cell::GetCellPosition() const
{
	return position;
}

bool Cell::SetGameObject(GameObject * pGObj)
{
	if(pGObj == NULL)
		{pGameObject = NULL;
	return true;}
	if (pGameObject != NULL)
		return false;

	pGameObject = pGObj;
	return true;
}

GameObject * Cell::GetGameObject() const
{
	return pGameObject;
}

Ladder * Cell::HasLadder() const
{
	return dynamic_cast<Ladder *>(pGameObject);
}

Snake * Cell::HasSnake() const
{

	return dynamic_cast<Snake *>(pGameObject); 
}

Card * Cell::HasCard() const
{

		return dynamic_cast<Card *>(pGameObject);

}



void Cell::DrawCellOrCard(Output* pOut) const
{
	
	if (HasCard())
		pGameObject->Draw(pOut);
	else
		pOut->DrawCell(position, -1); // draw empty cell (no card -1)
}

void Cell::DrawLadderOrSnake(Output* pOut) const
{
	if (HasLadder() || HasSnake())

		pGameObject->Draw(pOut); 

}
