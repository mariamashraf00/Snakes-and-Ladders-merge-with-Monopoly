#pragma once
#include "Card.h"

class CardThree :public Card 
{
private:

	CellPosition  newcellposition;

public:
	CardThree(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void Save(ofstream &OutFile, type t);
	~CardThree();
};
