/*Riorganizzare il codice del programma di: "Gestione triplette di numeri" utilizzando le
funzioni. Per ogni opzione del menu' di scelta andare a richiamare una differente funzione.*/

#include <iostream>
#include <string>

using namespace std;


/*funzione leggi tentativo
legge un numero float
reinserire se <=0

parametri formali:
string text (per cambiare il numero del tentativo)

valore restituito:
float tentativo
*/

float leggiTentativo(string text) {

	// dichiarazione variabili
	float tentativo;

	// inserimento tentativo e controllo > 0
	cout << "inserisci il tempo del "<<text<<" tentativo: ";
	cin >> tentativo;
	while (tentativo <= 0) {
		cout << "reinserire primo tentativo: ";
		cin >> tentativo;
	}
	return tentativo;
}






/*funzione ricerca del massimo tra i numeri inseriti (3)

parametri formali:
float t1, float t2, float t3

valore restituito:
float max
*/

float ricercaMax(float t1, float t2, float t3) {

	// dichiarazione variabili;
	float max;

	// ricerca del massimo
	max = t1;
	if (t2 > max)
		max = t2;
	if (t3 > max)
		max = t3;

	return max;
}





/*funzione ricerca del minimo tra i 3 tempi

parametri formali:
float t1, float t2, float t3

valore restituito:
float min
*/

float ricercaMin(float t1, float t2, float t3) {

	// dichiarazione variabili;
	float min;

	// ricerca del minimo
	min = t1;
	if (t2 < min)
		min = t2;
	if (t3 < min)
		min = t3;

	return min;
}





/*funzione ricerca del tempo medio tra i 3 tempi

parametri formali:
float t1, float t2, float t3

valore restituito:
float Tmedio
*/

float ricercaTmedio(float t1, float t2, float t3) {
	// dichiarazione variabili
	float Tmedio;

	// inizializzazione
	Tmedio = 0;

	// calcolo Tmedio
	Tmedio = (t1 + t2 + t3) / 3;

	return Tmedio;
}





/*funzione ricerca dell'incertezza

parametri formali:
float max, float min

valore restituito:
float incertezza
*/

float ricercaIncertezza(float max, float min) {
	// dichiarazione variabili
	float incertezza;

	// inizializzazione
	incertezza = 0;

	// calcolo incertezza
	incertezza = (max - min) / 2;

    return incertezza;
}





/*funzione stampa del Tmedio e incertezza

parametri formali:
float Tmedio, float incertezza

valore restituito:
null
*/

void stampaRisultati(float Tmedio, float incertezza) {
	cout << "\nil formato completo dei 3 tentativi e di: " << Tmedio << "+-" << incertezza << " (Tmedio +- incertezza)" << endl;
}



int main() {
	// dichiarazione variabili
	float t1; //1 tempo
	float t2; //2 tempo
	float t3; //3 tempo
	float max; //il tempo + alto
	float min; //il tempo - basso
	float Tmedio; //il tempo medio
	float incertezza; //differenza tra max e min

	// lettura dei tentativi
	t1 = leggiTentativo("primo");
	t2 = leggiTentativo("secondo");
	t3 = leggiTentativo("terzo");

	// ricerca del max
	max = ricercaMax(t1, t2, t3);

	// ricerca del min
	min = ricercaMin(t1, t2, t3);

	// calcolo Tmedio
	Tmedio = ricercaTmedio(t1, t2, t3);

	// calcolo incertezza
	incertezza = ricercaIncertezza(max, min);

	// stampa incertezza e Tmedio
	stampaRisultati(Tmedio, incertezza);

	return 0;
}