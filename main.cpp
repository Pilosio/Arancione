#include <iostream>
//#include "struct.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////

#include <string>

using namespace std;
//dichiarazione
    struct anagrafiche{
        int idPersona;
        string Cognome;
        string Nome;
        string Indirizzo;
        string Localita;
        string Sigla_provincia;
        string Telefono;
    };

////////////////////////////////////////////////////////////////////////////////////

void bubble_Sort(anagrafiche arr[], int dim){

   	for(int j=0;j<=dim-1;j++)
        for(int i=0;i<=dim-1;i++){
            if(arr[i].idPersona > arr[i+1].idPersona)
                swap(arr[i].idPersona, arr[i+1].idPersona);
        }//for
}

int main(){

    int dim =6;
    anagrafiche arr[dim];

    arr[0].idPersona =1;
    arr[1].idPersona =3;
    arr[2].idPersona =10;
    arr[3].idPersona =2;
    arr[4].idPersona =9;
    arr[5].idPersona =5;

    bubble_Sort(arr, dim);

    for(int j=0; j < dim; j++){
        cout<<arr[j].idPersona<<endl;
    }
}
