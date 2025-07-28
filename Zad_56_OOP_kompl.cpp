#include <iostream>

using namespace std;


class Kompleksni{

public:
    double re, im;

    Kompleksni (double _re, double _im){
        re = _re;
        im = _im;
        //cout << "(" << re << " , " << im << ")" << endl;
    }

    Kompleksni zbroji(Kompleksni z){
        double r, i;
        r = re + z.re;
        i = im + z.im;
        return Kompleksni(r,i);
    }
    Kompleksni zbroji(double d){
        double r, i;
        r = re + d;
        i = im;
        return Kompleksni(r,i);
    }

    Kompleksni operator +(Kompleksni z){ // definicija opertora + za kompleksne objekte
        double r, i;
        r = re + z.re;
        i = im + z.im;
        return Kompleksni(r,i);
    }

    Kompleksni operator +(double f){
        double r, i;
        r = re + f;
        i = im;
        return Kompleksni(r,i);
    }

    Kompleksni oduzmi(Kompleksni z){
        double r, i;
        r = re - z.re;
        i = im - z.im;
        return Kompleksni(r, i);
    }
    Kompleksni operator -(Kompleksni z){ // definicija opertora + za kompleksne objekte
        double r, i;
        r = re - z.re;
        i = im - z.im;
        return Kompleksni(r,i);
    }


    Kompleksni pomnozi(Kompleksni z){
        double r, i;
        //  (z1*z2 = (re+im*i)*(z.re+z.im i) = re*z.re-im*z.im  + (re*z.im+im*z.re) i)
        r = re*z.re-im*z.im;
        i = re*z.im+im*z.re;
        return Kompleksni(r, i);
    }
    Kompleksni operator *(Kompleksni z){
        double r, i;
        //  (z1*z2 = (re+im*i)*(z.re+z.im i) = re*z.re-im*z.im  + (re*z.im+im*z.re) i)
        r = re*z.re-im*z.im;
        i = re*z.im+im*z.re;
        return Kompleksni(r, i);
    }

    Kompleksni podijeli (Kompleksni z){
        double r, i, nazivnik;
        nazivnik = z.re * z.re + z.im*z.im;
        r = (re*z.re+im*z.im)/nazivnik;
        i = (im*z.re - re*z.im)/nazivnik;
        return Kompleksni(r, i);
    }
    Kompleksni operator / (Kompleksni z){
        double r, i, nazivnik;
        nazivnik = z.re * z.re + z.im*z.im;
        r = (re*z.re+im*z.im)/nazivnik;
        i = (im*z.re - re*z.im)/nazivnik;
        return Kompleksni(r, i);
    }

    Kompleksni podijeli (double d){
        // dijeljenje sa cisto realnim dijelom je ISTO kao dijeljenje sa kompleksnim (nazivnik) ciji je Im dio 0
        double r, i;
        r = re/d;
        i = im/d;
        return Kompleksni(r, i);
    }

    void ispisi(){
        cout << re << ((im>=0)?"+":"") << im << "i";
    }

    // PREFIKS - INKREMENT: PRVO UVECAJ pa onda upotrijebi
    Kompleksni operator ++ (){  // definicija prefiksa ++ za KOMPLEKSNI BROJ (re,im) -> (re++, im++)
        re++;
        im++;
        return *this;   // vracamo objekt sa NOVIM vrijednostima re i ima
    }

    // PREFIKS - DEKREMENT: PRVO UMANJI pa onda upotrijebi
    Kompleksni operator -- (){  // definicija prefiksa -- za KOMPLEKSNI BROJ (re,im) -> (re--, im--)
        re--;
        im--;
        return *this;   // vracamo objekt sa NOVIM vrijednostima re i ima
    }


    // POSTFIX INKREMENT: PRVO UPOTRIJEBI, pa TEK ONDA UVECAJ!  (int) luzi SAMO ZATO da razlikuje POSTfix od PREfiksa
    Kompleksni operator ++ (int){  // definicija postfiksa ++ za KOMPLEKSNI BROJ (re,im) -> (re++, im++)
        Kompleksni stari = *this;  // duplikat sa svim TRENUTNIM vrijednostima naseg objekta
        re++;
        im++;
        return stari;   // vracamo objekt sa STARIM vrijednostima re i im, ali objek PAMTI uvecanje re i im
                        // sto ce se vidjeti pri PRVOJ SLJEDECOJ UPOTREBI objekta
    }

    // POSTFIX DEKREMENT: PRVO UPOTRIJEBI, pa TEK ONDA UMANJI!  (int) luzi SAMO ZATO da razlikuje POSTfix od PREfiksa
    Kompleksni operator -- (int){  // definicija postfiksa ++ za KOMPLEKSNI BROJ (re,im) -> (re--, im--)
        Kompleksni stari = *this;  // duplikat sa svim TRENUTNIM vrijednostima naseg objekta
        re--;
        im--;
        return stari;   // vracamo objekt sa STARIM vrijednostima re i im, ali objek PAMTI smanjenje re i im
                        // sto ce se vidjeti pri PRVOJ SLJEDECOJ UPOTREBI objekta
    }

private:

};

ostream& operator << (ostream& izlaz, Kompleksni z){  // ispis objekta
    izlaz << z.re << ((z.im>=0)?"+":"") << z.im << "i";
    return izlaz;
}

Kompleksni operator + (float f, Kompleksni z){  // ovo je FUNKCIJA, a NE METODA jer nije pridruzena nekom objektu
    double r, i;
    r = f + z.re;
    i = z.im;
    return Kompleksni(r,i);
}

Kompleksni zbroji(float f, Kompleksni z){
    double r, i;
    r = f + z.re;
    i = z.im;
    return Kompleksni(r,i);
}

Kompleksni podijeli (double d, Kompleksni z){
    // dijeljenje sa cisto realnog broja sa kompleksnim je ISTO kao dijeljenje kompleksnog broja (brojnik) ciji je Im dio 0
    double r, i, nazivnik;   // Nulom proglasavamo SAMO im (Imaginarna komponenata samo PRVOG objekta)
    nazivnik = z.re * z.re + z.im*z.im;  // OVDJE NISTA NE BRISEMO !!!
    r =  d*z.re/nazivnik;
    i = -d*z.im/nazivnik;
    return Kompleksni(r, i);
}


int main(){

    Kompleksni z1(0,1);
    Kompleksni z2(3,-1);


    Kompleksni z3 = z1.zbroji(z2);              // z3 = z1+z2
    cout << "\nz1.zbroji(z2) = " << z3.re << "   " << z3.im  << endl;
    z3 = z1 + z2;
    z3 = z1 + z2;
    cout << "z1 + z2 = "<<z3.re << "   " << z3.im  << endl << "------------------" << endl;


    Kompleksni z4 = z1.oduzmi(z2);              // z4 = z3-z2  = z1
    cout << "\nz1.oduzmi(z2) = " << z4.re << "   " << z4.im << endl;
    z4 = z1 - z2;
    cout << "z1 - z2 = " << z4.re << "  " << z4.im << endl << "------------------" << endl;


    Kompleksni z5 = z1.pomnozi(z2);              // z5 = z1 * z2
    cout << "\nz1.pomnozi(z2) = " << z5.re << "   " << z5.im << endl;
    z5 = z1 * z2;
    cout << "z1 * z2 = " << z5.re << "  " << z5.im << endl << "------------------" << endl;


    cout << "z5 / z1 = z2" << endl << "z2 = " << z2.re << ", " << z2.im << endl;
    Kompleksni z6 = z5.podijeli(z1);              // z6 = z5 / z1
    cout << "\nz5.podijeli(z1) = " << z6.re << "   " << z6.im << endl;
    z6 = z5 / z1;
    cout << "z5 / z1 = " << z6.re << "  " << z6.im << endl << "------------------" << endl;

    /// kombinacije kompleksni i double

    Kompleksni z7 = z1.zbroji(5);              // z7 = z1 + 5
    cout << "\nz1.zbroji(5) = " << z7.re << "   " << z7.im << endl;
    z7= z1 + 5;
    cout << "z1 + 5 = "<<z7.re << "   " << z7.im  << endl << "------------------" << endl;


    z7 = 5 + z1;
    cout << "5 + z1 = "<<z7.re << "   " << z7.im  << endl;
    z7 = zbroji(5, z1);   //  zbog svojstva komutacije je ISTO KAO  z1.zbroji(5)  ili z1.pomnozi(5)
    cout << "z1 + 5 = "<<z7.re << "   " << z7.im  << endl << "------------------" << endl;

    // kod oduzimanja i kod dijeljenja komutacije NE VRIJEDI !!! pa U SVAKOM SLUCAJU
    // MORAMO pisati dodatnu funkciju kod poretka parametara (double, kompleksni)

    Kompleksni z8 = z1.podijeli(2);
    cout << "z1/2 = "<<z8.re << "   " << z8.im  << endl << "------------------" << endl;

    z8 = podijeli(2,z1);
    cout << "2/z1 = "<<z8.re << "   " << z8.im  << endl << "------------------" << endl;

    /// a/b = c            ->  b*c = a
    /// 2/(0,1) = (0,-2)   ->  (0,1)*(0,-2) = 2

    Kompleksni z9 = z8 * z1;
    cout << "z8 * z1 = " << z9.re << ", " << z9.im << endl;

    int a=0;  // postfix je operacija koja se izvodi NAKON upotrebe varijable
    cout << "Postfix za a=0 je   a=" << a++ << endl;
    cout << "Nakon toga a=" << a << endl;

    // prefix je operacija koja se izvodi PRIJE upotrebe varijable
    cout << "\nPrefix za a=1 je   a=" << ++a << endl;
    cout << "Nakon toga a=" << a << endl;


    Kompleksni z10 = Kompleksni(11,-11);
    cout << endl << z10 << endl;
    //cout << "Nakon toga z1=" << z1 << endl;
    z10.ispisi();

    cout << endl << "-----------------------------" << endl << "z1=" << z1 << endl;
    cout << ++z1 << endl;  // ponasanje PREFIKSA
    cout << z1 << endl;

    cout << endl << "-----------------------------" << endl << "z1=" << z1 << endl;
    cout << z1++ << endl;  // ponasanje POSTFIKSA
    cout << z1 << endl;

    cout << endl << "-----------------------------" << endl << "z1=" << z1 << endl;
    cout << --z1 << endl;  // ponasanje PREFIKSA
    cout << z1 << endl;

    cout << endl << "-----------------------------" << endl << "z1=" << z1 << endl;
    cout << z1-- << endl;  // ponasanje POSTFIKSA
    cout << z1 << endl;


    return 0;
}
