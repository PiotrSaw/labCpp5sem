#include <iostream>
#include "Dictionary.h"
using namespace std;

int main()
{
    Dictionary dict;
    dict.add("Samochod", "Car");
    dict.add("Rower", "Bike");
    dict.add("Motocykl", "Motorbike");
    dict.add("Tir", "Truck");
    dict.add("Statek", "Ship");

    dict.print();
    cout << endl << endl;
    dict.printTranslation("Samochod");
    dict.deleteWord("Statek");
    dict.printTranslation("Statek");


    return 0;
}
