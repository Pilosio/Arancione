#include <iostream>
#include <fstream>
#include <string>
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
        	getline (Inputfile,stringa, ' \n');
            cout << stringa;
        }
    }


}

int main()
{
  
    return 0;
}
