/*Si abbia in input una stringa, in output si vuole sapere che non ci siano caratteri ripetuti nella stessa.*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // inserimento variabili
    string parola;
    int count;      // conteggio di quante ripetizioni ci sono
    bool controllo; // se c'è almeno una ripetizione
    int i;
    int j;

    // inizializzazione variabili
    controllo = false;
    count = 0;

    // input utente
    cout << "inserisci una parola: ";
    getline(cin, parola);

    // 2 cicli utilizzati per confrontare ogni carattere con tutti gli altri successivi nella parola.
    for (i = 0; i < parola.length(); i++)
    {
        for (j = i + 1; j < parola.length(); j++)
        {
            if (parola[j] == parola[i])
            {
                controllo = true;
                count++;
            }
        }
    }

    // stampa se ci sono ripetizioni o no
    if (controllo == false)
    {
        cout << "non ci sono ripetizioni";
    }
    else
    {
        cout << "ci sono in totale " << count << " ripetizioni";
    }
    return 0;
}