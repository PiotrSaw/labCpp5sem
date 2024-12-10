#ifndef CITIZEN_H
#define CITIZEN_H
#include <string>

using namespace std;

class Citizen
{
    public:
        Citizen();
        Citizen(string n, string sn, int a, char s, string p_c);
        virtual ~Citizen();
        void show();
        string getName();
        string getSurname();
        int getAge();
        char getSex();
        string getPostal_code();

    private:
        string name;
        string surname;
        int age;
        char sex;
        string postal_code;
};

#endif // CITIZEN_H
