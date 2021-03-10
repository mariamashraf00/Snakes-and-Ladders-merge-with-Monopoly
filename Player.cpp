#include "Player.h"

#include "GameObject.h"




Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum((playerNum >= 0 && playerNum <= MaxPlayerCount-1)? playerNum:0)
{   
	this->justRolledDiceNum=0;
	this->pCell = pCell;
	this->turnCount = 0;
	this->prevent=0;

	// BONUS
	numberofattacks = 0;
	 ice = 0;
      fire = 0;
	  poison = 0;
	  lightning = 0;
	 isburnt = 0;
	 burncounter = 0;
	   ispoisoned =0;
	poisoncounter=0;
}


void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::SetTurnCount(int count) 
{
	if (count >= 0 && count <= 3)
		turnCount = count;
}

int Player::getPlayerNum() const
{
	return playerNum;
}
int Player::GetjustRolledDiceNum()
{
	return (this->justRolledDiceNum);
}

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer (pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = (pCell->HasCard()) ? (UI.CellColor_HasCard) : (UI.CellColor_NoCard);
	
	
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}




void Player ::Bonus_Attack (Grid * pGrid)
{
	  
	Output* pOut = pGrid->GetOutput();
	Input * pIn = pGrid->GetInput();

	    this->turnCount=0;
		++numberofattacks;
		pOut->PrintMessage("Choose a special attack : 1-Ice, 2-Fire , 3-Poison , 4-Lightning (you can only choose each attack once)");
		attack = pIn->GetInteger(pOut);
		switch (attack)
		{
		case 1:
			{ while (ice==1 && attack==1)
			{
		
		pOut->PrintMessage("You can't choose ice again : choose a different attack");
		attack= pIn->GetInteger(pOut);
		}
			}
			break;
		case 2:
			{ while (fire==1 && attack==2 )
		{ pOut->PrintMessage("You can't choose fire again : choose a different attack");
			attack = pIn->GetInteger(pOut);
			}
			}
			break;
		case 3:
			{ while (poison==1 && attack==3)
		{ pOut->PrintMessage("You can't choose poison again : choose a different attack ");
			attack = pIn->GetInteger(pOut);
			}
			}
			break;
		case 4:
			{ while (lightning==1 && attack==4)
		{ pOut->PrintMessage("You can't choose lightning again : choose a different attack");
			attack = pIn->GetInteger(pOut);
			}
			}
			break;
		
		}
	switch (attack)
	{
	case 1:
		
		{  ice++;
			pOut->PrintMessage("Choose the number of player you wish to freeze ");
		int num = pIn->GetInteger(pOut);
		while (num == this->playerNum){
		
		pOut->PrintMessage("You can't attack yourself choose again");
		num = pIn->GetInteger(pOut);
		}
	Player* frozen = pGrid->getPlayerPointer(num);
	frozen->setpreventP(1);
		}
	    break;
		case 2:
		{ fire ++;
		pOut->PrintMessage("Choose the number of player you wish to burn");
		int num = pIn->GetInteger(pOut);
		while (num == this->playerNum){
		
		pOut->PrintMessage("You can't attack yourself choose again");
		num = pIn->GetInteger(pOut);
		}
		Player* burnt = pGrid->getPlayerPointer(num);
		burnt->isburnt=1;
		}
		break;
		case 3:
		{ poison ++;
		pOut->PrintMessage("Choose the number of player you wish to poison ");
		int num = pIn->GetInteger(pOut);
		while (num == this->playerNum){
		
		pOut->PrintMessage("You can't attack yourself choose again");
		num = pIn->GetInteger(pOut);
		}
		Player* poisoned = pGrid->getPlayerPointer(num);
		poisoned->ispoisoned=1;
		}
		break;
	case 4:
		{ lightning++;
		for (int i=0; i<4; i++)
		{
			Player * p = pGrid->getPlayerPointer(i);
			if ( p != this)
			p->SetWallet(p->GetWallet() -20);
		
		}
		}
	    break;

	}
}
void Player::Move(Grid * pGrid, int diceNumber)
{    
	Output* pOut = pGrid->GetOutput();
	Input * pIn = pGrid->GetInput();


	if (this->getpreventP()==1)
	{
		pOut->PrintMessage("You're prevented from rolling the dice this turn....click to continue");
		this->setpreventP(0);
		return;
	
	}

	this->turnCount = this->turnCount + 1;

	if (this->turnCount==4)
	{   pOut->PrintMessage("Would you like to launch an attack instead of recharging your wallet ? ( 1 = yes , 0=no)");
	choice = pIn->GetInteger(pOut);
	if (numberofattacks > 1)
	{   
		pGrid->PrintErrorMessage("You have already launched two special attacks, your wallet will be recharged...click to continue");
		choice=0;
		}
	if (choice == 0)
			{this->wallet = this->wallet + 10*diceNumber;
			this->turnCount=0;
			return;}
	else if (choice == 1)
	{ 
		this->Bonus_Attack(pGrid);
		pOut->PrintMessage("Player " + to_string(playerNum) +" has launched an attack....click to continue");
		return;
	}
	}


	if (this->isburnt==1)
	{ 
		if (burncounter<3)
			{
			this->SetWallet(this->GetWallet()-20);
			burncounter++;
			pGrid->PrintErrorMessage("You have been burnt ... your wallet will lose 20 coins...click to continue");
			}
		else {
			burncounter=0;
		this->isburnt = 0;
		}
		}
	

	if (this->ispoisoned==1)
	{ 
		if (poisoncounter<5)
			{
				diceNumber -=1;
			poisoncounter++;
			pGrid->PrintErrorMessage("You have been poisoned ... your diceroll will lose 1...click to continue");
			}
		else {
			poisoncounter=0;
		this->ispoisoned = 0;
		}
		}

	if (this->wallet<=0) return;

	this->justRolledDiceNum = diceNumber;
	CellPosition pos = pCell->GetCellPosition();
	pos.AddCellNum(diceNumber);

	pGrid->UpdatePlayerCell(this,pos);


	if (pos.GetCellNum()==99)
	{ 
	 pGrid->SetEndGame(true);
	int winningplayer = this->playerNum;
	pOut->PrintMessage("Player "+ to_string(winningplayer) +" is the winner");
	}
	pOut->ClearStatusBar();
}
void Player::setpreventP(int i)
{
	if (i == 0 || i == 1)
		prevent = i;
	else
		prevent = 0;
}

void Player::ResetAttacks() 

{

	numberofattacks = 0;
	 ice = 0;
      fire = 0;
	  poison = 0;
	  lightning = 0;
	 isburnt = 0;
	 burncounter = 0;
	   ispoisoned =0;
	poisoncounter=0;
}

int Player::getpreventP() {
	return prevent;
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(this->playerNum) + "(" ;
	playersInfo += to_string(this->wallet) + ", ";
	playersInfo += to_string(this->turnCount) + ")";
}