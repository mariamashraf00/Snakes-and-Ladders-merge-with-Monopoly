#include "CardTwelve.h"

Player* CardTwelve::CardTwelveOwner = NULL;
int CardTwelve::CardTwelvePrice = 0;
int CardTwelve::CardTwelveFees = 0;
bool CardTwelve::isCardTwelveOwned = false;
int CardTwelve::CardTwelveNUM = 0;
bool CardTwelve::isCardTwelveSaved = false;



CardTwelve::CardTwelve(const CellPosition & pos) : Card(pos), newCard(true)
{
	cardNumber = 12;
}

CardTwelve::~CardTwelve(void)
{
}



void CardTwelve::ReadCardParameters(Grid * pGrid)
{
	if(CardTwelveNUM==0 || newCard == false)
	{
		Output * pOut = pGrid->GetOutput();
		Input *pIn = pGrid->GetInput();


		pOut->PrintMessage( "Enter Card Price");
		int P=pIn->GetInteger(pOut);
		CardTwelvePrice=P;

		pOut-> ClearStatusBar();

		pOut->PrintMessage( "Enter Fees to be removed");
		int F=pIn->GetInteger(pOut);
		CardTwelveFees = F;

		pOut-> ClearStatusBar();
	}
	CardTwelveNUM++;
	newCard = false;
}


void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	Card::Apply(pGrid,pPlayer);
	if (isCardTwelveOwned == false)
	{
		pOut->PrintMessage( "Do you want to buy this card? 1=YES 0=NO");
		int s=pIn->GetInteger(pOut);
		pOut-> ClearStatusBar();
		if (s==1)
			if(pPlayer->GetWallet()>= CardTwelvePrice)
			{
				pPlayer->SetWallet(pPlayer->GetWallet()-CardTwelvePrice);
				CardTwelveOwner =pPlayer;
				isCardTwelveOwned =true;
				pOut->PrintMessage( "Done!");
			}
			else
				pOut->PrintMessage( "Not enough money!");
	}
	else
	{
		if(!(pPlayer->getPlayerNum()==CardTwelveOwner->getPlayerNum()))
		{
			pPlayer->SetWallet(pPlayer->GetWallet()-CardTwelveFees);
		}
	}
}

void CardTwelve::Read(ifstream &Infile){
	if (CardTwelveNUM == 0) //find if it is the first card of this number or not
	{
		Infile >> CardTwelvePrice;
		Infile >> CardTwelveFees;
	}
	CardTwelveNUM++;
}

void CardTwelve::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);
	if(!isCardTwelveSaved)
	{
		OutFile<<CardTwelvePrice<<" ";
		OutFile<<CardTwelveFees<<" ";
		isCardTwelveSaved = true;
	}

	OutFile << endl;
}

