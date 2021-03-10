#pragma once

#include "DEFS.h"
#include "UI_Info.h"

class Input;
class Output;
class Grid;

class ApplicationManager
{
	Grid* pGrid; 
	Input *pIn;
	Output *pOut;

public:

	ApplicationManager();  

	~ApplicationManager(); 

	Grid * GetGrid() const;    

	void UpdateInterface() const;

	

	ActionType GetUserAction() const; 


	void ExecuteAction(ActionType) ;  

};

