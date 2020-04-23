#include <iostream>
#include "dinstring.hpp"

using namespace std;

class Tastatura{
protected:
    DinString proizvodjac;
    int brojTastera;
public:
    void ispis(){
        cout << proizvodjac << " " << brojTastera;
    }
};

class GejmerskaTastatura : public Tastatura{
private:
    int brojPritisaka;
public:
    GejmerskaTastatura(){
        brojPritisaka = 0;
        proizvodjac = "Red Dragon";
        brojTastera = 104;
    }
    GejmerskaTastatura(int a, DinString b, int c){
        brojPritisaka = a;
        proizvodjac = b;
        brojTastera = c;
    }
    GejmerskaTastatura(const GejmerskaTastatura &g){
        brojPritisaka = g.brojPritisaka;
        proizvodjac = g.proizvodjac;
        brojTastera = g.brojTastera;
    }

    ~GejmerskaTastatura(){}

    void ispis(){
        Tastatura::ispis();
        cout << " " << brojPritisaka << endl;
    }
    void pritisniTaster(){
        brojPritisaka += 1;
    }
    void drziTaster(int sec){
        brojPritisaka += sec;
    }
};

class NumerickaTastatura : public Tastatura{
private:
    int brojPritisakaBrojeva;
public:
    NumerickaTastatura(){
        brojPritisakaBrojeva = 0;
        proizvodjac = "Logitech";
        brojTastera = 17;
    }
    NumerickaTastatura(int a, DinString b, int c){
        brojPritisakaBrojeva = a;
        proizvodjac = b;
        brojTastera = c;
    }
    NumerickaTastatura(const NumerickaTastatura &n){
        brojPritisakaBrojeva = n.brojPritisakaBrojeva;
        proizvodjac = n.proizvodjac;
        brojTastera = n.brojTastera;
    }
    ~NumerickaTastatura(){}

    void ispis(){
        Tastatura :: ispis();
        cout << brojPritisakaBrojeva << endl;
    }
    void pritisniTaster(bool pritisnutiBroj){
        if(pritisnutiBroj)
            brojPritisakaBrojeva += 1;
    }
    void drziTaster(int sec, bool pritisnutiBroj){
        if(pritisnutiBroj)
            brojPritisakaBrojeva += sec;
    }
};

int main()
{
    GejmerskaTastatura g1;
    GejmerskaTastatura g2(0, "Razer", 101);
    GejmerskaTastatura g3(g1);

    g1.ispis();
    g2.ispis();
    g3.ispis();

    g1.drziTaster(30);
    g2.pritisniTaster();

    g1.ispis();
    g2.ispis();

    NumerickaTastatura n1;
    NumerickaTastatura n2(700, "LG", 17);
    NumerickaTastatura n3(n1);

    n1.ispis();
    n2.ispis();
    n3.ispis();

    n1.drziTaster(3,true);
    n2.pritisniTaster(false);

    n1.ispis();
    n2.ispis();

    n1.pritisniTaster(false);
    n2.drziTaster(5,true);

    n1.ispis();
    n2.ispis();

    n1.drziTaster(8,true);
    n2.pritisniTaster(false);

    n1.ispis();
    n2.ispis();

    return 0;
}
