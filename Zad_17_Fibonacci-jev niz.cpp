/*
Fibonacc-ijev niz se definira kao:
a_n+2 = a_n+1 + a_n
a_0 = 0  i  a_1 = 1

Primjer:
Neka korisnik upise n (index zadnjeg clana)
Ispisati zadanji niz

0,1,1,2,3,5,8,13,21, ....
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    int f1 = 0;
    int f2 = 1;
    int zbroj = 0;

    cout << "Fibonacci-jev niz." << endl;
    cout << endl << "Upisite redni broj zadnjeg clana niza: ";
    cin >> n;

    cout << f1 << " " << f2 << " ";
    for(int i = 2; i <= n; i++){
        //a_n+2 = a_n+1 + a_n
        zbroj = f1 + f2;
        f1 = f2;
        f2 = zbroj;

        cout << zbroj << " ";
    }
    cout << endl;

    return 0;
}
