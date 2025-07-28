/*
Ispis kruga
Za uneseni radius r crtamo krug

Na primjer radius = 3 crtamo:
y   x 0123456789       y = [r,-r]        x = [x_l,x_d]
-------------------
3    |  *****          (x-xs)^2 + y^2 = r^2   - crtamo SVE zvjezdice izmedju x_l i x_d
2    | *******          x_l = xs - sqrt(r^2 - y^2) -> polozaj krajnje desne tocke kruznice
1    |*********         x_d = xs + sqrt(r^2 - y^2) -> polozaj krajnje lijeve tocke kruznice
0    |*********         razmaci = [0,x_l-1]
-1   |*********
-2   | *******
-3   |  *****
-------------------

*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int r, x,y,xl,xd,xs, sirina;

    xs=20;
    cout << "Krug" << endl;
    cout << "Unesite radius: ";
    cin >> r;
    cout << endl;

    // idemo red po red - dakle mijenjamo y-ne od +r do -r
    for(y = r; y > -r; y--)
    {
        cout << "|";

        xl = xs - (int) (0.5+sqrt(r*r - (y-0.5)*(y-0.5)));
        xd = xs + (int) (0.5+sqrt(r*r - (y-0.5)*(y-0.5)));

        // 1) crtanje razmaka
        for(x = 0; x < xl; x++){
            cout << " ";
        }

        // 2) crtanje zvjezdica
        // zvjezdice su na polozajima od xl do xd
        for(x = xl; x <= xd; x++)
        {
            cout << "*";
        }
        cout << endl;

        /*
        for(stupac = 0; stupac < red; stupac++){
            cout << " ";
        }
        cout << "|" << endl;
        */
    }

    return 0;
}
