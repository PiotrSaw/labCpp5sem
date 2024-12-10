#include <iostream>
using namespace std;

template <int d, typename T>
void showConvertingFromGrams(T elem)
{
    cout << "Dla podanego typu brak specjalizacji" << endl;
}

template<>
void showConvertingFromGrams<10, int>(int elem)
{
    cout << elem << "g = " << elem/10 << "dag" << endl;
}

template<>
void showConvertingFromGrams<10, float>(float elem)
{
    cout << elem << "g = " << elem/10 << "dag" << endl;
}

template<>
void showConvertingFromGrams<1000, int>(int elem)
{
    cout << elem << "g = " << elem/1000 << "kg" << endl;
}

template<>
void showConvertingFromGrams<1000, float>(float elem)
{
    cout << elem << "g = " << elem/1000 << "kg" << endl;
}

template<>
void showConvertingFromGrams<1000000, int>(int elem)
{
    cout << elem << "g = " << elem/1000000 << "t" << endl;
}

template<>
void showConvertingFromGrams<1000000, float>(float elem)
{
    cout << elem << "g = " << elem/1000000 << "t" << endl;
}


// dzielnik podano -1 poniewaz do int nie mozna wstawic 0.001
template<>
void showConvertingFromGrams<-1, int>(int elem)
{
    cout << elem << "g = " << elem/0.001 << "mg" << endl;
}

template<>
void showConvertingFromGrams<-1, float>(float elem)
{
    cout << elem << "g = " << elem/0.001 << "mg" << endl;
}


int main()
{
    showConvertingFromGrams<1000, float>(350.6);   // konwersja na kilogramy
    showConvertingFromGrams<1000000, int>(2000000); // konwersja na tony
    showConvertingFromGrams<10, int>(470);          // konwersja na dekagramy
    showConvertingFromGrams<-1, float>(6.8);       // dzielnik wynosi 0.001 - konwersja na miligramy
    showConvertingFromGrams<1000, double>(6.8);
    showConvertingFromGrams<10, string>("123");


    return 0;
}
