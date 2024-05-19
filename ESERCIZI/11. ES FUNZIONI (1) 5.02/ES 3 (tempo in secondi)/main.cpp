/*Creare una funzione che riceva una quantità di tempo in formato ore, minuti e secondi e la
restituisca espressa solamente in secondi.
Creare un programma principale che chieda in input all’utente due quantità di tempo e
stampi in output quale quantità di tempo è maggiore.*/

#include <iostream>
#include <string>

using namespace std;



/*funzione lettura dell'ora

parametri formali:
string text

valore restituito:
int ore
*/

int letturaOre(string text) {

	//dichiarazione variabili
	int ore;

	//input utente e controllo che ore <0 >24
	cout<<"\ninserisci le ore del "<<text<<" orario: ";
	cin>>ore;

	while(ore<0||ore>23) {
		cout<<"reinserisci le ore del "<<text<<" orario: ";
		cin>>ore;
	}

	return ore;
}





/*funzione lettura dei minuti

parametri formali:
string text

valore restituito:
int min
*/

int letturaMin(string text) {

	//dichiarazione variabili
	int min;

	//input utente e controllo che minuti <0 >60
	cout<<"\ninserisci i minuti del "<<text<<" orario: ";
	cin>>min;

	while(min<0||min>59) {
		cout<<"reinserisci i minuti del "<<text<<" orario: ";
		cin>>min;
	}

	return min;
}





/*funzione lettura dei secondi

parametri formali:
string text

valore restituito:
int sec
*/

int letturaSec(string text) {

	//dichiarazione variabili
	int sec;

	//input utente
	cout<<"\ninserisci i secondi del "<<text<<" orario: ";
	cin>>sec;

	while(sec<0||sec>59) {
		cout<<"reinserisci i secondi del "<<text<<" orario: ";
		cin>>sec;
	}

	return sec;
}



/*funzione calcolo e trasformazione dell'orario in secondi

parametri formali:
int ore, int min, int sec

valore restituito:
int tempo
*/

int calcoloOrario(int ore, int min, int sec) {

	//dichiarazione variabili
	int tempo;

	//calcolo e conversione orario in secondi
	tempo=(ore*3600)+(min*60)+sec;

	//stampa dei secondi totali
	cout<<"l'orario ha in totale: "<<tempo<<" secondi\n\n";

	return tempo;

}





/*funzione stampa dell'orario piu alto

parametri formali:
int tempo1, int tempo2

valore restituito:
null
*/

void tempoMaggiore(int tempo1, int tempo2) {

	//stampa di quale tempo è maggiore, o se sono uguali
	if(tempo1>tempo2) {
		cout<<"\ntra i due orari che hai inserito, il primo orario e quello piu alto.";
	} else if(tempo1<tempo2) {
		cout<<"\ntra i due orari che hai inserito, il secondo orario e quello piu alto.";
	} else {
		cout<<"\ni due orari che hai inserito, sono uguali.";
	}
}





int main() {

	//dichiarazione variabili
	int ora1; //prima ora
	int ora2; //seconda ora
	int min1; //primi minuti
	int min2; //secondi minuti
	int sec1; //primi secondi
	int sec2; //secondi secondi
	int tempo1; //il primo orario convertito totalmente in secondi
	int tempo2; //il secondo orario convertito totalmente in secondi

	//lettura primo orario
	ora1=letturaOre("1°");
	min1=letturaMin("1°");
	sec1=letturaSec("1°");
	cout<<endl;

	//trasformazione 1 orario in secondi (completamente)
	tempo1=calcoloOrario(ora1, min1, sec1);


	//lettura secondo orario
	ora2=letturaOre("2°");
	min2=letturaMin("2°");
	sec2=letturaSec("2°");
	cout<<endl;

	//trasformazione 2 orario in secondi (completamente)
	tempo2=calcoloOrario(ora2, min2, sec2);


	//stampa di qual'è l'orario con piu secondi
	tempoMaggiore(tempo1, tempo2);

	return 0;
}