#include <iostream>
#include <fstream>
#include "arancio_funzioni.h"

using namespace std;

int main()
{
    const int DIM=10;
    ifstream fileIn;
    Anagrafiche arrAnagrafiche[DIM];

    fileIn.open("Progetto_Arancione.txt");
    if(fileIn.fail()){
        cout<<" Errore apertura file"<<endl;
        exit(0);
    }
    CaricamentoFile(fileIn, arrAnagrafiche, DIM);

    menuArancio();
    return 0;
}
