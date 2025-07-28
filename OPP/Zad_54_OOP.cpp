#include <iostream>

using namespace std;

/*

- klasa(class) je nacrt(blueprint) za kreiranje buducih objekata koji ce imati upravo strukturu definiranu klasom
- klasa je vrlo slicna po svojstvima tipu varijable struct(struct je public default)
- struct tip podataka je po deafultu vidljiv iz glavne funkcije(main), pa ga smatramo public varijablom
- klasa po defaultu ima skrivene argumente i funkcije od drugih drugih, pa ih smatramo po defaultu private
- ako objekt ima funkcije koje zelimo pridruziti samo njemu stvorit cemo ga kao instancu(instance) neke klase
-
- da bi u glavnom programu stvorili objekt mi prvo moramo izvan(prije) glavnog programa definirati klasu prema kojoj ce se stvarati novi objekti(instance)
- varijable koje pripadaju objektima se nazivaju atributi(atributes)
- funkcije koje pripadaju objektima se nazivaju metode


*/

class Covjek{           //klase nemaju argumente kao funkcije

public:                 //ako izostavimo rijeci public ili private(argumenti vidljivosti-access specifier), tada ce se podrazumjevati
                        //da je njihova vrijednost private   = defaultna vrijednost, na taj nacin sve varijable i funkcije
                        //koje deklariramo unutar klase ce biti nevidljive iz glavne funkc
                        //drugim rijecima ako zelimo za neku varijablu iz klase da bude vidljiva iz maina moramo je posebno
                        //deklarirati sa public
    int visina, starost;
    string ime, prezime;

    void pozdrav(string broj_covjeka){
        cout << "Pozdrav od " << broj_covjeka << "!" << endl;
    }

    void predstavljanje(){
        cout << "Ja sam " << ime << endl << endl;
    }

};



int main(){

    Covjek covjek1;     //i dalje deklaracija se sastoji od specificiranja tipa podataka i ime varijable, to znaci da nam je klasa
                        //jos jedan tip podatka
                        //covjek1 nam je ime objekta(instanca) koja je napravljena prema nacrtu(klasi) po imenu covjek
                        //inicijaliziranje vrijednosti(pridavanje) se radi sa "dot" metodom u kojoj se prvo navede ime instance
                        //zatim tocka i na kraju ime atributa ili metode
    covjek1.ime = "Mate Miso";
    covjek1.prezime = "Kovac";
    covjek1.visina = 185;
    covjek1.starost = 70;

    cout << "Stvoren je objekt covjek1 i njegovi atributi su: " << endl;
    cout << "   - Ime i prezime: " << covjek1.ime << " " << covjek1.prezime << endl;
    cout << "   - visina: " << covjek1.visina << endl;
    cout << "   - starost: " << covjek1.starost << endl << endl;

    covjek1.pozdrav("covjek1");

    covjek1.predstavljanje());

    //---------------------------------------------------------

    Covjek covjek2;     //drugi objekt sa istom klasom

    covjek2.ime = "Antonio";
    covjek2.prezime = "Milin";
    covjek2.visina = 185;
    covjek2.starost = 20;

    covjek2.pozdrav("covjek2");

    covjek2.predstavljanje();

    return 0;
}





