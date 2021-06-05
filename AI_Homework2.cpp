#include "DataClassifier.h"



int main()
{
    DataClassifier dclassifier("test.csv", 5);


    dclassifier.printData();

    std::cout << "\n\n\n\n";

    std::cout << dclassifier.classify(1000, Frequency::Often);


    return 0;
}


