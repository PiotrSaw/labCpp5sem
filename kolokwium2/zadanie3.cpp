/*
Napisz program wykorzystujący następujący wektor krotek:
vector< tuple<string, float, float, float, float, float, int, string> > planety
     = { {"Merkury", 0.3825, 0.552, 0.3871, 0.2408, 58.64306, 0, "skalista"},
         {"Wenus", 0.9489, 0.8149, 0.7233, 0.6152, 243.01875, 0, "skalista"},
         {"Ziemia", 1.0, 1.0, 1.0, 1.0, 0.99727, 1, "skalista"},
         {"Mars", 0.5335, 0.1074, 1.5237, 1.8808, 1.02596, 2, "skalista"},
         {"Jowisz", 11.2092, 317.8, 5.2034, 11.8637, 0.41354, 79, "gazowa"},
         {"Saturn", 9.494, 95.1620, 9.5371, 29.4484, 0.44400, 82, "gazowa"},
         {"Uran", 4.0074, 14.5360, 19.1913, 84.0711, 0.71833, 27, "gazowo-lodowa"},
         {"Neptun", 3.8827, 17.1470, 30.0690, 164.8799, 0.67125, 14, "gazowo-lodowa"} };
(Poszczególne elementy każdej z krotek w wektorze oznaczają:
nazwę planety, średnicę planety, masę planety, odległość od słońca, czas obiegu wokół słońca w latach, czas obrotu wokół osi w dniach, liczbę księżyców i rodzaj planety.)
Utwórz zwykłą funkcję sortowanie(), która będzie użyta w algorytmie sort() do sortowania wektora planety wg. czasu obiegu planety wokoł słońca.
W funkcji main() wyświetl wszystkie elementy wektora korzystając z algorytmu for_each() i nienazwanej funkcji lambda print() wyświetlającej elementy każdej krotki z wektora planety podobnie do:
cout << nazwa << "\tsrednica: " << srednica << "\tmasa: " << masa << "\todleglosc od slonca: " << odleglosc << "\tczas obiegu [lata]: " << obieg << "\tczas obrotu [dni]: " << obrot <<     "\tliczba ksiezycow: " << ksiezyce << "\trodzaj: " << rodzaj << endl;
Korzystając z algorytmu std::sort() i funkcji sortowanie() posortuj wektor planety według czasu obiegu planety wokół słońca.
Następnie wyświetl ponownie elementy wektora po posortowaniu.
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool sortowanie(tuple<string, float, float, float, float, float, int, string> t1, tuple<string, float, float, float, float, float, int, string> t2)
{
    return get<4>(t1) < get<4>(t2);
}

int main()

{
    vector<tuple<string, float, float, float, float, float, int, string>> planety = {{"Merkury", 0.3825, 0.552, 0.3871, 0.2408, 58.64306, 0, "skalista"},
                                                                                     {"Wenus", 0.9489, 0.8149, 0.7233, 0.6152, 243.01875, 0, "skalista"},
                                                                                     {"Ziemia", 1.0, 1.0, 1.0, 1.0, 0.99727, 1, "skalista"},
                                                                                     {"Mars", 0.5335, 0.1074, 1.5237, 1.8808, 1.02596, 2, "skalista"},
                                                                                     {"Jowisz", 11.2092, 317.8, 5.2034, 11.8637, 0.41354, 79, "gazowa"},
                                                                                     {"Saturn", 9.494, 95.1620, 9.5371, 29.4484, 0.44400, 82, "gazowa"},
                                                                                     {"Uran", 4.0074, 14.5360, 19.1913, 84.0711, 0.71833, 27, "gazowo-lodowa"},
                                                                                     {"Neptun", 3.8827, 17.1470, 30.0690, 164.8799, 0.67125, 14, "gazowo-lodowa"}};

    for_each(planety.begin(), planety.end(), [](tuple<string, float, float, float, float, float, int, string> t)
             { cout << get<0>(t) << "\tsrednica: " << get<1>(t) << "\tmasa: " << get<2>(t) << "\todleglosc od slonca: " << get<3>(t) <<
             "\tczas obiegu [lata]: " << get<4>(t) << "\tczas obrotu [dni]: " << get<5>(t) << "\tliczba ksiezycow: " << get<6>(t) << "\trodzaj: " << get<7>(t) << endl; });


    sort(planety.begin(), planety.end(), sortowanie);

    cout << endl << endl << "Posortowane planety wg czasu obiegu wokol slonca:" << endl;
    for_each(planety.begin(), planety.end(), [](tuple<string, float, float, float, float, float, int, string> t)
             { cout << get<0>(t) << "\tsrednica: " << get<1>(t) << "\tmasa: " << get<2>(t) << "\todleglosc od slonca: " << get<3>(t) <<
             "\tczas obiegu [lata]: " << get<4>(t) << "\tczas obrotu [dni]: " << get<5>(t) << "\tliczba ksiezycow: " << get<6>(t) << "\trodzaj: " << get<7>(t) << endl; });

    return 0;
}