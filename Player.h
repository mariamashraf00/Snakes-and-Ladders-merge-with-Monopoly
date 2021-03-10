#pragma once

#include "Grid.h"
#include "Cell.h"
class Player
{
	Cell * pCell;		    

	const int playerNum;  

	int stepCount;		   
	int wallet;		       
	int justRolledDiceNum; 
	int turnCount;        
	int prevent;
	//BONUS_RELATED
    int choice;
	int attack;
	int numberofattacks;
	int ice;
     int fire;
	 int poison;
	 int lightning;
	 bool isburnt;
	 int burncounter;
	 bool ispoisoned ;
	int poisoncounter;

	
public:

	
	Player(Cell * pCell, int playerNum);

	void SetCell(Cell * cell);	
	Cell* GetCell() const;		

	void SetWallet(int wallet);	
	int GetWallet() const;			

	void SetTurnCount(int);
	int GetTurnCount() const;		

	int GetjustRolledDiceNum();

	int getPlayerNum() const;

	void Draw(Output* pOut) const;			

	void ClearDrawing(Output* pOut) const;	

	void Move(Grid * pGrid, int diceNumber);	

	void Bonus_Attack (Grid * pGrid);

	void setpreventP(int i); 

	void ResetAttacks (); 

	int getpreventP();

	void AppendPlayerInfo(string & playersInfo) const; 

};

