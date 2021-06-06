#include "DataClassifier.h"



int main()
{

    std::ofstream outputFile("results.txt", std::ios::out);


    DataClassifier dclassifier("Training dataset HW2_AI 2021.csv");

    
    unsigned int expenditureLow = 500;
    unsigned int expenditureHigh = 1900;

    unsigned int expenditureJump = 25;


    for (unsigned int expenditure = expenditureLow; expenditure < expenditureHigh + expenditureJump; expenditure += expenditureJump)
    {
        for (Frequency frequency = Frequency::Rarely; frequency != Frequency::Never; ++frequency)
        {
            outputFile << "expenditure: " << expenditure << ",  frequency: " << frequency << "\n";

            for (unsigned int k = 1; k < 41; k += 1)
            {
                dclassifier.setK(k);

                ClientProfile classified = dclassifier.classify(expenditure, frequency);
                outputFile << classified.caresAboutSpecialOffers() << "     k = " << k << "\n";
            }

            outputFile << "\n\n\n";
        }
    }

    
    

    
    


    return 0;
}


