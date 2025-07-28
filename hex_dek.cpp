/*
index:                  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15
string hex_znamenke = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}
string hex_znamenke = "0123456789ABCDEF"

hex_znamenke[0]='0'
...
hex_znamenke[9]='9'
--------------------
hex_znamenke[10]='A'
hex_znamenke[11]='B'
hex_znamenke[12]='C'
hex_znamenke[13]='D'
hex_znamenke[14]='E'
hex_znamenke[15]='F'

*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
    int dek, temp, znamenka,potencija_16;
    string hex = "";

    cout << "Pretvorba dekadskog u hexadekadski" << endl << endl;

    cout << "Upisite dekadski broj: ";
    cin >> dek;


/*
        - staviti IF funkciju i uvrstavati brojeve u odredene znamenke(brojeve i slova) i tek onda ih uvrstavati u hex. ispis broja

           dek%16=[0,9] u ['A', ... 'F']  ->|
           ulaz 1 (dek%16):         broj   | 0 | 1 |          | 9 | 10| 11| 12| 13| 14| 15|
           --------------------------------------------------------------------------------
  if       ulaz 2 (dek%16+48):      broj   |48 |49 |  . . .   |55 |
  else if  ulaz 3 (dek%16+65):      broj                          | 65| 66| 67| 68| 69| 70|

        izlaz: char((dek%16)+48) znak   |'0'|'1'|    . . .    |'9'|'A'|'B'|'C'|'D'|'E'|'F'|
        ASCII('0') = 48 , ... , ASCII('7') = 48+7 = 55
        */

    while(dek > 0){
        temp = dek%16;   // temp=[0,15]

        if(temp >= 0 && temp <= 9){  // temp = [0,9]
            hex = (char)(temp + 48) + hex;
        }
        else if(temp >= 10 && temp <= 15){  // temp = [10,15] , temp-10 ->[0,5]
            // ASCII('A') = 65  ...  ASCII('F') = 70
            hex = (char)(temp - 10 + 65) + hex;
        }
        dek = dek / 16;
    }
    cout << "Hex: " << hex << " | " << "Rezultat: " << dek << endl;
    cout << endl << "----------------------------------" << endl << endl;



    cout << "Pretvorba hexadekadskog u dekatski" << endl << endl;
    cout << "Upisite hexadekadski broj: ";
    cin >> hex;    // ne ocekujemo razlomke, zbog toga koristimo cin a ne getline

    // 012    indexiznakova unutar stringa hex
    // F9A -> 0 + 10*16^0 + 9*16^1 + 15*16^2

    int l = hex.length();  // koliko znamenki ima nas hex broj
    dek=0;
    potencija_16 = 1;
    for(int i = l-1; i >= 0; i--){
        // ASCII('0')->48   ASCII ('9')->57    ->[48,57]  - prvi interval   -> [0,9]
        // ASCII('A')->65   ASCII ('F')->70    ->[65,70]  - drugi interval  -> [10,15]
        znamenka = (int)hex[i];   // temp je ASCII od trenutne znamenke
        if(znamenka >= 48 && znamenka <= 57){  // spada u prvi interval
            znamenka =  znamenka - 48;         //-> [0,9]
        }
        else {  // nalazimo se u drugom intervalu  [65,70]
            znamenka = znamenka - 55;    //-> [10,15]
        }
        dek = dek + znamenka * potencija_16;

        potencija_16 = potencija_16 * 16;
    }
    cout << "Dek: " << dek << endl;

    return 0;
}
