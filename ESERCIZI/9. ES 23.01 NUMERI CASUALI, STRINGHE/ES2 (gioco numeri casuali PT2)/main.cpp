/*Modificare l’esercizio n.1 chiedendo in input il numero massimo di tentativi che l’utente deve fare per indovinare il numero.
 Se l’utente supera il numero di tentativi senza indovinare il numero allora il programma esce segnalando l’insuccesso.*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    // inserimento variabili
    int numeroC;   // numero casuale
    int numeroU;   // numero dell'utente
    int tent;      // tentativi dell'utente
    int i;         // iteratore e conteggio tentativi
    bool vittoria; // nel caso vinci

    // inizializzazione variabili e generazione del numero casuale
    srand(time(NULL));
    numeroC = rand() % 100 + 1;
    vittoria = false;

    // input utente
    cout << "inserisci quanti tentativi vuoi avere: ";
    cin >> tent;

    // se inserisco una quantita <0 al
    while (tent <= 0)
    {
        cout << "inserisci una quantita valida!: ";
        cin >> tent;
    }
    cout << endl;

    // INIZIO GIOCO
    for (i = 0; i < tent && vittoria != true; i++)
    {
        // input utente
        cout << "(" << i + 1 << " tentativo) inserisci un numero tra 1 e 100: ";
        cin >> numeroU;

        // se inserisco un numero al di fuori della richiesta
        while (numeroU <= 0 || numeroU > 100)
        {
            cout << "inserisci un numero valido!: ";
            cin >> numeroU;
        }

        if (numeroU == numeroC)
        {
            vittoria = true;
        }
        else if (numeroU < numeroC)
        {
            cout << "hai inserito un numero troppo basso! riprova!\n"
                 << endl;
        }
        else
        {
            cout << "hai inserito un numero troppo alto! riprova!\n"
                 << endl;
        }
    }
    if (vittoria == true)
    {
        cout << "\ncomplimenti hai vinto dopo " << i + 1 << " tentativi!";
    }
    else
    {
        cout << "\nhai perso! hai esaurito i tentativi, il numero era: " << numeroC << endl;
    }
    return 0;
}