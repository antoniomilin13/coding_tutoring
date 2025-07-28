/*
Palindrom je zrcalno simetrični string

Npr:
ulaz: "ANA"   "NEVEN"  "123321"  "a5a"
izlaz:  'jest palindrom


ulaz: "ANKA"
izlaz: "nije palndrom"
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


int main(){
    string rijec;
    int palindrom;

    cout << "Upisi rijec: ";
    cin >> rijec;              //cin - od citavog stringa ucitava samo prvu rijec dakle do prvog razmaka!!!
    int l = rijec.length();
    /*
    - kada imamo transformacije granica uvijek moramo provjeriti da li nam je formula ispravna, tako da
      provjerimo krajnju lijevu i krajnju desnu granicu  NEVEN
    */
    palindrom = 1; // flag uvijek ima SAMO 2 vrijednosti
    for(int index = 0; index < l /2; index++){ // index je oznaka mijesta slova za ispitivanje
        if(rijec[index] != rijec[l - index - 1]){
            palindrom = 0;
            break;  // izlazimo iz PETLJE cim detektiramo prvo slovo koje NEMA isto na zrcalno simetricnoj poziciji
        }
    }

    /*
    - ako bi napisali cout  << "Ova rijec je palindrom." << endl; ona bi bila ispisana uvik
    - da bi ta izjava bila samo ponekad mormao koristiti uvijetno ispisivanje

    */
    if(palindrom == 1){
        cout << "Ova rijec je palindrom." << endl;
    }
    else{
        cout << "Ova rijec nije palindrom." << endl;
    }

    return 0;
}
