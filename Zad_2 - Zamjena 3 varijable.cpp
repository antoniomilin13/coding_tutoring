/*
neven.gorsic@gmail.com
Zamijeni sadrzaj 3 varijable a,b i c po pravilu:   a->c->b->a

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
   int kopijaA;
   int kopijaB;
   int kopijaC;

   cout << "STANJE PRIJE ZAMJENE a->c->b->a: " << endl;
   cout << "A: " << a << endl;
   cout << "B: " << b << endl;
   cout << "C: " << c << endl;

   // a->c->b->a
   kopijaA = a;
   kopijaB = b;
   kopijaC = c;

   c = kopijaA;
   b = kopijaC;
   a = kopijaB;


   cout << "STANJE NAKON ZAMJENE a->c->b->a: " << endl;
   cout << "A: " << a << endl;
   cout << "B: " << b << endl;
   cout << "C: " << c << endl;

   return 0;
}
