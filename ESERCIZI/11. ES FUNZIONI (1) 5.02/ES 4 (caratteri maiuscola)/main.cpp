/*Progettare una funzione che verifichi se il carattere dato in input sia una lettera maiuscola.
Creare un programma che faccia inserire all’utente tre caratteri e stampi quale di questi sia
maiuscolo. Stampare anche il numero totale dei caratteri maiuscoli.*/

#include <iostream>
#include <string>
using namespace std;


/*funzione inserimento di un carattere

parametri formali:
string text

valore restituito:
char C
*/

char leggiChar(string text) {

	//dichiarazione variabili
	char C;

	//inserimento char1
	cout<<"inserisci il "<<text<<" carattere: ";
	cin>>C;
	cout<<endl;

	return C;
}





/*funzione stampa e conteggio delle maiuscole

parametri formali:
char C

valore restituito:
int count
*/

int maiuscolaOminuscola(char C, int count) {

	//controllo se tra i caratteri inseriti ci sono maiuscole o minuscole
	if(isupper(C)) {
		cout<<C<<endl;
		count++;
	}
	return count;
}





/*funzione stampa della Quantità di maiuscole

parametri formali:
int count

valore restituito:
null
*/

void stampaMaiuscola(int count) {

	//stampa della Q di maiuscole
	cout<<"\nil numero di maiuscole e: "<<count;
}


int main() {

	//dichiarazione variabili;
	char C1; //primo carattere
	char C2; //secondo carattere
	char C3; //terzo carattere
	int count; //coteggio delle maiuscole

	//inizializzazione variabili
	count=0;

	//lettura dei caratteri
	C1=leggiChar("prima");
	C2=leggiChar("seconda");
	C3=leggiChar("terza");

	//elaborazione e stampa di maiuscole minuscole
	count=maiuscolaOminuscola(C1,count);
	count=maiuscolaOminuscola(C2,count);
	count=maiuscolaOminuscola(C3,count);

	//stampa maiuscole
	stampaMaiuscola(count);

	return 0;
}