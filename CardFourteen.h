#pragma once

#include "Card.h"

class CardFourteen :	public Card
{
	bool newCard;
public:
	static Player* CardFourteenOwner;
	static int CardFourteenPrice;
	static int CardFourteenFees;
	static bool isCardFourteenOwned;
	static int CardFourteenNUM;
	static bool isCardFourteenSaved;

	CardFourteen(const CellPosition & pos);

	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 
	
	virtual void Read(ifstream &InFile);

	virtual void Save(ofstream &OutFile, type t);

	virtual ~CardFourteen();
};