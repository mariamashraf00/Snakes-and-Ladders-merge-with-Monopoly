#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 2; 
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid * pGrid)
{
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();
		int amount;
	do {
	
	pOut->PrintMessage( "New CardTwo: Enter a positive wallet amount to be added ");
	amount = pIn->GetInteger(pOut);
	walletAmount=amount;
	}
	while (amount<0);
	pOut-> ClearStatusBar();

}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	
	Card::Apply(pGrid,pPlayer);
	pPlayer->SetWallet(pPlayer->GetWallet()+walletAmount);
}

void CardTwo::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);

	OutFile << walletAmount<<endl;
}

void CardTwo::Read(ifstream &InFile){
	InFile>>walletAmount ;
}


int CardTwo::getinfo1()
{
	return walletAmount;
}

void CardTwo::setinfo1(int w)
{
	walletAmount = w;
}