#include <iostream>
#include <QVector>

using namespace std;

class Samochod
{
public:
    string markaIModel;
    string VIN;
    int rokProdukcji;
    Samochod(string markaIModel, string VIN, int rokProdukcji)
    {
        this->markaIModel = markaIModel;
        this->VIN = VIN;
        this->rokProdukcji = rokProdukcji;
    }
    void show()
    {
        cout << "Marka i model: " << this->markaIModel << ", VIN: " << this->VIN << ", rok produkcji: " << this->rokProdukcji << endl;
    }
};

class Katalog
{
private:
    QVector<Samochod> vect;

public:
    Katalog();
    void push(Samochod s)
    {
        vect.push_back(s);
    }

    void printAll()
    {
        QVector<Samochod>::iterator p;
        for (p = vect.begin(); p != vect.end(); ++p)
        {
            *p->show();
        }
    }

    int countOlderThanYear(int y)
    {
        int count = 0;
        QVector<Samochod>::iterator p;
        for (p = vect.begin(); p != vect.end(); ++p)
        {
            if (*p->rokProdukcji < y)
                count++;
        }

        return count;
    }

    void eraseByVIN(string VIN)
    {
        vect.erase(
            remove_if(vect.begin(), vect.end(), [](const Samochod &obj)
                      {
                          return obj.VIN == VIN; // Warunek usunięcia
                      }),
            vect.end());
    }

    void print1()
    {
        sort(vect.begin(), vect.end(), [](const Samochod &obj1, const Samochod &obj2)
             { return obj1.rokProdukcji > obj2.rokProdukcji; });

        printAll();
    }

    void print2()
    {
        sort(vect.begin(), vect.end(), [](const Samochod &obj1, const Samochod &obj2)
             { return obj1.markaIModel < obj2.markaIModel; });

        printAll();
    }
};


int main()
{
    Katalog k;
    k.push(Samochod("Toyota Corolla", "VIN001", 2015));
    k.push(Samochod("Ford Fiesta", "VIN002", 2018));
    k.push(Samochod("Honda Civic", "VIN003", 2012));
    k.push(Samochod("BMW X5", "VIN004", 2020));
    k.push(Samochod("Audi A4", "VIN005", 2016));
    k.push(Samochod("Mercedes C-Class", "VIN006", 2017));
    k.push(Samochod("Volkswagen Passat", "VIN007", 2010));
    k.push(Samochod("Kia Sportage", "VIN008", 2019));
    k.push(Samochod("Hyundai Tucson", "VIN009", 2014));
    k.push(Samochod("Skoda Octavia", "VIN010", 2013));

    k.printAll();

    cout << endl << "Ilosc starszych niż 2014: " << k.countOlderThanYear(2014) << endl;
    cout << "Usuwam samochod o VIN: VIN001" << endl;
    k.eraseByVIN("VIN001");


    cout << "Wyswietlenie rosnaco po marce: " << endl;
    k.print2();


    cout << "Wyswietlenie malejaco po roku produkcji: " << endl;
    k.print1();

    return 0;
}