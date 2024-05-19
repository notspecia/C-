/*Leggere un array di N posizioni, N dato in input. Dire se ogni valore memorizzato nell’array
è minore del quadrato del numero nella cella precedente.*/

#include <iostream>
using namespace std;

const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void quadratoMinore(int numeri[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main() {
    // dichiarazione variabili
    int numeri[MAX];  // dimensione dell'array
    int N;            // quantità di numeri nell'array

    // funzione per inserimento di N
    leggiN(N, MAX);

    // funzione inserimento dei numeri nell'array
    leggiNumeri(numeri, N);

    // funziona che controlla se sono in ordine crescente
    quadratoMinore(numeri, N);

    return 0;
}


/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge il numero N (1-100) inserito dall'user

parametri formali:
int &N, const int MAX

valore restituito:
null
*/
void leggiN(int &N, const int MAX) {
    do {
        cout << "\ninserisci quanti numeri vuoi registrare (2-100): ";
        cin >> N;
    } while (N < 2 || N > MAX);
}



/*funzione che legge e memomorizza i numeri nell'array

parametri formali:
int numeri[], int N

valore restituito:
null
*/
void leggiNumeri(int numeri[], int N) {
    // dichiarazione variabili
    int i;

    // ciclo per memorizzare i numeri inseriti dall'user
    for (i = 0; i < N; i++) {
        cout << "\ninserisci il " << i + 1 << " numero: ";
        cin >> numeri[i];
    }
}



/*funzione se il numero dell'array è minore del quadrato del numero precedente

parametri formali:
int numeri[], int N

valore restituito:
null
*/
void quadratoMinore(int numeri[], int N) {
    // dichiarazione variabili
    int i;

    // quadrato della prima cella dell'array
    numeri[0] *= numeri[0];

    for (i = 1; i < N; i++) {
        // facciamo il quadrato di ogni cella
        numeri[i] = numeri[i] * numeri[i];

        // verifica se il numero attuale è minore del numero precedente
        if (numeri[i] < numeri[i - 1]) {
            cout << "\nIl numero nella posizione " << i + 1 << " (" << numeri[i] << ") e inferiore al quadrato della cella precedente (" << numeri[i - 1] << ")\n"
                 << endl;
        }
    }
}