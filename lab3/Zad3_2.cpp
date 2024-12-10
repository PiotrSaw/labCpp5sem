#include <iostream>

using namespace std;

template <typename T>
T min(T *tab, int n)
{
    T min = tab[0];
    for(int i = 1; i<n; i++)
    {
        if(tab[i] < min)
        {
            min = tab[i];
        }
    }
    return min;
}

int main()
{
    int tab1[] = {1, 6, 3, 7, 3, 5, 8};
    cout << "Element minimalny tablicy tab1 jest " << min(tab1, 7) << endl;

    double tab2[] = {7.2, 8.4, 6.36, 7.11};
    cout << "Element minimalny tablicy tab2 jest " << min(tab2, 4) << endl;


    return 0;
}
