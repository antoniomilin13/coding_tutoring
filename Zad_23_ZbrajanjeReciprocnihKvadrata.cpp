/*

Zbroji_raz:
 1 + ¼ + 1/9 + 1/16 + ... + 1/(n-1)^2 + 1/n^2    RJ : ulaz 6 izlaz : 1.49
zbroj(n) = zbroj (n-1) + 1/n^2

*/


#include <iostream>

using namespace std;

double zbroj(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return zbroj(n-1) + 1/(double) (n*n);   // cast operator -> pretvara "int u double"... jedan tip u drugi
    }

}

int main(){
    int n;

    cout << "Upisite zadnji clan: ";
    cin >> n;

    cout << zbroj(n) << endl;

    return 0;
}
