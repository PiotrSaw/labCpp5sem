#include <iostream>
#include <QMap>
#include <algorithm>
#include <cctype>

using namespace std;

class Kraje
{
private:
    QMap<string, int> kraje;  // Zmieniamy map na QMap

public:
    Kraje() {}
    
    // Dodanie kraju do mapy
    void dodajKraj(string nazwa, int ludnosc)
    {
        kraje.insert(nazwa, ludnosc);
    }

    // Wyświetlenie wszystkich krajów i ich ludności
    void wyswietl()
    {
        for (auto k : kraje)
        {
            cout << k.first << "  " << k.second << endl;
        }
    }

    // Wyświetlenie tylko nazw krajów
    void wyswietlKraje()
    {
        for (auto k : kraje)
        {
            cout << k.first << endl;
        }
    }

    // Usunięcie kraju z mapy
    void usunKraj(string s)
    {
        kraje.remove(s);  // Używamy remove zamiast erase
    }
};

int main()
{
    Kraje kraje;
    kraje.dodajKraj("Kraj1", 50000000);
    kraje.dodajKraj("Kraj2", 150000000);
    kraje.dodajKraj("Kraj3", 430000000);
    kraje.dodajKraj("Kraj4", 130000000);
    kraje.dodajKraj("Kraj5", 52000000);

    cout << "Wszystkie dane:" << endl;
    kraje.wyswietl();

    cout << "Same kraje:" << endl;
    kraje.wyswietlKraje();

    cout << "Usunięcie kraju Kraj5" << endl;
    kraje.usunKraj("Kraj5");

    cout << "Wszystkie dane po usunięciu Kraj5:" << endl;
    kraje.wyswietl();

    return 0;
}
