
#include <iostream>
#include <time.h>

using namespace std;


int main(){

    int nm, nv;

    srand(time(NULL));

    nm = rand();
    nv = nm;

    int broj;

    //cout << nm << " ";
    for(int i = 1; i<500000; i++){
        broj = rand();
        if(broj > nv){
            nv = broj;
        }
        else if(broj < nm){
            nm = broj;
        }
        //cout << broj << " ";
    }
    cout << endl << "Najveci je: " << nv << endl << "Najmanji je: " << nm << endl;

    return 0;
}
