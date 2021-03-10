#pragma once

#include "Card.h"

class CardTwelve :	public Card
{
	bool newCard;
public:
	static Player* CardTwelveOwner;
	static int CardTwelvePrice;
	static int CardTwelveFees;
	static bool isCardTwelveOwned;
	static int CardTwelveNUM;
	static bool isCardTwelveSaved;

	CardTwelve(const CellPosition & pos);

	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual void Read(ifstream &InFile);

	virtual void Save(ofstream &OutFile, type t);
	
	virtual ~CardTwelve();
};