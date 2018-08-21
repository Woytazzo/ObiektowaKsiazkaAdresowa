#include "Uzytkownicy.h"

using namespace std;

Uzytkownicy::Uzytkownicy()
{
    this->idZalogowanegoUzytkownika = 0;
    plikUzytkownicy.wczytajUzytkownikowZPliku(uzytkownicy);
}

Uzytkownicy::~Uzytkownicy()
{
    uzytkownicy.clear();
}

void Uzytkownicy::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikUzytkownicy.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void Uzytkownicy::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    int iloscProb = 3;
    bool czyIstniejeUzytkownik = false;

    cout << endl << "Podaj login: ";
    cin >> login;
    cin.ignore();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr->Uzytkownik::pobierzLogin() == login)
        {
            while (iloscProb > 0)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;
                cin.ignore();

                if (itr->Uzytkownik::pobierzHaslo() == haslo)
                {
                    this->idZalogowanegoUzytkownika = itr->Uzytkownik::pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    czyIstniejeUzytkownik = true;
                    break;
                }
                iloscProb--;
            }
            if (iloscProb == 0)
            {
                cout << endl << "Wprowadzono 3 razy bledne haslo." << endl << endl;
                this->idZalogowanegoUzytkownika = 0;
                czyIstniejeUzytkownik = true;
                break;
            }
        }
        itr++;
    }
    if (czyIstniejeUzytkownik == false)
    {
        cout << endl << "Nie ma uzytkownika z takim loginem" << endl << endl;
    }

    system("pause");
}

void Uzytkownicy::zmianaHaslaZalogowanegoUzytkownika()
{
    if (idZalogowanegoUzytkownika > 0)
    {
        string noweHaslo = "";
        bool czyZmienionoHaslo = false;

        noweHaslo = wprowadzHaslo();

        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            if (itr->Uzytkownik::pobierzId() == idZalogowanegoUzytkownika)
            {
                itr->Uzytkownik::ustawHaslo(noweHaslo);
                czyZmienionoHaslo = true;
            }
        }
        plikUzytkownicy.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);

        if (czyZmienionoHaslo)
        {
            cout << "Haslo zostalo zmienione." << endl << endl;
        }
        else
        {
            cout << "Haslo NIE zostalo zmienione." << endl << endl;
        }
    }
    else
    {
        cout << "Niepoprawny numer id. Aby zmienic haslo musisz sie zalogowac." << endl << endl;
    }

    system("pause");
}

Uzytkownik Uzytkownicy::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do
    {
        cout << endl << "Podaj login: ";
        cin >> login;
        cin.ignore();
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    haslo = wprowadzHaslo();
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

string Uzytkownicy::wprowadzHaslo()
{
    string haslo ="";

    do
    {
        cout << "Podaj haslo (minimum 3 znaki): ";
        cin >> haslo;
        cin.ignore();
    } while (haslo.length() < 3);

    return haslo;
}

int Uzytkownicy::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
    {
        return 1;
    }
    else
    {
        return uzytkownicy.back().pobierzId() + 1;
    }
}

bool Uzytkownicy::czyIstniejeLogin(string login)
{
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();

    while (itr != uzytkownicy.end())
    {
        if (itr->Uzytkownik::pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else
        {
            itr++;
        }
    }
	
    return false;
}

int Uzytkownicy::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void Uzytkownicy::wyloguj()
{
    this->idZalogowanegoUzytkownika = 0;
}
