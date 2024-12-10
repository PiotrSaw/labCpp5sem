#include "Employee.h"
#include <string>
#include <iostream>

using namespace std;

Employee::Employee()
{
    //ctor
}

Employee::Employee(string su, int a, int e, int sa) : surname(su), age(a), experience(e), salary(sa)
{
    //ctor
}

Employee::~Employee()
{
    //dtor
}

string Employee::getSurname() {return surname;}

int Employee::getAge() {return age;}

int Employee::getExperience() {return experience;}

int Employee::getSalary() {return salary;}

void Employee::show()
{
    cout << "Nazwisko: " << surname << ", wiek: " << age << ", doswiadczenie: " << experience << ", wynagrodzenie: " << salary << endl;
}
