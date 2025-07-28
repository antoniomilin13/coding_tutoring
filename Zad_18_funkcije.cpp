/*
Faktorijele kao f-ja
n! = 1*2*3* ... n

Primjer:
Neka korisnik upise n - broj faktorijela
Ispisati sve prethodne faktorijele

0! = 1
1! = 1
2! = 2
3! = 6
...
*/
#include <iostream>

using namespace std;

int fakt(int n){
    int i,umnozak = 1;
    for (i=2; i<=n;i++){
        umnozak *= i;
    }
    return umnozak;
}


int main()
{
    int n;

    cout << "Faktorijele" << endl;
    cout << endl << "Upisite koliko faktorijela zelite: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << i << "! = " << fakt(i) << endl;
    }


    return 0;
}
