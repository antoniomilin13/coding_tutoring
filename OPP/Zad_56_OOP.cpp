#include <iostream>

using namespace std;


class Auto{
public:
    string marka;
                    //postoji posebna metoda koja se naziva konstructor i koja se automatski poziva(izvrsava)
                    //bez da je pozovemo i to u trenutku stvaranja objekta. Da bi se razlikovala od ostalih
                    //metoda ona nema definiran tip i ima isto ime kao i klasa

    Auto(string m){         //ovo je constructor i ona se AUTOMATSKI POKRECE pri stvaranju objekta
        cout << "Stvoren je novi objekt" << endl;
        marka = m;
        cout << "(ispis u konstraktoru) Marka auta je: " << marka << endl;
    }

    void marka_auta(string pregrada){
        cout << "Ispis iz metode marka_auta: Marka auta: " << pregrada << marka << endl;
    }
};



int main(){

    Auto auto1("BMW");
    cout << "Ispis iz glavnog programa: " << auto1.marka << endl;
    auto1.marka_auta("|||");

    Auto auto2("Volvo");
    auto2.marka_auta("###");

    return 0;
}





