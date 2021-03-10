#pragma once

#include "Card.h"

class CardOne :	public Card
{
	int walletAmount;

public:
	CardOne(const CellPosition & pos);

	virtual void ReadCardParameters(Grid * pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream &OutFile, type t);

	virtual void Read(ifstream &InFile);
	
	virtual int  getinfo1();

	virtual void setinfo1(int w);
	
	virtual ~CardOne();
};