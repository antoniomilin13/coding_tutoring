/*
Granice termostata klima uredaja su:
    t > 25 C        - hladi
    18 < t < 25     - ne radi
    t < 18 C        - grije
U ovisnosti o temperaturi ispisi mod rada
*/

#include <iostream>
using namespace std;

int main()
{
    int t;

    cout << "Termometar radi u sljedecim granicama:" << endl;
    cout << "t < 18 C        - grije" << endl;
    cout << "18 < t < 25     - ne radi" << endl;
    cout << "t > 25 C        - hladi" << endl << endl;


    cout << "Trenutacna temperatura je: ";
    cin >> t;
    cout << endl;

    if(t > 25)
    {
        cout << "Uredaj pocinje sa hladenjem!" << endl;
    }
    else if(t < 18)
    {
        cout << "Uredaj pocinje sa grijanjem!" << endl;
    }
    else
    {
        cout << "Uredaj trenutacno ne radi" << endl;
    }

    return 0;
}
