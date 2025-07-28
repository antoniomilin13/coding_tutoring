/*
Ispis trokuta
Za unesenu sirinu crtamo gornji trokut

Na primjer sirina = 7 crtamo:
red
3  |   *   |
2  |  ***  |
1  | ***** |
0  |*******|

raz + zv + raz = sirina
zv = sirina - 2*raz
zv = sirina - 2*red   -> broj zvjezdica u pojedinom redu

koristimo nasu UNIVERZALNU (vrijedi za svaki red) FORMULU ZA ZADNJI RED:
zv = sirina - 2*red
1 = sirina - 2*red_zad
red_prvi = (sirina - 1)/2

*/

#include <iostream>
using namespace std;

int main()
{
    int red, stupac, sirina, kopija_sirine, b_raz, b_zv, red_prvi;

    cout << "Gornji trokut" << endl;
    cout << "Unesite sirinu trokuta: ";
    cin >> sirina;
    cout << endl;

    if(sirina % 2 == 0){  // broj je paran
        sirina++;  // increment - povecavanje za 1
    }

    red_prvi = (sirina - 1)/2;

    for(red = red_prvi; red >= 0; red--)
    {   // 1) crtanje razmaka
        for(stupac = 0; stupac < red; stupac++){
            cout << " ";
        }

        // 2) crtanje zvjezdica
        //  broj zvjezdica = sirina - 2*red   -> broj zvjezdica u pojedinom redku
        for(stupac = 0; stupac < sirina - 2*red; stupac++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
