
//VEKTORI
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void ispis(int *p, int duljina){ //kada vanjskoj fuknciji zelimo predati polje tada predajemo i pointer na pocetak polja i broj elemenata polja
    cout << "   polje: ";
    for(int i = 0; i<duljina-1; i++){
        cout << p[i] << ", ";
    }
    cout << p[duljina - 1] << endl;
}

int main(){
    vector <int> polje;
    int velicina, zadnji;

    velicina = polje.size();
    cout << "1." << endl << "Velicina (praznog) vektorskog polja: " << velicina << endl;

    polje.push_back(5);
    velicina = polje.size();
    cout << "2." << endl << "Velicina (novog) vektorskog polja: " << velicina << endl;
    //cout << "   polje[" << 0 << "] = " << polje[0] << endl;
    ispis(&polje[0], velicina);

    polje.push_back(10);
    polje.push_back(20);
    velicina = polje.size();
    cout << "3." << endl << "Velicina (novog) vektorskog polja: " << velicina << endl;
    ispis(&polje[0], velicina);

    zadnji = polje.back();                  //citanje zadnjeg elementa ali bez brisanja
    polje.pop_back();
    velicina = polje.size();
    cout << "4." << endl << "Velicina (novog) vektorskog polja: " << velicina << endl;
    ispis(&polje[0], velicina);
    cout << "   izbrisani element: " << zadnji << endl;


    int broj_umetnuti = 13;
    polje.insert(polje.begin() + 1, broj_umetnuti);
    velicina = polje.size();
    cout << "5." << endl << "Velicina (novog) vektorskog polja: " << velicina << endl;
    ispis(&polje[0], velicina);
    cout << "   umetnuti element: " << broj_umetnuti << endl;


    polje.insert(polje.begin() + 1, 3, 9);
    velicina = polje.size();
    cout << "6." << endl << "Velicina (novog) vektorskog polja: " << velicina << endl;
    ispis(&polje[0], velicina);


    polje.erase(polje.begin() + 1, polje.begin() + 4);  // desna granica nije ukljucena
    velicina = polje.size();
    cout << "7." << endl << "Velicina (novog) vektorskog polja: " << velicina << endl;
    ispis(&polje[0], velicina);

    polje.insert(polje.begin() + 1, 3, 1234);
    velicina = polje.size();
    cout << "8." << endl << "Velicina (novog) vektorskog polja: " << velicina << endl;
    ispis(&polje[0], velicina);

    auto p3 = remove(polje.begin(), polje.end(), 1234);  // p3 pokazuje adresu di je visak polja
    polje.erase(p3, polje.end());
    velicina = polje.size();
    cout << "9." << endl << "Velicina (novog) vektorskog polja: " << velicina << endl;
    ispis(&polje[0], velicina);

    return 0;
}
