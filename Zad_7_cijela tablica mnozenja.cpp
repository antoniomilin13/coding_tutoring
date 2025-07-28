/*
Ispis cijele tablice mnozenja

1 2 3 4 5 6 7 8 9 10
...
5 10 15 20 25 30 35 40 45 50
...
10 20 30 40 50 60 70 80 90 100
*/

#include <iostream>
using namespace std;

int main()
{
    int red, stupac;

    cout << "Tablica mnozenja:" << endl << endl;

    for(red = 1; red <= 10; red++)
    {
        for(stupac = 1; stupac <= 10; stupac++)
        {
            cout << red * stupac << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
