#pragma once
#include "Action.h"
#include "Grid.h"

class ToPlayModeAction : public Action
{
public:

	ToPlayModeAction(ApplicationManager* pApp);
	void ReadActionParameters();

	void Execute();
};

