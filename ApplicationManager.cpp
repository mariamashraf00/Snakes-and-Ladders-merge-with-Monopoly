#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "EditCardAction.h"
#include "AddCardAction.h"
#include "AddSnakeAction.h"
#include "RollDiceAction.h"
#include "InputDiceAction.h"
#include "SaveAction.h"
#include "CopyCardAction.h"
#include "CutCardAction.h"
#include "PasteCardAction.h"
#include "NewGame.h"
#include "DeleteGameObject.h"
#include "ToPlayModeAction.h"
#include "ToDesignModeAction.h"
#include "OpenAction.h"


ApplicationManager::ApplicationManager()
{
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}


ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}


Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}


ActionType ApplicationManager::GetUserAction() const
{
	
	return pIn->GetUserAction();
}

void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;
    case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		pAct = new AddCardAction(this);
		break;

	case EDIT_CARD:

		pAct = new EditCardAction(this);
		break;

	case SAVE_GRID:
		pAct = new SaveAction (this);
		break;
	case PASTE_CARD:
		pAct= new PasteCardAction(this);
		break;
	case COPY_CARD:
		pAct = new CopyCardAction (this);
		break;
	case CUT_CARD :
		pAct = new CutCardAction(this);
		break;

	case OPEN_GRID:
		pAct= new  OpenAction (this);
		break;
	case EXIT:
		break;

	case TO_PLAY_MODE:
		pAct = new ToPlayModeAction(this);
		break;

	case ROLL_DICE:
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		pAct = new ToDesignModeAction(this);

		break;

	case NEW_GAME:
		pAct = new NewGame(this);
		break;


	case INPUT_DICE_VALUE:
		pAct = new InputDiceAction(this);

	case STATUS:
		return;

	case DELETE_GAME_OBJECT:
		pAct = new DeleteGameObject(this);
		break;
	}

	if(pAct != NULL)
	{
		pAct->Execute(); 
		delete pAct;	 
		pAct = NULL;
	}
}
