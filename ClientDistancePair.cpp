#include "ClientDistancePair.h"

ClientDistancePair::ClientDistancePair(std::multiset<ClientProfile>::iterator _clientPtr, double _distance) :
	clientPtr(_clientPtr), distance(_distance)
{
}

std::multiset<ClientProfile>::iterator ClientDistancePair::first() const
{
	return clientPtr;
}

double ClientDistancePair::second() const
{
	return distance;
}

bool operator>(const ClientDistancePair& left, const ClientDistancePair& right)
{
	return left.distance > right.distance;
}
