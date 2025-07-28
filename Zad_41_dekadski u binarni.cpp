/*
Pretvorba dekadskog u binarni broj:

 12  |  0
  6  |  0
  3  |  1  ^      1100_2 = 0*2^0 + 0*2^1 + 1*2^2 + 1*2^3 = 0+0+4+8= 12
  1  |  1  |
  0

*/

#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int dek,znamenka;
    string bin = "";

    cout << "Upisite dekadski broj: ";
    cin >> dek;

    // DEKADSKI -> BIN
    while(dek > 0){
        bin = (char) (48 + dek%2) + bin;
        dek = dek / 2;
        // sada cemo int pretvoriti u char  ->  0 -> '0' &  1 -> '1'
        // ASCII nam daje kod 48 za znak '0' i 49 za znak '1'
        // to znaci da trebamo dodati 48 na int da bi dobili ASCII od pripadajuceg znaka (char)
        cout << "BIN: " << bin << " | " << "Rezultat: " << dek << endl;
    }

    int l = bin.length();

    // dek = 0;  nepotrebno jer ZNAMO da je dek = 0 NAKON PETLJE
    // BIN -> DEK
    // "1100"  kad gledamo znamenke s liva na desno prva znamenka nikad nema isti iznos,
    //       dakle moze biti 2^3, 2^8,,,itd., ali kada gledamo s desna na livo tada
    //       prva znamenka ima uvik 2^0 i zbog toga je lakse krenuti is tog smjera
    // 0*2^0 + 0*2^1 + 1*2^2 + 1*2^3 = 0+0+4+8 = 12
    for(int i = 0; i < l; i++){
        znamenka = bin[l - i - 1] - 48;
        // u programu char i int imaju automatsku konverziju(casting), problem u tome
        // je sto dobijamo s jedne strane int a s druge strane ASCII kod
        // ako zelimo uskladiti znamenku s brojem moramo od chara oduzeti 48 kako bi
        // od znaka '0' dobili int 0, jer je ASCII ('0') = 48;
        cout << "Znamenka temp: " << znamenka << endl;
        dek = dek + znamenka * pow(2, i);

    }
    cout << "Dekadski: " << dek;

    return 0;
}
