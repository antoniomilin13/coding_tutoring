/*
Napiši rekurzivnu funkciju koja računa n-tu potenciju prirodnog broja a

y=a^n = a*a*a*a*a*a*a   - n puta
a^(n+1) = a*a*a*a*a*a*a*a - n+1 puta
a^(n+1) = a*a*...*a  * a = a^n * a

a^(n+1) = a^n * a   - rekurzija

Unesi a i n.
izracunaj a^n
npr. 2^n
2 4 8 16 ...
*/

#include <iostream>
using namespace std;

double umnozak(double a, int n){

    if(n == 0){
        return 1;
    }
    else{
        return umnozak(a, n-1) * a; // cast operator -> pretvara "int u double"... jedan tip u drugi
    }

}

int main(){
    int n;
    double a;

    cout << "Upisite bazu: ";
    cin >> a;
    cout << "Upisite eksponent: ";
    cin >> n;

    cout << umnozak(a, n) << endl;

    return 0;
}
