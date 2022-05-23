#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <vector>
#include <cstdlib>
#include "funzioniArancio.h"


using namespace std;

int main(){
    ifstream fileDatiIn;
    ofstream fileDatiout;
    vector <Anagrafica> vectAnagrafiche;
    int sceltaMenu;
    bool fineProgramma;
    char sceltaSave;

    setlocale(LC_ALL, "");
   // Apertura file dati
    fileDatiIn.open("Anagrafiche.csv");

    // Controllo che l'apertura sia andata a buon fine
    if (fileDatiIn.fail()) {
        cout << "Lettura del file \"Anagrafiche.csv\" fallita. Verificare che esso sia presente" << endl;
        exit(0);
    }
    LoadDati(fileDatiIn,vectAnagrafiche);
    fileDatiIn.close();
    // Inizio output del programma
    fineProgramma= false;
    while (!fineProgramma){
     sceltaMenu=showMenu();
     fineProgramma=GestioneSceltaMenu(sceltaMenu,vectAnagrafiche);
     system("pause");
     system("cls");

     if (fineProgramma) {
            do {
                std::cout << "[!] Ci sono delle modifiche non salvate! Salvarle nel file? (s/n): ";
                cin >>sceltaSave;
                sceltaSave= toupper(sceltaSave);
            } while (sceltaSave != 'S' && sceltaSave != 'N');
            if (sceltaSave == 'S'){
                cout<<"salvo";
                fileDatiout.open("Anagrafiche.csv");
                if( fileDatiout.fail()){
                    cout<<"errore apertua file in scrittura"<<endl;
                    exit(0);
                }
                saveAnagrafiche(fileDatiout, vectAnagrafiche);
                fileDatiout.close();
            }
     }
    }//while
    std::cout << "Chiusura programma. . .";
    return 0;
}
