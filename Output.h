#ifndef OUPTUT_H
#define OUPTUT_H

#include "DEFS.h"
#include "UI_Info.h" 
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CellPosition.h"

class Input;

class Output	
{
private:	

	window* pWind;	

	int GetCellStartX(const CellPosition & cellpos) const;	

	int GetCellStartY(const CellPosition & cellpos) const;	

	void DrawCardNumber(const CellPosition & cellpos, int cardNum) const;	

	void ClearToolBar() const;	

public:

	Output();	

	window* CreateWind(int, int, int , int) const; 

	Input* CreateInput() const;	
	
	void ClearStatusBar() const;	
	void ClearGridArea() const;	    

	void CreateDesignModeToolBar() const;	

	void CreatePlayModeToolBar() const;		
	
	void PrintMessage(string msg) const;	

	void PrintPlayersInfo(string info);		

	void DrawCell(const CellPosition & cellpos, int cardNum=-1) const;	
														
	void DrawPlayer(const CellPosition & cellpos, int playerNum, color playerColor) const;  
	                                               

	void DrawLadder(const CellPosition & fromCellPos, const CellPosition & toCellPos) const;
													
	void DrawSnake(const CellPosition & fromCellPos, const CellPosition & toCellPos) const;
													
	~Output();	
};

#endif