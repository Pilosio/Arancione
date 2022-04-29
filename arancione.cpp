#include <string>
#include <sstream>
#include "arancio_funzioni.h"
/*
void lettura(std::fstream& inputFile, std::vector<Dati_Macchine>& DM)
{

    Dati_Macchine DataM;
    std::string strLine,strTok;
    std::istringstream issLine;

    getline(inputFile, strLine);
    while (!inputFile.eof()){
        issLine.str(strLine);
        getline(issLine,strTok, ';');
        DataM.IdAuto = std::stoi(strTok);

        getline(issLine,DataM.Ind_Venduta,';');
        getline(issLine, strTok, ';');
        DataM.AnnoArrivoDep = std::stoi(strTok);
        getline(issLine, DataM.MeseArrivoDep, ';');
        getline(issLine, DataM.des_auto, ';');
        getline(issLine, strTok, ';');
        DataM.Anno_Imm = std::stoi(strTok);
        getline(issLine, strTok, ';');
        DataM.Km_Auto = std::stoi(strTok);
        getline(issLine, strTok, ';');
        DataM.prz_acq = std::stoi(strTok);
        getline(issLine, strTok, ';');
        DataM.prz_ven = std::stoi(strTok);

        DM.push_back(DataM);
        issLine.clear();
        getline(inputFile, strLine);
    }// while (!inputFile.eof())
}

*/


int CaricamentoFile(std::ifstream &fileIn, Anagrafiche arrAna[], int dim){
 std::string riga,  strTok;
 std::istringstream issRiga;
 int i=0;
 Anagrafiche ana;

 std::getline(fileIn,riga);
 while (fileIn.eof()&& i < dim ){
  issRiga.str(riga);
  getline(issRiga,strTok, ';');
  arrAna[i].idPersona= std::stoi(strTok);
  issRiga.clear();

  std::getline(fileIn,riga);
  getline(issRiga,strTok, ';');
  arrAna[i].Cognome= strTok;

   issRiga.clear();
  std::getline(fileIn,riga);
  getline(issRiga,strTok, ';');
  arrAna[i].Nome= strTok;
  issRiga.clear();

std::getline(fileIn,riga);
getline(issRiga,strTok, ';');
arrAna[i].Indirizzo= strTok;
issRiga.clear();

 std::getline(fileIn,riga);
  getline(issRiga,strTok, ';');
  arrAna[i].Localita= strTok;
  issRiga.clear();

  std::getline(fileIn,riga);
getline(issRiga,strTok, ';');
arrAna[i].Sigla_provincia= strTok;
issRiga.clear();

std::getline(fileIn,riga);
getline(issRiga,strTok, ';');
arrAna[i].Telefono= strTok;
issRiga.clear();











  i++;
 }//while




}//CaricamnetoFile
