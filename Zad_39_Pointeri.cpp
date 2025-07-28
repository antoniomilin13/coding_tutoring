/*
Pointeri
*/

#include <iostream>


using namespace std;

int main(){
    int i = 11, j;  // vrijednost u i je obicni integer

    /*
        - deklaracijom pronalazimo prazno misto u memoriji i definiramo tip varijable koi ce se nalaziti u njemu
        - adresa u memoriji se pamti u varijabli tipa pointer
        - sa pointerima ne mozemo dobiti vridnost varijable nego samo njezinom adresom u memoriji
    */

    int *pi, *pj;  // vrijednost od pi je pointer tj. ADRESA u memoriji tj. 4-bajtni hex adresa

    /*
        - pi je pointer koi za sada nema konkretnu vridnost
    */

    pi = &i;  //adresu u memoriji gdje se nalazi varijabla i smo pridruzili pointeru pi
    pj = &j;

    cout << "Varojabla i iznosi: " << i << endl;

    cout << "Adresa u memoriji od varijable i: " << pi << endl;
    cout << "Adresa u memoriji od varijable j: " << pj << endl;
    /*
        - 0x61fe14 --> standardni zapis heksadecimalne adrese pocinje sa 0x.
            baza sustava je 16, pa imamo 16 znamenki = [0,1,...,9,A;B;C;D;E;F]
            0xFC9 ->  9*16^0 + C*16^1 + F*16^2 = 9*1 + 12*16 + 15*256
        - 0b101110 --> zapis binarne adrese pocinje sa 0b,
            baza sustava je 2, pa imamo 2 znamenke = [0,1]
            0b101110 = 0*2^0 + 1*2^1 + 1*2^2 + 1*2^3 + 0*2^4 + 1*2^5 = 0 + 2 + 4 + 8 + 0 + 32 = 46
        - 0o675374 --> zapis oktalne adrese pocinje sa 0o,
            baza sustava je 8, pa imamo 8 znamenki = [0,1,2,3,4,5,6,7]
            0o67 = 7*8^0 + 6*8^1 = 7 + 48 = 55
        */

    j = 2* (*pi);  // *pi je vrijednost varijable koja se nalazi u memoriji na mistu(adresi) pi

    cout << "2 * i = " << j << endl;

    // drugi nacin

    *pj = 3*i;  // upisujemo NOVU VRIJEDNOST u varijablu j, tj. u memorijsku lokaciju pj
    // sama adresa pj se time ne mijenja
    cout << "2 * i = " << j << endl;

    return 0;
}
