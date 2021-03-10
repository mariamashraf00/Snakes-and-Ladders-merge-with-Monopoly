#pragma once

#include "Card.h"


class CardTwo :	public Card
{
	
	int walletAmount; 

public:
	CardTwo(const CellPosition & pos); 

	virtual void ReadCardParameters(Grid * pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual void Save(ofstream &OutFile, type t);

	virtual void Read(ifstream &InFile);

	virtual int getinfo1();

	virtual void setinfo1(int w);

	virtual ~CardTwo(); 
};

