#ifndef PLIKUZYTKOWNICY_H
#define PLIKUZYTKOWNICY_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include "Uzytkownik.h"
#include "Plik.h"

using namespace std;

class PlikUzytkownicy : private Plik
{
private:
    string nazwaPlikuZUzytkownikami;

public:
    PlikUzytkownicy();
    virtual ~PlikUzytkownicy();

    void wczytajUzytkownikowZPliku(vector<Uzytkownik> &uzytkownicy);
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku(vector<Uzytkownik> &uzytkownicy);

private:
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
};

#endif
