
#include <iostream>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));

    int i = 0, broj, postoji, ukupno = 0;

    int polje[1000];

/*
    Generiranje slucajnih brojeva od 1000 do 1999 (BEZ PONAVLJANJA)
    Gen. broj ima opci oblik -> pocetak + rand() % raspon
*/

    while(i != 1000){
        broj = 1000 + rand() % (1999 - 1000 + 1);
        ukupno++;

        /*

        for(lista kroz novu listu dok se lista ne napuni [ j = i]
            if(ako rand broj ne postoji u polju):
               polje[i] = rand broj

        [1,2,3,4,5]

        */

        postoji = 0;
        for(int j = 0; j < i; j++){
            if(polje[j] == broj){
                postoji = 1;
                break;
            }
        }
        if (postoji == 0){ // nema duplikata random broja u polju
            polje[i] = broj;
            i++;
        }

    }
    cout << "Lista: ";
    for(i = 0; i<1000; i++){
        cout << " " << polje[i] << " ";
    }

    cout << endl << endl << "Broj random brojeva generiranih u programu: " << ukupno << endl;

    cout << "Efikasnost algoritma: " << (int)((double)1000/ukupno * 100) << "%" << endl;

    return 0;
}
