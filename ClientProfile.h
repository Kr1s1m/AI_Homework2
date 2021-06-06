#pragma once

#include <iostream>
#include <vector>
#include <string>

enum class Frequency
{
    Never,
    Rarely,
    Sometimes,
    Often,
    VeryOften,

    
};

std::ostream& operator<<(std::ostream&, const Frequency&);
Frequency& operator++(Frequency&);


class ClientProfile
{
private:

    int expenditure;
    Frequency frequency;

    bool discount;

    Frequency getFrequency(const std::string&);

public:

    ClientProfile(int = 0, Frequency = Frequency::Never, bool = false);
    ClientProfile(const std::vector<std::string>&);

    int getExpenditure() const;
    Frequency getFrequency() const;
    bool caresAboutSpecialOffers() const;

    friend bool operator<(const ClientProfile&, const ClientProfile&);

    friend std::ostream& operator<<(std::ostream&, const ClientProfile&);

};
