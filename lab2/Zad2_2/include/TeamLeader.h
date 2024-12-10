#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include "Employee.h"


class TeamLeader : public Employee
{
    public:
        TeamLeader();
        TeamLeader(string su, int a, int e, int sa);
        virtual ~TeamLeader();
        virtual float calculateBonus(int value) override;
        virtual void show() override;

    protected:

    private:
};

#endif // TEAMLEADER_H
