/*

Utwórz klasę GrupaDziekanska. Klasa reprezentuje fikcyjną grupę osób które mają określony numer indeksu i jeden lub dwa skojarzone z tym numerem adresy e-mail.
Klasa powinna mieć:

pole typu map o nazwie grupa łączące adresy e-mail studentów z ich numerami indeksów (jeden student może mieć kilka adresów e-mail),

metodę wyswietlgrupe wyświetlającą wszystkie elementy mapy

metodę findklucz wyszukującą klucz z mapy grupa o podanej w argumencie wartości,

metodę szukajwartosc wyszukującą i wyświetlającą z mapy wszystkie elementy o wartości podanej w argumencie.

Przetestuj działanie programu na następujących danych:
anna.nowak@gmail.com 1100
s54321@pollub.edu.pl 1101
s99999@pollub.edu.pl 1100
s12345@pollub.edu.pl 1001
s55555@pollub.edu.pl 1002
jan.kowalski@gmail.com 1010
s11111@pollub.edu.pl 1010

wyświetl wszystkich członów grupy dziekańskiej

wyszukaj adres jan.kowalski@gmail.com i wyświetl informacje dotyczące elementu wyszukanego mapy,

wyszukaj i wyświetl wszystkie elementy mapy o numerze indeksu 1100.

*/

#include <iostream>
#include <map>

using namespace std;

class GrupaDziekanska
{
private:
    map<string, string> student;

public:
    GrupaDziekanska() {}
    ~GrupaDziekanska() {}
    void wyswietlgrupe()
    {
        cout << "Cala grupa dziekanska:" << endl;
        for (auto i : student)
        {
            cout << i.first << " " << i.second << endl;
        }
    }

    void szukajwartosc(string wart)
    {
        cout << "Elementy mapy o wartosci " << wart << ":" << endl;
        int l = 0;
        for (auto i : student)
        {
            if (i.second == wart)
            {
                l++;
                cout << i.first << " " << i.second << endl;
            }
        }
        if (l == 0)
            cout << "BRAK" << endl;
    }

    void add(string email, string ind)
    {
        student.insert(pair<string, string>(email, ind));
    }

    void print()
    {
        cout << "Wszyscy studenci w grupie: " << endl;
        for (auto i : student)
        {
            cout << "Email: " << i.first << ", inex: " << i.second << endl;
        }
    }

    void findklucz(string klucz)
    {
        cout << "Info " << klucz << ":" << endl;
        bool ok = true;
        for (auto i : student)
        {
            if (i.first == klucz)
            {
                cout << "Email: " << i.first << ", inex: " << i.second << endl;
                ok = false;
            }
        }
        if(ok)
        {
            cout << "Nie znaleziono adresu " << klucz << endl;
        }
    }
};

int main()
{
    GrupaDziekanska g1;
    g1.add("anna.nowak@gmail.com", "1100");
    g1.add("s54321@pollub.edu.pl", "1101");
    g1.add("s99999@pollub.edu.pl", "1100");
    g1.add("s12345@pollub.edu.pl", "1001");
    g1.add("s55555@pollub.edu.pl", "1002");
    g1.add("jan.kowalski@gmail.com", "1010");
    g1.add("s11111@pollub.edu.pl", "1010");

    cout << endl;
    g1.print();
    cout << endl;
    g1.findklucz("jan.kowalski@gmail.com");
    cout << endl;
    g1.szukajwartosc("1100");

    return 0;
}
