#include <iostream>
#include<string>
#define NMAXPARTECIPANTI 200
using namespace std;

//definizione delle strutture dati
struct Tempo{
	int hh;
	int mm;
	int ss;
	int totSecondi;
};

struct Partecipante{
	int pettorale;
	string nome;
	Tempo tempoImpiegato;
};

//definizione dei prototipi delle funzioni

/* Funzione:Input del numero dei partecipanti alla gara 
   Parametri formali: NULL
   Valori di ritorno: int
*/
int chiediNumPartecipanti();

/* Funzione:Input delle informazioni dei partecipanti 
   Parametri formali: Partecipante tab, int N
   Valori di ritorno: NULL
*/
void caricaTabella(Partecipante tab[], int N);

//Funzione che effettua l’ordinamento
//a secondo del tempo di arrivo
void ordina(Partecipante tab[], int N);

//Stampa a video dei risultati della gara
void stampa(Partecipante tab[], int N);

/* 
Problema:
Alla fine di una gara campestre vengono memorizzati, 
per ogni partecipante, il numero di pettorale, il nome 
e il tempo impiegato espresso in ore, minuti e secondi.
Si vuole la stampa dei partecipanti ordinati rispetto 
al tempo impiegato.
*/

int main(int argc, char** argv) {
	
	int N; //Numero di partecipanti
	// Tabella dei partecipanti alla gara
	Partecipante tabella[NMAXPARTECIPANTI];

	//Inserimento dati
	N = chiediNumPartecipanti();
	caricaTabella(tabella, N);
	
	//Ordinamento 
	ordina(tabella, N);
	
	//Stampa
	stampa(tabella, N);

	return 0;
}

/* Funzione:Input del numero dei partecipanti alla gara 
   Parametri formali: NULL
   Valori di ritorno: int
*/	
int chiediNumPartecipanti(){
	int n;
	
	do{
		cout << "Inserisci il numero dei partecipanti [max "<< NMAXPARTECIPANTI << "]: ";
		cin >> n;
	} while(n<1 || n > NMAXPARTECIPANTI);
	
	return n;
}

/* Funzione:Input delle informazioni dei partecipanti 
   Parametri formali: Partecipante tab, int N
   Valori di ritorno: NULL
*/
void caricaTabella(Partecipante tab[], int N){
	int i;
	
	cout <<"\n *** INSERIMENTO PARTECIPANTI ***\n";
	for(i=0;i<N; i++){
		
		cout << "Numero di pettorale: ";
		cin >> tab[i].pettorale;
		
		cout << "Nome del concorrente: ";
		cin >> tab[i].nome;
		
		cout << "Ore impiegate: ";
		cin >> tab[i].tempoImpiegato.hh;
		
		cout << "Minuti impiegati: ";
		cin >> tab[i].tempoImpiegato.mm;
		
		cout << "Secondi impiegati: ";
		cin >> tab[i].tempoImpiegato.ss;
		
		tab[i].tempoImpiegato.totSecondi=tab[i].tempoImpiegato.hh*3600+tab[i].tempoImpiegato.mm*60+tab[i].tempoImpiegato.ss;		
	}
}

//Funzione che effettua l'ordinamento
//a secondo del tempo di arrivo
void ordina(Partecipante tab[], int N){
	Partecipante temp;
	int i,j;
	
	//loop annidati del selection sort
	for(i=0; i< N ; i++)
		for(j=i+1; j<N;j++)
			if(tab[i].tempoImpiegato.totSecondi > tab[j].tempoImpiegato.totSecondi){
			//if(calcolaSecondi(tab[i])> calcolaSecondi(tab[j])) {
			//if( isMaggiore(tab[i]),tab[j]) ) {
			
				temp=tab[i];
				tab[i]=tab[j];
				tab[j]=temp;
			}
	
}

//Stampa a video dei risultati della gara
void stampa(Partecipante tab[], int N){
	int i;
	
	cout <<"\n *** STAMPA PARTECIPANTI ***\n";
	cout << "Pettorale\t";
	cout << "Nome\t\t";
	cout << "Tempo\n\n";
	for(i=0;i<N; i++){
		
		cout << tab[i].pettorale << "\t\t";
		cout << tab[i].nome << "\t\t";
		cout << tab[i].tempoImpiegato.totSecondi << "\n";
	}
}
