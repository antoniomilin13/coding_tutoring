/*
Ispis pravokutnika

Za znesenu sirinu i visinu crtamo pravkutnik

Na primjer sirina =5 i visina =3 crtamo:

*****
*****
*****
*/

#include <iostream>
using namespace std;

int main()
{
    int red, stupac, v, s;

    cout << "Pravokutnik" << endl << endl;
    cout << "Unesite visinu pravokutnika: ";
    cin >> v;
    cout << "Unesite sirinu pravokutnika: ";
    cin >> s;
    cout << endl;

    for(red = 0; red < v ; red++)
    {
        for(stupac = 0; stupac < s; stupac++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
