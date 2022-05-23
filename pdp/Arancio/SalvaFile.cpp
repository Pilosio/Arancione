#include <iostream>
#include <fstream>
using namespace std;
void Salvataggio(ifstream &Salva, string legge)
{
    ifstream Salva;
    string legge;
    Salva.open("Progetto realta il testo.txt");
    if(Salva != 0)
    {
        cout <<"il file si sta salvando \n";
      while(!Salva.eof())
       {
          getline(Salva,legge,';');
          cout <<"  ";
          cout << legge;

       }
    }
}

int main()
{
    Salvataggio(Salva,Legge);

    return 0;
}
