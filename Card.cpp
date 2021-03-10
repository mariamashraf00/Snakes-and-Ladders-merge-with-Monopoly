#include "Card.h"
#include <fstream>

Card::Card(const CellPosition & pos) : GameObject(pos) 
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum;
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{


	pOut->DrawCell(position,cardNumber);
}

void Card::ReadCardParameters(Grid * pGrid)
{
	
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}


void Card::Save(ofstream &OutFile, type t) {

	OutFile << cardNumber << " "<< position.GetCellNum()<<" ";

}

int Card::getinfo1()
{
	return 0;
}

void Card::setinfo1(int w)
{
}

Card::~Card()
{
}

void Card::Read(ifstream &InFile){}