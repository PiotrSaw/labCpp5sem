#include "Dictionary.h"
#include <iostream>
using namespace std;

Dictionary::Dictionary()
{
    //ctor
}

Dictionary::~Dictionary()
{
    //dtor
}


void Dictionary::add(string s1, string s2)
{
    if(words.find(s1) == words.end()) words.insert(pair<string, string>(s1, s2));
    else cout << "To pojecie juz istnieje w slowniku" << endl;
}

void Dictionary::deleteWord(string s)
{
    words.erase(s);
}

void Dictionary::print()
{
    for(auto it = words.begin(); it != words.end(); it++)
    {
        cout << it->first << " - " << it->second <<endl;
    }
}

 void Dictionary::printTranslation(string s)
 {
     if(words.find(s) != words.end()) cout << s << " - " << words[s] << endl;
     else cout << "Nie istnieje pojecie " << s << " w slowniku" << endl;
 }
