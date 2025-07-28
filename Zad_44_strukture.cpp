/*
korisnicki definirani tipovi podataka koji imaju vise od 1 podatka

npr.:
osoba ima i ime i prezime i starost i visinu

*/

#include <iostream>

using namespace std;

struct Osoba { // mi definirao novi TIP varijable
    string ime;
    string prezime;
    int starost;
    int visina;
};

int main(){
    Osoba otac, majka, brat;  // varijable otac majka i brat su tipa osoba

    cout << "Podatci vaseg oca." << endl;

    cout << "Ime: ";
    cin >> otac.ime;
    cout << "Prezime: ";
    cin >> otac.prezime;
    cout << "Starost: ";
    cin >> otac.starost;
    cout << "Visina: ";
    cin >> otac.visina;
    cout << endl;
/*
    cout << endl << "Podatci vase majke." << endl;

    cout << "Ime: ";
    cin >> majka.ime;
    cout << "Prezime: ";
    cin >> majka.prezime;
    cout << "Starost: ";
    cin >> majka.starost;
    cout << "Visina: ";
    cin >> majka.visina;

    cout << endl << "Podatci vaseg brata." << endl;

    cout << "Ime: ";
    cin >> brat.ime;
    cout << "Prezime: ";
    cin >> brat.prezime;
    cout << "Starost: ";
    cin >> brat.starost;
    cout << "Visina: ";
    cin >> brat.visina;

  */
    cout << "Podatci za oca su: " << endl;
    cout << "Ime: " << otac.ime << endl;
    cout << "Prezime: " << otac.prezime << endl;
    cout << "Starost: " << otac.starost << endl;
    cout << "Visina: " << otac.visina << endl;

    return 0;
}
