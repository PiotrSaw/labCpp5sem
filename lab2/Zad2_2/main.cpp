#include <iostream>

#include "Employee.h"
#include "Developer.h"
#include "TeamLeader.h"

using namespace std;

void whoWorkMoreThan5Years(Employee ** e, int size)
{
    for(int i = 0; i<size; i++)
    {
        if(e[i]->getExperience() > 5) e[i]->show();
    }
}

float averageBonus(Employee ** e, int size)
{
    float sum = 0;

    for(int i = 0; i<size; i++)
    {
        sum += e[i]->calculateBonus(1); // nie wiem co to jest to value we wzorze ktore musze podac jako parametr wywolania
    }
    cout << sum/size << endl;;
    return sum/size;
}

int howManyEarnLessThanMeanBonus(Employee ** e, int size)
{
    float average = averageBonus(e, size);
    int quantity = 0;
    for(int i = 0; i<size; i++)
    {
        if(e[i]->calculateBonus(1) < average)
        quantity ++;
    }

    return quantity;
}

int main()
{
    int size = 5; // rozmiar tablicy
    Employee ** e = new Employee*[size];

    e[0] = new Developer("Kowalski", 35, 10, 15000);
    e[1] = new Developer("Wisniewska", 24, 1, 7000);
    e[2] = new TeamLeader("Nowak", 40, 7, 11000);
    e[3] = new Developer("Nowakowski", 50, 30, 28000);
    e[4] = new TeamLeader("Krol", 29, 3, 9000);

    cout << "Pracuja wiecej niz 5 lat:" << endl;
    whoWorkMoreThan5Years(e, size);
    cout << endl;
    cout << "Ilosc osob majaca premie ponizej sredniej: " << howManyEarnLessThanMeanBonus(e, size) << endl;

    for(int i = 0; i<size; i++) delete e[i];
    delete [] e;
    return 0;
}
