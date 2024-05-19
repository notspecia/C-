/*Data la seguente definizione di dati:
struct Persona {
int matricola;
string nome;
string indirizzo;
string dataNascita;
string codiceFiscale;
bool isConiugato;
};
Persona dipendente;

Modificare la struttura Persona per rappresentare l’indirizzo come una struttura formata
dai campi: via, CAP, Comune.*/

#include <iostream>
#include <string>
using namespace std;

/*							     STRUCTS
--------------------------------------------------------------------*/

// struttura che modifica nella struttura persona l'indirizzo
struct pippo
{
    string via;
    int CAP;
    string comune;
};

// struttura che rappresenta i dati di una persona
struct persona
{
    int matricola;
    string nome;
    pippo indirizzo; // MODIFICA DELL'INDIRIZZO (vengono messi in + Via, CAP, comune)
    string dataNascita;
    string codiceFiscale;
    bool isConiugato;
};

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    persona dipendente;

    // inizializzazione variabili
    dipendente.indirizzo.via = "via gaetano amati";
    dipendente.indirizzo.CAP = 10078;
    dipendente.indirizzo.comune = "Venaria";

    // stampa delle variabili
    cout << "\n\necco dove vivi: " << dipendente.indirizzo.via << ", CAP " << dipendente.indirizzo.CAP << ", comune di " << dipendente.indirizzo.comune << endl;

    return 0;
}
