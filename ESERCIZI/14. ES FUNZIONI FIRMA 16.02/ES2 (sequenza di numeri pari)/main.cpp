/*Si legga una sequenza di numeri. Terminare la lettura quando si incontra un numero
dispari. In output si stampa quanti numeri sono stati letti e quanti fra essi sono risultati
diversi da zero.*/

#include <iostream>
using namespace std;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/
void sequenzaNumeri(bool &, int &, int &);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/
int main() {
    // dichiarazione variabili
    bool controllo;  // quando mettiamo un numero dispari usciamo dal programma
    int count;       // conteggio dei numeri pari
    int count2;      // conteggio totale dei numeri letti

    // inizializzazione variabili
    controllo = false;
    count = 0;
    count2 = 0;

    // conteggio di sequenza di numeri che termina con num dispari
    do {
        sequenzaNumeri(controllo, count, count2);

    } while (controllo != true);

    // stampa delle quantità di numeri pari ed = 0
    cout << "\n\nin totale sono stati letti: " << count2 << " numeri, la quantita di numeri pari e /=0 sono: " << count;
    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che controlla se il numero è pari/dispari/ =0

parametri formali:
int &controllo, int &count, int &count2

valore restituito:
null
*/
void sequenzaNumeri(bool &controllo, int &count, int &count2) {
    // dichiarazione variabili
    int num;

    // inserimento numero e verifica se è pari dispari o = 0
    cout << "inserisci numero: ";
    cin >> num;
    if (num == 0) {
        count2++;
    } else if (num % 2 == 0) {
        count++;
        count2++;
    } else {
        count2++;
        controllo = true;
    }
}