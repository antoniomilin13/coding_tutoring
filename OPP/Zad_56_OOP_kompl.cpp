#include <iostream>

using namespace std;


class Kompleksni{

public:
    int re, im;

    Kompleksni (int _re, int _im){
        re = _re;
        im = _im;
        cout << "(" << re << " , " << im << ")" << endl;
    }
    Kompleksni (float _re, float _im){
        float re = _re;
        float im = _im;
        cout << "(" << re << " , " << im << ")" << endl;
    }

    Kompleksni zbroji(Kompleksni z){
        int r, i;
        r = re + z.re;
        i = im + z.im;
        return Kompleksni(r,i);
    }
    Kompleksni zbroji(float f){
        int r, i;
        r = re + f;
        i = im;
        return Kompleksni(r,i);
    }

    Kompleksni operator +(Kompleksni z){ // definicija opertora + za kompleksne objekte
        int r, i;
        r = re + z.re;
        i = im + z.im;
        return Kompleksni(r,i);
    }
    Kompleksni operator +(float f){
        int r, i;
        r = re + f;
        i = im;
        return Kompleksni(r,i);
    }

    Kompleksni oduzmi(Kompleksni z){
        int r, i;
        r = re - z.re;
        i = im - z.im;
        return Kompleksni(r, i);
    }
    Kompleksni operator -(Kompleksni z){ // definicija opertora + za kompleksne objekte
        int r, i;
        r = re - z.re;
        i = im - z.im;
        return Kompleksni(r,i);
    }


    Kompleksni pomnozi(Kompleksni z){
        int r, i;
        //  (z1*z2 = (re+im*i)*(z.re+z.im i) = re*z.re-im*z.im  + (re*z.im+im*z.re) i)
        r = re*z.re-im*z.im;
        i = re*z.im+im*z.re;
        return Kompleksni(r, i);
    }
    Kompleksni operator *(Kompleksni z){
        int r, i;
        //  (z1*z2 = (re+im*i)*(z.re+z.im i) = re*z.re-im*z.im  + (re*z.im+im*z.re) i)
        r = re*z.re-im*z.im;
        i = re*z.im+im*z.re;
        return Kompleksni(r, i);
    }

    Kompleksni podijeli (Kompleksni z){
        float r, i, nazivnik;
        nazivnik = z.re * z.re + z.im*z.im;

        r = (re*z.re+im*z.im)/nazivnik;
        i = (im*z.re - re*z.im)/nazivnik;
        return Kompleksni(r, i);
    }
    Kompleksni operator / (Kompleksni z){
        float r, i, nazivnik;
        nazivnik = z.re * z.re + z.im*z.im;

        r = (re*z.re+im*z.im)/nazivnik;
        i = (im*z.re - re*z.im)/nazivnik;

        cout << "nazivnik: " << nazivnik << endl;
        cout << "re: " << re << "  im: " << im << endl;
        cout << "z.re: " << z.re << "  z.im: " << z.im << endl;
        return Kompleksni(r, i);
    }
    //DOMACI -/*/ /  -> OPERATORI

private:

};


Kompleksni operator + (float f, Kompleksni z){
    int r, i;
    r = f + z.re;
    i = z.im;
    return Kompleksni(r,i);
}


int main(){

    Kompleksni z1(3,1);
    Kompleksni z2(1,2);


    Kompleksni z3 = z1.zbroji(z2);              // z3 = z1+z2
    cout << "z1.zbroji(z2) = " << z3.re << "   " << z3.im  << endl;

    z3 = z1 + z2;
    cout << "z1 + z2 = "<<z3.re << "   " << z3.im  << endl << "------------------" << endl;



    Kompleksni z4 = z1.oduzmi(z2);              // z4 = z3-z2  = z1
    cout << "z1.oduzmi(z2) = " << z4.re << "   " << z4.im << endl;

    z4 = z1 - z2;
    cout << "z1 - z2 = " << z4.re << "  " << z4.im << endl << "------------------" << endl;



    Kompleksni z5 = z1.pomnozi(z2);              // z5 = z1 * z2
    cout << "z1.pomnozi(z2) = " << z5.re << "   " << z5.im << endl;

    z5 = z1 * z2;
    cout << "z1 * z2 = " << z5.re << "  " << z5.im << endl << "------------------" << endl;



    Kompleksni z6 = z5.podijeli(z1);              // z5 = z1 * z2
    cout << "z1.podijeli(z2) = " << z6.re << "   " << z6.im << endl;

    z6 = z5 / z1;
    cout << "z1 / z2 = " << z6.re << "  " << z6.im << endl << "------------------" << endl;








    Kompleksni z7 = z1.zbroji(5);              // z7 = z1 + 5
    cout << "z1.zbroji(5) = " << z7.re << "   " << z7.im << endl;

    z7= z1 + 5;
    cout << "z1 + 5 = "<<z7.re << "   " << z7.im  << endl << "------------------" << endl;



    z7= 5 + z1;
    cout << "5 + z1 = "<<z7.re << "   " << z7.im  << endl << "------------------" << endl;


    return 0;
}
