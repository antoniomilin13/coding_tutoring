/*
Zbroji_raz:
1/2 - 2/3 + 3/4 - 4/5 + ...
zbroj(n) = zbroj (n-1) + (-1)^(n+1) * n/(n+1)
*/

#include <iostream>
using namespace std;

double zbroj(int n){
    double predznak;

    if(n % 2 == 0){
        predznak = -1;
    }
    else{
        predznak = +1;
    }

    if(n <= 1){
        return 0.5;
    }
    else{
        return zbroj(n-1) + predznak * n/(n+1); // cast operator -> pretvara "int u double"... jedan tip u drugi
    }

}

int main(){
    int n;

    cout << "Upisite zadnji clan: ";
    cin >> n;

    cout << zbroj(n) << endl;

    return 0;
}
