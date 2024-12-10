#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

template <typename T>
class Array
{
    public:
        Array<T>();
        Array<T>(int n);
        virtual ~Array();
        void sort_tab();
        T max();
        void print();
        void add(T elem);
        T elem(int ind);

    protected:

    private:
        T *tab;
        int size;
        int index;
};

template <typename T>
Array<T>::Array(){size = 10; index = 0; tab = new T[10];}

template <typename T>
Array<T>::Array(int n){size = n; index = 0; tab = new T[n];}

template <typename T>
Array<T>::~Array(){delete [] tab;}

template <typename T>
void Array<T>::sort_tab()
{
	for(int i = 0; i<index-1; i++)
    {
        for(int j = i+1; j<index; j++)
        {
            if(tab[j] < tab[i]) swap(tab[i], tab[j]);
        }
    }
}

template <typename T>
T Array<T>::max()
{
    T max = tab[0];
    for(int i = 1; i<index; i++)
    {
        if(tab[i] > max) max = tab[i];
    }
    return max;
}

template <typename T>
void Array<T>::print()
{
    cout << "Twoja tablica: ";
    for(int i = 0; i<index; i++) cout << tab[i] << "   ";
    cout << endl;
}

template <typename T>
void Array<T>::add(T elem)
{
    if(index < size)
    {
        tab[index] = elem;
        index ++;
    }
    else cout << "Brak miejsca w tablicy" << endl;
}

template <typename T>
T Array<T>::elem(int ind)
{
    return tab[ind];
}

template<>
string Array<string>::max()
{
    int max = 0;
    for(int i = 1; i<index; i++)
    {
        if(tab[i].size() > tab[max].size()) max = i;
    }
    return tab[max];
}

template<>
void Array<string>::sort_tab()
{
	for(int i = 0; i<index-1; i++)
    {
        for(int j = i+1; j<index; j++)
        {
            if(tab[j].size() < tab[i].size()) swap(tab[i], tab[j]);
        }
    }
}

#endif // ARRAY_H
