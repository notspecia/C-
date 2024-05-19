/*Il programma genera un numero naturale casuale compreso tra 1 e 100 e l’utente deve indovinare il numero generato,
ad ogni tentativo il programma dice se il numero inserito era troppo alto o troppo basso; il programma termina quando viene indovinato.*/

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    // inserimento variabili
    int numeroC;  // numero casuale
    int numeroU;  // numero dell'utente

    // inizializzazione variabili e generazione del numero casuale
    srand(time(NULL));
    numeroC = rand() % 100 + 1;

    // INIZIO GIOCO
    do {
        // input utente e se in caso inserisco un numero al di fuori della richiesta
        cout << "\nindovina il numero che ho inserito tra 1 e 100: ";
        cin >> numeroU;

        while (numeroU <= 0 || numeroU > 100) {
            cout << "inserisci un numero valido!: ";
            cin >> numeroU;
        }

        if (numeroU > numeroC) {
            cout << "riprova! hai inserito un numero troppo alto!: " << endl;
        } else if (numeroU < numeroC) {
            cout << "riprova! hai inserito un numero troppo basso!: " << endl;
        }
    } while (numeroU != numeroC);

    // se inserisci il numero corretto hai vinto
    cout << "\nhai vinto!, il numero da indovinare era: " << numeroC << endl;

    return 0;
}