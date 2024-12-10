#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <vector>
#include <map>
using namespace std;
using namespace boost::multi_index;

class Contact
{
public:
    string name;
    string lastname;
    int age;
    string phone_number;
    string street;
    Contact(string name, string lastname, int age, string phone_number, string street)
    {
        this->name = name;
        this->lastname = lastname;
        this->age = age;
        this->phone_number = phone_number;
        this->street = street;
    }

    // zastosowano kody kolorow w celu ulatwienia czytania informacji
    void show() const { cout << "\033[32mImie: " << name << ", \033[33mnazwisko: " << lastname << ", \033[34mwiek: " << age << ", \033[35mnumer telefonu: " << phone_number << ", \033[0mulica: " << street << endl; }
};

typedef multi_index_container<Contact, indexed_by<
                                           hashed_unique<member<Contact, string, &Contact::phone_number>>,
                                           ordered_non_unique<member<Contact, string, &Contact::lastname>>,
                                           ordered_non_unique<member<Contact, string, &Contact::street>>,
                                           ordered_non_unique<member<Contact, int, &Contact::age>>>>
    contact_multi;

class Contacts
{
private:
    contact_multi contacts;

public:
    Contacts() = default;
    void showAll();
    void addContact(Contact c);
    void removeContact(string number);
    void showStreet(string street);
    void showByAge(int from, int to);
    Contact findNumber(string number);
    void changeStreetName(string oldName, string newName);
    int howManyAdults();
    int howManyUniqueLastnames();
};

void Contacts::addContact(Contact c)
{
    if (contacts.find(c.phone_number) != contacts.end())
        cout << "Podany numer juz znajduje sie w ksiazce!" << endl;
    else
        contacts.insert(c);
}

void Contacts::showAll()
{
    cout << "Lista wszystkich kontkatow: " << endl;
    for (const auto &contact : contacts)
        contact.show();
}

void Contacts::removeContact(string number)
{
    auto &phone_index = contacts.get<0>();
    auto it = phone_index.find(number);
    if (it != phone_index.end())
        phone_index.erase(it);
}

void Contacts::showStreet(string street)
{
    auto &street_index = contacts.get<2>();
    const auto from = street_index.lower_bound(street);
    const auto to = street_index.upper_bound(street);

    cout << "Wszystkie osoby mieszkajace na ulicy: '" << street << "'" << endl;
    for (auto it = from; it != to; it++)
    {
        it->show();
    }
}

void Contacts::showByAge(int from, int to)
{
    // dodanie indeksu wiek
    auto &age_index = contacts.get<3>();

    // znalezienie zakresu iterowania po kontenerze
    const auto start = age_index.lower_bound(from);
    const auto stop = age_index.upper_bound(to);

    // wyswietlenie wynikow
    cout << "Wszystkie osoby z przedzialu wiekowego " << from << "-" << to << ": " << endl;
    for (auto it = start; it != stop; it++)
    {
        it->show();
    }
}

Contact Contacts::findNumber(string number)
{
    // jezeli kontakt odnaleziony to zwraca odnaleziony obiekt Contact, jesli nie odnaleziony to zwaraca nowy obiekt z pustymi wartosciami
    auto it = contacts.get<0>().find(number);
    if (it != contacts.get<0>().end())
        return *it;
    else
        return Contact("", "", 0, "", "");
}

void Contacts::changeStreetName(string oldName, string newName)
{
    auto &street_index = contacts.get<2>();

    // wyszukanie zakresu z ulica oldName
    auto range = street_index.equal_range(oldName);

    // utworzenie wektora na zaktualizowane kontakty
    vector<Contact> updated;

    // aktualizacja kontaktow
    for (auto it = range.first; it != range.second; ++it)
    {
        Contact c = *it;
        c.street = newName;
        updated.push_back(c);
    }

    // usuniecie zakresu kontakow do aktualizacji
    street_index.erase(range.first, range.second);

    // dodanie zaktualizowanych kontaktow znajdujacych sie w wektorze
    for (auto c : updated)
    {
        street_index.insert(c);
    }
}

int Contacts::howManyAdults()
{
    // dodanie indeksu wiek
    auto &age_index = contacts.get<3>();

    // znalezienie poczatkowego zakresu
    const auto start = age_index.lower_bound(18);

    // obliczenie ilosci osob
    int quantity = 0;
    for (auto it = start; it != age_index.end(); ++it)
    {
        quantity++;
    }

    return quantity;
}

int Contacts::howManyUniqueLastnames()
{
    map<string, int> lastnames;
    auto &lastname_index = contacts.get<1>();
    for (auto it = lastname_index.begin(); it != lastname_index.end(); ++it)
    {
        if (lastnames.find(it->lastname) == lastnames.end())
        {
            lastnames.insert(pair<string, int>(it->lastname, 1));
        }
        else
        {
            lastnames[it->lastname]++;
        }
    }

    int n = 0;

    for (auto elem : lastnames)
    {
        if (elem.second == 1)
            n++;
    }

    return n;
}

int main()
{
    cout << endl
         << endl;

    // utworznie 7 obiektow Contact
    Contact c1("Jan", "Kowalski", 44, "444555666", "Nadbystrzycka");
    Contact c2("Jan", "Nowak", 15, "444555668", "Orkana");
    Contact c3("Anna", "Wisniewska", 26, "555666342", "Zana");
    Contact c4("Michal", "Nowak", 83, "275424578", "Zana");
    Contact c5("Jakub", "Kolodziej", 66, "439679587", "Lipowa");
    Contact c6("Barbara", "Kolodziej", 18, "439679588", "Lipowa");
    Contact c7("Jakub", "Kolodziej", 66, "111111111", "Lipowa"); // ta osoba zostanie usunieta w celu przesestowania usuwania wg. numeru telefonu

    Contacts contacts_book;

    // dodanie kontaktow do ksiazki adresowej
    contacts_book.addContact(c1);
    contacts_book.addContact(c2);
    contacts_book.addContact(c3);
    contacts_book.addContact(c4);
    contacts_book.addContact(c5);
    contacts_book.addContact(c6);
    contacts_book.addContact(c7);

    // usuniecie kontaktu o numerze 111111111
    contacts_book.removeContact("111111111");
    contacts_book.showAll();
    cout << endl;

    // wyswietlenie wszystkich kontaktow z ulica Zana
    contacts_book.showStreet("Zana");
    cout << endl;

    // wyswietlenie wszystkich kontaktow do osob poniedzy 30 a 70 rokiem zycia
    contacts_book.showByAge(30, 70);
    cout << endl;

    // odnalezienie i wyswietlenie kontaktu o numerze 444555666
    Contact find = contacts_book.findNumber("444555666");
    cout << "Osoba z numerem telefonu 444555666:" << endl;
    find.show();
    cout << endl;

    // zmiana nazwy ulicy z Zana na Tomasza Zana i wyswietlenie wszystkich kontaktow
    contacts_book.changeStreetName("Zana", "Tomasza Zana");
    cout << "Po zmianie nazwy:" << endl;
    contacts_book.showAll();
    cout << endl;

    // policzenie osob doroslych (>18 lat)
    cout << "Osob pelnoletnich jest: " << contacts_book.howManyAdults() << endl;

    // policzenie unikatowych nazwisk
    cout << "Liczba unikatowych nazwisk wynosi: " << contacts_book.howManyUniqueLastnames() << endl;

    cout << endl
         << endl;
    return 0;
}