#include <iostream>
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


void nuov_anagraf(anagrafiche arr[], int dim_usata, int dim_max){

	cout<<"inserire l'Id Persona:"<<endl;
    cin>>arr[dim_usata].idPersona;
	cout<<"inserire il cognome:"<<endl;
	cin>>arr[dim_usata].Cognome;
	cout<<"inserire il nome:"<<endl;
	cin>>arr[dim_usata].Nome;
	cout<<"inserire l' indirizzo:"<<endl;
	cin>>arr[dim_usata].Indirizzo;
	cout<<"inserire la localita':"<<endl;
	cin>>arr[dim_usata].Localita;
	cout<<"inserire la sigla della provincia':"<<endl;
	cin>>arr[dim_usata].Sigla_provincia;
	cout<<"inserire il numero di telefono':"<<endl;
	cin>>arr[dim_usata].Telefono;
	dim_usata++;
}

int main() {

	int dim_max=10;
	int dim_usata=0;
	anagrafiche arr[dim_max];
	nuov_anagraf(arr,dim_usata, dim_max);
	return 0;
}
