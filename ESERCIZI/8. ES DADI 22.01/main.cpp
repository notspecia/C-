/*Scrivere un programma che lanci un numero di dadi a sei facce scelto dall’utente,
mostri i risultati e dica quante volte è uscito il 6.*/

#include <cstdlib>  //libreria per generare numeri casuali
#include <ctime>    //idem, per generare numeri casuali
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int N;          // quantita di dadi da tirare
    int i;          // iteratore
    int conteggio;  // conteggio di quante volte è uscito il 6
    int risultato;  // per tenere conto del numero che è uscito casualmente

    // inizializzazione
    conteggio = 0;
    srand(time(NULL));  // necessario per generare numeri casuali

    // input utente
    cout << "quante volte vuoi lanciare il dado?: ";
    cin >> N;

    if (N <= 0) {
        cout << "inserisci una quantita valida!";

        // tiri dado
    } else {
        for (i = 0; i < N; i++) {
            risultato = rand() % 6 + 1;  // generazione casuale di un numero tra 1 e 6

            cout << i + 1 << " lancio: " << risultato << endl;
            if (risultato == 6) {
                conteggio++;
            }
        }
        cout << "\nnumero di volte in cui è uscito sei: " << conteggio;  // stampa quante volte è uscito il 6
    }
    return 0;
}