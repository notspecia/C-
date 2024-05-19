/*QUARTO ALGORITMO ordina numeri ordine crescente*/

#include <algorithm>
#include <iostream>

using namespace std;
const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void spostaElementi(int numeri[], int N);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main() {
    // dichiarazione variabili
    int numeri[MAX];
    int N;

    // funzione che legge la dimensione dell'array
    leggiN(N, MAX);

    // funzione che legge i numeri dell'array
    leggiNumeri(numeri, N);

    // funzione che cicla ogni elemento e contolla se = K
    spostaElementi(numeri, N);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che legge il numero N (1-15) inserito dall'user

parametri formali:
int &N, const int MAX

valore restituito:
null
*/
void leggiN(int &N, const int MAX) {
    do {
        cout << "\ninserisci quanti numeri vuoi registrare nell'array (1-100): ";
        cin >> N;
    } while (N < 1 || N > MAX);
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

/*funzione che ordina in ordine crescente gli elementi dell'array

parametri formali:
int numeri[], int N

valore restituito:
null
*/
void spostaElementi(int numeri[], int N) {
    // dichiarazione variabili
    int i;
    int j;
    
    // ciclo che ordina in modo crescente gli elementi dell'array
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (numeri[i] > numeri[j]) {
                swap(numeri[i], numeri[j]);
            }
        }
    }

    // ciclo che stampa i numeri dell'array ordinati in ordine crescente
    cout << "\n\necco gli elementi dell'array riordinati: ";
    for (i = 0; i < N; i++) {
        cout << numeri[i] << "  ";
    }
}
