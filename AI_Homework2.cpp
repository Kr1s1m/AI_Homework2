#include "DataClassifier.h"



int main()
{
    DataClassifier dclassifier("test.csv", 7);


    dclassifier.printData();

    std::cout << "\n\n\n\n";

    std::cout << dclassifier.classify(1000, Frequency::Sometimes) << "\n";


    return 0;
}


