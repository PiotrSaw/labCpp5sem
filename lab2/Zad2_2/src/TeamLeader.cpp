#include "TeamLeader.h"
#include <iostream>
using namespace std;

TeamLeader::TeamLeader()
{
    //ctor
}

TeamLeader::~TeamLeader()
{
    //dtor
}

TeamLeader::TeamLeader(string su, int a, int e, int sa) : Employee(su, a, e, sa){}

float TeamLeader::calculateBonus(int value)
{
    return value * (1 + getSalary() + getExperience());
}

void TeamLeader::show()
{
    cout << "Nazwisko: " << getSurname() << ", wiek: " << getAge() << ", wynagrodzenie: " << getSalary() << endl;
    cout << "Jestem Team Leader z " << getExperience() << " letnim doswiadczeniem" << endl;
}
