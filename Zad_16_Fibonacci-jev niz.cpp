/*
Geometrijski niz se definira kao:
a_n+1 / a_n = q   OMJER dva susjedna clana je uvijek isti
a_n+1 = a_n * q     q = const
a_n+1 = a_0 * q^n

Primjer:
2,4,8,16,...     a_0=2,  q=2
-1,1,-1,1,...    a_0=-1, q=-1

Neka korisnik upise a_0, q i n (index zadnjeg clana)
Ispisati zadanji niz
*/

#include <iostream>

using namespace std;

int main()
{
    int a, q, n;

    cout << "Geometrijski niz." << endl;
    cout << endl << "Upisite pocetni broj: ";
    cin >> a;
    cout << "Upisite q: ";
    cin >> q;
    cout << "Upisite index zadnje clana: ";
    cin >> n;

    for(int i = 0; i <= n; i++){
        // a_n+1 / a_n = q

        cout << a << " ";
        a = a * q;

    }
    cout << endl;

    return 0;
}
