#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    cout << "Tablica int:" << endl;
    Array<int> a1(5);
    a1.add(10);
    a1.add(7);
    a1.add(4);
    a1.add(8);
    a1.sort_tab();
    cout << "Max = " << a1.max() << endl;
    a1.print();
    cout << "Element pod indexem 1 to " << a1.elem(1) << endl;


    cout << endl << endl << "Tablica string:" << endl;
    Array<string> a2(4);
    a2.add("Ala ma kota");
    a2.add("NIE WIEM");
    a2.add("OK");
    a2.add("Jan Kowalski");
    a2.sort_tab();
    cout << "Max = " << a2.max() << endl;
    a2.print();
    cout << "Element pod indexem 1 to " << a2.elem(1) << endl;


    return 0;
}
