#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream mioFile;                        //dichiarazione file di tipo fstream
    string buffer;

    mioFile.open("pippo.txt");               //riferimento dalla ram alla rom
    if(mioFile){                             //pari a 0 se e' aperto correttamente oppure un 1 se non e' aperto correttamente
    while(!mioFile.eof()){                   //torna true quando sono alla fine del file
        getline(mioFile, buffer, '\n');      //buffer= indirizzo di mem del buffer
        cout<< "\nValore letto: "<<buffer;
    }//while
    }//if
}
