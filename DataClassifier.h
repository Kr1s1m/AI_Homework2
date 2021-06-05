#pragma once


#include <fstream>
#include <sstream>
#include <set>

#include "ClientProfile.h"


class DataClassifier
{
private:

	unsigned int k;

	std::multiset<ClientProfile> clientData;

	std::string databaseFilename;

	void loadDataFrom(const std::string&);

public:
	
	DataClassifier(const std::string&, unsigned int = 1);

	void printData();
	void addClientProfile(ClientProfile);
	
	ClientProfile classify(int, Frequency);


};

