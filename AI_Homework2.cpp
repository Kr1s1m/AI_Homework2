#include "DataClassifier.h"



int main()
{
    int k = 7;

    DataClassifier dclassifier("Training dataset HW2_AI 2021.csv", k);


    std::cout << dclassifier.classify(1000, Frequency::Sometimes) << "\n";


    return 0;
}


