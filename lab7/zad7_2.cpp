#include <iostream>
#include <string>
#include <QSet>
#include <algorithm>
#include <cctype>

using namespace std;


void lowercase(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

bool czyPangram(QSet<char> s)
{
    char litery[] = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i<size(litery); i++)
    {
        if(!s.contains(litery[i])) {
            if(static_cast<int>(litery[i]) == 0) continue;
            else return false;
        }
    }

    return true;
}

int main()
{
    string napis;
    cout << "Podaj napis do sprawdzenia: ";
    getline(cin, napis);
    lowercase(napis);
    QSet<char> s;
    for(int i = 0; i<size(napis); i++)
    {
        s.insert(napis[i]);
    }

    if(czyPangram(s)) cout << "Twoj napis jest pangramem";
    else cout << "Twoj napis nie jest pangramem";

    return 0;
}