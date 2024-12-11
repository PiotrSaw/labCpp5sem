/*

Napisz program zawierający 2 klasy „bazowa” i „pochodna”.
Klasa bazowa powinna zawierać pole liczba - typu int oraz konstruktor wczytujący wartość liczba w argumencie.

W klasie bazowej utwórz 2 metody:
1) print() - drukującą: cout << "liczba bazowa: "<< liczba << endl;
2) metodę wirtualną show() drukującą: cout << "liczba bazowa virtual: "<< liczba << endl;

Klasa pochodna powinna zawierać konstruktor wczytujący wartość liczba*100 w argumencie.
W klasie pochodnej utwórz również 2 metody:
1) print() - drukującą: cout << "liczba pochodna: "<< liczba << endl;
2) metodę wirtualną show() drukującą: cout << "liczba pochodna virtual: "<< liczba << endl;

Napisz program demonstrujący działanie funkcji print() i show() z obu klas i funkcji wirtualnej show().

*/


#include <iostream>

using namespace std;

class Bazowa
{
private:
    int liczba;

public:
    Bazowa(int liczba)
    {
        this->liczba = liczba;
    }

    void print()
    {
        cout << "liczba bazowa: " << liczba << endl;
    }

    virtual void show()
    {
        cout << "liczba bazowa virtual: " << liczba << endl;
    }

    int getLiczba()
    {
        return liczba;
    }
};

class Pochodna : public Bazowa
{

public:
    Pochodna(int liczba): Bazowa(liczba * 100) {}
    void print()
    {
        cout << "liczba pochodna: "<< getLiczba() << endl;
    }

    virtual void show()
    {
        cout << "liczba pochodna virtual: "<< getLiczba() << endl;
    }
};

int main()
{
    Bazowa b(10);
    Pochodna p(10);

    cout << "Dla klasy bazowej:" << endl;
    b.print();
    b.show();

    cout << endl << "Dla klasy pochodnej:" << endl;
    p.print();
    p.show();


    return 0;
}