/*
Napiši rekurzivnu funkciju koja računa n-ti korjen izraza:

sqrt(a+sqrt(a+ ... + sqrt(a)))  sa n nivoa

y(n+1) = sqrt(a + y(n))

Unesi a,n.
izracunaj n-ti korjen

*/

#include <iostream>
#include <math.h>

using namespace std;

double korijen(double a, int n){

    if(n == 1){
        return sqrt(a);
    }
    else{
        return sqrt(a + korijen(a, n-1)); // cast operator -> pretvara "int u double"... jedan tip u drugi
    }

}

int main(){
    int n;
    double a;

    cout << "Program racuna sqrt(a+sqrt(a+ ... + sqrt(a)))  sa n nivoa" << endl << endl;
    cout << "Upisite broj pod korijenom: ";
    cin >> a;
    cout << "Upisite n: ";
    cin >> n;

    cout << korijen(a, n) << endl;

    return 0;
}
