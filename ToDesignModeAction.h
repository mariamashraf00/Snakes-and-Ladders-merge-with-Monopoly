#pragma once
#include "Action.h"
#include "Grid.h"

class ToDesignModeAction :	public Action
{
public:
	ToDesignModeAction(ApplicationManager* pApp);
	void ReadActionParameters();

	void Execute();
};

