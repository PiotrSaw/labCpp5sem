#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
using namespace std;

int main()
{
    srand(time(0));
    int n = rand()%20 + 1; // losowanie liczby od 1 do 20 wlacznie
    list<int> lista;
    int liczba;

    for(int i = 0; i<n; i++)
    {
        liczba = rand()%201 - 100;

        if(liczba >= 0) lista.push_front(liczba);
        else lista.push_back(liczba);
    }
    for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
        cout << *it << "  ";  // Wyswietlanie kazdego elementu
    }
}
