#ifndef MREZA_HPP_INCLUDED
#define MREZA_HPP_INCLUDED

#include <cmath>
using namespace std;

enum TipMreze {DUBOKA, OBICNA};

class NeuronskaMreza
{
private:
    int brSkrivenihSlojeva;
    int brNeuronaPoSloju;
public:
    NeuronskaMreza(int s, int b)
    {
        if(s > 0)
            brSkrivenihSlojeva = s;
        else
            brSkrivenihSlojeva = 0;
        if(b > 0)
            brNeuronaPoSloju = b;
        else
            brNeuronaPoSloju = 0;
    }
    void dodajSkriveniSloj()
    {
        brSkrivenihSlojeva += 1;
        cout << brSkrivenihSlojeva << endl;
    }
    void dodajNeuron()
    {
        brNeuronaPoSloju += 1;
        cout << brNeuronaPoSloju << endl;
    }
    double izracunajUspeh() const
    {
        double s = brSkrivenihSlojeva * 100 / 100;
        double n = brNeuronaPoSloju * 100 / 100;
        return 1 - (1 / log(s * n));
    }
    TipMreze getTipMreze() const
    {
        if(brSkrivenihSlojeva * brNeuronaPoSloju >= 998)
            return DUBOKA;
        else
            return OBICNA;
    }
};

#endif // MREZA_HPP_INCLUDED
