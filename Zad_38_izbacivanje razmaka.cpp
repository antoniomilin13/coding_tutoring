/*
prosjek unaprid nepoznatog broja ocijena

*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
    int i, n, l;
    string recenica, kopija = "";

    cout << "Upisite recenicu: ";
    getline(cin, recenica);

    l = recenica.length();      //duljina je izrazena u broju mjesta, a ne u broju bajtova kao kod sizeof

    /*
        - for petlja se uptrebljava kad unaprid znamo koliko puta je triba proci
        - while kad neznamo
    */

    for(i = 0; i < l; i++){
        if(recenica[i] != ' '){     // karakter se uokvirava samo ' ' znakovima, a ne " "
            kopija = kopija + recenica[i];
        }
    }

    cout << "Recenica bez razmaka: " << endl << "- - - - - - - - - -" << endl << kopija << endl;

    return 0;
}
