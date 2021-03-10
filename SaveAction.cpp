#include "SaveAction.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include "Grid.h"

SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
	CardTen::isCardTenSaved=false;
	CardEleven::isCardElevenSaved=false;
	CardTwelve::isCardTwelveSaved=false;
	CardThirteen::isCardThirteenSaved=false;
	CardFourteen::isCardFourteenSaved=false;
}

SaveAction::~SaveAction()
{
}

void SaveAction::ReadActionParameters()
{
}

void SaveAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output * pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter File Name");
	filename = pIn->GetSrting(pOut);

	if(!extensionCheck(filename))
		filename.append(".txt");
	data.open (filename.c_str());
	if (data.is_open()==false)
	{
		ofstream data (filename.c_str());
	}
	pGrid->calcnumberofobjects();
	pGrid->SaveAll(data, ladder);
	pGrid->SaveAll(data, snake);
	pGrid->SaveAll(data, card);
	data.close();
	pOut->PrintMessage("Grid Data Saved");
}
bool SaveAction::extensionCheck(const std::string &str)
{
	string suffix = ".txt";
	return str.size() >= suffix.size() &&
		str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}
