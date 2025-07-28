/*
Faktorijele se definiraju kao:
n! = 1*2*3 ... *n
n! =  1*2*3 ... *(n-1)*n = (n-1)! * n  - rekurzivna formula spaja PREDHODNU sa SLJEDECOM vrijednosti


Primjer:
4! = (((1)*2)*3)*4

Neka korisnik upise n

prezentac dvojnog komplementa
signed int = int = najvisi bit je predznak (0-plus i 1 minus)
00000000 - 0
. . .
01111111 - 127   - najveci int u 8 bita ili 1 byte
10000000
10000001         - negativni brojevi
11111111         -1
-1 + 1 = 0
    1111 1111    -1
    0000 0001    +1
    ---------    --
  1 0000 0000     0

*/

#include <iostream>

using namespace std;

int main()
{
    int n,umnozak;

    cout << "Faktroijele." << endl;
    cout << "Upisite broj faktorijela: ";
    cin >> n;

    umnozak = 1;
    cout << umnozak << endl;
    for(int i = 2; i <= n; i++){
        // n! = (n-1)! * n  - rekurzivna formula spaja PREDHODNU sa SLJEDECOM vrijednosti
        umnozak = umnozak * i;
        cout << umnozak << endl;
    }
    cout << endl;

    return 0;
}
