/*
Ispis jednog reda tablice mnozenja

na primjer za ulaz = 5 ispisujemo:
5 10 15 20 25 30 35 40 45 50
*/

#include <iostream>
using namespace std;

int main()
{
    int r,i;

    cout << "Unesite zeljeni redak tablice mnozenja: ";
    cin >> r;
    cout << endl;

    cout << "Nacrtani pravac je ispod:" << endl;

    for(i = 1; i <= 10; i++)
    {
        cout << i * r << " ";
    }
    cout << endl;

    return 0;
}
