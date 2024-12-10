#ifndef MAXBUFOR_H
#define MAXBUFOR_H
#include "Bufor.h"

class MaxBufor : public Bufor
{
    public:
        MaxBufor();
        MaxBufor(int s);
        virtual ~MaxBufor();
        virtual double calculate() override;
        void add(int value);

    protected:

    private:
};

#endif // MAXBUFOR_H
