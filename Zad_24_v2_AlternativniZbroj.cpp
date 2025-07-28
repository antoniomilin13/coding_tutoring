/*

Zbroji_raz:
 1-2+3-4+...(-1)^(n+1)               RJ : ulaz 6 izlaz -3
zbroj(n) = zbroj (n-1) + (-1)^(n+1) * n

*/


#include <iostream>

using namespace std;

int zbroj(int n, int predznak){

    if(n <= 1){
        return 1;
    }
    else{
        return zbroj(n-1, -predznak) + predznak * n; // cast operator -> pretvara "int u double"... jedan tip u drugi
    }

}

int main(){
    int n;

    cout << "Upisite zadnji clan: ";
    cin >> n;

    cout << zbroj(n,-1) << endl;

    return 0;
}
