#pragma once


#include <fstream>
#include <sstream>
#include <set>
#include <queue>


#include "ClientProfile.h"
#include "ClientDistancePair.h"

typedef std::priority_queue<ClientDistancePair, std::vector<ClientDistancePair>, std::greater<ClientDistancePair>> minHeap;

class DataClassifier
{
private:

	unsigned int k;

	std::multiset<ClientProfile> clientData;

	std::string databaseFilename;

	void loadDataFrom(const std::string&);

	std::pair<double, double> normalizeData(const ClientProfile&);

	double getDistanceBetween(const ClientProfile&, const ClientProfile&);

	bool getMajority(minHeap&);

public:
	
	DataClassifier(const std::string&, unsigned int = 1);

	void printData();
	void addClientProfile(ClientProfile);
	
	ClientProfile classify(int, Frequency);


};

