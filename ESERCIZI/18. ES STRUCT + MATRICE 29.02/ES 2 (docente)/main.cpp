/*Codificare una struttura che possa contenere i dati relativi al docente di una scuola.*/

#include <iostream>
#include <string>
using namespace std;

/*							     STRUCTS
--------------------------------------------------------------------*/

struct docente
{
    string nome;
    string cognome;
    int anni;
    string materia;
    int Nstudenti;
};

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    docente insegnante;

    // inizializzazione variabili
    insegnante.nome = "Massimo ";
    insegnante.cognome = "Papa ";
    insegnante.anni = 20;
    insegnante.materia = "informatica";
    insegnante.Nstudenti = 30;

    // stampa dei dati dell'insegnante
    cout << "\nl'insegnante si chiama " << insegnante.nome << insegnante.cognome << endl
         << "ha " << insegnante.anni << " anni" << endl
         << "ed insegna " << insegnante.materia << " a " << insegnante.Nstudenti << " studenti\n" << endl;

    return 0;
}

