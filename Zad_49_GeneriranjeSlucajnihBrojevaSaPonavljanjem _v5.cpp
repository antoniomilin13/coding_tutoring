
#include <iostream>
#include <vector>
#include <time.h>

/*   GENERIRANJE 50 BROJEVA OD 100 DO 149

    polje.begin()    polje.end()   -> pointeri - ADRESE U MEMORIJI
          |                 |
indexi    0 1 2 3 4 5 6 7 8 9     imamo 9 elemenata polja
polje    |6 6 6 5 5 5 4 4 4|


    polje.end() - polje.begin() = polje.size()  - broj elemenata polja
*/
using namespace std;

int main(){
    srand(time(NULL));

    int i, broj, index, raspon = 50;

    vector <int> polje;
    vector <int> polje2;

    for(i = 0; i < raspon; i++){
        polje.push_back(100 + i);
    }

    for(i = 0; i < raspon; i++){
        cout << polje[i] << " ";
    }
    cout << endl;

    cout << "1" << endl;

    for(i = 0; i < raspon; i++){
        index = rand() % (raspon - i);     // index nam oznacava polozaj u polju i zbog toga uvik mora krenuti od nule do raspon - 1
        polje2.push_back(polje[index]);
        polje.erase(polje.begin() + index);
    }

    /*
    cout << "Polje: ";
    for(i = 0; i < 10; i++){
        cout << polje[i] << " ";
    }
    cout << endl;
    */                  // - polje vise ne postoji i on ispisuje bivse elemente iz tog polja

    cout << "2" << endl;

    cout << "Polje2: ";
    for(i = 0; i < raspon; i++){
        cout << polje2[i] << " ";
    }
    cout << endl;

    cout << "3" << endl;
/*
    polje.insert(polje2.begin() + 1, 9990);

    for(i = 0; i < raspon + 1; i++){
        cout << polje2[i] << " ";
    }
    cout << endl;
*/
    return 0;
}
