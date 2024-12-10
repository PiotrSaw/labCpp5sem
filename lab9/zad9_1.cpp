#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// funckcja wyswietla linie bez komentarzy
bool wyswLinie(string line, bool ok)
{
    //zmienna pozwala nie wyswietlac zbednych entorow w przypadku kom jednolinijkowych
    bool inputok = ok;
    //zmienna pozwala nie wyswietlac zbednych entorow w przypadku kom wielolinijkowych
    bool changeok = false;
    for (int i = 0; i < line.size(); i++)
    {
        if (ok)
        {
            if (line[i] == '/' && i < line.size() - 1 && line[i + 1] == '/')
            {
                // warunek pozwala nie wyswietlac zbednych enterow w przypadku komentarzy 1 liniowych w liniach w ktorych nie ma wiecej kodu
                if(!ok && !inputok) cout << endl;
                return ok;
            }
            else if (line[i] == '/' && i < line.size() - 1 && line[i + 1] == '*')
            {
                i += 2;
                changeok = true;
                ok = false;
            }
            else
                cout << line[i];
        }
        else
        {
            if (line[i] == '*' && i < line.size() - 1 && line[i + 1] == '/')
            {
                i += 2;
                changeok = true;
                ok = true;
            }
        }
    }
    // warunek pozwala nie wyswietlac zbednych enterow w przypadku wielu linii komentarzy
    if(changeok && ok) cout << endl;
    return ok;
}

int main()
{

    bool ok = true;
    ifstream file;
    try
    {
        file.open("kod.txt");
        if (!file.is_open())
        {
            throw ios_base::failure("Nie mozna otworzyc pliku");
        }

        string line, fullLine;
        bool ok = true;
        while (!file.eof())
        {
            getline(file, fullLine);
            ok = wyswLinie(fullLine, ok);
        }
        file.close();
    }
    catch (const ios_base::failure &e)
    {
        cerr << e.what();
    }
    catch (...)
    {
        cerr << "Wystapil inny blad" << endl;
    }

    return 0;
}