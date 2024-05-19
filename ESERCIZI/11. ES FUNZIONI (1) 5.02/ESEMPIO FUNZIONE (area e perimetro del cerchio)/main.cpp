#include <iostream>

using namespace std;


/*funzione leggi raggio
legge un numero float
reinserire se <=0

parametri formali:
null

valore restituito:
float raggio
*/

float leggiRaggio() {

	//dichiarazione variabili
	float raggio;

	//inserimento raggio e verifica se > 0
	cout<<"inserisci il raggio: ";
	cin>>raggio;

	while(raggio<=0) {
		cout<<"reinserire valore>0: ";
		cin>>raggio;
	}

	//restituisci il valore alla variabile "raggio"
	return raggio;
}





/*funzione calcolo del perimetro

parametri formali:
float raggio del cerchio

valore restituito:
float perimetro del cerchio

*/

float calcoloPerimetro(float raggio) {

	//dichiarazione variabili
	float perimetro;

	//calcolo del perimetro
	perimetro=2*raggio*3.1415;

	//restituisce il valore alla variabile "perimetro"
	return perimetro;

}





/*funzione calcolo dell'area

parametri formali:
float raggio del cerchio

valore restituito:
float area del cerchio
*/

float calcoloArea(float raggio) {

	//dichiarazione variabili
	float area;

	//calcolo dell'area
	area=raggio*raggio*3.1415;

	//restituisce il valore alla variabile "area"
	return area;

}





/*funzione stampa del perimetro e dell'area

parametri formali:
float perimetro
float area

valore restituito:
null

void non restituisce il valore
*/

void stampaRisultati(float perimetro, float area) {

	cout<<"\nil perimetro del cerchio e di: "<<perimetro<<endl;
	cout<<"l'area del cerchio e di: "<<area<<endl;
}





int main() {
	
	//DICHIARAZIONE
	float raggio; 	 //raggio del cerchio
	float perimetro; //perimetro del cerchio
	float area; 	 //area del cerchio;

	//INPUT UTENTE
	raggio=leggiRaggio();

	//ELABORAZIONE E CALCOLI (perimetro ed area)

	perimetro = calcoloPerimetro(raggio); /*all'interno delle parentesi del main, se vogliamo EX:
	calcolare il perimetro, dobbiamo richiamare per forza il raggio, altrimenti è impossibile*/

	area = calcoloArea(raggio);

	//STAMPA DI PERIMETRO E AREA

	stampaRisultati(perimetro,area); /*non bisogna per forza effettuare delle operazioni nelle funzioni
	che alla fine ridanno indietro un valore*/

	return 0;
}