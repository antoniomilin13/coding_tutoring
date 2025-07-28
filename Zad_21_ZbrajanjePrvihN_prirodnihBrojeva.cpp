/*

Zbroji 1 + 2 + 3 +...+ (n-1) + n rekurzijom

*/


#include <iostream>

using namespace std;

int zbroj(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return zbroj(n-1) + n;
    }
}

int main(){
    int n;

    cout << "Upisite zadnji clan: ";
    cin >> n;

    cout << zbroj(n) << endl;

    return 0;
}
