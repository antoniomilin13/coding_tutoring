
//VEKTORI

#include <vector>                           // - ukljucujemo modul za vector
vector <int> polje                          // - deklariranje integer vektorskog polja

polje.size()                                // - dimenzija (broj clanova) vektorskog polja
polje.push_back(ocjena)                     // - dodavanje elementa ocijena na zadnje misto u polju
polje.pop_back()                            // - brisanje zadnjeg elementa u polju
polje.erase(polje.begin() + i)              // - brisanje elementa na mistu i
polje.insert(polje.begin() + i, broj1, b2)  // - umetanje dva broja na poziciji 'i' i 'i + 1'

//STRINGOVI

string1.size()                                // - funkcija koja prikazuje broj bajtova stringa

-48 je konverzija znamenke (char) u brojeve (int) od 0 do 9
-65 za znakove heksadecimalnih vrijednosti(slova A - F)
