#include "DataClassifier.h"


void DataClassifier::loadDataFrom(const std::string& filename)
{
	std::ifstream iFile;
	iFile.open(filename, std::ios::in);

	std::string buffer;
	std::string field;
	std::vector<std::string> clientInfo;

	//skip first line
	std::getline(iFile, buffer);
	buffer.clear();

	while (std::getline(iFile, buffer))
	{
		
		std::stringstream bufferStream(buffer);

		while (std::getline(bufferStream, field, ';'))
		{
			clientInfo.push_back(field);
			field.clear();
		}
		
		clientData.insert(ClientProfile(clientInfo));

		field.clear();
		clientInfo.clear();
		buffer.clear();
		

	}

	iFile.close();

}



DataClassifier::DataClassifier(const std::string& filename, unsigned int _k)
{
	loadDataFrom(filename);
	databaseFilename = filename;

	if (_k > clientData.size())
		k = clientData.size();
	else if (_k == 0)
		k = 1;
	else
		k = _k;
}

void DataClassifier::printData()
{
	
	for (std::multiset<ClientProfile>::iterator it = clientData.begin(); it != clientData.end(); it++)
		std::cout << *it;

}

void DataClassifier::addClientProfile(ClientProfile clip)
{
	clientData.insert(clip);

	std::ofstream oFile;
	oFile.open(databaseFilename, std::ios::out | std::ios::app);
	
	if (!oFile)
	{
		std::cerr << "Database file " << databaseFilename << " error!\n";
		return;
	}
	
	oFile << clip;

	oFile.close();

}

ClientProfile DataClassifier::classify(int testExpend, Frequency testFreq)
{
	unsigned int nearestByExpendCount = 0;

	bool testInterest = false;

	std::vector<std::multiset<ClientProfile>::iterator> kNearestByExpend;

	std::multiset<ClientProfile>::iterator i = clientData.lower_bound(testExpend);
	std::multiset<ClientProfile>::iterator j = i;

	kNearestByExpend.push_back(j);
	nearestByExpendCount++;

	i++;
	j--;

	while (nearestByExpendCount < k)
	{
		
		if (abs(i->getExpenditure() - testExpend) < abs(j->getExpenditure() - testExpend))
		{
			kNearestByExpend.push_back(i);
			i++;

		}
		else
		{
			kNearestByExpend.push_back(j);
			j--;

		}

		nearestByExpendCount++;
	}

	

	return ClientProfile(testExpend, testFreq, testInterest);
}
