/*
Pointeri
*/

#include <iostream>


using namespace std;

int main(){
    int polje[4] = {11,22,33,44}, i;
    int *pp;

    pp = &polje[0];

    *pp = 55;  // upisivanje u nulti clan polja(prvi)

//1.
    for(int i = 0; i<4; i++){
        cout << polje[i] << " ";
    }
    cout << endl;

//2.
    for(int i = 0; i<4; i++){
        polje[i] = 0;
        cout << polje[i] << " ";
    }
    cout << endl;

//3.
    for(int i = 0; i<4; i++){
        pp = &polje[i];   // ovdje STALNO MIJENJAMO ADRESU u pp
        *pp = 4;
        cout << polje[i] << " ";
    }
    cout << endl;

//4.
    // pp = &polje[0];   prvi nacin
    pp = polje;   //     drugi nacin  -> IME POLJE JE UJEDNO POINTER na 0-ti element
    for(int i = 0; i<4; i++){
        *(pp + i) = 5*i;
        cout << "Adresa od p[" << i << "]: " << pp + i << "| ";
        cout << "1.nacin: polje[i] -> " << polje[i] << ".   " << "2. nacin: *(pp + i) ->" << *(pp + i) << endl;
    }
    cout << endl;

    return 0;
}
