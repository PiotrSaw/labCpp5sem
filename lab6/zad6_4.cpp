#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <iostream>
#include <map>

using namespace std;

template <typename T>
struct TypeCounter
{
    map<string, int> &type_map;

    TypeCounter(map<string, int> &m) : type_map(m) {}

    template <typename Elem>
    void operator()(const Elem &elem) const
    {
        string type_name = typeid(elem).name();
        if (type_name == typeid(int).name())
            type_map["int"]++;
        else if (type_name == typeid(double).name())
            type_map["double"]++;
        else if (type_name == typeid(float).name())
            type_map["float"]++;
        else if (type_name == typeid(bool).name())
            type_map["bool"]++;
        else if (type_name == typeid(char).name())
            type_map["char"]++;
    }
};

template <typename Vect>
map<string, int> countTypes(const Vect &vect)
{
    map<string, int> m = {{"int", 0}, {"double", 0}, {"float", 0}, {"bool", 0}, {"char", 0}};
    TypeCounter<Vect> counter(m);
    boost::fusion::for_each(vect, counter);
    return m;
}

int main()
{
    boost::fusion::vector<int, double, float, bool, char, int, bool, double> vec{10, 3.14, 1.76f, true, 'a', 20, false, 2.71};
    map<string, int> m = countTypes(vec);
    for (auto pair : m)
    {
        cout << pair.first << " --> " << pair.second << endl;
    }
    return 0;
}