#include <iostream>

#include "dinstring.hpp"
#include "list.hpp"

enum Vrsta {Medo, Zeko, Kuca, Maca};

using namespace std;

class Igracka
{
protected:
    DinString Naziv;
    DinString OpsegGodina;
public:
    virtual void ispisi() = 0;
    DinString getNaziv() const
    {
        return Naziv;
    }
};

class PlisanaIgracka : public Igracka
{
private:
    Vrsta vrsta;
public:
    PlisanaIgracka()
    {
        vrsta = Maca;
        Naziv = "Hello Kitty";
        OpsegGodina = "2 - 7";
    }
    PlisanaIgracka(DinString n, DinString og, Vrsta v)
    {
        vrsta = v;
        Naziv = n;
        OpsegGodina = og;
    }
    void ispisi()
    {
        cout << "Plisana igracka:" << endl;
        cout  << "Naziv: " << Naziv << endl;
        cout <<"Vrsta: ";
        if(vrsta == Medo)
            cout << "Medo" << endl;
        else if(vrsta == Maca)
            cout << "Maca" << endl;
        else if(vrsta == Zeko)
            cout << "Zeko" << endl;
        else
            cout << "Kuca" << endl;
        cout << "Opseg godina: " << OpsegGodina << endl;
    }
};

class Autic : public Igracka
{
private:
    bool NaStruju;
public:
    Autic()
    {
        Naziv = "Hot Wheels";
        OpsegGodina = "3 - 8";
        NaStruju = false;
    }
    Autic(DinString n, DinString og, bool s)
    {
        Naziv = n;
        OpsegGodina = og;
        NaStruju = s;
    }
    void ispisi()
    {
        cout << "Autic:" << endl;
        cout << "Naziv: " << Naziv << endl;
        cout << "Na struju: ";
        if(NaStruju)
            cout << "Jeste" << endl;
        else
            cout << "Nije" << endl;
        cout << "Opseg godina: " << OpsegGodina << endl;
    }
};

class Igraonica
{
private:
    List <Igracka*> igracka;
public:
    bool dodajIgracku(Igracka* i)
    {
        if(igracka.add(igracka.size() + 1, i))
            return true;
        else
            return false;
    }
    bool baciIgracku(int j)
    {
        if(igracka.remove(j))
            return true;
        else
            return false;
    }
    bool nadjiIgracku(DinString n)
    {
        bool Postojanje = false;
        Igracka* i;
        for(int j = 1; j <= igracka.size(); ++j)
        {
            igracka.read(j, i);
            if(i -> getNaziv() == n)
                Postojanje = true;
        }
        return Postojanje;
    }
    void ispisiIgracke()
    {
        cout<<"Igraonica:"<<endl;
        cout  << "Broj igracaka: " << igracka.size() << endl;
        Igracka* i;
        for(int j = 1; j <= igracka.size(); ++j)
        {
            igracka.read(j, i);
            i -> ispisi();
        }
    }
};

int main()
{
    PlisanaIgracka p1;
    PlisanaIgracka p2("Mihajlo", "2 - 5", Kuca);
    Autic a1;
    Autic a2("Audi","4 - 15",true);
    Igracka *i1 = &p1;
    Igracka *i2 = &p2;
    Igracka *i3 = &a1;
    Igracka *i4 = &a2;
    i1 -> ispisi();
    i2 -> ispisi();
    i3 -> ispisi();
    i4 -> ispisi();
    Igraonica igraonica;
    igraonica.dodajIgracku(i1);
    igraonica.ispisiIgracke();
    igraonica.dodajIgracku(i2);
    igraonica.dodajIgracku(i3);
    igraonica.ispisiIgracke();
    igraonica.baciIgracku(2);
    igraonica.dodajIgracku(i4);
    igraonica.ispisiIgracke();

    return 0;
}
