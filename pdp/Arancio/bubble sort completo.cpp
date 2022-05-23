#include <iostream>
#include "struct.h"

using namespace std;

void bubble_Sort(anagrafiche arr[], int dim){

   	for(int j=0;j<=dim-1;j++)
        for(int i=0;i<=dim-1;i++){
            if(arr[i].idPersona > arr[i+1].idPersona)
                swap(arr[i].idPersona, arr[i+1].idPersona);
        }//for
}

int main(){

    int dim =100;           //metto dim=100 per esempio
    anagrafiche arr[dim];   //creao array chiamato arr

    bubble_Sort(arr, dim);  //faccio il bubble sort 
}
