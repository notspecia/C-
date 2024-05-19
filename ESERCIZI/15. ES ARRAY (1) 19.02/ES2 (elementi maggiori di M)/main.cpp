/*Dopo aver caricato in memoria un array di numeri interi con 10 componenti, contare le componenti
che hanno valore superiore a M inserito in input.*/

#include <iostream>
using namespace std;

int const MAX = 10;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiNumeri(int numeri[]);
int conteggioNumeri(int numeri[], int M);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main() {
    // dichiarazione variabili
    int numeri[MAX];  // EX:= {1,2,3,4,5,6,7,8,9,10}; array dei numeri interi
    int M;           // valore input utente
    int count;       // conteggio numeri > M

    // input utente numero di riferimento
    cout << "inserisci il valore M: ";
    cin >> M;

    // funzione che memorizza i numeri nell'array
    leggiNumeri(numeri);

    // funzione che controlla e conta i numeri > M
    count = conteggioNumeri(numeri, M);

    // stampa di quanti numeri sono > M
    cout << "\nla quantita di numeri > M, e di: " << count;
}


/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge e memomorizza i numeri nell'array

parametri formali:
int numeri[]

valore restituito:
null
*/
void leggiNumeri(int numeri[]) {

    // dichiarazione variabili
    int i;

    // ciclo per memorizzare i numeri inseriti dall'user
    for (i = 0; i < 10; i++) {
        cout << "\ninserisci il " << i + 1 << " numero: ";
        cin >> numeri[i];
    }
}



/*funzione che conta i numeri memorizzati > M

parametri formali:
int numeri[], int M

valore restituito:
int count
*/
int conteggioNumeri(int numeri[], int M) {

    // dichiarazione variabili
    int i;
    int count;

    // inizializzazione variabili
    count = 0;

    // ciclo che controla se i numeri memorizzati sono > M
    for (i = 0; i < 10; i++) {
        if (numeri[i] > M) {
            count++;
        }
    }
    return count;
}