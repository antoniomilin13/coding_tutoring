/*
neven.gorsic@gmail.com
Zamijeni sadrzaj 4 varijable a,b i c po pravilu:   a->c->b->d->a

b->a  - znaci stara vrijednost varijable b upisuje se kao nova vrijednost varijable a
      - strijelica znaci operaciju pridruzivanja
      - u programskom jeziku ne postoji simbol pridruzivanja nego se koristimo znakom jednakosti=
      - pri otme triba paziti da to nije jednadzba nego pridruzivanje i ima drugo znacenje
      a=b znaci:
      uzmi staru vrijednost varijable b i upisi je kao novu vrijednost varijable a
      pamtimo kao prebacivanje vrijednosti sa desne na livu stranu

ULAZ:
a=1
b=2
c=3
d=4
....

Rezultat: (NOVE VRIJEDNOSTI VARIJABLI)
a=4        d->a
b=3        c->b
c=1        a->c
d=2        b->d
*/

#include <iostream>

using namespace std;

int main()

{

   int a = 1;
   int b = 2;
   int c = 3;
   int d = 4;
   int kopijaA;
   int kopijaB;
   int kopijaC;
   int kopijaD;

   cout << "STANJE PRIJE ZAMJENE a->c->b->d->a: " << endl;
   cout << "A: " << a << endl;
   cout << "B: " << b << endl;
   cout << "C: " << c << endl;
   cout << "D: " << d << endl;

   kopijaA = a;

   kopijaB = b;

   kopijaC = c;

   kopijaD = d;

   a = kopijaD;

   b = kopijaC;

   c = kopijaA;

   d = kopijaB;

   cout << "STANJE NAKON ZAMJENE a->c->b->d->a: " << endl;
   cout << "A: " << a << endl;
   cout << "B: " << b << endl;
   cout << "C: " << c << endl;
   cout << "D: " << d << endl;

   return 0;
}
