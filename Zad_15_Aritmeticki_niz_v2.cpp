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
    int a, d, n;

    cout << "Aritmeticki niz." << endl;
    cout << endl << "Upisite pocetni broj: ";
    cin >> a;
    cout << "Upisite d: ";
    cin >> d;
    cout << "Upisite index zadnje clana: ";
    cin >> n;

    for(int i = 0; i <= n; i++){
        // a_(n+1) = a_(n) + d  rekurzivna formula
        cout << a << " ";
        a = a + d;  // ovo NIJE JEDNAKOST NEGO PRIDRUZIVANJE desne strane lijevoj
        // ovo pridruzivanje daje SLIJEDECU vrijednost iz PREDHODNE
        // a s lijeve strane je NOVI a (a_n+1), a a s desne je STARI a (a_n)
    }
    cout << endl;

    return 0;
}
