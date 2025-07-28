/*
Aritmeticki niz se definira kao:
a_n+1 = a_n + d
a_n+1 - a_n = d = const
a_n+1 = a_0 + n*d

Primjer:
1,3,5,7,9,...    a_0=1,  d=2
-3,1,5,9,...     a_0=-3, d=4

Neka korisnik upise a_0, d i n (index zadnjeg clana)
Ispisati zadanji niz
*/

#include <iostream>

using namespace std;

int main()
{
    int a_0, d, n;

    cout << "Aritmeticki niz." << endl;
    cout << endl << "Upisite pocetni broj: ";
    cin >> a_0;
    cout << "Upisite d: ";
    cin >> d;
    cout << "Upisite index zadnje clana: ";
    cin >> n;

    for(int i = 0; i <= n; i++){

        cout << a_0 + d * i << " ";
    }
    cout << endl;

    return 0;
}
