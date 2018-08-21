#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Uzytkownicy.h"
#include "PlikUzytkownicy.h"
#include "Plik.h"
#include "Uzytkownik.h"
// #include "KsiazkaAdresowa.h"

using namespace std;

char wybierzOpcjeZMenuGlownego();
char wybierzOpcjeZMenuZalogowanegoUzytkownika();

int main()
{
    Uzytkownicy uzytkownicy;
    PlikUzytkownicy plik;
    plik.wczytajUzytkownikowZPliku(uzytkownicy);

    char wybor;

    while (true)
    {
        if (uzytkownicy.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                uzytkownicy.rejestracjaUzytkownika();
                break;
            case '2':
                uzytkownicy.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else if (uzytkownicy.pobierzIdZalogowanegoUzytkownika() > 0)
        {
            // KsiazkaAdresowa ksiazkaAdresowa(uzytkownicy.pobierzIdZalogowanegoUzytkownika());

            do
            {
                wybor = wybierzOpcjeZMenuZalogowanegoUzytkownika();

                switch (wybor)
                {
                case '1':
                    // ksiazkaAdresowa.dodajAdresata();
                    break;
                case '2':
                    // ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                    break;
                case '3':
                    // ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                    break;
                case '4':
                    // ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                    break;
                case '5':
                    // ksiazkaAdresowa.usunAdresata();
                    break;
                case '6':
                    // ksiazkaAdresowa.edytujAdresata();
                    break;
                case '7':
                    uzytkownicy.zmianaHaslaZalogowanegoUzytkownika();
                    break;
                case '8':
                    uzytkownicy.wyloguj();
                    break;
                }
            } while (wybor != '8');
        }
    }
    return 0;
}

char wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;
    cin.ignore();

    return wybor;
}

char wybierzOpcjeZMenuZalogowanegoUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> wybor;
    cin.ignore();

    return wybor;
}
