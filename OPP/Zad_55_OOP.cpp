#include <iostream>

using namespace std;


class Auto{
public:
    string marka;
                    //postoji posebna metoda koja se naziva konstructor i koja se automatski poziva(izvrsava)
                    //bez da je pozovemo i to u trenutku stvaranja objekta. Da bi se razlikovala od ostalih
                    //metoda ona nema definiran tip i ima isto ime kao i klasa

    Auto(){         //ovo je constructor
        cout << "Stvoren je novi objekt" << endl;
    }

    void marka_auta(){
        cout << "Marka auta: " << marka << endl;
    }
};



int main(){
    Auto auto1;
    auto1.marka = "BMW";
    auto1.marka_auta();

    return 0;
}





