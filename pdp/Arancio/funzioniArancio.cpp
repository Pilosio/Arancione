#include <iostream>
#include <fstream>
#include <string>
#include "funzioniArancio.h"

int showMenu(){
unsigned int sceltaMenu;
std::cout << "\n\n\t\t------ANAGRAFICHE ------\n";
        std::cout << "\n\tBenvenuto nella gestione Anagrafiche cosa vuoi fare?:\n";
        std::cout << "\t [1]  Inserire nuova Anagrafica\n";
        std::cout << "\t [2]  Ricercare una Anagrafica\n";
        std::cout << "\t [3]  Cancellare una Anagrafica\n";
        std::cout << "\t [4]  Stampare le Anagrafiche\n";
        std::cout << "\t [5]  Salvataggio modifiche\n";
        std::cout << "\t [6]  Exit\n";
        do {
            std::cout << "\n n scelta: ";
            std::cin >> sceltaMenu;
        } while (sceltaMenu < 1 || sceltaMenu > 7);

 return sceltaMenu;
}

bool GestioneSceltaMenu(int sceltaMenu, std::vector <Anagrafica> &vectAna){

 bool fineProgramma= false;
 int idAna,idxAnaTrovato;
 std::ofstream fl_Dati_Out;

 switch(sceltaMenu){
        case 1:
            //inserimento nuova Anagrafica;
            insertAnagrafica(vectAna);
            break;
        case 2:

            std::cout << "Inserisci l'ID Anagrafica che vuoi cercare:  ";
            std::cin >> idAna;
            idxAnaTrovato = SeachAnaById(vectAna,idAna);
            if (idxAnaTrovato!=-1)
                showAnagrafica(vectAna,idxAnaTrovato);
            else
                std::cout << "[!] ID Anagrafica non presente\n";
            break;
        case 3:
            std::cout << "Inserisci l'ID della persona che vuoi eliminare:  ";
            std::cin >> idAna;
            idxAnaTrovato= SeachAnaById(vectAna, idAna);
            if (idxAnaTrovato==-1)
                std::cout << "[!] ID Persona non presente\n";
            else
             deleteAna(vectAna,idxAnaTrovato);
            break;
        case 4:
            showAnagrafiche(vectAna);
            break;
        case 5:
            //salvataggio modifiche;
            fl_Dati_Out.open("Anagrafiche.csv");
            if (fl_Dati_Out.fail()){
                std::cout <<"errore apertura file per scrittura"<<std::endl;
                exit(0);
            }
            saveAnagrafiche(fl_Dati_Out,vectAna);
            fl_Dati_Out.close();
            break;
        case 6:
            fineProgramma=true;
            break;
        }//switch
 return fineProgramma;
}

void LoadDati(std::istream &fl_DatiIn, std::vector<Anagrafica> &vectAna){
    Anagrafica tempAna;
    std::string strTok, tempStr;

    std::getline(fl_DatiIn, tempStr);
    while (!fl_DatiIn.eof())
     {
       std::getline(fl_DatiIn, tempStr, ';');
       if(fl_DatiIn.eof())
            break;
        tempAna.idPersona = stoi(tempStr);

        std::getline(fl_DatiIn, tempStr, ';');
        tempAna.cognome= tempStr;
        std::getline(fl_DatiIn, tempStr, ';');
        tempAna.nome= tempStr;

        std::getline(fl_DatiIn, tempAna.indirizzo, ';');
        std::getline(fl_DatiIn, tempAna.localita, ';');
        std::getline(fl_DatiIn, tempAna.sigla_provincia, ';');
        std::getline(fl_DatiIn, tempStr);
        tempAna.telefono= tempStr;
       //std::getline(fl_DatiIn, tempAna.telefono, ';');
        vectAna.push_back(tempAna);
     }//while
}

void showAnagrafica(std::vector<Anagrafica> &vectAna,int idAna){

    std::cout << "|" << vectAna[idAna].idPersona << "\t";
    std::cout << "|" << vectAna[idAna].cognome << "\t\t";
    std::cout << "|" << vectAna[idAna].nome << "\t";
    std::cout << "|" << vectAna[idAna].localita << "\t\t";
    std::cout << "|" << vectAna[idAna].sigla_provincia << "\t";
    std::cout << "|" << vectAna[idAna].telefono << "\t" << std::endl;

}//showAnagrafica

void showAnagrafiche(std::vector <Anagrafica> &vectAna){
std::cout << "\n|ID PERSONA\t|COGNOME\t|NOME\t\t|INDIRIZZO\t|LOCALITA\t|PROV\t|TELEFONO\n" <<
            "----------------------------------------------------------------------------------------------------------------\n";
for (int i=0;i<vectAna.size(); i++){
        std::cout << "|" << vectAna[i].idPersona << "\t";
        std::cout << "|" << vectAna[i].cognome << "\t\t";
        std::cout << "|" << vectAna[i].nome << "\t";
        std::cout << "|" << vectAna[i].localita << "\t\t";
        std::cout << "|" << vectAna[i].sigla_provincia << "\t";
        std::cout << "|" << vectAna[i].telefono << "\t" << std::endl;
}//for
}

int SeachAnaById(std::vector<Anagrafica> &vectAna, int idAna){

int iMid, iStart, iEnd;
iStart=0;
iEnd= vectAna.size()-1;

iMid= (iStart+iEnd)/2;
while (iEnd >= iStart){
  if(vectAna[iMid].idPersona== idAna)
        return iMid;
  else if (vectAna[iMid].idPersona > idAna){
    iEnd= iMid-1;
    iMid= (iStart+iEnd)/2;
  }
  else{
    iStart= iMid+1;
    iMid= (iStart+iEnd)/2;
  }
}//while
return -1; //non trovato
}//SeachAnaById

void deleteAna(std::vector <Anagrafica> &vectAna, int idxAna){
int len;
  len= vectAna.size();
  for(int i=idxAna; i <len-1;i++ ){
    std::swap(vectAna[i], vectAna[i+1]);
  } //for
  vectAna.pop_back();
}//deleteAna

void sortAnagraficheById(std::vector <Anagrafica> &vectAna){
 //per sort viene utilizzato l'goritmo di ordinamento BubbleSort
int len, i,j;
bool isSwap;
len= vectAna.size();
for (i=0; i <len; i++){
 isSwap= false;
 for(j=0; j<len;j++){
   if(vectAna[j].idPersona> vectAna[j+1].idPersona){
        std::swap(vectAna[j],vectAna[j+1]);
        isSwap= true;
   }
 }//for j
 if (!isSwap)
    return;
}//for i

}//sortAnagrafiche

void insertAnagrafica(std::vector<Anagrafica> &vectAna){
Anagrafica tempAna;
tempAna.idPersona= vectAna.size()+1;
std::cin.ignore();
std::cout<<"Inserire cognome: ";
getline(std::cin,tempAna.cognome);
std::cout<<"Inserire nome: ";
getline(std::cin,tempAna.nome);
std::cout<<"Inserire indirizzo: ";
getline(std::cin,tempAna.indirizzo);
std::cout<<"Inserire localita: ";
getline(std::cin,tempAna.localita);
std::cout<<"Inserire sigla provincia: ";
getline(std::cin,tempAna.sigla_provincia);
std::cout<<"Inserire telefono: ";
getline(std::cin,tempAna.telefono);
vectAna.push_back(tempAna);
}//insertAnagrafica

void saveAnagrafiche(std::ofstream &fl_DatiOut, std::vector <Anagrafica> &vectAna){

//intestazione
fl_DatiOut<<"idPersona;";
  fl_DatiOut<<"cognome;";
  fl_DatiOut<<"nome;";
  fl_DatiOut<<"indirizzo;";
  fl_DatiOut<<"localita;";
  fl_DatiOut<<"sigla_provincia;";
  fl_DatiOut<<"telefono"<<std::endl;

for (int i= 0;i< vectAna.size(); i++){
  fl_DatiOut<<vectAna[i].idPersona<<";";
  fl_DatiOut<<vectAna[i].cognome<<";";
  fl_DatiOut<<vectAna[i].nome<<";";
  fl_DatiOut<<vectAna[i].indirizzo<<";";
  fl_DatiOut<<vectAna[i].localita<<";";
  fl_DatiOut<<vectAna[i].sigla_provincia<<";";
  fl_DatiOut<<vectAna[i].telefono<<std::endl;
}
}//saveAnagrafiche
