#pragma once

#include "GameObject.h"
#include "Player.h"
#include <fstream>


class Card : public GameObject
{
protected:
	int cardNumber; 

public:
	Card(const CellPosition & pos); 

	void SetCardNumber(int cnum);   

	int GetCardNumber();            

	void Draw(Output* pOut) const;  

	virtual void ReadCardParameters(Grid * pGrid); 

	virtual void Apply(Grid* pGrid, Player* pPlayer);  
	                                              
	virtual int getinfo1();

	virtual void setinfo1(int w);

	virtual void Save(ofstream &OutFile, type t);

	virtual void Read(ifstream &InFile);

	virtual ~Card();
};

