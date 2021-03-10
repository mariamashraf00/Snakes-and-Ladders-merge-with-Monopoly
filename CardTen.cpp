#include "CardTen.h"
#include "SaveAction.h"
#include <fstream>

Player* CardTen::CardTenOwner = NULL;
int CardTen::CardTenPrice = 0;
int CardTen::CardTenFees = 0;
bool CardTen::isCardTenOwned = false;
int CardTen::CardTenNUM = 0;
bool CardTen::isCardTenSaved = false;


CardTen::CardTen(const CellPosition & pos) : Card(pos), newCard(true)
{
	cardNumber = 10;
}

CardTen::~CardTen(void)
{
}



void CardTen::ReadCardParameters(Grid * pGrid)
{
	if(CardTenNUM==0 || newCard == false)
	{
		Output * pOut = pGrid->GetOutput();
		Input *pIn = pGrid->GetInput();


		pOut->PrintMessage( "Enter Card Price");
		int P=pIn->GetInteger(pOut);
		CardTenPrice=P;

		pOut-> ClearStatusBar();

		pOut->PrintMessage( "Enter Fees to be removed");
		int F=pIn->GetInteger(pOut);
		CardTenFees = F;

		pOut-> ClearStatusBar();
	}
	CardTenNUM++;
	newCard = false;
}


void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	Card::Apply(pGrid,pPlayer);
	if (isCardTenOwned == false)
	{
		pOut->PrintMessage( "Do you want to buy this card? 1=YES 0=NO");
		int s=pIn->GetInteger(pOut);
		pOut-> ClearStatusBar();
		if (s==1)
			if(pPlayer->GetWallet()>= CardTenPrice)
			{
				pPlayer->SetWallet(pPlayer->GetWallet()-CardTenPrice);
				CardTenOwner =pPlayer;
				isCardTenOwned =true;
				pOut->PrintMessage( "Done!");
			}
			else
				pOut->PrintMessage( "Not enough money!");
	}
	else
	{
		if(!(pPlayer->getPlayerNum()==CardTenOwner->getPlayerNum()))
		{
			pPlayer->SetWallet(pPlayer->GetWallet()-CardTenFees);
		}
	}
}

void CardTen::Read(ifstream &Infile){
	if (CardTenNUM == 0) //find if it is the first card of this number or not
	{
		Infile >> CardTenPrice;
		Infile >> CardTenFees;
	}
	CardTenNUM++;
}

void CardTen::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);
	if(!isCardTenSaved)
	{
		OutFile<<CardTenPrice<<" ";
		OutFile<<CardTenFees<<" ";
		isCardTenSaved = true;
	}

	OutFile << endl;
}

