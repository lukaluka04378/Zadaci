#include <iostream>

#include "Mreza.hpp"
#include "Test.hpp"

using namespace std;

int meni()
{
    int n;
    cout << "Unesite broj za operaciju koju zelite:" << endl;
    cout << "1. Procesiraj" << endl;
    cout << "2. Potrebno optimizovati" << endl;
    cout << "3. Optimizuj" << endl;
    cin >> n;
    return n;
}
int main()
{
    Test t(0.9);
    int n;
    bool b;
    do
    {
        n = meni();
        switch(n)
        {
        case 1:
            b = t.procesiraj();
            break;
        case 2:
            b = t.potrebnoOptimizovati();
            break;
        case 3:
            if(t.getStanje() == OPTIMIZACIJA)
            {
                cout << "Pritisnite 1 da dodate sloj, a 2 da dodate neuron: ";
                int i;
                do
                {
                    cin >> i;
                    if(i == 1)
                        b = t.optimizuj(DODAJ_SLOJ);
                    if(i == 2)
                        b = t.optimizuj(DODAJ_NEURON);
                    else
                        cout << "Nepostojeca opcija" << endl;
                }
                while(i > 2 || i < 1);
                break;
            }
            else
                cout<<"Nepostojeca opcija"<<endl;
        }
        if(n > 3 || n < 1)
            cout << "Nepostojeca opcija" << endl;
        else if(b == true)
            ispisiTest(t);
    }
    while(t.getStanje() != KRAJ);
    return 0;
}
