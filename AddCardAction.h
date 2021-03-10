#pragma once

#include "Action.h"

class AddCardAction : public Action
{
	int cardNumber;           
	CellPosition cardPosition;
	
public:
	AddCardAction(ApplicationManager *pApp); 
		
	virtual void ReadActionParameters(); 
	
	virtual void Execute(); 
	
	virtual ~AddCardAction(); 

};