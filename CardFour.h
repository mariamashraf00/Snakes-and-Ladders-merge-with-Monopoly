#pragma once
#include "Card.h"

class CardFour : public Card
{
private:
	CellPosition newcellposition;
public:
	CardFour(const CellPosition& pos);

	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream &OutFile, type t);

	~CardFour();

};
