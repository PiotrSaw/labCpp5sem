#include <iostream>
#include "MeanBufor.h"
#include "MaxBufor.h"
#include "Bufor.h"
using namespace std;

int main()
{
    MeanBufor * b1 = new MeanBufor(6);
    b1->add(7);
    b1->add(15);
    b1->add(5);
    b1->add(8);
    cout << "Pierwszy: " << b1->getFirst() << endl;
    cout << "Srednia: " << b1->calculate() << endl;
    b1->print();

    cout << endl << endl;

    MeanBufor * b2 = new MeanBufor();
    b2->add(26);
    b2->add(11);
    b2->add(7);
    b2->add(83);
    cout << "Pierwszy: " << b2->getFirst() << endl;
    cout << "Srednia: " << b2->calculate() << endl;
    b2->print();

    cout << endl << endl;

    MaxBufor * b3 = new MaxBufor(3);
    b3->add(17);
    b3->add(18);
    b3->add(19);
    b3->add(20);
    cout << "Pierwszy: " << b3->getFirst() << endl;
    cout << "Max: " << b3->calculate() << endl;
    b3->print();


    delete b1;
    delete b2;
    delete b3;
    return 0;
}
