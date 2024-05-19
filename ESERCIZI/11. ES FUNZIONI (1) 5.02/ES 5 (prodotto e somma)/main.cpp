/*Creare una funzione che calcoli il prodotto e la somma tra tre numeri interi e restituisca la
differenza tra il prodotto e la somma calcolati.
Creare poi un main che consenta di usare la funzione.*/

#include <iostream>
#include <string>

using namespace std;


/*funzione leggi i numeri
legge un numero int

parametri formali:
string text

valore restituito:
int num
*/

int leggiN(string text) {

	//dichiarazione variabili
	int num;

	//input utente
	cout<<"inserisci il "<<text<<" numero: ";
	cin>>num;

	return num;
}





/*funzione calcolo della somma

parametri formali:
int num

valore restituito:
int somma
*/

int sommaNumeri(int n1, int n2, int n3) {

	//dichiarazione variabili
	int somma;

	//inizializzazione variabili
	somma=0;

	//somma dei 3 numeri
	somma=n1+n2+n3;

	//stampa somma
	cout<<"\nla somma dei tre numeri e di: "<<somma;

	return somma;
}





/*funzione calcolo del prodotto

parametri formali:
int num

valore restituito:
int prodotto
*/

int prodottoNumeri(int n1, int n2, int n3) {

	//dichiarazione variabili
	int prodotto;

	//inizializzazione variabili
	prodotto=0;

	//somma dei 3 numeri
	prodotto=n1*n2*n3;

	//stampa prodotto
	cout<<"\nil prodotto dei tre numeri e di: "<<prodotto;

	return prodotto;
}





/*funzione calcolo della differenza

parametri formali:
int prodotto, int somma

valore restituito:
int differenza
*/

int datiDifferenza(int prodotto, int somma) {

	//dichiarazione variabili
	int differenza;

	//inizializzazione variabili
	differenza=0;

	//differenza tra prodotto e somma
	differenza=prodotto-somma;

	return differenza;
}





/*funzione stampa della differenza

parametri formali:
int differenza

valore restituito:
null
*/

void stampaDifferenza(int differenza) {

	cout<<"\nla differenza tra prodotto e somma, e di: "<<differenza;

}



int main() {

	//dichiarazione variabili
	int n1; //primo numero
	int n2; //secondo numero
	int n3; //terzo numero
	int somma; //somma dei numeri
	int prodotto; //moltiplicazione dei 3 numeri
	int differenza; //differenza tra prodotto e somma

	//lettura dei 3 numeri
	n1=leggiN("primo");
	n2=leggiN("secondo");
	n3=leggiN("terzo");

	//somma dei numeri
	somma=sommaNumeri(n1,n2,n3);

	//prodotto dei numeri
	prodotto=prodottoNumeri(n1,n2,n3);

	//differenza tra prodotto e somma
	differenza=datiDifferenza(prodotto,somma);

	//stampa della differenza (prodotto-somma)
	stampaDifferenza(differenza);


	return 0;
}