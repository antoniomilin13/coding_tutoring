/*
korisnicki definirani tipovi podataka koji imaju vise od 1 podatka

npr.:
osoba ima i ime i prezime i starost i visinu

*/


// bilo kojeg sustava izmedu 2 i 16. hexa, septa, oenta...


#include <iostream>

using namespace std;

// polje je skup vridnosti istog tipa

struct Osoba { // mi definirao novi TIP varijable
    string ime;
    string prezime;
    int starost;
    int visina;
};



int main(){
    Osoba ucenik;  // varijable otac majka i brat su tipa osoba
    Osoba ucenici[30]; // ime tipa   ime varijable  [dimenzija polja]
    int br_ucenika;

    cout << "Koliko ucenika ima razred: " << endl;
    cin >> br_ucenika;

    for(int i = 0; i < br_ucenika; i++){
        cout << "Ucenik broj " << i+1 << endl;
        cout << "Ime: ";
        cin >> ucenici[i].ime;
        cout << "Prezime: ";
        cin >> ucenici[i].prezime;
        cout << "Starost: ";
        cin >> ucenici[i].starost;
        cout << "Visina: ";
        cin >> ucenici[i].visina;
        cout << endl;
    }

    return 0;
}
