#ifndef DEVELOPER_H
#define DEVELOPER_H
#include "Employee.h"


class Developer : public Employee
{
    public:
        Developer();
        Developer(string su, int a, int e, int sa);
        virtual ~Developer();
        virtual float calculateBonus(int value) override;

    protected:

    private:
};

#endif // DEVELOPER_H
