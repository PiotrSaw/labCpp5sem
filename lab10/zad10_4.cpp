#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

int main()
{
    cout << "Podaj imie: " << endl;
    string name;
    cin >> name;
    cout << "Podaj nazwisko: ";
    string lastname;
    cin >> lastname;
    cout << "Podaj wiek: ";
    string age;
    cin >> age;
    cout << "Podaj numer telefonu: ";
    string phone;
    cin >> phone;
    cout << "Podaj email: ";
    string email;
    cin >> email;

    regex patternName("^[A-Z][a-z][a-z]+$");
    regex patternLastname("^[A-Z][a-z][a-z]+(-[A-Z][a-z][a-z]+)?$");
    regex patternAge("^([1-9])|([1-9][0-9])$");
    regex patternPhone("^[1-9][0-9]{8}$");
    regex patterEmail(R"(^[a-z][a-z0-9_\-\+!\.]+@[a-z0-9]+\.[a-z0-9]+$)");

    try
    {
        if (!regex_match(name, patternName))
            throw runtime_error("Bledne imie");
        if (!regex_match(lastname, patternLastname))
            throw runtime_error("Bledne nazwisko");
        if (!regex_match(age, patternAge))
            throw runtime_error("Bledny wiek");
        if (!regex_match(phone, patternPhone))
            throw runtime_error("Bledny numer telefonu");
        if (!regex_match(email, patterEmail))
            throw runtime_error("Bledny email");

        ofstream file;
        file.open("kartoteka.csv", ios::app);
        if (file.is_open())
        {
            file << name << ";" << lastname << ";" << age << ";" << phone << ";" << email << "\n";
            cout << "Zapisano do pliku" << endl;
            file.close();
        }
        else
        {
            throw runtime_error("Blad otwarcia pliku");
        }
    }
    catch (exception &e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }

    return 0;
}