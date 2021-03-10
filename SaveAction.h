#pragma once
#include "Action.h"
#include<fstream>
#include <string>
class SaveAction : public Action
{   string filename;
	ofstream data;
	bool extensionCheck(const std::string &str);
public:
	SaveAction(ApplicationManager* pApp);
	~SaveAction();
	void ReadActionParameters();
	void Execute();
};

