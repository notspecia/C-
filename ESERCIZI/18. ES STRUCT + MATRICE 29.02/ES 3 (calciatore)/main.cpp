/*Codificare la struttura che possa contenere i dati relativi al giocatore tesserato in una
squadra di calcio*/

#include <iostream>
#include <string>
using namespace std;

/*							     STRUCTS
--------------------------------------------------------------------*/

struct giocatore
{
    int matricola;
    string nome;
    string cognome;
    int anni;
    string squadra;
    string piede;
};

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    giocatore calciatore;

    // inizializzazione variabili
    calciatore.matricola = 12345;
    calciatore.nome = "Gabriele ";
    calciatore.cognome = "Speciale ";
    calciatore.anni = 19;
    calciatore.squadra = "venaria ASC";
    calciatore.piede = "destro";

    // stampa del calciatore
    cout << "\nGIOCATORE MATRICOLA: " << calciatore.matricola << "\n-------------------------" << endl;
    cout << "\nil calciatore si chiama " << calciatore.nome << calciatore.cognome << endl
         << "ha " << calciatore.anni << " anni" << endl
         << "N matricola " << calciatore.matricola << ", gioca per il " << calciatore.squadra << endl
         << "piede forte del giocatore: " << calciatore.piede << endl;

    return 0;
}
