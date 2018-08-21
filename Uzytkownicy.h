#ifndef UZYTKOWNICY_H
#define UZYTKOWNICY_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Uzytkownik.h"
#include "PlikUzytkownicy.h"

using namespace std;

class Uzytkownicy
{
private:
    vector<Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;
    PlikUzytkownicy plikUzytkownicy;

public:
    Uzytkownicy();
    virtual ~Uzytkownicy();

    int pobierzIdZalogowanegoUzytkownika();
    void logowanieUzytkownika();
    void rejestracjaUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyloguj();

private:
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    string wprowadzHaslo();
};

#endif
