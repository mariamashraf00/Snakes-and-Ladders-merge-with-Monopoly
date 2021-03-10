#pragma once

#include "ApplicationManager.h"
#include "Cell.h"

class Action
{
protected:

	ApplicationManager *pManager;

public:

	Action(ApplicationManager *pApp);


	virtual void ReadActionParameters() = 0; 

	virtual void Execute() = 0;  

	virtual ~Action();  
};

