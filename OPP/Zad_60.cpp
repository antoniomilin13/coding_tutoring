#include <iostream>
#include <ctime>

using namespace std;


class Auto{

private:
    int broj;   // ako se eksplicit ne navede public deklaracija sve varijable su private

public:
    // varijabla koja pripada klasi a ne pojedinom objektu nazivamo statickom varijablom
    static int ukupno;  // broji OBJEKTE instancirane u toj klasi
    static int ukupna_starost;
    static double prosjecna_starost; // izracunava prosjecnu starost svih auta

    int godiste;   // pripadaju KONKRETNOM OBJEKTU instanca dane klase)
    int starost;

    Auto(int _godiste){
        int tekuca_godina;
        time_t now = time(0);

        tm *ltm = localtime(&now);
        tekuca_godina = 1900+ltm->tm_year;

        ukupno++;
        godiste = _godiste;
        starost = tekuca_godina - _godiste;
        ukupna_starost = ukupna_starost + starost;
        prosjecna_starost = (double)ukupna_starost / ukupno;
    }

    void set_broj(int _broj){
        broj = _broj;   //_broj -> broj
    }

    int get_broj(){
        return broj;
    }
};

int Auto::ukupno = 0;  // postavlja se samo jedanput na pocetku programa
int Auto::ukupna_starost = 0;
double Auto::prosjecna_starost = 0;

/*
- sve staticke varijable bez obzira dali se izracunavaju iz prethodnih vrijednosti moraju biti inicijalizirane prije glavnog programa

*/


int main(){


    Auto a1(1997);
    cout << "Ukupan broj objekata: " << Auto::ukupno << endl; // poziv staticke varijable priko klase
    //cout << "Ukupan broj objekata: " << a1.ukupno << endl;  // staticka varijabla s emoze pozvat i priko pojedinog objekta
    cout << "Auto " << Auto::ukupno<< " (" << a1.godiste<< ")" << endl;
    cout << "   -ukupna starost auta: " << Auto::ukupna_starost << endl;
    cout << "   -prosjecna starost auta: " << Auto::prosjecna_starost << endl;
    cout << "-------------------------" << endl;

    Auto a2(2005);
    cout << "Ukupan broj objekata: " << Auto::ukupno << endl; // poziv staticke varijable priko klase
    //cout << "Ukupan broj objekata: " << a1.ukupno << endl;  // staticka varijabla s emoze pozvat i priko pojedinog objekta
    cout << "Auto " << Auto::ukupno<< "(" << a2.godiste<< ")" << endl;
    cout << "   -ukupna starost auta: " << Auto::ukupna_starost << endl;
    cout << "   -prosjecna starost auta: " << Auto::prosjecna_starost << endl;
    cout << "-------------------------" << endl;

    Auto a3(2020);
    cout << "Ukupan broj objekata: " << Auto::ukupno << endl; // poziv staticke varijable priko klase
    //cout << "Ukupan broj objekata: " << a1.ukupno << endl;  // staticka varijabla s emoze pozvat i priko pojedinog objekta
    cout << "Auto " << Auto::ukupno<< "(" << a3.godiste<< ")" << endl;
    cout << "   -ukupna starost auta: " << Auto::ukupna_starost << endl;
    cout << "   -prosjecna starost auta: " << Auto::prosjecna_starost << endl;
    cout << "-------------------------" << endl;

/*
    a1.set_broj(10);
    cout << a1.get_broj() << endl;

    cout << "Starost: " << a1.starost << endl;

    Auto a2(2000);
    cout << "Ukupan broj objekata: " << Auto::ukupno << endl;
    cout << "Godiste auta: " << a2.godiste << endl;
    cout << "Starost: " << a2.starost << endl;

    Auto a3(2011);
    cout << "Ukupan broj objekata: " << Auto::ukupno << endl;
    cout << "Ukupan broj objekata: " << a3.ukupno << endl;
    cout << "Starost: " << a3.starost << endl;

    //prosjecna_starost = (double)(a1.starost+a2.starost+a3.starost)/Auto::ukupno;
    //cout << "Prosjecna starost je: " << prosjecna_starost <<  endl;
*/
    return 0;
}
