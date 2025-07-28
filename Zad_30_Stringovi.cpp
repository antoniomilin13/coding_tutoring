/*
Ucitaj string i ispisi pojedina slova u obrnutom redosljedu

Npr:
ulaz: "DOBAR"
izlaz:  'R','A','B','O','D'
*/

#include <iostream>
#include <string>

using namespace std;


int main(){
    string rijec, recenica;

    cout << "Upisi rijec: ";
    cin >> rijec;              //cin - od citavog stringa ucitava samo prvu rijec dakle do prvog razmaka!!!
    cout << rijec << endl;

    cout << "Upisi recenicu(cin): ";
    cin >> recenica;
    cout << recenica << endl;

    cout << "Upisi recenicu(getline): ";
    getline(cin, recenica);   // upisuje recenicu sa razmacima
    cout << recenica << endl;

    cout << "Upisi::: ";
    getline(cin, recenica);
    cout << recenica << endl;
    /*

    - upisivanje se vrsi priko buffera koji se cita sa naredbom cin i getline
    - cin cita sa pocetka buffera sve do prvog razmaka i pridruzuje taj niz navedenoj varijabli
    - pri tome brise procitani podniz iz buffera
    - sljedeci cin ponovno cita buffer od pocetka do prvog razmaka ili kraja buffera
    - samo u slucaju da je buffer prazan program nam daje mogucnost da upisemo nesto sa tastature
    - ako u bufferu ima nesto tada se sljedeci cin prazni s njime i ne daje nam mogucnost unosa

    */
    return 0;
}
