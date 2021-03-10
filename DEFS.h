#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"


enum ActionType 
{
	

	ADD_LADDER,
	ADD_SNAKE,	
	ADD_CARD,		
	COPY_CARD,
	CUT_CARD,
	PASTE_CARD,
	EDIT_CARD,
	DELETE_OBJECT,
	SAVE_GRID,
	OPEN_GRID,
	DELETE_GAME_OBJECT,
	EXIT,
	TO_PLAY_MODE,
	NEW_GAME,
	ROLL_DICE,
	INPUT_DICE_VALUE,
	TO_DESIGN_MODE,	

	EMPTY,				
	GRID_AREA,			
	STATUS 				
};

#endif