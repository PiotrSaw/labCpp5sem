#ifndef CITY_H
#define CITY_H
#include <vector>
#include "Citizen.h"


class City
{
    public:
        City();
        City(string n);
        virtual ~City();
        void addCitizen(Citizen z);
        void deleteCitizen(string sn, int a);
        void show_citizens();
        void show_city();
        int women();
        int city_citizens();
        int adults();
        int postal_codes();
        int how_many_citizens();
        int how_many_postal_codes();

    protected:

    private:
        string city_name;
        vector<Citizen> citizens;
};

#endif // CITY_H
