#include "City.h"
#include <iostream>
#include <map>

City::City()
{
    //ctor
}

City::City(string n)
{
    city_name = n;
}

City::~City()
{
    //dtor
}

void City::addCitizen(Citizen c)
{
    citizens.push_back(c);
}

 void City::deleteCitizen(string sn, int a)
 {
     int i = 0;
     for(std::vector<Citizen>::iterator it = citizens.begin(); it!=citizens.end(); it++)
     {
         if(it->getSurname() == sn && it->getAge() == a)
         {
             citizens.erase(it);
             break;
         }
     }
 }

 void City::show_citizens()
 {
     for(std::vector<Citizen>::iterator it = citizens.begin(); it!=citizens.end(); it++)
     {
         it->show();
     }
 }

 void City::show_city()
 {
     std::cout << "Miasto: " << city_name << endl;
 }

 int City::women()
 {
     int l = 0;
     for(std::vector<Citizen>::iterator it = citizens.begin(); it!=citizens.end(); it++)
     {
         if(it->getSex() == 'k') l++;
     }
     return l;
 }

 int City::city_citizens()
{
    return citizens.size();
}

int City::adults()
{
    int l = 0;
    for(int i = 0; i<citizens.size(); i++)
    {
        if(citizens.at(i).getAge() >= 18) l++;
    }
    return l;
}


int City::postal_codes()
{
    std::map<string, int> mapa;
    int l = 0;
    for(std::vector<Citizen>::iterator it = citizens.begin(); it!=citizens.end(); it++)
    {
        auto it2 = mapa.find(it->getPostal_code());
        if(it2 != mapa.end())
        {
            mapa[it->getPostal_code()] += 1;
        }else
        {
            mapa[it->getPostal_code()] = 1;
        }
    }

    for (const auto& para : mapa) {
        if(para.second != 1)
        {
            std::cout << para.first << ": " << para.second << std::endl;
        }
        else l++;
    }

    cout << "Liczba unikatowych: ";

    return l;
}

int City::how_many_citizens()
{
    return citizens.size();
}


int City::how_many_postal_codes()
{
    std::map<string, int> mapa;
    int l = 0;
    for(std::vector<Citizen>::iterator it = citizens.begin(); it!=citizens.end(); it++)
    {
        auto it2 = mapa.find(it->getPostal_code());
        if(it2 != mapa.end())
        {
            mapa[it->getPostal_code()] += 1;
        }else
        {
            mapa[it->getPostal_code()] = 1;
        }
    }

    return mapa.size();
}
