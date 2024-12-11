/*

Utwórz funkcję szablonową wspolne(), która jako parametr przyjmie dwa kontenery typu vector przechowujące dane tego samego typu określonego poprzez szablon. Funkcja powinna wyznaczyć część wspólną zbiorów i zapisać ją w nowym kontenerze typu set zwracanym jako wynik działania funkcji.

Za pomocą pełnej specjalizacji należy zdefiniować funkcję tak aby możliwe było jej uruchomienie dla danych typu int oraz float. W przypadku typu float wynikowy kontener typu set powinien zostać zbudowany tak aby porównywał i zapisywał elementy z dokładnością do 1-go miejsca po przecinku.

Zbuduj program testujący działanie funkcji wspolne() zbiorów typu int oraz float.

*/

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T>
set<T> wspolne(vector<T> v1, vector<T> v2)
{
    set<T> wynik;
    set<T> s1, s2;
    for (auto i : v1)
    {
        s1.insert(i);
    }

    for (auto i : v2)
    {
        s2.insert(i);
    }
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator<set<T>>(wynik, wynik.begin()));
    return wynik;
}

template <>
set<int> wspolne<int>(vector<int> v1, vector<int> v2)
{
    set<int> wynik;
    set<int> s1, s2;
    for (auto i : v1)
    {
        s1.insert(i);
    }

    for (auto i : v2)
    {
        s2.insert(i);
    }
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator<set<int>>(wynik, wynik.begin()));
    return wynik;
}

template <>
set<float> wspolne<float>(vector<float> v1, vector<float> v2)
{
    set<float> wynik;

    for(auto i : v1)
    {
        for(auto j : v2)
        {
            if(abs(i-j) < 0.1)
            {
                wynik.insert(i);
            }
        }
    }

    return wynik;
}

int main()
{
    vector<int> int1 = {1, 2, 3, 4, 4, 4, 5, 6};
    vector<int> int2 = {1, 2, 3, 10, 11, 1, 12};
    set<int> wspolneInt = wspolne<int>(int1, int2);
    cout << "Elementy wspolne w wektorach int1, int2 to: ";
    for (auto i : wspolneInt)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<float> float1 = {1.123, 2.222, 43.44, 11.11};
    vector<float> float2 = {1.125, 2.212, 432.44, 11.21};
    set<float> wspolneFloat = wspolne<float>(float1, float2);
    cout << "Elementy wspolne w wektorach float1, float2 to: ";
    for (auto i : wspolneFloat)
    {
        printf("%.1f ", i);
    }
    cout << endl;

    return 0;
}