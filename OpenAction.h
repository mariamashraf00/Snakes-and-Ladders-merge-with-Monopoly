#pragma once
#include<fstream>

#include "Action.h"

class OpenAction : public Action
{
	string filename;
	ifstream Infile;
	bool extensionCheck(const std::string &str);
public:
	OpenAction(ApplicationManager *pApp); 

	virtual void ReadActionParameters();

	virtual void Execute(); 


	virtual ~OpenAction();
};
