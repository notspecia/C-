/*Si abbia in input una stringa, in output si vuole sapere se la stringa contiene doppie.*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // dichiarazione variabili
    string parola;
    int cont; // conteggio doppie
    int i;    // iteratore

    // inizializzazione variabili
    cont = 0;

    // input utente
    cout << "inserisci una parola: ";
    getline(cin, parola);

    // ciclo per verificare se ci sono doppie nella stringa (ex: caRRo)
    for (i = 0; i < parola.length() - 1; i++)
    {
        if (parola[i] == parola[i + 1])
        {
            cont++;
        }
    }

    // stampa se ci sono o no delle ripetizioni
    if (cont > 0)
    {
        cout << "ci sono in totale: " << cont << " ripetizioni";
    }
    else
    {
        cout << "non ci sono ripetizioni";
    }

    return 0;
}