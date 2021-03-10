#pragma once

#include "GameObject.h"
#include <fstream>

class Ladder :	public GameObject 
{

	CellPosition endCellPos;

public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos);

	virtual void Draw(Output* pOut) const; 

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	CellPosition GetEndPosition() const;
	  
	virtual void Save(ofstream &OutFile, type t);

	virtual ~Ladder(); 
};

