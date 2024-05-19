/* inserisci un numero e di all'utente se è pari o dispari*/

#include <iostream>

using namespace std;

/*funzione leggi numero
legge un numero intero
reinserire se <=0

parametri formali:
null

valore restituito:
int numero*/

int numUser() {

	// dichiarazione variabili
	int num;

	// inserimento numero + controllo se numero > 0
	cout << "inserisci un numero: ";
	cin >> num;

	while (num <= 0) {
		cout << "inserisci un numero >0!: ";
		cin >> num;
	}

	return num;
}





/*funzione per capire se num è pari o dispari
legge un booleano

parametri formali:
int num

valore restituito:
bool controllo
*/

bool pariDispari(int num) {

	// dichiarazione variabili
	bool controllo;

	// inizializzazione variabili
	controllo = false;

	// verifica se il num è pari o dispari
	if (num % 2 == 0) {
		controllo = true;
	}

	return controllo;
}





/*funzione stampa se il numero è pari o dispari

parametri formali:
bool controllo

valore restituito:
null
*/

void stampaRisultati(bool controllo) {
	if (controllo == false) {
		cout << "il numero che hai inserito, e dispari.";
	} else if (controllo == true) {
		cout << "il numero che hai inserito, e pari.";
	}
}



int main() {

	// dichiarazione variabili
	int num;
	bool controllo;

	// lettura del numero
	num = numUser();

	// verifica se il numero è pari o dispari
	controllo = pariDispari(num);

	// stampa
	stampaRisultati(controllo);

	return 0;
}