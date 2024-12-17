#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Buffer
{
public:
    virtual void add(int a) = 0;
    virtual void write() = 0;
    Buffer() { cout << "Konstruktor Buffer" << endl; }
    ~Buffer() { cout << "Destruktor Buffer" << endl; }
};

class BufferArr : public Buffer
{
private:
    unique_ptr<int[]> tab;
    int counter;
    int size;

public:
    BufferArr(int n)
    {
        tab = make_unique<int[]>(n);
        counter = 0;
        size = n;
        cout << "Konstruktor BufferArr" << endl;
    }
    void add(int a) override
    {
        if (counter == size)
        {
            cout << "Nie masz miejsca w tablicy!" << endl;
        }
        else
        {
            tab[counter] = a;
            counter++;
            cout << "Dodano liczbe" << endl;
        }
    }

    void write() override
    {
        if (counter > 0)
        {
            cout << "Dodane elementy:" << endl;
            for (int i = 0; i < counter; i++)
            {
                cout << tab[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Brak dodanych elementow" << endl;
        }
    }

    ~BufferArr() { cout << "Destruktor BufferArr" << endl; }
};

class BufferFile : public Buffer
{
private:
    unique_ptr<fstream> file;
    string path;

public:
    BufferFile(string path)
    {
        cout << "Konstruktor BufferFile" << endl;
        this->path = path;
        file = make_unique<fstream>(path, ios::in | ios::out);
        if (!file->is_open())
        {
            cout << "Blad otwarcia pliku" << endl;
        }
    }
    ~BufferFile()
    {
        cout << "Destruktor BufferFile" << endl;
        file->close();
    }

    void add(int a) override
    {
        if (file->is_open())
        {
            *file << a << "\n";
            file->flush();
        }
        else
        {
            cout << "Nie mozna dopisac do pliku" << endl;
        }
    }

    void write() override
    {
       
        if (file->is_open())
        {
            cout << "Dane z pliku:" << endl;
            string line;
            file->clear(); // Czyszczenie flag błędów
            file->seekg(0, ios::beg);
            while (getline(*file, line))
            {
                cout << line << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Nie mozna odczytac danych z pliku!" << endl;
        }
    }
};

int main()
{
    vector<shared_ptr<Buffer>> vect;

    vect.push_back(make_shared<BufferArr>(5));
    vect.push_back(make_shared<BufferFile>("dane.txt"));

    cout << endl << "BufferArr:" << endl;
    vect[0]->write();
    vect[0]->add(1);
    vect[0]->add(2);
    vect[0]->add(3);
    vect[0]->add(4);
    vect[0]->add(5);
    vect[0]->add(6);
    vect[0]->write();

    cout << endl << "BufferFile:" << endl;
    vect[1]->add(1);
    vect[1]->add(2);
    vect[1]->add(3);
    vect[1]->add(4);
    vect[1]->add(5);
    vect[1]->add(6);
    vect[1]->write();

    cout << endl;

    return 0;
}