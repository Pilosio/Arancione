#include <iostream>

using namespace std;
void menu()
{
    char scelta ;
    int id, risultato;

    while (1)
    {

        cout << "--------Benvenuti all'anagrafica--------\n"
            << "[1]Vizualizzare contenuto dell'anagrafica\n"
            << "[2]Inserire nuovi ID\n"
            << "[3]Ricerca tramite ID\n"
            << "[4]Eliminazione ID\n"
            << "[5]Esci dal programma\n";


        switch (scelta - 48)
        {
        case 1:
            Nome_funzione();
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "Inserimento di un ID: \n";
            Nome_funzione();
            system("pause");
            system("cls");
            break;

        case 3:
            cout << "Inserisci il ID da cercare : ";
            cin >> id;
            risultato = Nome_funzione();
            if (risultato == -1)
                cout << "ID cercato non si trova nei server \n";
            else
                     cout << " \n ID persona : " << struct << endl
                          << " cognome : " << struct << endl
                          << " nome : " << struct << endl
                          << " indirizzo " << struct << endl
                          << " località : " << struct  << endl
                          << " sigla provincia : " << struct<< "%" << endl
                          << " telefono : " <<struct << endl;
            system("pause");
            system("cls");
            break;
        case 4:
            Nome_funzione;
            cout << "Inserisci il ID da eliminare: ";
            cin >> id;
            Nome_funzione;
            Nome_funzione per vizualizzare;
            system("pause");
            system("cls");
            break;
        case 5:
            std::cout << "Salvando le modifiche nel file\n";
            //salvataggio_su_file();
            file.close();
            cout << "Arrivederci!";
            exit(0);

        }


    }
}


int main()
{

}
