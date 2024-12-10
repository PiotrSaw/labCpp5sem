#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <map>
using namespace std;


class Dictionary
{
    public:
        Dictionary();
        virtual ~Dictionary();
        void add(string s1, string s2);
        void deleteWord(string s);
        void print();
        void printTranslation(string s);

    protected:

    private:
        map<string, string> words;

};

#endif // DICTIONARY_H
