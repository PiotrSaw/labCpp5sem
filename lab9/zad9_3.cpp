#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <limits>

#define RED "\033[31m"
#define RESET "\033[0m";

using namespace std;

class Student
{

private:
    string imie;
    string nazwisko;
    char plec;
    float ocena;
    string email;

public:
    // Konstruktor domyslny
    Student() : imie(""), nazwisko(""), plec(' '), ocena(0.0), email("") {}

    // Konstruktor parametrowy (wszystkie pola)
    Student(const string &imie, const string &nazwisko, char plec, float ocena, const string &email)
        : imie(imie), nazwisko(nazwisko), plec(plec), ocena(ocena), email(email) {}

    // Konstruktor parametrowy (bez email)
    Student(const string &imie, const string &nazwisko, char plec, float ocena)
        : imie(imie), nazwisko(nazwisko), plec(plec), ocena(ocena), email("") {}

    // Gettery
    string getImie() const { return imie; }
    string getNazwisko() const { return nazwisko; }
    char getPlec() const { return plec; }
    float getOcena() const { return ocena; }
    string getEmail() const { return email; }

    // Settery
    void setImie(const string &imie) { this->imie = imie; }
    void setNazwisko(const string &nazwisko) { this->nazwisko = nazwisko; }
    void setPlec(char plec) { this->plec = plec; }
    void setOcena(float ocena) { this->ocena = ocena; }
    void setEmail(const string &email) { this->email = email; }

    void print()
    {
        // cout << setfill('_'); // z zastosowaniem znaku _ w puste miejsca bardzo niewyraznie wyglada wyswietlony wynik
        cout << setw(15) << imie;
        cout << setw(20) << nazwisko;
        cout << setw(3) << plec;
        cout << setw(5) << ocena;
        cout << setw(35) << email;
        cout << endl;
    }
};

vector<string> split(const string &input, char delimiter)
{
    vector<string> tokens;
    stringstream ss(input); // Tworzymy strumien z wejsciowego stringa
    string token;

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token); // Dodajemy kazdy fragment do wektora
    }

    return tokens;
}

vector<Student> read()
{
    vector<Student> students;
    ifstream file;
    string line;
    file.open("studenci.csv");
    if (file.is_open())
    {
        // odczytanie linijki z naglowkami
        getline(file, line);
        while (getline(file, line)) // Poprawiony sposob iteracji
        {
            if (line.empty())
                continue; // Pomijamy puste wiersze

            try
            {
                vector<string> result = split(line, ';');

                if (result.size() == 4)
                {
                    students.push_back(Student(result[0], result[1], result[2][0], stof(result[3])));
                }
                else if (result.size() == 5)
                {
                    students.push_back(Student(result[0], result[1], result[2][0], stof(result[3]), result[4]));
                }
                else
                {
                    throw runtime_error("Nieprawidlowa liczba kolumn w wierszu: " + line);
                }
            }
            catch (const std::exception &e)
            {
                cerr << RED << "Blad podczas przetwarzania wiersza: \"" << line << "\". Szczegoly: " << e.what() << endl
                     << RESET;
            }
        }
        file.close();
    }
    else
    {
        cerr << RED << "Blad otwarcia pliku!!!" << endl
             << RESET;
        return students;
    }

    return students;
}

void writeAll(vector<Student> s)
{
    cout << "Lista wszystkich studentow:" << endl;
    for (auto student : s)
    {
        student.print();
    }
}

bool isValidEmail(const string &email)
{
    // Prosta walidacja e-maila (sprawdzanie formatu)
    regex emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return regex_match(email, emailPattern);
}

bool isValidName(const string &name)
{
    // Prosta walidacja e-maila (sprawdzanie formatu)
    regex namePattern("^[A-Z][a-z]{2,}$");
    return regex_match(name, namePattern);
}

void addStudent(vector<Student> &s)
{
    try
    {
        string imie;
        string nazwisko;
        string plec;
        float ocena;
        string email;

        cout << endl
             << "Dodanie studenta: " << endl;

        cout << "Podaj imie: ";
        cin >> imie;
        cout << "Podaj nazwisko: ";
        cin >> nazwisko;
        cout << "Podaj plec (k/m): ";
        cin >> plec;

        cout << "Podaj email: ";
        cin >> email;

        cout << "Podaj ocene: ";
        cin >> ocena;
        if (cin.fail())
        {
            cin.clear();                                         // Czyszczenie stanu błędu
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorowanie złych danych w buforze
            throw runtime_error("To nie jest liczba zmiennoprzecinkowa!");
        }

        if (!isValidName(imie))
            throw runtime_error("Niepoprawny format imienia!");
        if (!isValidName(nazwisko))
            throw runtime_error("Niepoprawny format nazwiska!");
        if (plec[0] != 'k' && plec[0] != 'm')
            throw runtime_error("Niepoprawna plec!");
        if (ocena != 2 && ocena != 3 && ocena != 3.5 && ocena != 4 && ocena != 4.5 && ocena != 5)
            throw runtime_error("Niepoprawna ocena!");
        if (email != "" && !isValidEmail(email))
            throw runtime_error("Niepoprawny email");

        s.push_back(Student(imie, nazwisko, plec[0], ocena, email));
        ofstream file;
        file.open("studenci.csv", ios::app);
        if (file.is_open())
        {
            file << imie << ";" << nazwisko << ";" << plec << ";" << ocena;
            if (email != "")
                file << ";" << email << "\n";
            else
                file << "\n";
            file.close();
        }
        else
        {
            cerr << RED << "Blad otwarcia pliku do dopisania danych" << endl
                 << RESET;
        }
    }
    catch (const std::exception &e)
    {
        cerr << RED << e.what() << '\n'
             << RESET;
    }
}

void splitData()
{
    ifstream data;
    ofstream male, female;
    data.open("studenci.csv");
    male.open("mezczyzni.csv");
    female.open("kobiety.csv");

    if (data.is_open())
    {
        if (male.is_open())
        {
            if (female.is_open())
            {
                string line;
                getline(data, line);
                male << line << "n";
                female << line << "n";

                while (getline(data, line))
                {
                    vector<string> v = split(line, ';');
                    if (v[2] == "k")
                        female << line << "\n";
                    else if (v[2] == "m")
                        male << line << "\n";
                }

                data.close();
                male.close();
                female.close();
            }
            else
            {
                data.close();
                male.close();
                cerr << RED << "Blad otwarcia pliku kobiety.csv" << endl
                     << RESET;
            }
        }
        else
        {
            data.close();
            cerr << RED << "Blad otwarcia pliku mezczyzni.csv" << endl
                 << RESET;
        }
    }
    else
    {
        cerr << RED << "Blad otwarcia pliku studenci.csv" << endl
             << RESET;
    }
}

void printFirstX(int x, vector<Student> s)
{
    try
    {
        if (s.size() < x)
            throw runtime_error("Nie ma tylu studentow na liscie!");
        else
        {
            cout << "Pierwsze " << x << " studentow: " << endl;
            for (int i = 0; i < x; i++)
            {
                s[i].print();
            }
        }
    }
    catch (const std::exception &e)
    {
        cerr << RED << "ERROR: " << e.what() << endl
             << RESET;
    }
}

void sortStudents(vector<Student> &s)
{
    sort(s.begin(), s.end(), [](const Student &a, const Student &b)
         {
             return a.getOcena() < b.getOcena(); // Porównanie wg ocen rosnąco
         });

    try
    {
        ofstream file;
        file.open("studenci.csv");
        if (file.is_open())
        {
            for (auto st : s)
            {
                file << st.getImie() << ";" << st.getNazwisko() << ";" << st.getPlec() << ";" << st.getOcena();
                if (st.getEmail() == "")
                    file << "\n";
                else
                    file << ";" << st.getEmail() << "\n";
            }
            file.close();
        }
        else
            throw runtime_error("Blad otwarcia pliku studenci.csv!");
    }
    catch (const std::exception &e)
    {
        cerr << RED << "ERROR: " << e.what() << endl
             << RESET;
    }
}

void printBySurname(string surname, vector<Student> v)
{
    cout << "Lista studentow o nazwisku: " << surname << ": " << endl;
    bool ok = false;
    for (auto s : v)
    {
        if (s.getNazwisko() == surname)
        {
            ok = true;
            s.print();
        }
    }

    if (!ok)
        cout << "BRAK!" << endl;
}

int main()
{
    cout << RESET;
    vector<Student> students = read();
    int n;
    cout << R"(Menu: 
    1. Wyswietl liste wszystkich studentow
    2. Dodaj nowa osobe
    3. Wyswietl osoby o podanym nazwisku
    4. Utworz pliki kobiety.csv oraz mezczyzni.csv
    5. Wyswietl x pierwszych studentow
    6. Posortuj studentow rosnoco wg. oceny
    7. Wyjscie
    )" << endl;
    do
    {
        cout << "Podaj opcje: ";
        cin >> n;
        string surname;

        switch (n)
        {
        case 1:
            writeAll(students);
            break;
        case 2:
            addStudent(students);
            break;
        case 3:
            cout << "Podaj nazwisko: ";
            cin >> surname;
            printBySurname(surname, students);
            break;
        case 4:
            splitData();
            break;
        case 5:
            int x;
            cout << "Podaj x: ";
            cin >> x;
            if (cin.fail())
            {
                cerr << RED << "To nie jest liczba calkowita!" << endl
                     << RESET;
                cin.clear(); // Czyszczenie stanu błędu
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                printFirstX(x, students);
            }
            break;
        case 6:
            sortStudents(students);
            break;
        case 7:
            break;
        default:
            cerr << RED << "Niewlasciwa opcja!" << endl
                 << RESET;
            break;
        }

    } while (n != 7);

    return 0;
}
