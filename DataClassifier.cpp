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

void DataClassifier::setK(unsigned int _k)
{
	k = _k;
}

std::pair<double, double> DataClassifier::normalizeData(const ClientProfile& clip)
{
	double minExpend = clientData.begin()->getExpenditure();
	double maxExpend = (--clientData.end())->getExpenditure();

	double expend = ((double)clip.getExpenditure() - minExpend) / ((double)maxExpend - minExpend);

	double freq = ((double)clip.getFrequency() - (double)Frequency::Rarely) / ((double)Frequency::VeryOften - (double)Frequency::Rarely);

	return std::make_pair(expend, freq);
}

double DataClassifier::getDistanceBetween(const ClientProfile& left, const ClientProfile& right)
{
	std::pair<double, double> leftNorm = normalizeData(left);
	std::pair<double, double> rightNorm = normalizeData(right);

	double x1 = leftNorm.first;
	double x2 = leftNorm.second;

	double y1 = rightNorm.first;
	double y2 = rightNorm.second;

	double euqlid = sqrt(((x1 - y1) * (x1 - y1)) + ((x2 - y2) * (x2 - y2)));

	return euqlid;
}

bool DataClassifier::getMajority(minHeap& distQ)
{
	unsigned int interested = 0;
	unsigned int notIntersted = 0;
	unsigned int examined = 0;

	bool closest = distQ.top().first()->caresAboutSpecialOffers();


	while (examined < k && !distQ.empty())
	{

		if (distQ.top().first()->caresAboutSpecialOffers())
			interested++;
		else
			notIntersted++;

		distQ.pop();
		examined++;

		if (interested > k / 2) return true;

	    if (notIntersted > k / 2) return false;
		
	}

	return (interested == notIntersted) ? closest : (interested > notIntersted);
}


ClientProfile DataClassifier::classify(int testExpend, Frequency testFreq)
{
	minHeap distanceQueue;

	ClientProfile test(testExpend, testFreq, false);

	for (std::multiset<ClientProfile>::iterator it = clientData.begin(); it != clientData.end(); ++it)
		distanceQueue.push(ClientDistancePair( it, getDistanceBetween(*it, test) ));

	return ClientProfile(testExpend, testFreq, getMajority(distanceQueue)); 
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

void DataClassifier::printData()
{

	for (std::multiset<ClientProfile>::iterator it = clientData.begin(); it != clientData.end(); it++)
		std::cout << *it;

}