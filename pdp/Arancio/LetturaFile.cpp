#include <iostream>
#include <fstream>
using namespace std;
void LetturaFile()
{
    ifstream Inputfile;
    string stringa;
    Inputfile.open("Progetto realta il testo.txt");
    if (Inputfile != 0)
    {
        cout <<"ok il file si sta aprendo \n";
        while(!Inputfile.eof())
        {
        	getline (Inputfile,stringa, ';');
        	cout <<"  ";
            cout << stringa;
        }
    }


}

int main()
{
	LetturaFile();
  
    return 0;
}


