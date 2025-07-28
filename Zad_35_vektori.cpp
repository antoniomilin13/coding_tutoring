
#include <iostream>
#include <vector>

using namespace std;

/*
Prosjek ocjena koristenjem vektora = dinamicki prosirivo polje

*/

int main(){
    vector <int> polje;  // kad deklariramo neku varijablu kao vektorsko polje, tada je njegova inicijalna
    int i,n,ocjena;    // duljina(broj mjesta u polju) = 0
                       // novo mijesto na kraju polja se dodaje naredbom "push_back"
                       // zadnje misto polja se brise sa "pop_back"

    cout << "Upisite n: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Upisi ocijenu: ";
        cin >> ocjena;
        polje.push_back(ocjena);
        cout << "Dimenzija dinamickog polja: " << polje.size() << endl;
    }


    cout << "------------" << endl;
    cout << "Ispis popunjenje liste:" << endl;

    for(int i = 0; i < n; i++){
        cout << polje[i] << endl;
    }

    cout << "Brisanje polja" << endl << endl;

    for(int i = 0; i < n; i++){
        cout << "Lista (trenutacna): ";
        for(int j = 0; j < polje.size(); j++){
            cout << polje[j] << " ";
        }
        cout << endl;
        ocjena = polje.back();      // citanje(dohvacanje) vrijednost zadnjeg elementa niza(polja)
        // polje[polje.size() - 1] je takoder citanje zadnjeg elementa
        polje.pop_back();           // brisanje zadnjeg elementa niza
        //cout << ocjena << endl;

    }


    return 0;
}
