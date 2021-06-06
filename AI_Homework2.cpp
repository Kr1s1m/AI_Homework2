#include "DataClassifier.h"



int main()
{

    std::ofstream outputFile("results.txt", std::ios::out);


    DataClassifier dclassifier("Training dataset HW2_AI 2021.csv");




    for (unsigned int expenditure = 500; expenditure < 1910; expenditure += 10)
    {
        for (Frequency frequency = Frequency::Rarely; frequency != Frequency::Never; ++frequency)
        {
            outputFile << "expenditure: " << expenditure << ",  freqency: " << frequency << "\n";

            for (unsigned int k = 1; k < 41; k += 1)
            {
                dclassifier.setK(k);
                outputFile << dclassifier.classify(expenditure, frequency).caresAboutSpecialOffers() << "     k = " << k << "\n";
            }

            outputFile << "\n\n\n";
        }
    }

    
    

    
    


    return 0;
}


