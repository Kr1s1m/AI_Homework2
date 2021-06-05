#pragma once
#include "ClientProfile.h"
#include <set>

class ClientDistancePair
{
private:

	std::multiset<ClientProfile>::iterator clientPtr;
	double distance;


public:

	ClientDistancePair(std::multiset<ClientProfile>::iterator, double);

	friend bool operator>(const ClientDistancePair&, const ClientDistancePair&);

	std::multiset<ClientProfile>::iterator first()const;
	double second()const;


};

