#include "MaxBufor.h"
#include <iostream>

MaxBufor::MaxBufor() : Bufor()
{
    //ctor
}

MaxBufor::MaxBufor(int s) : Bufor(s)
{
    //ctor
}

MaxBufor::~MaxBufor()
{
    //dtor
}

double MaxBufor::calculate()
{
    double max = getTab(0);
    for(int i = 1; i<getIndex(); i++) if(getTab(i) > max) max = getTab(i);
    return max;
}

void MaxBufor::add(int value)
{
    if(getIndex() < getSize())
    {
        setFirst(value);
        setIndex();
    }
    else std::cout << "Nie mozna dodac kolejnego elementu!" << std::endl;
}
