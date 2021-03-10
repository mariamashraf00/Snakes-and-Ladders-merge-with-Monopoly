#pragma once
#include "Action.h"

class InputDiceAction : public Action
{
	int diceNum;
	Output* pOut;
	Input* pIn;
	Grid *Gptr;
public:
	InputDiceAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); //////////not sure////////////////

	virtual void Execute();

	~InputDiceAction();
};

