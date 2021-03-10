#include "CardFourteen.h"

Player* CardFourteen::CardFourteenOwner = NULL;
int CardFourteen::CardFourteenPrice = 0;
int CardFourteen::CardFourteenFees = 0;
bool CardFourteen::isCardFourteenOwned = false;
int CardFourteen::CardFourteenNUM = 0;
bool CardFourteen::isCardFourteenSaved = false;

CardFourteen::CardFourteen(const CellPosition & pos) : Card(pos), newCard(true)
{
	cardNumber = 14;
}

CardFourteen::~CardFourteen(void)
{
}



void CardFourteen::ReadCardParameters(Grid * pGrid)
{
	if(CardFourteenNUM==0 || newCard == false)
	{
		Output * pOut = pGrid->GetOutput();
		Input *pIn = pGrid->GetInput();


		pOut->PrintMessage( "Enter Card Price");
		int P=pIn->GetInteger(pOut);
		CardFourteenPrice=P;

		pOut-> ClearStatusBar();

		pOut->PrintMessage( "Enter Fees to be removed");
		int F=pIn->GetInteger(pOut);
		CardFourteenFees = F;

		pOut-> ClearStatusBar();
	}
	CardFourteenNUM++;
	newCard = false;
}


void CardFourteen::Apply(Grid* pGrid, Player* pPlayer)
{
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
	Card::Apply(pGrid,pPlayer);
	if (isCardFourteenOwned == false)
	{
		pOut->PrintMessage( "Do you want to buy this card? 1=YES 0=NO");
		int s=pIn->GetInteger(pOut);
		pOut-> ClearStatusBar();
		if (s==1)
			if(pPlayer->GetWallet()>= CardFourteenPrice)
			{
				pPlayer->SetWallet(pPlayer->GetWallet()-CardFourteenPrice);
				CardFourteenOwner =pPlayer;
				isCardFourteenOwned =true;
				pOut->PrintMessage( "Done!");
			}
			else
				pOut->PrintMessage( "Not enough money!");
	}
	else
	{
		if(!(pPlayer->getPlayerNum()==CardFourteenOwner->getPlayerNum()))
		{
			pPlayer->SetWallet(pPlayer->GetWallet()-CardFourteenFees);
		}
	}
}

void CardFourteen::Read(ifstream &Infile){
	if (CardFourteenNUM == 0) //find if it is the first card of this number or not
	{
		Infile >> CardFourteenPrice;
		Infile >> CardFourteenFees;
	}
	CardFourteenNUM++;
}
void CardFourteen::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);
	if(!isCardFourteenSaved)
	{
		OutFile<<CardFourteenPrice<<" ";
		OutFile<<CardFourteenFees<<" ";
		isCardFourteenSaved = true;
	}

	OutFile << endl;
}
