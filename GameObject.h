#pragma once

#include "Grid.h"
#include <fstream>

class GameObject
{

protected:

	CellPosition position; 
	
public:

	GameObject(const CellPosition & pos); 
	
	CellPosition GetPosition() const;  

	void setObjectPosition(CellPosition pos)
	{
		position=pos;
	}

	virtual void Draw(Output* pOut) const = 0;	 

	virtual void Apply(Grid* pGrid, Player* pPlayer) = 0;  

     virtual void Save(ofstream &OutFile, type t) =0;
	
	
	virtual ~GameObject(); 
};

