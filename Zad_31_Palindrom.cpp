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
    int brojac;

    cout << "Upisi rijec: ";
    cin >> rijec;              //cin - od citavog stringa ucitava samo prvu rijec dakle do prvog razmaka!!!

    int l = rijec.length();
    /*
    - kada imamo transformacije granica uvijek moramo provjeriti da li nam je formula ispravna, tako da
      provjerimo krajnju lijevu i krajnju desnu granicu  NEVEN
    */
    brojac = 0;
    for(int index = 0; index < l /2; index++){ // index je oznaka mijesta slova za ispitivanje
        if(rijec[index] == rijec[l - index - 1]){
            brojac++; // broj parova
        }
    }
    if(brojac == l/2){
        cout << "Ova rijec je palindrom." << endl;
    }
    else{
        cout << "Ova rijec nije palindrom." << endl;
    }

    return 0;
}
