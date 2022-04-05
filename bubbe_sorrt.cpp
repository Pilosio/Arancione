#include <iostream>

using namespace std;

void bubble_Sort(int vett1[], int dim){
    int n=0;
    for(int i=0; (dim-2-n)>0; i++){
        if(vett1[i] > vett1[i+1])
            swap(vett1[i],vett1[i+1]);
    n--;
    }//for
}

int main(){

    int dim= 7;
    int vett1[dim] ={1, 4, 3,  2, 5, 6, 7};
    bubble_Sort(vett1, dim);
    for(int i=0; i < dim; i++){
        cout<<vett1[i]<<endl;
    }
}
