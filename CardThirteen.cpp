#include "CardThirteen.h"

Player* CardThirteen::CardThirteenOwner = NULL;
int CardThirteen::CardThirteenPrice = 0;
int CardThirteen::CardThirteenFees = 0;
bool CardThirteen::isCardThirteenOwned = false;
int CardThirteen::CardThirteenNUM = 0;
bool CardThirteen::isCardThirteenSaved = false;

CardThirteen::CardThirteen(const CellPosition & pos) : Card(pos), newCard(true)
{
	cardNumber = 13;
}

CardThirteen::~CardThirteen(void)
{
}



void CardThirteen::ReadCardParameters(Grid * pGrid)
{
	if(CardThirteenNUM==0 || newCard == false)
	{
		Output * pOut = pGrid->GetOutput();
		Input *pIn = pGrid->GetInput();


		pOut->PrintMessage( "Enter Card Price");
		int P=pIn->GetInteger(pOut);
		CardThirteenPrice=P;

		pOut-> ClearStatusBar();

		pOut->PrintMessage( "Enter Fees to be removed");
		int F=pIn->GetInteger(pOut);
		CardThirteenFees = F;

		pOut-> ClearStatusBar();
	}
	CardThirteenNUM++;
	newCard = false;
}


void CardThirteen::Apply(Grid* pGrid, Player* pPlayer)
{
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	Card::Apply(pGrid,pPlayer);
	if (isCardThirteenOwned == false)
	{
		pOut->PrintMessage( "Do you want to buy this card? 1=YES 0=NO");
		int s=pIn->GetInteger(pOut);
		pOut-> ClearStatusBar();
		if (s==1)
			if(pPlayer->GetWallet()>= CardThirteenPrice)
			{
				pPlayer->SetWallet(pPlayer->GetWallet()-CardThirteenPrice);
				CardThirteenOwner =pPlayer;
				isCardThirteenOwned =true;
				pOut->PrintMessage( "Done!");
			}
			else
				pOut->PrintMessage( "Not enough money!");
	}
	else
	{
		if(!(pPlayer->getPlayerNum()==CardThirteenOwner->getPlayerNum()))
		{
			pPlayer->SetWallet(pPlayer->GetWallet()-CardThirteenFees);
		}
	}
}
void CardThirteen::Read(ifstream &Infile){
	if (CardThirteenNUM == 0) //find if it is the first card of this number or not
	{
		Infile >> CardThirteenPrice;
		Infile >> CardThirteenFees;
	}
	CardThirteenNUM++;
}

void CardThirteen::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);
	if(!isCardThirteenSaved)
	{
		OutFile<<CardThirteenPrice<<" ";
		OutFile<<CardThirteenFees<<" ";
		isCardThirteenSaved = true;
	}

	OutFile << endl;
}
