/*

Faktorijela - umnozak svih prirodnih brojeva do n

n! = 1*2*3*...*(n-1)  * n = (n-1)! * n
n! = (n-1)! * n    ->  sljedeca katorijela = prethodna faktorijela * novi clan
fakt(n) = fakt(n-1) * n

*/


#include <iostream>

using namespace std;

int fakt(int n){

    /*
        - Return vraca rez. iz funkcije. Da bi vratia rezultat prvo mora izracunati umnozak "fakt(n-1) * n".
        - Buduci da nezna koliko je "fakt(n-1)" on poziva funkciju fakt za argument koi je za 1 broj manji od
          prethodnoga, dakle za argument (n-1). To za program pretstavlja potpuno novu funkciju neovisnu o prethodnoj.
        - Buduci da svaki put pozivamo funkciju sa argumentom za 1 manje nekako moramo osigurati mehanizam da se
          zaustavimo prije nule.
        - Zbog toga, prvu stvar koju moramo napraviti u svkaoj rekurzivnoj funkciji je osiguranje donje granice kako ne bi otisli u beskonacnu petlju
        - To radimo sa usporedivanjem iznosa kontrolne varijable sa donjom granicom. Tek nakon toga mozemo ici u novi krug rekurzije, a ako je donja
          granica postignuta vracamo rezultat(return).
        - Kod faktorijela donja granica je 0! = 1, ili 1!= 1
    */

    if(n <= 1){  // osigurali smo se da ne pride donju granicu i vratili faktorijel od 0 ili 1 = 1
        return 1;
    }
    else{
        return fakt(n-1) * n;
        /*
        return od fakt(4) * 5
            return fakt(3) * 4
                return fakt(2) * 3
                    return fakt(1) * 2
                        return 1;
        */
    }
}

int main(){
    int n;

    cout << "Upisite zadnji clan faktorijela: ";
    cin >> n;

    cout << fakt(n) << endl;

    return 0;
}
