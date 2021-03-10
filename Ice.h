#pragma once

#include "ApplicationManager.h"
#include "Cell.h"

class Ice
{ 
	static int number [4];

	ApplicationManager *pManager;

public:
	Ice ();
 void Execute();

	~Ice(); 
};

