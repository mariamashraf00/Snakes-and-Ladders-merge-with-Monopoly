#pragma once
#include "Card.h"
class CardFive :public Card
{
	CellPosition newcellposition;
public:
	CardFive(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream &OutFile, type t);


	~CardFive();
};
