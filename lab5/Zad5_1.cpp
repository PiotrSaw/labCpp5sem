#include <iostream>
#include <vector>
#include <set>
using namespace std;

pair<int, int> repeat(vector<int> n)
{
    set<int> s;
    int sum=0, x;
    for(int i = 0; i<n.size(); i++)
    {
        if(s.find(n[i]) == s.end())
        {
            s.insert(n[i]);
            sum += n[i];
        }
        else
        {
            x = n[i];
        }
    }
    return pair<int, int>(x, sum);
}

int main()
{
    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(4);
    numbers.push_back(5);
    pair<int, int> x = repeat(numbers);
    cout << "Powtarzajacy sie element to: " << x.first << ", suma unikatow wynosi: " << x.second << endl;

    return 0;
}
