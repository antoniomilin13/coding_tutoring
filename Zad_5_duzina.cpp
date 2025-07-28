/*
Ispis pravca zadane duzine

Za duljinu na primjer 5 crtamo:
*****
*/

#include <iostream>
using namespace std;

int main()
{
    int d,i;

    cout << "Unesite zeljenu duljinu vaseg pravca: ";
    cin >> d;
    cout << endl;

    cout << "Nacrtani pravac je ispod:" << endl;

    for(i = 0; i < d; i++)
    {
        cout << "*";
    }
    cout << endl;

    return 0;
}
