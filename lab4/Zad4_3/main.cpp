#include <iostream>
#include "Citizen.h"
#include "City.h"
#include <vector>

using namespace std;

void sort_cities(vector <City> &c)
{
    for(int i = 0; i<c.size()-1; i++)
    {
        for(int j = i+1; j<c.size(); j++)
        {
            if(c[i].how_many_citizens() > c[j].how_many_citizens()) swap(c[i], c[j]);
        }
    }
}

void statatistic(vector <City> c)
{
    for(vector<City>::iterator it = c.begin(); it != c.end(); it++)
    {
        it->show_city();
        int citizens = it->how_many_citizens();
        int women = it->women();
        int men = citizens - women;
        int adults = it->adults();
        int children = citizens - adults;

        cout << "Liczba mieszkancow: " << citizens << ", kobiety: " << women << ", mezczyzni: " << men << ", dorosli: " << adults << ", dzieci: " << children << endl;
    }
}

void showCities(vector<City> c)
{
    for(vector<City>::iterator it = c.begin(); it != c.end(); it++)
    {
        cout << "Nazwa: "; it->show_city();
        cout << "Liczba kobiet: " << it->women() << endl;
        cout << "Dorosli: " << it->adults() << endl;
        cout << "Kody pocztowe: " << it->postal_codes() << endl;
        cout << endl << endl;
    }
}

void the_most(vector<City> c, int mode)
{
    if (mode == 1)
    {
        vector<City>::iterator max = c.begin();
        for(vector<City>::iterator it = c.begin(); it != c.end(); it++)
        {
            if(max->how_many_postal_codes() < it->how_many_postal_codes()) max = it;
        }

        cout << "Pierwsze miasto w ktorym jest najwiecej kodow pocztowych to: "; max->show_city();
    }
    else if(mode == 2)
    {
        vector<City>::iterator min = c.begin();
        for(vector<City>::iterator it = c.begin(); it != c.end(); it++)
        {
            if(min->how_many_citizens() > it->how_many_citizens()) min = it;
        }

        cout << "Pierwsze miasto w ktorym jest najmniej mieszkancow to: "; min->show_city();
    }
}


int main()
{

    Citizen c1("Jan", "Kowalski", 56, 'm', "20-123");
    Citizen c2("Janina", "Kowalska", 54, 'k', "20-123");
    Citizen c3("Michal", "Nowak", 23, 'm', "20-111");
    Citizen c4("Michalina", "Nowak", 56, 'k', "20-111");
    Citizen c5("Aleksander", "Kowalski", 14, 'm', "20-777");
    Citizen c6("Stefan", "Wisnia", 79, 'm', "00-234");
    Citizen c7("Anna", "Sliwka", 33, 'k', "00-246");
    Citizen c8("Jakub", "Kowalski", 11, 'm', "00-948");
    Citizen c9("Jan", "Kowalski", 51, 'm', "00-948");
    Citizen c10("Adam", "Kowalski", 26, 'm', "00-948");

    City city1("Lublin");
    City city2("Warszawa");

    city1.addCitizen(c1);
    city1.addCitizen(c2);
    city1.addCitizen(c3);
    city1.addCitizen(c4);
    city1.addCitizen(c5);

    city2.addCitizen(c6);
    city2.addCitizen(c7);
    city2.addCitizen(c8);
    city2.addCitizen(c9);
    city2.addCitizen(c10);

    city2.deleteCitizen("Kowalski", 26);

    city2.show_citizens();
    city1.show_city();
    cout << "Women: " << city1.women() << endl;
    cout << "Adults: " << city2.adults() << endl;
    cout << "Miasto 1:\n" << city1.postal_codes() << endl;
    cout << "Miasto 2:\n" << city2.postal_codes() << endl;



    vector<City> cities;
    cities.push_back(city1);
    cities.push_back(city2);

    cout << "\n\n\n\n";
    showCities(cities);
    cout << "\n\n";

    the_most(cities, 1);
    the_most(cities, 2);
    cout << endl;

    sort_cities(cities);
    statatistic(cities);

    return 0;
}
