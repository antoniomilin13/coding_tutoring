/*
Iz recenice izbaci razmake

Npr:
ulaz:  "ANA ide u prvi razred"
izlaz: "ANAideuprvirazred"
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main(){
    string recenica;
    string kopija="", znak;

    cout << "Upisi rijec: ";
    getline(cin, recenica);

    int l;
    l = recenica.length();

    for(int index = 0; index < l; index++){
        znak = recenica[index];
        if(strcmp(znak, " "){  // znak je razmak
            znak.assign("");
            // '' oznacava char, a "" oznacava string
        }
        kopija = kopija + znak;
    }

    cout << znak << endl;
    return 0;
}
