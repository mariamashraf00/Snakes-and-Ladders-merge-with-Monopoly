#pragma once

#include "Card.h"

class CardTen :	public Card
{
	bool newCard;
public:
	static Player* CardTenOwner;
	static int CardTenPrice;
	static int CardTenFees;
	static bool isCardTenOwned;
	static int CardTenNUM;
	static bool isCardTenSaved;

	CardTen(const CellPosition & pos);

	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual void Read(ifstream &InFile);

	virtual void Save(ofstream &OutFile, type t);

	virtual ~CardTen();
};