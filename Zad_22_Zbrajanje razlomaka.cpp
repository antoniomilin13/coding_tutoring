/*

Zbroji_raz:
 1 + ½ + 1/3 + ¼ + ...+1/(n-1) + 1/n     -> RJ : ulaz = 6; izlaz = 2.45;
zbroj(n-1) + 1/n   = zbroj (n)

*/


#include <iostream>

using namespace std;

double zbroj_razl(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return zbroj_razl(n-1) + 1/(double) n;   // cast operator -> pretvara "int u double"... jedan tip u drugi
    }

}

int main(){
    int n;

    cout << "Upisite zadnji clan: ";
    cin >> n;

    cout << zbroj_razl(n) << endl;

    return 0;
}
