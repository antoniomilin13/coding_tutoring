/*
pi/4 = + 1/1 - 1/3 + 1/5 - 1/7 + 1/9 ...
n - broj clanova do kojih idemo u racunu

10 - pi
100 - pi
1000 - pi
10000 - pi
100000 - pi
1000000 - pi

*/
#include <iostream>
#include <math.h>

using namespace std;

double pi(int n){
    double zbroj = 0;
    int i, predznak = -1;
    for (i = 1; i <= n ; i++){
        // dijeljenje dva cila borja je cili broj; npr. 1/3 = 0, zbog toga bi nam rezultat bia krivi,
        //pa jedan od njih moramo pretvoriti u double
        zbroj = zbroj - predznak * ((double)1/(i*2 - 1));
        predznak *= -1;
    }
    return zbroj*4;
}

double fakt(int n){
    double f = 1;
    for(int i = 2; i <= n; i++){
        f *= i;
    }
    return f;
}

double pi2(int n){
    double novi, zbroj = 0;

    for(int k = 0; k <= n; k++){
        novi = fakt(4*k) * (1103 + 26390*k)/(pow(fakt(k), 4) * pow(396, 4*k));
        zbroj = zbroj + novi;
    }
    zbroj = zbroj * 2*sqrt(2)/9801;
    return 1/zbroj;
}


int main()
{
    int n;

    cout << "Broj pi iznosi" << endl;

    n = 10;
    for(int i = 0; i < 6; i++){
        cout << n << " -> " << pi(n) << endl;
        n *= 10;
    }
    cout << endl;

    n = 1;
    for(int i = 0; i < 6; i++){
        cout << n << " -> " << pi2(n) << endl;
        n += 1;
    }

    //ispis fakrotijela do 5
    //cout << "5! = " << fakt(5);
    //cout << "2^4 =" << pow(2, 4);
    return 0;
}
