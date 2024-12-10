#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
    public:
        Employee();
        Employee(string su, int a, int e, int sa);
        virtual ~Employee();
        virtual void show();
        virtual float calculateBonus(int value) = 0;
        int ageEmployment();
        string getSurname();
        int getAge();
        int getExperience();
        int getSalary();


    protected:

    private:
        string surname;
        int age;
        int experience;
        int salary;
};

#endif // EMPLOYEE_H
