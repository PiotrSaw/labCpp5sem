#ifndef MEANBUFOR_H
#define MEANBUFOR_H

#include "Bufor.h"

class MeanBufor : public Bufor
{
    public:
        MeanBufor();
        MeanBufor(int s);
        virtual ~MeanBufor();
        virtual double calculate() override;

    protected:

    private:
};

#endif // MEANBUFOR_H
