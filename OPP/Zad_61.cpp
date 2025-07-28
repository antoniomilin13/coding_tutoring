#include <iostream>

using namespace std;


class Olovka{
private:

public:

    static int zadnji_ID;
    static int broj_olovaka;

    int id;

    Olovka(){
        id = ++zadnji_ID;
        broj_olovaka++;
    }
    ~Olovka(){  // unistili smo jednu olovku
        broj_olovaka--;
    }
};

int Olovka::zadnji_ID = 0;
int Olovka::broj_olovaka = 0;

int main(){

    Olovka *o1 = new Olovka;
    cout << "ID o1: " << o1->id << "    Ukupno olovaka: " << Olovka::broj_olovaka << endl;

    Olovka *o2 = new Olovka;
    cout << "ID o2: " << o2->id << "    Ukupno olovaka: " << Olovka::broj_olovaka << endl;

    Olovka *o3 = new Olovka;
    cout << "ID o3: " << o3->id << "    Ukupno olovaka: " << Olovka::broj_olovaka << endl;

    Olovka *o4 = new Olovka;
    cout << "ID o4: " << o4->id << "    Ukupno olovaka: " << Olovka::broj_olovaka << endl;

    delete o3;
    delete o4;

    cout << "[trenutacno] - ukupno olovaka: " << Olovka::broj_olovaka << endl;

    Olovka *o5 = new Olovka;  // ID = 5, broj_olovaka = 3
    cout << "ID o5: " << o5->id << "    Ukupno olovaka: " << Olovka::broj_olovaka << endl;
    Olovka *o6 = new Olovka;  // ID = 6, broj_olovaka = 4
    cout << "ID o6: " << o6->id << "    Ukupno olovaka: " << Olovka::broj_olovaka << endl;

    return 0;
}
