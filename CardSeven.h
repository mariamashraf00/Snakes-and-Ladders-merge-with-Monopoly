#pragma once

#include "Card.h"

class CardSeven : public Card
{
	
		
	
	public:
		CardSeven(const CellPosition& pos); 

		virtual void ReadCardParameters(Grid* pGrid);

		virtual void Apply(Grid* pGrid, Player* pPlayer); 

		virtual void Save(ofstream &OutFile, type t);

		virtual ~CardSeven();
};

