#include "MeanBufor.h"

MeanBufor::MeanBufor() : Bufor()
{

}

MeanBufor::MeanBufor(int s) : Bufor(s)
{

}

MeanBufor::~MeanBufor()
{

}

double MeanBufor::calculate()
{
    int sum = 0;
    for(int i = 0; i<getIndex(); i++) sum += getTab(i);
    return sum*1./getIndex();
}
