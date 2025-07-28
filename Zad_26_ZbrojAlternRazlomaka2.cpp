/*
Zbroji_raz:
n = 0   1     2     3
    1 – 1/3 + 1/5 – 1/7 + ...
zbroj(n) = zbroj (n-1) + 1/(2*n+1)
*/

#include <iostream>
using namespace std;

double zbroj(int n){
    double predznak;

    if(n % 2 == 0){
        predznak = 1;
    }
    else{
        predznak = -1;
    }

    if(n == 0){
        return 1;
    }
    else{
        return zbroj(n-1) + predznak * 1/(2*n+1); // cast operator -> pretvara "int u double"... jedan tip u drugi
    }

}

int main(){
    int n;

    //
    int total = 0;
    while (flag != 0) {
        int one = zbroj(i);

    }

    cout << zbroj(n) << endl;

    cout << "Broj pi (1) = " << zbroj(n) * 4 << endl;


    return 0;
}
