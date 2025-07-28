
#include <iostream>
#include <vector>

/*

*/

using namespace std;

int main(){

    vector<int> polje = { 10, 20, 30, 40 };
    int poljeStat[] = {1,5,3,15,52,3,53,35};

    int velicina;

    velicina = sizeof(polje)/sizeof(int);  // iako su naredbe prosle nisu primjenjive za dinamicka polja
    cout << "Velicina(sizeof): " << velicina << endl;

    velicina = sizeof(poljeStat)/sizeof(int);  // naredba za velicinu statickog polja
    cout << "Velicina(sizeof - staticko polje): " << velicina << endl;

    velicina = polje.size();  // polje.size() je ISPRAVNA naredba za saznavanje velicine dinamickog polja
    cout << "Velicina(.size()): " << velicina << endl;   // .size() radi samo za dinamicka



    polje.push_back(50);
    // ----KLASICNI ISPIS ELEMENATA POLJA POMOCU INDEXA----
    for(int i = 0; i < polje.size(); i++){ //kod ispisa dinamickih polja uvik koristiti .size() unutar for loop
        cout << polje[i] << " ";
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
    auto p = polje.begin();
    for(p = polje.begin(); p != polje.end(); p++){     // buduci su ispisani svi elemnti polja,
                                                            // to znaci da polje.end() pokazuje na element iza zadnjega, a ne na zadnji
        cout << *p << " ";                                  // *polje.begin() == polje[0] -> sadrzaj nultog elementa polja
    }                                                       // p++ uvecanje za jedno misto, a ne za jedan bajt
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
    cout << "INSERTIRAMO BROJ 13 NA POZICIJU POETKA POLJA:" << endl;
    for(auto p = polje.begin(); p != polje.end(); p++){

        cout << *p << " ";
    }
    cout << endl;

    p = polje.begin(); // zbog prosirivanja polja pocetak polja se uvik moze minjati
    polje.insert(p + 3, 88);

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

    return 0;
}
