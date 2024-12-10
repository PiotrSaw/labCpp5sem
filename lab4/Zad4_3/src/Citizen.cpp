#include "Citizen.h"
#include <iostream>

Citizen::Citizen()
{
    //ctor
}

Citizen::~Citizen()
{
    //dtor
}

Citizen::Citizen(string n, string sn, int a, char s, string p_c)
{
    name = n;
    surname = sn;
    age = a;
    sex = s;
    postal_code = p_c;
}

void Citizen::show()
{
    std::cout << "Imie: " << name << ", nazwisko: " << surname << ", wiek: " << age << ", plec: " << sex << ", kod pocztowy: " << postal_code << endl;
}

string Citizen::getName()
{
    return name;
}

string Citizen::getSurname()
{
    return surname;
}

int Citizen::getAge()
{
    return age;
}

char Citizen::getSex()
{
    return sex;
}

string Citizen::getPostal_code()
{
    return postal_code;
}
