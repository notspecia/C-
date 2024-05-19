/*Si abbia in input un numero intero positivo N . In output si vuole il fattoriale di N.
Fattoriale di n: Definizione: n! = n(n-1)(n-2)...2*1 ; 0! = 1 esempio: 4! = 4*3*2= 24*/

#include <iostream>

using namespace std;

int main() {
	//dichiarazione delle variabili
	int n; //numero da inserire
	int nfattoriale; //numero fattoriale
	int i; //iteratore
	
	//Inserimento dati
	do {
		cout << endl<<"Inserisci n >= 0 : ";
		cin >> n;
	} while(n<0);
	
	// calcolo fattoriale
	nfattoriale=1;
	for(i=1; i<=n; i++)
		nfattoriale *= i;
		
	// stampa risultato
	cout << endl << n <<"! = " << nfattoriale;
	return 0;
}
