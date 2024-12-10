#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumacyfr(int l)
{
    int suma = 0;
    if(l<0) l = -l;
    while(l > 0)
    {
        suma += l%10;
        l /= 10;
    }

    return suma;
}

int liczbacyfr(int l)
{
    int liczba = 0;
    if(l<0) l = -l;
    while(l > 0)
    {
        l /= 10;
        liczba ++;
    }

    return liczba;
}

void sort1(vector<int> &v)
{
    for(int i = 0; i<v.size()-1; i++)
    {
        for(int j = i+1; j<v.size(); j++)
        {
            if(sumacyfr(v[i]) > sumacyfr(v[j])) swap(v[i], v[j]);
        }
    }
}

void sort2(vector<int> &v)
{
    for(int i = 0; i<v.size()-1; i++)
    {
        for(int j = i+1; j<v.size(); j++)
        {
            if(liczbacyfr(v[i]) < liczbacyfr(v[j])) swap(v[i], v[j]);
        }
    }
}

void print(int i)
{
    cout << i << "  ";
}

int main()
{
    vector<int> liczby = {1, 6, 2, 6, 3, 7, 3, 5, 8, 4, 8, 5, 2, 65, 2, 6, 7, 3, 7, 5, 72, 5, 52, 6, 62};
    cout << "Posortowane wzgledem sumy cyfr rosnaco: " << endl;
    sort1(liczby);
    for_each(liczby.begin(), liczby.end(), print);
    cout << endl;

    cout << "Posortowane wzgledem liczby cyfr malejaco: " << endl;
    sort2(liczby);
    for_each(liczby.begin(), liczby.end(), print);
    cout << endl;



    return 0;
}
