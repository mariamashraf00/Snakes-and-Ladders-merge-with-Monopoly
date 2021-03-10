#include "OpenAction.h"
#include <string>

#include "CellPosition.h"

#include "Card.h"
#include "Ladder.h"
#include "Snake.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

#include <fstream>

OpenAction::OpenAction(ApplicationManager *pApp) : Action(pApp)
{
}

OpenAction::~OpenAction()
{
}

void OpenAction::ReadActionParameters() 
{	
	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter File Name");
	filename = pIn->GetSrting(pOut);

	if(!extensionCheck(filename))
		filename.append(".txt");

}

void OpenAction::Execute() 
{
	
	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pGrid->ClearGridArea();

	ReadActionParameters();

	Infile.open (filename.c_str());
	if(!Infile.is_open())
	{
		pOut->PrintMessage("File doesn't exist!");
	}
	else{
		int d,z,f;
		Infile >> d; //number of ladders
		for(int i=0;i<d;i++)
		{
			Infile >> z; //start cell
			Infile >> f; //end cell
			CellPosition cellpo(z);
			CellPosition cellpos(f);
			Ladder* Ladp = new Ladder(cellpo,cellpos);
			pGrid->AddObjectToCell(Ladp);
		}
		Infile >> d; //now d = number of snakes
		for(int i=0;i<d;i++)
		{
			Infile >> z; //start cell
			Infile >> f; //end cell
			CellPosition cellpo(z);
			CellPosition cellpos(f);
			Snake* Snakep = new Snake(cellpo,cellpos);
			pGrid->AddObjectToCell(Snakep);
		}
		Infile >> d; //now d = number of cards
		CardTen::CardTenNUM =0;
		CardEleven::CardElevenNUM =0;
		CardTwelve::CardTwelveNUM =0;
		CardThirteen::CardThirteenNUM =0;
		CardFourteen::CardFourteenNUM =0;
		for(int i=0;i<d;i++)
		{
			Infile >> z;
			Infile >> f;
			CellPosition cellposs(f);
			Card *cp = NULL;

			switch(z){
			case 1:
				cp = new CardOne(cellposs);
				break;
			case 2:
				cp = new CardTwo(cellposs);
				break;
			case 3:
				cp = new CardThree(cellposs);
				break;
			case 4:
				cp = new CardFour(cellposs);
				break;
			case 5:
				cp = new CardFive(cellposs);
				break;
			case 6:
				cp = new CardSix(cellposs);
				break;
			case 7:
				cp = new CardSeven(cellposs);
				break;
			case 8:
				cp = new CardEight(cellposs);
				break;
			case 9:
				cp = new CardNine(cellposs);
				break;
			case 10:
				cp = new CardTen(cellposs);
				break;
			case 11:
				cp = new CardEleven(cellposs);
				break;
			case 12:
				cp = new CardTwelve(cellposs);
				break;
			case 13:
				cp = new CardThirteen(cellposs);
				break;
			case 14:
				cp = new CardFourteen(cellposs);
				break;
			}

			cp->Read(Infile);
			pGrid->AddObjectToCell(cp);
		}

		Infile.close();
	}
}

bool OpenAction::extensionCheck(const std::string &str)
{
	string suffix = ".txt";
	return str.size() >= suffix.size() &&
		str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}
