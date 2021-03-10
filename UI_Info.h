#ifndef UI_INFO_H
#define UI_INFO_H

#include "CMUgraphicsLib\CMUgraphics.h"



#define NumHorizontalCells 11
#define NumVerticalCells 9
#define MaxPlayerCount 4

enum GUI_MODE		
{
	MODE_DESIGN,	
	MODE_PLAY       
};

enum DESIGN_MODE_ITEMS 
{

	ITM_ADD_LADDER,
	ITM_ADD_SNAKE,
	ITM_ADD_CARD,
	ITM_COPY_CARD,
	ITM_CUT_CARD,
	ITM_PASTE_CARD,
	ITM_EDIT_CARD,
	ITM_DELETE_GAME_OBJECT,
	ITM_SAVE_GRID,
	ITM_OPEN_GRID,
	ITM_EXIT,
	ITM_SWITCH_TO_PLAY_MODE,
	

	DESIGN_ITM_COUNT	
};

enum PLAY_MODE_ITEMS 
{

	ITM_ROLL_DICE,
	ITM_INPUT_DICE_VALUE,
	ITM_NEW_GAME,
	Exit_Play_Mode,
	ITM_SWITCH_TO_DESIGN_MODE,


	PLAY_ITM_COUNT		
};


__declspec(selectany) 

struct UI_Info	
{
	GUI_MODE InterfaceMode;

	int	width, height,			
		wx , wy,				
		StatusBarHeight,		
		ToolBarHeight,			
		MenuItemWidth;			
	
	int CellHeight;				
	int CellWidth;				
	
	color MsgColor;			
	color PlayerInfoColor;	

	color CellColor_HasCard;
	color CellColor_NoCard;		

	color ToolBarColor;		
	color StatusBarColor;		

	color GridLineColor;		

	int CellNumFont;			
	color CellNumColor;			

	int CardNumFont;			
	color CardNumColor;		

	int LadderXOffset;			
	int LadderYOffset;			
	int LadderlineWidth;		
	color LadderColor;			
	int SnakelineWidth;			
	color SnakeColor;			

	color PlayerColors[MaxPlayerCount];		

} UI ;	

#endif