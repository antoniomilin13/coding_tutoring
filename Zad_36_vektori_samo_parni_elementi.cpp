/*
Iz vektorskog polja izbaci sve neparne brojeve

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> polje;  // kad deklariramo neku varijablu kao vektorsko polje, tada je njegova inicijalna
    int i,n,ocjena;    // duljina(broj mjesta u polju) = 0
                       // novo mijesto na kraju polja se dodaje naredbom "push_back"
                       // zadnje misto polja se brise sa "pop_back"

    cout << "Upisite n: ";
    cin >> n;

    for(i = 0; i < n; i++){
        cout << "Upisi broj: ";
        cin >> ocjena;
        polje.push_back(ocjena);
        cout << endl;
        cout << " - Dimenzija dinamickog polja: " << polje.size() << endl;
    }


    cout << "------------" << endl;
    cout << "Ispis popunjenje liste:" << endl;

    for(i = 0; i < n; i++){
        cout << polje[i] << endl;
    }

    cout << "Brisanje neparnih brojeva iz polja" << endl << endl;


    i = 0;
    int provjera = 0;
    while(provjera < n){
        cout << "Lista (trenutacna): ";
        for(int j = 0; j < polje.size(); j++){
            cout << polje[j] << " ";
        }
        cout << endl;


        if(polje[i]%2 != 0){
            polje.erase(polje.begin() + i);  //---> brisanje el. iz polja na poziciji sa indexom i
            i = i - 1;
            // nakon brisanja ne ostaje rupa u polju nego se svi elementi do kraja polja automatski prebacuju
            // ne jedno misto ispred, tako da se smanji velicina polja za jedan
        }
        i++;
        provjera++;  // broj provjerenih elemenata
    }

    cout << endl << "Konacna lista: ";
    for(int j = 0; j < polje.size(); j++){
        cout << polje[j] << " ";
    }
    cout << endl;
    
    cout << "Capacity of the vector: " << polje.capacity() << endl;
    cout << "Size of the vector: " << polje.size() << endl;

    cout << "...\n...\nAfter shrinkage of capacity\n...";
    polje.shrink_to_fit();
    cout << "Capacity of the vector: " << polje.capacity() << endl;
    cout << "Size of the vector: " << polje.size() << endl;

    return 0;
}
