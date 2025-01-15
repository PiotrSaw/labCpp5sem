/*
Wypisz wszystkie łańcuchy odpowiadające wyrażeniu regularnemu określającemu adres e-mail w następującej formie:
na początku musi wystąpić przynajmniej jedna litera lub liczba,
po niej może ale nie musi wystąpić pojedynczy znak "_" lub "-" lub ".",
następnie musi wystąpić dowolny łańcuch znaków składający się z przynajmniej jednej litery.
kolejnym znakiem musi być "@" rozdzielająca nazwę konta od części domenowej,
Cześć domenowa (po znaku @) musi się składać z:
dowolnego ciągu liter lub cyfr po których następuje znak kropki "." - ta sekwencja może się powtórzyć minimum raz a maksimum 4 razy.
na końcu musi znajdować się łańcuch składający się z co najmniej 2 liter.
Przetestuj działanie programu wypisującego wszystkie poprawne adresy e-mail na następującym łańcuchu znaków:
Ala Nowak: alanowak@costam.pl, Jan Kowalski: jan123Kowalski@inny.costam.pl, Jan Maria X: jm.x@xyz.aaa.bb1.pl, Zły Adres1: zlyadres@pl, zły adres2: zly2@123.45 itd
*/

#include <iostream>
#include <regex>

using namespace std;


int main()
{
    string text = "Ala Nowak: alanowak@costam.pl, Jan Kowalski: jan123Kowalski@inny.costam.pl, Jan Maria X: jm.x@xyz.aaa.bb1.pl, Zły Adres1: zlyadres@pl, zły adres2: zly2@123.45";
    regex pattern("[a-zA-Z0-9]+[.-_]?[a-zA-Z]+@([0-9a-zA-Z]+.){1,4}[a-zA-Z][a-zA-Z]+");
    smatch match;
    while(regex_search(text, match, pattern))
    {
        cout << match[0] << endl;
        text = match.suffix().str();
    }
    
    return 0;
}