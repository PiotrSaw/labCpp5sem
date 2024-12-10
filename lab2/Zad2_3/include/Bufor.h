#ifndef BUFOR_H
#define BUFOR_H


class Bufor
{
    public:
        Bufor();
        Bufor(int s);
        virtual ~Bufor();
        virtual void add(int value);
        virtual double calculate() = 0;
        int getIndex();
        int getSize();
        int getFirst();
        int getTab(int i);
        void setFirst(int value);
        void setTab(int pos, int value);
        void print();
        void setIndex();

    protected:

    private:
        int * table;
        int size;
        int index;
};

#endif // BUFOR_H
