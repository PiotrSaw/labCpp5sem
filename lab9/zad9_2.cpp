#include <iostream>
#include <limits>

using namespace std;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string RESET = "\033[0m";

void inputNumber(int &successTrials, int &failedTrials, int &sum)
{
    int n;
    cout << endl;
    cout << "W tym momencie suma wynosi " << sum << endl;
    cout << "Podaj liczbe calkowita: ";
    cin >> n;

    if (cin.fail() || cin.peek() != '\n')
    {
        cerr << RED << "Nie podano liczby calkowitej!" << RESET << endl;
        failedTrials++;

        // Oczyszczenie strumienia w przypadku błędu wejścia
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        if (sum + n <= 21)
        {
            cout << "Podano poprawna liczbe!" << endl;
            successTrials++;
            sum = sum + n;
        }
        else
        {
            failedTrials++;
            throw -1;
        }
    }
}

int main()
{
    int successTrials = 0, failedTrials = 0, sum = 0;

    while (sum < 21)
    {
        try
        {
            inputNumber(successTrials, failedTrials, sum);
        }
        catch (int err)
        {
            if (err == -1)
                cerr << YELLOW << "Podano za duza liczbe!" << RESET << endl;
        }
    }

    cout << endl;
    cout << GREEN << "Udalo sie osiagnac sume " << sum << RESET << endl;
    cout << "Udanych prob: " << successTrials << endl;
    cout << "Nieudanych prob: " << failedTrials << endl;

    return 0;
}