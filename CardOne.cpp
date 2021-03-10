#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos)
{
	cardNumber = 1; 
}


CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	
	Output * pOut = pGrid->GetOutput();
	Input *pIn = pGrid->GetInput();

	int amount;

	do {
	
	pOut->PrintMessage( "New CardOne: Enter a positive wallet amount to be removed ");

	amount = pIn->GetInteger(pOut);

	walletAmount=amount;
	}
	while (amount<0);
	
	pOut-> ClearStatusBar();

}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	Card::Apply(pGrid,pPlayer);
	
	pPlayer->SetWallet((pPlayer->GetWallet())-walletAmount);
}

void CardOne::Save(ofstream &OutFile, type t) {

	Card::Save(OutFile, t);

	OutFile << walletAmount<<endl;
}

void CardOne::Read(ifstream &InFile){
	InFile>>walletAmount ;
}


int CardOne::getinfo1()
{
	return walletAmount ;
}

void CardOne::setinfo1(int w)
{
	walletAmount = w;
}