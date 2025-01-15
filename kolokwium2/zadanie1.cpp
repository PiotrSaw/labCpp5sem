/*
Napisz program, w którym funkcja"readIntegerFile" otworzy plik "IntegerFile.txt", odczyta z niego liczby całkowite i zapamięta je w wektorze "myInts".
Program powinien obsłużyć 2 wyjątki:
1. Jeżeli funkcji nie uda się otworzyć pliku - powinien zostać wyrzucony wyjątek w postaci: throw "Nie udało się otworzyć pliku ".
2. Jeżeli funkcji nie uda się odczytać danych z pliku (wpisz w pliku np. łańcuch znaków "abcd") - powinien zostać wyrzucony wyjątek w postaci: throw "Nie potrafię poprawnie odczytać danych z pliku ". Podpowiedź: wystarczy sprawdzić czy udało się przy czytaniu dotrzeć do końca pliku (eof()).
Jeżeli żaden z wyjątków nie wystąpi program powinien wydrukować zawartość wektora "myInts". W przeciwnym wypadku po obsłużeniu wyjątku powinien przerwać działanie z kodem zakończenia 1.
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> readIntegerFile()
{
    vector<int> myInts;
    int number;
    ifstream file;
    file.open("IntegerFile.txt");
    if (!file.is_open())
    {
        throw "Nie udalo sie otworzyc pliku ";
    }
    while (file >> number)
    {
        myInts.push_back(number);
    }
    if (!file.eof())
    {
        throw "Nie potrafie poprawnie odczytac danych z pliku ";
    }
    file.close();
    return myInts;
}

int main()
{
    try
    {
        vector<int> myInts = readIntegerFile();
        for (int i : myInts)
        {
            cout << i << " ";
        }
    }
    catch (const char *e)
    {
        cout << e << endl;
        return 1;
    }
    return 0;
}