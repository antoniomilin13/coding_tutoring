
//#include <iostream>
//#include <vector>
#include <bits/stdc++.h>

/*

*/

using namespace std;

int main(){

    vector<int> polje = { 10, 20, 30, 40 };
    int poljeStat[] = {1,5,3,15,52,3,53,35};   // kod statickog polja samo ime polja je pointer na pocetak

    int velicina;

    velicina = sizeof(polje)/sizeof(int);  // iako su naredbe prosle nisu primjenjive za dinamicka polja
    cout << "Velicina(sizeof): " << velicina << endl;

    velicina = sizeof(poljeStat)/sizeof(int);  // naredba za velicinu statickog polja
    cout << "Velicina(sizeof - staticko polje): " << velicina << endl;

    velicina = polje.size();  // polje.size() je ISPRAVNA naredba za saznavanje velicine dinamickog polja
    cout << "Velicina(.size()): " << velicina << endl;   // .size() radi samo za dinamicka



    polje.push_back(50);
    // index na kojem je spremljen broj 50 je: i = polje.size() - 1

    // ----KLASICNI ISPIS ELEMENATA POLJA POMOCU INDEXA----
    for(int i = 0; i < polje.size(); i++){ //kod ispisa dinamickih polja uvik koristiti .size() unutar for loop
        cout << polje[i] << " ";  // indeksirani pristup  polje[i]  ISTI je i za statička i za dinamička polja
    }
    cout << endl;

    cout << "Staticko polje" << endl;
    //-----ISPIS ELEMENATA *STATICKOG* POLJA POMOCU POINTERA-----
    for(int i = 0; i < sizeof(poljeStat)/sizeof(int); i++){
        cout << *(poljeStat + i) << " ";
    }
    cout << endl << endl;

    cout << "Dinamicko polje" << endl;
    //-----ISPIS ELEMENATA *DINAMICKOG* POLJA POMOCU POINTERA-----
    //  auto -> automatsko biranje tipa pointera koi se razlikuje od pointera na staticko polje
    auto p = polje.begin();  // kod statickog polja, adresa (pointer) na nulti element se dobije sa imenom polja poljeStat
    for(p = polje.begin(); p != polje.end(); p++){      // buduci su ispisani svi elemnti polja,
        cout << *p << " ";                              // p++ uvecanje za jedno misto, a ne za jedan bajt
    }
    /*
                       polje.begin()   polje.end() - NE POKAZUJE ZADNJI ELEMENT NEGO 1 IZA NJEGA
                          |                   |
         index            0   1   2   3   4   5
        polje[index]     10  20  30  40  50
    */


    int a=99;
    int *pi = &a;

    cout << endl << "Adresa od varijable a: " << pi;   // ispisujemo sadrzaj koi se nalazi u memorijskoj lokaciji na adresi pi
    cout << endl << "Sadrzaj varijable a: " << *pi << endl << endl;

    p = polje.begin(); // zbog prosirivanja polja pocetak polja se uvik moze minjati

    polje.insert(p, 13);
    cout << "INSERTIRAMO BROJ 13 NA POZICIJU POCETKA POLJA:" << endl;
    for(auto p = polje.begin(); p != polje.end(); p++){
        cout << *p << " ";
    }
    cout << endl;

    p = polje.begin(); // zbog prosirivanja polja pocetak polja se uvik moze minjati
    polje.insert(p + 3, 88);   // UMETANJE, elementi na mjestu 3 i vise se POMICU za 1 mjesto udesno

    cout << "INSERTIRAMO BROJ 88 NA POZICIJU 4:" << endl;
    for(auto p = polje.begin(); p != polje.end(); p++){
        cout << *p << " ";
    }
    cout << endl;

    p = polje.begin(); // zbog prosirivanja polja pocetak polja se uvik moze minjati
    polje.insert(p + 3, 4, 5);

    cout << "INSERTIRAMO BROJ 5 cetri puta na poziciji 4:" << endl;
    for(auto p = polje.begin(); p != polje.end(); p++){
        cout << *p << " ";
    }
    cout << endl;

    // -------UMETANJE STATICKOG POLJA U DINAMICKO--------

    p = polje.begin(); // pocetak polja u TOM TRENUTKU
    int d = sizeof(poljeStat)/sizeof(int);
    //int poljeStat[] = {1,5,3,15,52,3,53,35};

    /*A - kad insert ima 3 parametra od kojih je 1. pointer a ostala 2 brojevi to znaci
          umetni 3. parametar 2. parametar  puta na poziciju 1. parametra
          npr:  polje.insert(p + 3, 4, 5);
                -> umetni broj 5 4 puta na poziciju 1. parametra(indexa 3)
      B - kad insert ima 3 parametra od kojih su sva 3 pointeri, to znaci da umetne drugo polje
          koje pocinje na parametru dva i zavrsava na parametru 3 sa pocetkom na poziciji
          parametru 1
          npr:  polje.insert(polje.begin() + 7, poljeStat, poljeStat + d);
                -> umetni citavo polje statPolje na misto 7 u dinamickog polju

    */

    polje.insert(p + 7, poljeStat, poljeStat + d);
    polje.insert(polje.begin() + 7, 3, poljeStat[0]);  // NUZNO JE POTREBAN NOVI .BEGIN()
    cout << "INSERTIRAMO CITAVO STATICKO POLJE na poziciju 7:" << endl;
    for(auto p = polje.begin(); p != polje.end(); p++){
        cout << *p << " ";
    }
    cout << endl;


    polje.erase(polje.begin() + 5);    // brise element na tom mistu
    cout << "BRISEMO ELEMENT NA POZICIJI INDEXA 5:" << endl;
    for(auto p = polje.begin(); p != polje.end(); p++){
        cout << *p << " ";
    }
    cout << endl;

    polje.erase(polje.begin() + 2, polje.begin() + 6);   // brise u razmaku izmedu ta dva parametra
                                                //zadnji nijenukljucen( ... + 6 -1)
    cout << "BRISEMO ELEMENTE OD INDEXA 2 DO INDEXA 5:" << endl;
    for(auto p = polje.begin(); p != polje.end(); p++){
        cout << *p << " ";
    }
    cout << endl;

    auto p3 = remove(polje.begin(), polje.end(), 1);
    /*
        - remove brise zadani element (ako postoji) u polju i naveden je kao 3. argument
        - pocetna adresa di pocinje gledati elemente je navedena sa prvim argumentom,
          a zavrsna adresa je navedena sa drugim argumentom -> s tim da desna granima nie ukljucena
        - remove ostavlja jednaku dimenziju polja, s time ako makne neke elemente dodaje toliki
          broj izbrisanih polja
    */

    cout << "BRISEMO ELEMENT SA VRIJEDNOSTI 1 IZ CITAVOG POLJA:" << endl;
    for(auto p = polje.begin(); p != polje.end(); p++){
        cout << *p << " ";
    }
    cout << endl;

    polje.erase(p3, polje.end());

    cout << "BRISEMO duplikate sa kraja polja:" << endl;
    for(auto p = polje.begin(); p != polje.end(); p++){
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}
