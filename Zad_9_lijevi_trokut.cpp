/*
Ispis pravokutnika

Za unesenu sirinu crtamo lijevi trokut

Na primjer sirina = 5 crtamo:


****
***
**
*

*/

#include <iostream>
using namespace std;

int main()
{
    int red, stupac, sirina, kopija_sirine;

    cout << "Lijevi trokut" << endl;
    cout << "Unesite sirinu trokuta: ";
    cin >> sirina;
    cout << endl;

    kopija_sirine = sirina;  // sirina OSTAJE KONSTANTA
                             // kopija_sirine je VARIJABLA pa se moze mijenjati

    for(red = 0; red < sirina; red++)
    {
        for(stupac = 0; stupac < kopija_sirine; stupac++)
        {
            cout << "*";
        }
        kopija_sirine--;

        cout << endl;
    }
    cout << endl;

    return 0;
}
