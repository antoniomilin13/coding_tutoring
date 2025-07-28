/*
prosjek unaprid nepoznatog broja ocijena

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> polje;
    int suma, i, n, ocjena, izbor;

    n = 0;
    izbor = 1;

    while(izbor == 1){
        cout << "Upisi ocjenu: ";
        cin >> ocjena;

        polje.push_back(ocjena);

        cout << "Da li zelite jos unositi ocijena? (1/0)" << endl;
        cin >> izbor;
        //cout << " - Dimenzija dinamickog polja: " << polje.size() << endl;

        suma = suma + ocjena;

        n++;
    }
    cout << endl;

    double prosjek;

    prosjek = (double)suma/n;

    cout << "Prosjek ocijena je: " << prosjek << endl;

    return 0;
}
