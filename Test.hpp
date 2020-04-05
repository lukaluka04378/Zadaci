#ifndef TEST_HPP_INCLUDED
#define TEST_HPP_INCLUDED

#include "Mreza.hpp"
using namespace std;

enum StanjeTesta {START, PROCESIRANJE, OPTIMIZACIJA, KRAJ};
enum TipOptimizacije {DODAJ_SLOJ, DODAJ_NEURON};

class Test
{
private:
    NeuronskaMreza nm;
    double zeljeniProcenatUspesnosti;
    int brOptimizacija;
    StanjeTesta stanje;
public:
    Test(double z) : nm(3, 200)
    {
        if(z >= 0 && z <= 1)
            zeljeniProcenatUspesnosti = z;
        else
            zeljeniProcenatUspesnosti = 0.85;
        stanje = START;
        brOptimizacija = 0;
    }
    bool procesiraj()
    {
        if(stanje == START || stanje == OPTIMIZACIJA)
        {
            if(zeljeniProcenatUspesnosti >= nm.izracunajUspeh())
                stanje = PROCESIRANJE;
            else
            {
                stanje = KRAJ;
                cout << "Test je uspesan" << endl;
            }
            return true;
        }
        else
        {
            cout << "Nemoguca akcija" << endl;
            return false;
        }
    }
    bool potrebnoOptimizovati()
    {
        if(stanje == PROCESIRANJE)
        {
            stanje = OPTIMIZACIJA;
            return true;
        }
        else
        {
            cout << "Nemoguca akcija" << endl;
            return false;
        }
    }
    bool optimizuj(TipOptimizacije tip)
    {
        if(stanje == OPTIMIZACIJA)
        {
            if(tip == DODAJ_SLOJ)
                nm.dodajSkriveniSloj();
            else
                nm.dodajNeuron();
            return true;

        }
        else
        {
            cout << "Nemoguca akcija" << endl;
            return false;
        }
    }
    double izracunajUspeh() const
    {
        return nm.izracunajUspeh();

    }
    TipMreze getTipMreze() const
    {
        return nm.getTipMreze();
    }
    StanjeTesta getStanje() const
    {
        return stanje;
    }
};

void ispisiTest(const Test &t)
{
    cout<<"Stanje: ";
    if(t.getStanje()==0)
        cout<<"START"<<endl;
    else if(t.getStanje()==1)
        cout<<"PROCESIRANJE"<<endl;
    else if(t.getStanje()==2)
        cout<<"OPTIMIZACIJA"<<endl;
    else if(t.getStanje()==3)
        cout<<"KRAJ"<<endl;
    cout<<"Tip mreze: ";
    if(t.getTipMreze()==OBICNA)
        cout<<"OBICNA"<<endl;
    else
        cout<<"DUBOKA"<<endl;
    cout<<"Uspeh: "<<t.izracunajUspeh()<<endl;
}


#endif // TEST_HPP_INCLUDED
