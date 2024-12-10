#include <iostream>
#include <regex>

using namespace std;

int main()
{
    cout << "Wprowadz tekst: ";
    string txt;
    getline(cin, txt);

    regex pattern(R"([+-]\d+\.\d+)");
    // regex pattern(R"([^0-9\*/\^%][+-]\d+\.\d+)");
    if (regex_search(txt, pattern))
    {
        cout << "Znaleziono liczbe zmiennoprzecinkowa ze znakiem" << endl;
    }
    else
    {
        cout << "Nie znaleziono liczby zmiennoprzecinkowej ze znakiem" << endl;
    }
    return 0;
}