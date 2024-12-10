#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <regex>

using namespace std;

struct person
{
    string name;
    string lastname;
    string age;
    string phone;
    string email;
};

vector<person> load()
{
    ifstream file;
    vector<person> v;
    file.open("kartoteka.csv");
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            vector<string> parts;

            // Użycie boost::split
            boost::split(parts, line, boost::is_any_of(";"));
            person p1;
            p1.name = parts[0];
            p1.lastname = parts[1];
            p1.age = parts[2];
            p1.phone = parts[3];
            p1.email = parts[4];
            v.push_back(p1);
        }
        file.close();
    }
    else
    {
        cerr << "Blad otwarcia pliku" << endl;
    }

    return v;
}

void printPhones(vector<person> p)
{
    cout << "Numery telefonow konczace sie liczba parzysta:" << endl;
    for (auto i : p)
    {
        regex pattern("[02468]$");
        if (regex_search(i.phone, pattern))
            cout << i.phone << endl;
    }
}

void printDoubleLastnames(vector<person> p)
{
    cout << "Nazwiska laczone:" << endl;
    for (auto i : p)
    {
        regex pattern("-");
        if (regex_search(i.lastname, pattern))
            cout << i.lastname << endl;
    }
}

void printUniqueDomains(vector<person> p)
{
    cout << "Unikatowe nazwy domen:" << endl;
    map<string, int> d;
    for (auto i : p)
    {
        string domain;
        int at = i.email.find("@");
        domain = i.email.substr(at+1, i.email.size() - 1);
        if (d.find(domain) != d.end())
        {
            d[domain]++;
        }
        else
        {
            d.insert(pair<string, int>(domain, 1));
        }
    }

    for (auto i : d)
    {
        if (i.second == 1)
            cout << i.first << endl;
    }
}

int main()
{
    vector<person> p = load();
    cout << endl;
    printPhones(p);
    cout << endl;
    printDoubleLastnames(p);
    cout << endl;
    printUniqueDomains(p);
    cout << endl;
    return 0;
}