#include <iostream>
#include <regex>

using namespace std;

int main()
{
    cout << "Podaj ulice: ";
    string street;
    cin >> street;
    regex patternStr(R"([A-Z][a-z][a-z]+)"); // jedna wielka litera i przynajmniej 2 male
    if (regex_match(street, patternStr))
    {
        cout << "Poprawna ulica" << endl;
    }
    else
    {
        cout << "Niepoprawna ulica" << endl;
    }

    string postalCode;
    cout << "Podaj kod pocztowy: ";
    cin >> postalCode;
    regex patternPostCode(R"(\d{2}-\d{3})");
    if(regex_match(postalCode, patternPostCode))
    {
        cout << "Poprawny kod pocztowy" << endl;
    }
    else
    {
        cout << "Niepoprawny kod pocztowy" << endl;
    }

    string houseNumber;
    cout << "Podaj numer domu: ";
    cin >> houseNumber;
    regex patternNumb(R"(\d+[A-Z]?)");
    if(regex_match(houseNumber, patternNumb))
    {
        cout << "Poprawny numer domu" << endl;
    }
    else
    {
        cout << "Niepoprawny numer domu" << endl;
    }

    string flatNumber;
    cout << "Podaj numer mieszkania: ";
    cin >> flatNumber;
    regex patternNumbF(R"(\d+)");
    if(regex_match(flatNumber, patternNumbF))
    {
        cout << "Poprawny numer mieszkania" << endl;
    }
    else
    {
        cout << "Niepoprawny numer mieszkania" << endl;
    }

    return 0;
}