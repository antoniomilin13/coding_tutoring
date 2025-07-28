
#include <iostream>
#include <time.h>

using namespace std;

/*
    Generiranje slucajnih brojeva od 0 do 4  -> raspon od 5 brojeva
*/

int main(){

    int nm, nv;

    srand(time(NULL));

    nm = rand() % 5;  // slucajni broj ide u intervalu od [0 do 4]
    nv = nm;

    int broj;

    cout << nm << " ";
    for(int i = 1; i<20; i++){
        broj = rand() % 5;
        if(broj > nv){
            nv = broj;
        }
        else if(broj < nm){
            nm = broj;
        }
        cout << broj << " ";
    }
    cout << endl << "Najveci je: " << nv << endl << "Najmanji je: " << nm << endl;


/*
    Generiranje slucajnih brojeva od 10 do 14
    Gen. broj ima opci oblik -> pocetak + rand() % raspon
*/
    nm = 10 + rand() % 5;  // slucajni broj ide u intervalu od [10 do 14] -> raspon od 5 brojeva
    nv = nm;

    cout << nm << " ";
    for(int i = 1; i<20; i++){
        broj = 10 + rand() % (14 - 10 + 1);
        if(broj > nv){
            nv = broj;
        }
        else if(broj < nm){
            nm = broj;
        }
        cout << broj << " ";
    }
    cout << endl << "Najveci je: " << nv << endl << "Najmanji je: " << nm << endl;

    return 0;
}
