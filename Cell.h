#pragma once 

#include "UI_Info.h"
#include "CellPosition.h"

class Grid;
class Output;
class GameObject;
class Ladder;
class Snake;
class Card;
class Player;

class Cell
{
	const CellPosition position;

	GameObject * pGameObject;     

public:

	Cell(const CellPosition & pos);
	Cell(int v, int h);		        

	CellPosition GetCellPosition() const;  
	
	bool SetGameObject(GameObject * pGObj);

	GameObject * GetGameObject() const;     
		
	Ladder * HasLadder() const;	
	Snake * HasSnake() const;	
	Card * HasCard() const;	    

	void DrawCellOrCard(Output* pOut) const;

	void DrawLadderOrSnake(Output* pOut) const;	
	                                           
};

