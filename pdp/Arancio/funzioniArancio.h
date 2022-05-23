#include <vector>
#ifndef FUNZIONIARANCIO_H_INCLUDED
#define FUNZIONIARANCIO_H_INCLUDED

struct Anagrafica{
        int idPersona;
        std::string cognome;
        std::string nome;
        std::string indirizzo;
        std::string localita;
        std::string sigla_provincia;
        std::string telefono;
    };

int showMenu();
bool GestioneSceltaMenu(int scelta, std::vector <Anagrafica> vectAna);
void LoadDati(std::istream &fl_DatiIn, std::vector<Anagrafica> &vectAna);
void showAnagrafiche(std::vector <Anagrafica> &vectAna);
void showAnagrafica(std::vector<Anagrafica> &vectAna;int idAna);
int SeachAnaById(std::vector<Anagrafica> &vectAna, int idAna);
void deleteAna(std::vector <Anagrafica> vectAna, int idAna);
void sortAnagrafiche(std::vector <Anagrafica> vectAna);
void insertAnagrafica(std::vector<Anagrafica> vectAna, Anagrafica Ana);
void saveAnagrafiche(std::ofstream &fl_DatiOut, std::vector <Anagrafica> vectAna);

#endif // FUNZIONIARANCIO_H_INCLUDED
