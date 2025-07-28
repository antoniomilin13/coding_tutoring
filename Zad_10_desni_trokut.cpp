/*
Ispis pravokutnika

Za unesenu sirinu crtamo desni trokut

Na primjer sirina = 5 crtamo:
red
0  |****|
1  | ***|
2  |  **|
3  |   *|

zv + raz = sirina
zv = sirina - raz
zv = sirina - red   -> broj zvjezdica u pojedinom redu

*/

#include <iostream>
using namespace std;

int main()
{
    int red, stupac, sirina, kopija_sirine, b_raz, b_zv;

    cout << "Desni trokut" << endl;
    cout << "Unesite sirinu trokuta: ";
    cin >> sirina;
    cout << endl;

    for(red = 0; red < sirina; red++)
    {   // 1) crtanje razmaka
        for(stupac = 0; stupac < red; stupac++){

            cout << " ";
        }

        // 2) crtanje zvjezdica
        //  broj zvjezdica = sirina - red   -> broj zvjezdica u pojedinom redku
        for(stupac = 0; stupac < sirina - red; stupac++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
