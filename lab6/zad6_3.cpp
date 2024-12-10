#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <boost/bind.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace boost::placeholders; 

template <typename T>
void statistics(vector<T> vect)
{
    sort(vect.begin(), vect.end());
    double avg = 0;
    double me = 0;
    int size = vect.size();
    if (size % 2 == 0)
        me = (vect[size / 2] + vect[size / 2 + 1]) / 2.0;
    else
        me = vect[(size + 1) / 2.0];
    for (T elem : vect)
    {
        avg += elem;
    }
    avg /= size;

    cout << "Srednia elementow wynosi " << avg << ", a mediana: " << me << endl;

    int l1 = 0, l2 = 0, l3 = 0;

    for (T elem : vect)
    {
        if(elem < avg) l1++;
        if((elem > avg && elem < me) || (elem < avg && elem > me)) l2++;
        if(elem > 0) l3++;
    }

    cout << "Liczba elementow mniejszych niz srednia arytmetyczna: " << l1 << endl;
    cout << "Liczba elementow miedzy srednia a mediana: " << l2 << endl;
    cout << "Liczba elementow dodatnich: " << l3 << endl;
}

int main()
{
    vector<int> v1 = {1, -5, 2, 6, 8, -2, 4, 62, 7, -25, 7, 5, 2, -2, 5, 62, 6};
    vector<double> v2 = {1.5, 34.347, -26.88, 26.43, -1.85, 0.747, 27.888};
    cout << "\033[32mTyp int: \033[0m" << endl;
    auto f1 = boost::bind(&statistics<int>,_1);
    f1(v1);
    cout << "\033[32mTyp double: \033[0m" << endl;
    auto f2 = boost::bind(&statistics<double>,_1);
    f2(v2);
    return 0;
}