#include "Developer.h"

Developer::Developer()
{
    //ctor
}

Developer::Developer(string su, int a, int e, int sa) : Employee(su, a, e, sa){}

Developer::~Developer()
{
    //dtor
}

float Developer::calculateBonus(int value)
{
    return value + 0.2 * value * (getSalary() + getExperience());
}
