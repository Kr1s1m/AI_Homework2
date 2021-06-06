#include "DataClassifier.h"



int main()
{

    // Prefer the use of odd numbers for k to avoid ties, since there are only two possible classes.
    // If there is a tie, the class of the closest example will be chosen.
    int k = 7;

    DataClassifier dclassifier("Training dataset HW2_AI 2021.csv", k);

    std::cout <<  dclassifier.classify(1000, Frequency::Sometimes) << "  <------- Test example classified!"<< "\n";


    return 0;
}


