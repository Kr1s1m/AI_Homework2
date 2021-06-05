#include "ClientProfile.h"

Frequency ClientProfile::getFrequency(const std::string& freqDescription)
{
	switch (freqDescription[0])
	{
		case 'V' :
			return Frequency::VeryOften;
		break;

		case 'O':
			return Frequency::Often;
		break;

		case 'S':
			return Frequency::Sometimes;
		break;

		case 'R':
			return Frequency::Rarely;
		break;
		
		default:
			return Frequency::Never;
		break;
			
	}
}

ClientProfile::ClientProfile(int _expenditure, Frequency _frequency , bool _discount) :
	expenditure(_expenditure), frequency(_frequency), discount(_discount) { };


ClientProfile::ClientProfile(const std::vector<std::string>& clientInfo)
{
	if (clientInfo.size() != 3)
	{
		expenditure = 0;
		frequency = Frequency::Never;
		discount = false;
	}
	else
	{
		expenditure = stoi(clientInfo[0]);
		frequency = getFrequency(clientInfo[1]);
		discount = stoi(clientInfo[2]) ? true : false;
	}
	
}

int ClientProfile::getExpenditure() const
{
	return expenditure;
}

Frequency ClientProfile::getFrequency() const
{
	return frequency;
}

bool ClientProfile::caresAboutSpecialOffers() const
{
	return discount;
}



bool operator<(const ClientProfile& left, const ClientProfile& right)
{
	
	if (left.expenditure == right.expenditure)
		return (int)left.frequency < (int)right.frequency;
	

	return left.expenditure < right.expenditure;
}

std::ostream& operator<<(std::ostream& os, const ClientProfile& clip)
{
	std::string freqDescr;

	switch (clip.frequency)
	{
		case Frequency::Rarely :
			freqDescr = "Rarely";
		break;

		case Frequency::Sometimes :
			freqDescr = "Sometimes";
		break;

		case Frequency::Often :
			freqDescr = "Often";
		break;

		case Frequency::VeryOften :
			freqDescr = "Very often";
		break;

		default:
			freqDescr = "Never";
		break;
	}

	return os << "\n" << clip.expenditure << ";" << freqDescr << ";" << clip.discount;
}
