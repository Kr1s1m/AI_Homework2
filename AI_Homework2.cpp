#include "DataClassifier.h"



int main()
{
    DataClassifier dclassifier("test.csv", 5);


    dclassifier.printData();

    std::cout << "\n\n\n\n";

    dclassifier.classify(1000, Frequency::Sometimes);


    return 0;
}


