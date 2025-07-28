/*
dek -> okt   DIJELIMO SA 8 !!!

23 | 7   ^
2  | 2   |    27_8 = 2*8^1 + 7*8^0 = 16 + 7 = 23
0        |

*/

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int dek;

    cout << "Pretvorba dekadskog u oktalni i obrnuto!" << endl << endl;

    cout << "Upisite dekadski broj: ";
    cin >> dek;


    string rez = "";   //char -> '' (ima jedan znak pa je jedan navodnik), string -> "" (vise znakova pa je dvostruki navodnik)

    //ako program ne izlazi van to znaci da se vrti u beskonacnoj petlji

    while(dek != 0){  // uvjet unutar while-a je UVJET OSTANKA ili uvjet PONAVLJANJA PETLJE
        // char(ASCII) -> znak
        rez = char((dek%8)+48) + rez;
        /* dek%8=[0,7]  ->
        ulaz 1 (dek%8):         broj   | 0 | 1 |          | 7 |
        ulaz 2 (dek%8+48):      broj   |48 |49 |  . . .   |55 |
        izlaz: char((dek%8)+48) znak   |'0'|'1'|    . . . |'7'|
        ASCII('0') = 48 , ... , ASCII('7') = 48+7 = 55
        */
        dek = dek / 8;
    }

    cout << "Rezultat: " << rez << endl;

    return 0;
}
