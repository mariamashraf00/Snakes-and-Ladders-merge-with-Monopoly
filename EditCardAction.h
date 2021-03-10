#pragma once
#include "Action.h"

class EditCardAction : public Action
{
	
	int cardNumber;            
	CellPosition cardPosition;
	Card* pCard;

	
	
public:
	EditCardAction(ApplicationManager *pApp); 
		
	virtual void ReadActionParameters();
	
	virtual void Execute(); 
	
	virtual ~EditCardAction();
};