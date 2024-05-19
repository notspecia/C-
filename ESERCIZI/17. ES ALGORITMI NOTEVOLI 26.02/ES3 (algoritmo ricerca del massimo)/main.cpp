/*TERZO ALGORITMO ricerca del massimo*/


#include <iostream>

using namespace std;
const int MAX = 100;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/
void leggiN(int &N, const int MAX);
void leggiNumeri(int numeri[], int N);
void ricercaMassimo(int numeri[], int N);

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
    ricercaMassimo(numeri, N);

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

/*funzione che ricerca il massimo tra tutti gli elementi dell'array

parametri formali:
int numeri[], int N

valore restituito:
null
*/
void ricercaMassimo(int numeri[], int N) {
    // dichiarazione variabili
    int i;
    int max;

    // mettiamo come massimo temporaneo il primo elemento
    max = numeri[0];

    // ciclo che controlla se un elemento dell'array supera gli altri
    for (i = 1; i < N; i++) {
        if (numeri[i] > max) {
            max = numeri[i];
        }
    }

    // stampa del numero più alto nell'array
    cout << "\n\nil numero piu alto nell'array, e: " << max;
}
