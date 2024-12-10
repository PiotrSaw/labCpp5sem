#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename T>
T sum1(set<T> s1, set<T> s2)
{
    T sum = 0;
    set<T> setSymmetricDiff;

    set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator<set<T>>(setSymmetricDiff, setSymmetricDiff.begin()));

    for(auto it = setSymmetricDiff.begin(); it != setSymmetricDiff.end(); it++)
    {
        sum += *it;
    }

    return sum;
}


int main()
{
    set<int> s1 = {1, 2, 3, 4, 5};
    set<int> s2 = {4, 5, 6, 7, 8};

    cout << "Suma elementow znajdujacych sie tylko w 1 lub tylko 2 zbiorze jest rowna: " << sum1<int>(s1, s2) << endl;

    return 0;
}
