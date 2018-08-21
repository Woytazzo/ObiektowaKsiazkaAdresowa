#ifndef PLIK_H
#define PLIK_H

#include <iostream>
#include <fstream>

using namespace std;

class Plik
{
public:
    Plik();
    virtual ~Plik();

protected:
    bool czyPlikJestPusty(fstream &plikTekstowy);
};

#endif
