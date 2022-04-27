#include <string>
#include <sstream>


#include "arancio_funzioni.h"
int CaricamentoFile(std::ifstream &fileIn, Anagrafiche arrAna[], int dim){
 string riga;

 std::getline(fileIn,riga);
 while (fileIn.eof()){

  std::getline(fileIn,riga);
 }//while




}//CaricamnetoFile
