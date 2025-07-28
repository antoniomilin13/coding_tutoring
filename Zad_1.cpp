/*
Zamijeni sadrzaj 2 varijable a i b

ULAZ:
a=1
b=2

....

Rezultat:
a=2
b=1

*/

#include <iostream> // io - input output

using namespace std;  // std - standard io - tastatura i ekran

/*

-int je tip varijable koi cuva cijele brojeve
-float je tip varijable koji sprema brojeve sa decimalnom tockom koju inace nazivamo realna varijabla
-double je skraceni naciv za double float i prestavlja duplo precizniji tip zapisa realne varijable
-int zauzima 4 bajta, float zauzima 4 bajta, a double 8

-varijabla je imenovano misto u memoriji koja cuva jedan jedini podatak
-varijabla nikad nije prazna i uvik sadrzi nekakav broj
-ako varijabli ne dodijelimo nikakvu vrijednost ona nece ostati prazna nego ce imati slucajnu vrijednost koja se zatekla u njoj
-stoga je neophodno svaku varijablu inicijalizirati prije upotrebe(dodijeliti joj pocetnu vridnost)
-ako varijabli dodijelimo novi broj stari broj se gubi

-deklaracija je proces definiranja tipova varijabli
-inicijalizacija je proces dodijeljivanja pocetne vrijednosti nekoj varijabli
*/

int main()
// cak i kad funkc. ne prima nikakve ulazne parametre oble zagrade()  se tribaju pisat
{
/*
-{} zagrade pretstavljaju oznaku pocetka i kraja bloka naredbi koi se zajedno tretiraju kao jedna jedina (slozena) naredba
-najveci blok naredbi je glavni program(funkc.) i zato i za njega koristimo {}zagrade
-buduci da program moze sadrzavati vise funkcija mi moramo znati od koje funkcije da krenemo i to je uvik funkc. main
-obicaj preglednog pisanja nalaze da naredbe u svakom bloku uvucemo za isti broj razmaka i taj proces se zove poravnanje(indent)
-broj razmaka je odreden tipka tab i nju automatski ubacuje editor
*/

// svaka naredba mora zavrsiti sa ;

   // int a,b;  - posebno deklaracija
   // a=1;      - posebno inicijalizacija
   // b=2;
   int a = 1; // spojena deklaracija i inicijalizacija u jednome
   int b = 2; // iZVRASAVA SE SAMO JEDNOM, i to na pocetku programa

   // imena varijabli cemo smiljati da najbolje opisuju njezinu funkciju
   int kopija;

   cout << "STANJE PRIJE ZAMJENE a<->b: " << endl;
   cout << "A: " << a << endl;
   cout << "B: " << b << endl;

   kopija = a;
   a = b;
   b = kopija;

   cout << "STANJE NAKON ZAMJENE a<->b: " << endl;
   cout << "A: " << a << endl;
   cout << "B: " << b << endl;

//svaka funkc. vraca samo jedan jedini podatak naredbom return
//tip podatka se mora poklapati sa tipom funkcije
//return 0; znaci vrati operativnom sustavu vrijednost nula koja pretsavlja oznaku da je program zavrsio ispravno

    return 0;
}
