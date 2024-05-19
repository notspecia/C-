/*Si abbiano in input una stringa e un carattere. In output si vuole il conteggio di quante volte
quel carattere è contenuto nella stringa*/

#include <iostream>

using namespace std;

int main()
{
    // inserimento variabili
    string parola; // parola inserita dall'utente
    char C;        // la lettera richiesta
    char C2;       // la lettera richiesta (maiuscola)
    int cont;      // conteggio delle lettere
    int i;         // iteratore

    // input utente
    cout << "inserisci la parola che vuoi inserire: ",
        cin >> parola;

    cout << "\ninserisci la lettera che vuoi verificare: ";
    cin >> C;

    // trasforma la lettera richiesta anche in maiuscolo
    C2 = toupper(C);

    // elaborazione
    for (i = 0; i < parola.length(); i++)
    {
        if (parola[i] == C || parola[i] == C2)
        {
            cont++;
        }
    }
    cout << "la parola: " << parola << ", ha la lettera " << C << ", " << cont << " volte";
    return 0;
}