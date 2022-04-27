#ifndef ARANCIO_FUNZIONI_H_INCLUDED
#define ARANCIO_FUNZIONI_H_INCLUDED
//dichiarazione
    struct Anagrafiche{
        int idPersona;
        string Cognome;
        string Nome;
        string Indirizzo;
        string Localita;
        string Sigla_provincia;
        string Telefono;
    };


void menuArancio();
int CaricamentoFile(std::ifstream &fileIn, Anagrafiche arrAna[], int dim);

#endif // ARANCIO_FUNZIONI_H_INCLUDED
