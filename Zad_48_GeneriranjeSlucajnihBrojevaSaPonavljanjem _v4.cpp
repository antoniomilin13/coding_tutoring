
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));

    int i, broj, index;

    vector <int> polje;
    vector <int> polje2;

    for(i = 0; i < 10; i++){
        polje.push_back(i);
    }

    for(i = 0; i < 10; i++){
        cout << polje[i] << " ";
    }
    cout << endl;

    for(i = 0; i < 10; i++){
        index = 0 + rand() % (10 - i);
        polje2.push_back(polje[index]);
        polje.erase(polje.begin() + index);
        cout << "Velicina polja: " << polje.size() << endl;
    }

    /*
    cout << "Polje: ";
    for(i = 0; i < 10; i++){
        cout << polje[i] << " ";
    }
    cout << endl;
    */                  // - polje vise ne postoji i on ispisuje bivse elemente iz tog polja

    cout << "Polje2: ";
    for(i = 0; i < 10; i++){
        cout << polje2[i] << " ";
    }
    cout << endl;

    polje.insert(polje2.begin() + 1, 9990);

    for(i = 0; i < 11; i++){
        cout << polje2[i] << " ";
    }
    cout << endl;

    return 0;
}
