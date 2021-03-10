#pragma once
#include "Card.h"

class CardSix :public Card
{
	CellPosition newcellposition;
public:
	CardSix(const CellPosition &pos);

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream &OutFile, type t);

	~CardSix();

};
