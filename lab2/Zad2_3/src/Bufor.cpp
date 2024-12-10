#include <iostream>
#include "Bufor.h"

using namespace std;

Bufor::Bufor()
{
    table = new int[10];
    size = 10;
    index = 0;
}

Bufor::~Bufor()
{
    delete [] table;
}


Bufor::Bufor(int s)
{
    size = s;
    table = new int[s];
    index = 0;
}

void Bufor::add(int value)
{
    table[index] = value;
    index++;
}

int Bufor::getIndex()
{
    return index;
}

int Bufor::getSize()
{
    return size;
}

int Bufor::getTab(int i)
{
    return table[i];
}

int Bufor::getFirst()
{
    return table[0];
}

void Bufor::setFirst(int value)
{
    table[index] = value;
}

void Bufor::setTab(int pos, int value)
{
    table[pos] = value;
}

void Bufor::print()
{
    cout << "Zawartosc tablicy:" << endl;
    for(int i = 0; i<index; i++) cout << table[i] << "  ";
    cout << endl;
}

void Bufor::setIndex()
{
    index++;
}

