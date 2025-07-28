/*
neven.gorsic@gmail.com
Zamijeni sadrzaj 3 varijable a,b i c po pravilu:   a->c->b->d->a

ULAZ:
a=1
b=2
c=3
....

Rezultat: (NOVE VRIJEDNOSTI VARIJABLI)
a=2        b->a
b=3        c->b
c=1        a->c

*/

#include <iostream>

using namespace std;

int main()

{

   int a = 1;
   int b = 2;
   int c = 3;
   int d = 4;
   int kopija;

   cout << "STANJE PRIJE ZAMJENE a->c->b->d->a: " << endl;
   cout << "A: " << a << endl;
   cout << "B: " << b << endl;
   cout << "C: " << c << endl;
   cout << "D: " << d << endl;

   // a->c->b->d->a  pravilo zamjene
   // koristimo SAMO JEDNU KOPIJU

   kopija = b;
   b = c;
   c = a;
   a = d;
   d = kopija;

   cout << "STANJE NAKON ZAMJENE a->c->b->d->a: " << endl;
   cout << "A: " << a << endl;
   cout << "B: " << b << endl;
   cout << "C: " << c << endl;
   cout << "D: " << d << endl;

   return 0;
}
