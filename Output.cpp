#include "Output.h"

#include "Input.h"


Output::Output()
{
	UI.InterfaceMode = MODE_DESIGN;


	UI.StatusBarHeight = 60;
	UI.ToolBarHeight = 55;
	UI.MenuItemWidth = 55;

	UI.width = 1210;
	UI.height = 610; 
	UI.wx = 5;
	UI.wy = 5;

	UI.CellWidth = UI.width / NumHorizontalCells;
	UI.CellHeight = (UI.height -  UI.ToolBarHeight - UI.StatusBarHeight) / NumVerticalCells;


	UI.MsgColor = DARKRED;
	UI.PlayerInfoColor = DARKSLATEBLUE;

 
	UI.ToolBarColor = WHITE;
	UI.StatusBarColor = LIGHTGRAY; 


	UI.GridLineColor = WHITE;

	
	UI.CellColor_NoCard = LIGHTSLATEBLUE;
	UI.CellNumFont = 13;
	UI.CellNumColor = UI.GridLineColor;

	
	UI.CellColor_HasCard = SALMON;
	UI.CardNumFont = 35;
	UI.CardNumColor = WHITE;


	UI.LadderlineWidth = 6;
	UI.LadderColor = DARKSLATEBLUE;


	UI.LadderXOffset = (UI.CellWidth  - 2 * UI.LadderlineWidth) / 5;
	UI.LadderYOffset = UI.CellHeight / 2;

	
	UI.SnakelineWidth = 6;
	UI.SnakeColor = FIREBRICK;

	
	UI.PlayerColors[0] = GOLD;
	UI.PlayerColors[1] = DARKSLATEBLUE;
	UI.PlayerColors[2] = KHAKI;
	UI.PlayerColors[3] = CHOCOLATE;

	pWind = CreateWind(UI.width + 15, UI.height, UI.wx, UI.wy); 

	pWind->ChangeTitle("Snakes & Ladders");

	CreateDesignModeToolBar();
	ClearGridArea();
	ClearStatusBar();

}


window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	return pW;
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}


int Output::GetCellStartX(const CellPosition & cellPos) const
{
	int w =cellPos.HCell()* UI.CellWidth;
	

	return w; 
}


int Output::GetCellStartY(const CellPosition & cellPos) const
{
	int h = cellPos.VCell() * UI.CellHeight + UI.ToolBarHeight;
	return h ; 
}


void Output::DrawCardNumber(const CellPosition& cellPos, int cardNum) const
{
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	pWind->SetPen(UI.CardNumColor);
	pWind->SetFont(UI.CardNumFont, BOLD | ITALICIZED, BY_NAME, "Arial");

	int w = 0, h = 0;


	pWind->GetIntegerSize(w, h, cardNum); 


	int x = cellStartX + UI.CellWidth - UI.LadderXOffset - w - 5;

	int y = cellStartY + (UI.CellHeight - h) / 2;	


	pWind->DrawInteger(x, y, cardNum);

}



void Output::ClearToolBar() const
{
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}



void Output::ClearStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}



void Output::ClearGridArea() const
{
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			CellPosition cellPos(i, j);
			DrawCell(cellPos); 
		}
	}

}


void Output::CreateDesignModeToolBar() const
{
	UI.InterfaceMode = MODE_DESIGN;

	ClearToolBar(); 

	string MenuItemImages[DESIGN_ITM_COUNT];
	MenuItemImages[ITM_ADD_LADDER] = "images\\Menu_Ladder.jpg";
	MenuItemImages[ITM_ADD_SNAKE] = "images\\Menu_Snake.jpg";
	MenuItemImages[ITM_ADD_CARD] = "images\\Menu_Card.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu_Exit.jpg";
	MenuItemImages[ITM_SWITCH_TO_PLAY_MODE] = "images\\Menu_SwitchToGame.jpg";
	MenuItemImages[ITM_COPY_CARD] = "images\\document.jpg";
	MenuItemImages[ITM_CUT_CARD] = "images\\scissors.jpg";
	MenuItemImages[ITM_PASTE_CARD] = "images\\clipboard.jpg";
	MenuItemImages[ITM_EDIT_CARD] = "images\\resume.jpg";
	MenuItemImages[ITM_DELETE_GAME_OBJECT] = "images\\garbage.jpg";
	MenuItemImages[ITM_SAVE_GRID] = "images\\save.jpg";
	MenuItemImages[ITM_OPEN_GRID] = "images\\folder.jpg";




	for(int i=0; i < DESIGN_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


}


void Output::CreatePlayModeToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	ClearToolBar();
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_ROLL_DICE] = "images\\Menu_Dice.jpg";
	MenuItemImages[ITM_SWITCH_TO_DESIGN_MODE] = "images\\Menu_SwitchToGrid.jpg";
	MenuItemImages[ITM_INPUT_DICE_VALUE] = "images\\dices.jpg";
	MenuItemImages[ITM_NEW_GAME] = "images\\New.jpg";
	MenuItemImages[Exit_Play_Mode] = "images\\Menu_Exit.jpg";




	for(int i=0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}


void Output::PrintMessage(string msg) const	
{
	ClearStatusBar();	

	pWind->SetPen(UI.MsgColor);
	pWind->SetFont(18, BOLD , BY_NAME, "Verdana");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.3), msg);
}


void Output::PrintPlayersInfo(string info)
{
	
	ClearToolBar();
	CreatePlayModeToolBar();

	pWind->SetPen(UI.PlayerInfoColor); 
	pWind->SetFont(20, BOLD , BY_NAME, "Verdana");   

	int w=0, h=0;

	pWind->GetStringSize(w, h, info);


	int x = UI.width - w - 20; 

	int y = (UI.ToolBarHeight - h) / 2; 

	pWind->DrawString(x, y, info);


}


void Output::DrawCell(const CellPosition & cellPos, int cardNum) const
{
	
	int cellNum = cellPos.GetCellNum();
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	pWind->SetPen(UI.GridLineColor, 1);
	if (cardNum == -1) 
		pWind->SetBrush(UI.CellColor_NoCard);
	else
		pWind->SetBrush(UI.CellColor_HasCard);

	pWind->DrawRectangle(cellStartX, cellStartY, cellStartX + UI.CellWidth, cellStartY + UI.CellHeight);


	pWind->SetPen(UI.CellNumColor);
	pWind->SetFont(UI.CellNumFont, BOLD , BY_NAME, "Verdana");   

	int w=0, h=0;

	pWind->GetIntegerSize(w, h, cellNum);


	int x = cellStartX + (UI.CellWidth - w - 1);   

	int y = cellStartY + (UI.CellHeight - h - 1);  

	pWind->DrawInteger(x, y, cellNum);
	

	
	if (cardNum != -1) 
		DrawCardNumber(cellPos, cardNum);
}


void Output::DrawPlayer(const CellPosition & cellPos, int playerNum, color playerColor) const
{

	if (playerNum < 0 || playerNum>3)
		return ; 
	

	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	int radius = UI.CellWidth / 14; 

	int ySpace = UI.CellHeight / 6; 

	int y = cellStartY + ySpace + radius + 2;
	if (playerNum == 2 || playerNum == 3)
		y += radius + 2 + radius; 

	int x = cellStartX + UI.LadderXOffset + radius + 4;

	if (playerNum == 1 || playerNum == 3)
		x += radius + 2 + radius; 

	pWind->SetPen(playerColor,radius);
	pWind->SetBrush(playerColor);
	pWind->DrawCircle(x, y, radius);
	
}


void Output::DrawLadder(const CellPosition & fromCell, const CellPosition & toCell) const
{

	if ((fromCell.VCell() > toCell.VCell()) &&( fromCell.HCell()==toCell.HCell()))

	{

	int cellStartX = GetCellStartX(fromCell);
	int fromStartY = GetCellStartY(fromCell);

	int toStartY = GetCellStartY(toCell);

	int x12 = cellStartX + UI.LadderXOffset; 
	int y1 = fromStartY + UI.LadderYOffset;  
	int y2 = toStartY + UI.CellHeight - UI.LadderYOffset; 

	pWind->SetPen(UI.LadderColor, UI.LadderlineWidth);
	


	pWind->DrawLine (x12,y1,x12,y2,FRAME);


	int x34 = cellStartX + UI.CellWidth - UI.LadderXOffset; 

	pWind->SetPen(UI.LadderColor, UI.LadderlineWidth);



	pWind->DrawLine (x34,y1,x34,y2,FRAME);


	
	for (int i=(fromStartY); i>toStartY; i-=UI.CellHeight)
	{
		pWind->SetPen(UI.LadderColor, UI.LadderlineWidth);
	
	      pWind->DrawLine (x12,i,x34,i,FRAME);}
	}
	else return;
	
}



void Output::DrawSnake(const CellPosition & fromCell, const CellPosition & toCell) const
{

	
	if (fromCell.VCell() < toCell.VCell() && fromCell.HCell()==toCell.HCell())
	{

	int cellStartX = GetCellStartX(fromCell);
	int fromStartY = GetCellStartY(fromCell);
	int toStartY = GetCellStartY(toCell);


	int x12 = cellStartX + UI.LadderXOffset/2; 
	int y1 = fromStartY + UI.CellHeight/2;
	int y2 = toStartY + UI.CellHeight/2;


	pWind->SetPen(UI.SnakeColor,UI.SnakelineWidth);
	


	

	pWind->DrawLine (x12,y1,x12,y2,FRAME);


	pWind->SetPen(UI.SnakeColor, UI.SnakelineWidth);
	pWind->SetBrush(UI.SnakeColor);

	int yChange = UI.CellHeight / 4; 
	int xChange = UI.CellWidth /14 ; 

 int X[]={x12,x12+ xChange,x12,(x12-xChange)};
 int Y[]= {(y1-yChange),y1,(y1+yChange),y1};


	pWind->DrawPolygon(X,Y, 4,FILLED);
	}
	else return;
}



Output::~Output()
{
	
	delete pWind;
}

