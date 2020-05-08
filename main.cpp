#include <iostream>

#include "dinstring.hpp"
#include "list.hpp"

using namespace std;

class Karta
{
protected:
    DinString mestoPolaska;
    DinString mestoDolaska;
    float duzina;
    float cena;
    int id;
public:
    Karta()
    {
        mestoPolaska = "Beograd";
        mestoDolaska = "Berlin";
        duzina = 1200;
        cena = 21000;
        id = 22;
    }
    Karta(DinString a, DinString b, float c, float d, int e)
    {
        mestoPolaska = a;
        mestoDolaska = b;
        duzina = c;
        cena = d;
        id = e;
    }
    virtual bool jeftinaKarta() = 0;
    DinString getMestoPolaska()const
    {
        return mestoPolaska;
    }
    DinString getMestoDolaska()const
    {
        return mestoDolaska;
    }
    float getDuzina()const
    {
        return duzina;
    }
    float getCena()const
    {
        return cena;
    }
    int getId()const
    {
        return id;
    }
};

class avionskaKarta : public Karta
{
public:
    avionskaKarta() : Karta(){}
    avionskaKarta(DinString a, DinString b, float c, float d, int e) : Karta(a,b,c,d,e){}
    bool jeftinaKarta()
    {
        if(cena / duzina < 1)
            return true;
        else
            return false;
    }
    void ispisi()
    {
        cout<<"Mesto polaska: "<<mestoPolaska<<endl
        <<"Mesto dolaska: "<<mestoDolaska<<endl
        <<"Duzina: "<<duzina<<endl
        <<"Cena: "<<cena<<endl
        <<"Identifikacioni broj: "<<id<<endl;
    }
};

class Putovanje
{
private:
    DinString naziv;
    int maksCena;
    List <avionskaKarta> karte;
public:
    Putovanje()
    {
        naziv = "Idemo daleko";
        maksCena = 50000;
    }
    Putovanje(DinString a, int b)
    {
        naziv = a;
        maksCena = b;
    }
    DinString getNaziv()const
    {
        return naziv;
    }
    int getMaksCena()const
    {
        return maksCena;
    }
    bool dodajKartu(const avionskaKarta& a)
    {
        avionskaKarta poslednjaKarta;
        karte.read(karte.size(),poslednjaKarta);
        bool postoji = true;
        if(karte.size()==0)
            karte.add(1,a);
        else if(a.getMestoPolaska() == poslednjaKarta.getMestoDolaska() && a.getCena() <= maksCena)
        {
            for(int i = 1;i <= karte.size();++i)
            {
                karte.read(i,poslednjaKarta);
                if(poslednjaKarta.getId()==a.getId())
                    postoji = false;
            }
            if(postoji)
                karte.add(karte.size()+1,a);
        }
        else
            postoji = false;
        return postoji;
    }
    bool izbaciKartu(int iden)
    {
        avionskaKarta karta;
        for(int i = 1;i < karte.size();++i)
        {
            karte.read(i,karta);
            if(karta.getId() == iden)
            {
                karte.remove(i);
                return true;
            }
        }
        return false;
    }
    void ispisi()
    {
        cout<<"Naziv: "<<naziv<<endl
        <<"Maksimalna cena: "<<maksCena<<endl
        <<"Broj karti: "<<karte.size()<<endl;
        avionskaKarta karta;
        for(int i = 1;i <= karte.size();++i)
        {
            karte.read(i,karta);
            karta.ispisi();
            if(karta.jeftinaKarta())
                cout<<"Jeftina karta"<<endl;
            else
                cout<<"Nije jeftina karta"<<endl;
        }
    }
};

int main()
{
    avionskaKarta a1;
    avionskaKarta a2("Berlin", "Beograd",1200,25000,23);
    cout<<a1.getMestoPolaska()<<endl;
    cout<<a1.getMestoDolaska()<<endl;
    cout<<a1.getDuzina()<<endl;
    cout<<a1.getCena()<<endl;
    cout<<a1.getId()<<endl;
    a1.ispisi();
    cout<<a2.getMestoPolaska()<<endl;
    cout<<a2.getMestoDolaska()<<endl;
    cout<<a2.getDuzina()<<endl;
    cout<<a2.getCena()<<endl;
    cout<<a2.getId()<<endl;
    a2.ispisi();
    avionskaKarta a3("Beograd","Moskva",2000,30000,42);
    Putovanje p1;
    p1.ispisi();
    p1.dodajKartu(a1);
    p1.ispisi();
    p1.dodajKartu(a2);
    p1.ispisi();
    p1.dodajKartu(a3);
    p1.ispisi();
    Putovanje p2("Cim se zavrsi karantin iddem negde",100000);
    avionskaKarta a4("Moskva","Beograd",20000,35000,43);
    p2.dodajKartu(a2);
    p2.dodajKartu(a4);
    p2.ispisi();
    p2.izbaciKartu(105);
    p2.ispisi();
    cout<<p2.getNaziv()<<endl;
    cout<<p2.getMaksCena();
    return 0;
}
