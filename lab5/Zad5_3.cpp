#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> stringToMap(string s)
{
    map<char, int> m;
    for(int i = 0; i<s.size(); i++)
    {
        if(m.find(s[i]) == m.end())
        {
            m.insert(pair<char, int>(s[i], 1));
        }
        else
        {
            m[s[i]]++;
        }
    }
    return m;
}

char difference(string s1, string s2)
{
    map<char, int> m1, m2;
    m1 = stringToMap(s1);
    m2 = stringToMap(s2);

    for(auto it = m2.begin(); it != m2.end(); it++)
    {
        if(m1.find(it->first) == m1.end()) return it->first;
        else if(it->second != m1.find(it->first)->second) return it->first;
    }

    return NULL;
}

int main()
{
    string s1 = "kajak";
    string s2 = "jkkaak";

    cout << "Do drugiego napisu zostal dodany znak: " << difference(s1, s2) << endl;

    return 0;
}
