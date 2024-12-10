#include <iostream>
#include <regex>

using namespace std;

int main()
{
    cout << "Wprowadz godzine w formacie 'hh:mm:ss' lub 'hh:mm': ";
    string txt;
    getline(cin, txt);

    //                 godziny od 00 do 24 :  minuty    (: sekundy  )opcjonalnie
    regex pattern(R"((([01][0-9])|(2[0-3])):([0-5][0-9])(:[0-5][0-9])?)");
    if (regex_match(txt, pattern))
    {
        cout << "Podano poprawna godzine" << endl;
    }
    else
    {
        cout << "Nie podano poprawnej godziny" << endl;
    }
    return 0;
}