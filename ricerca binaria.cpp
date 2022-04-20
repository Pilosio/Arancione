#include <iostream>
#include <vector>
#include "struct.h"

using namespace std;

//per farlo funzionare inserire in ordine: vettore, numero da cercare e dimensione dell array inteso come lo spazio
//occupato dell array

//restituisce la posizione del num cercato
//se restituisce -1 non ha trovato il numero cercato


int ricerca_bin(anagrafiche arr[], int cercato,int dim){

    int i = 0, j = dim-1, m, pos = -1;

    do {
	m = (i + j)/2;
	if(arr[m].idPersona == cercato)
		pos = m;
	else if (arr[m].idPersona < cercato)
		i = m + 1;
	else
		j = m - 1;
    } while(i <= j && pos == -1);

    return pos;
}
