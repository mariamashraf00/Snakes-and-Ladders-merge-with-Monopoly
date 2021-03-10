#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include "Snake.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut)
{
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i);
		PlayerList[i]->Draw(pOut);
	}

	currPlayerNumber = 0;

	Clipboard = NULL;

	endGame = false;
}




bool Grid::AddObjectToCell(GameObject * pNewObject) 
{

	CellPosition pos = pNewObject->GetPosition();
	if (pos.GetCellNum()==1 || pos.GetCellNum()==99)
		return false;
	if (pos.IsValidCell()) 
	{

		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject) 
			return false; 

	
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; 
	}
	return false; 
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) 
	{
		delete CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	player->ClearDrawing(pOut);

	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	player->Draw(pOut);

	if (newCell->GetGameObject() != NULL)
	{ 
	GameObject * game_object= newCell->GetGameObject();

	game_object->Apply(this, player);
	}
}



Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) 
{
	Clipboard = pCard;
}

Card * Grid::GetClipboard() const
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; 
}

Cell* Grid::getCellPointer(CellPosition pos)
{
	Cell * p = CellList[pos.VCell()][pos.HCell()];
	return p;
}

Player * Grid:: getPlayerPointer(int num)


{
	Player * p = PlayerList[num];
	return p;

}




Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{

	int startH = position.HCell(); 
	for (int i = position.VCell(); i >= 0; i--) 
	{
		for (int j = startH; j < NumHorizontalCells; j++) 
		{
			if (CellList[i][j]->HasLadder()!=NULL)
				return CellList[i][j]->HasLadder();

		}
		startH = 0;
	}
	return NULL; 
}

Snake * Grid::GetNextSnake(const CellPosition & position)
{

	int startH = position.HCell();
	for (int i = position.VCell(); i >= 0; i--) 
	{
		for (int j = startH; j < NumHorizontalCells; j++)
		{

			if (CellList[i][j]->HasSnake()!=NULL)
				return CellList[i][j]->HasSnake();

		}
		startH = 0;
	}
	return NULL; 
}

int Grid::OverlappingSnakes (CellPosition&start, CellPosition&end)
{
	int top= start.VCell();
	int bottom = end.VCell();
	int hCell = start.HCell();
	for ( int i= top; i<= bottom-top ; i++)
	{
		if (CellList[i][hCell]->HasSnake())
			return 1;
	}
	for ( int i= top; i<= NumVerticalCells-1 ; i++)
	{
		if (CellList[i][hCell]->HasLadder())
		{
	     Ladder * pLadder = CellList[i][hCell]->HasLadder();
	     if ((pLadder->GetEndPosition()).VCell() == top)
			return -1;
		}
	}
	for ( int i= top; i>=0 ; i--)
	{
		if (CellList[i][hCell]->HasSnake())
		{
			Snake * pSnake = CellList[i][hCell]->HasSnake();
			if ( (pSnake->GetEndPosition()).VCell() >= top)
				return 1;
		}
	}
	return 0;
}

int Grid::OverlappingLadders (CellPosition&start, CellPosition&end)
{
	int bottom= start.VCell();
	int top = end.VCell();
	int hCell = start.HCell();
	for ( int i= bottom; i>= top ; i--)
	{
		if (CellList[i][hCell]->HasLadder())
			return 1;
	}

	for ( int i= top; i<= NumVerticalCells-1 ; i++)
	{
		if (CellList[i][hCell]->HasSnake())
		{
	     Snake * pSnake = CellList[i][hCell]->HasSnake();
		 if ((pSnake->GetEndPosition()).VCell() == bottom)
			return -1;
		}
		}
	for ( int i= bottom; i<=NumVerticalCells-1 ; i++)
	{
		if (CellList[i][hCell]->HasLadder())
		{
			Ladder * pLadder = CellList[i][hCell]->HasLadder();
			if ( (pLadder->GetEndPosition()).VCell() <= bottom)
				return 1;
		}
	}
	return 0;
}




void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
	 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) 
		{
			for (int j = 0; j < NumHorizontalCells; j++) 
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		for (int i = NumVerticalCells-1; i >= 0 ; i--) 
		{
			for (int j = 0; j < NumHorizontalCells; j++) 
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else
	{
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); 
			if (i < MaxPlayerCount-1) 
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}


	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}

void Grid::calcnumberofobjects()
{
	numladders = 0;

	numsnakes = 0;

	numcards = 0;

	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder() != NULL)
				numladders++;
			else if (CellList[i][j]->HasSnake() != NULL)
				numsnakes++;
			else if (CellList[i][j]->HasCard() != NULL)
				numcards++;
		}
	}

}

void Grid::SaveAll(ofstream &OutFile, type t)
{

	switch (t)
	{
	case ladder:
		OutFile<<numladders<<endl;

		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				if (CellList[i][j]->HasLadder() != NULL)
					CellList[i][j]->HasLadder()->Save(OutFile, t);

			}
		}
		break;

	case snake :
		OutFile << numsnakes << endl;
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				if (CellList[i][j]->HasSnake() != NULL)
					CellList[i][j]->HasSnake()->Save(OutFile, t);

			}
		}
		break;

	case card :
		OutFile << numcards << endl;
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
					if (CellList[i][j]->HasCard() != NULL)
						CellList[i][j]->HasCard()->Save(OutFile, t);
			}
		}
		break;

	}

}

void Grid::ClearGridArea()  
{
	for (int i = 0; i < NumVerticalCells; ++i) {
		for (int j = 0; j < NumHorizontalCells; ++j) {
				RemoveObjectFromCell(CellList[i][j]->GetCellPosition());
		}
	}
}

void Grid::ResetPlayers()
{
	CellPosition pos(NumVerticalCells - 1, 0);

	for (int i = 0; i < MaxPlayerCount; ++i) {
		PlayerList[i]->SetWallet(100);
		Cell* Cptr = PlayerList[i]->GetCell();
		
		UpdatePlayerCell(PlayerList[i], pos);
		PlayerList[i]->SetTurnCount(0);
		PlayerList[i]->ResetAttacks();
		PlayerList[i]->setpreventP(0);
		currPlayerNumber = 0;


	}

	for (int i = 0; i < NumVerticalCells; ++i) {
	for (int j = 0; j < NumHorizontalCells; ++j) {
		Card* Cptr = CellList[i][j]->HasCard();
		if (Cptr != NULL) {
			CardTen* Tenptr = dynamic_cast<CardTen*>(Cptr);
			if (Tenptr != NULL) {
				Tenptr->isCardTenOwned = false;
				Tenptr->CardTenOwner = NULL;
			}
			CardEleven* Elevenptr = dynamic_cast<CardEleven*>(Cptr);
			if (Elevenptr != NULL) {
				Elevenptr->isCardElevenOwned = false;
				Elevenptr->CardElevenOwner = NULL;
			}
			CardTwelve* Twelveptr = dynamic_cast<CardTwelve*>(Cptr);
			if (Twelveptr != NULL) {
				Twelveptr->isCardTwelveOwned = false;
				Twelveptr->CardTwelveOwner = NULL;
			}
			CardThirteen* Thirteenptr = dynamic_cast<CardThirteen*>(Cptr);
			if (Thirteenptr != NULL) {
				Thirteenptr->isCardThirteenOwned = false;
				Thirteenptr->CardThirteenOwner = NULL;
			}
			CardFourteen* Fourteenptr = dynamic_cast<CardFourteen*>(Cptr);
			if (Fourteenptr != NULL) {
				Fourteenptr->isCardFourteenOwned = false;
				Fourteenptr->CardFourteenOwner = NULL;
			}
		}
	}
  }

}

