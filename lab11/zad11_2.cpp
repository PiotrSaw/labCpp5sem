#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class WareHouse
{
private:
    string productName;
    int quantity;

public:
    WareHouse();
    WareHouse(string name, int q)
    {
        this->productName = name;
        this->quantity = q;
    }
    string getProductName() { return productName; }
    int getQuantity() { return quantity; }
    void setProductName(string name) { productName = name; }
    void setQuantity(int q) { quantity = 1; }
    void printInfo() { cout << "Nazwa towaru: " << productName << ", ilosc: " << quantity << endl; }
};

class Shop
{
public:
    vector<WareHouse> magazines;
    Shop(){}
    void sell(string name, int q)
    {
        for (auto i : magazines)
        {
            if (i.getProductName() == name && i.getQuantity() >= q)
            {
                i.setQuantity(i.getQuantity() - q);
                cout << "Sprzedano produkt " << name << " w liczbie sztuk " << q << endl;
            }
        }
    }

    void showMagazines()
    {
        cout << "Wszysktie magazyny:" << endl;
        for (auto i : magazines)
        {
            i.printInfo();
        }
    }
};

int main()
{
    shared_ptr<WareHouse> w1 = make_shared<WareHouse>("ksiazka", 1000);
    shared_ptr<WareHouse> w2 = make_shared<WareHouse>("klocki", 200);
    shared_ptr<WareHouse> w3 = make_shared<WareHouse>("pilki", 500);
    Shop s;
    s.magazines.push_back(*w1);
    s.magazines.push_back(*w3);
    s.magazines.push_back(*w2);
    s.sell("latawiec", 1);
    s.sell("pilki", 5);
    s.showMagazines();
    return 0;
}