#include "Input.h"

#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; 
}


void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y); 
}


string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )
			return "";	
		if(Key == 13 )	
			return Label;
		if((Key == 8) && (Label.size() >= 1))
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}


int Input::GetInteger(Output *pO) const 
{

	string x =GetSrting(pO);
	return stoi(x);




}



ActionType Input::GetUserAction() const
{	
	int x = -1, y = -1;

	GetPointClicked(x, y); 

	if ( UI.InterfaceMode == MODE_DESIGN )	
	{
		
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			

			switch (ClickedItemOrder)
			{
			case ITM_ADD_LADDER: return ADD_LADDER;
			case ITM_ADD_SNAKE: return ADD_SNAKE;
			case ITM_ADD_CARD: return ADD_CARD;
			case ITM_EXIT: return EXIT;
			case ITM_SWITCH_TO_PLAY_MODE: return TO_PLAY_MODE;
			case ITM_COPY_CARD: return COPY_CARD;
			case ITM_CUT_CARD: return CUT_CARD;
			case ITM_PASTE_CARD: return PASTE_CARD;
			case ITM_EDIT_CARD: return EDIT_CARD;
			case ITM_DELETE_GAME_OBJECT: return DELETE_GAME_OBJECT;
			case ITM_SAVE_GRID: return SAVE_GRID;
			case ITM_OPEN_GRID: return OPEN_GRID;





			default: return EMPTY;
			}
		}

		if ( (y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;	
		}

		return STATUS;
	}

	else	
	{
		

		if (y >= 0 && y < UI.ToolBarHeight) {
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_ROLL_DICE: return ROLL_DICE;
			case ITM_INPUT_DICE_VALUE: return INPUT_DICE_VALUE;
			case ITM_NEW_GAME: return NEW_GAME;
			case Exit_Play_Mode: return EXIT;
			case ITM_SWITCH_TO_DESIGN_MODE: return TO_DESIGN_MODE;
            
			default: return EMPTY;
			}
		}

		



	}	

}


CellPosition Input::GetCellClicked() const
{
	int x,y;
	pWind->WaitMouseClick(x, y);	

	CellPosition cellPos;

	if ( UI.InterfaceMode == MODE_DESIGN )	
	{
		if ( y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight))
		{
			
			cellPos.SetVCell((y-UI.ToolBarHeight)/UI.CellHeight);
			cellPos.SetHCell(x/UI.CellWidth);

		}
		else {
			cellPos.SetHCell(-1);
			cellPos.SetVCell(-1);
		}
	}

	return cellPos;
}

