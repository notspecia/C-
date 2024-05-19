/*Date N assicurazioni di automobili definite come la coppia (importo, incidente), dove incidente vale 0 se non vi è stato un incidente oppure 1 se vi è stato almeno un incidente.
Ogni importo viene aumentato del 10% se vi è stato un incidente, altrimenti viene scontato del 6%. Calcolare la somma degli importi e stampare il risultato.*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

//inserimento variaibili
	int N; //numero assicurazioni
	int i; //iteratore
	float importo;
	int incidente;
	int SA; //sconto o aumento dell'importo
	float somma0; //somma degli importi senza incidenti
	float somma1; //somma degli importi con incidenti
	float sommaF; //somma tra gli importi con incidente e quelli senza incidente

//inizializzazione delle variabili
	somma0=0;
	somma1=0;
	sommaF=0;

//chiede quante assicuazioni bisogna verificare
	cout<<"quante assicurazioni bisogna controllare?: ";
	cin>>N;
	if(N<=0) {
		cout<<"inserisci una quantita valida!"<<endl;

//ciclo per gli importi e la loro somma
	} else {
		for(i=0; i<N; i++) {
			cout<<"\ninserisci l'importo della "<<i+1<< " assicurazione: ";
			cin>>importo;
			if(importo<=0) {
				cout<<"inserisci un importo valido!"<<endl;

//inizio calcolo degli importi se sono > 0, chiedere all'utente se ha commeso o no degli incidenti
			} else {
				cout<<"se hai non hai fatto nessun incidente premi 0, se ne hai fatto almeno uno o piu premi 1: ";
				cin>>incidente;
			}

//se non ci sono stati incidenti
			if(incidente==0) {
				SA=(importo*6)/100;
				importo-=SA;
				somma0+=importo;
				cout<<endl;

//se ci sono stati incidenti
			} else if(incidente==1) {
				SA=(importo*10)/100;
				importo+=SA;
				somma1+=importo;
				cout<<endl;

//numero errato!
			} else {
				cout<<"numero inserito non valido!"<<endl;
			}
		}

//somma finale tra il totale degli importi senza incidente e con incidente
		sommaF=somma0+somma1;
		cout<<"la somma finale tra gli importi con incidente e quelli senza incidente, e di: "<<sommaF<<endl;
	}

	return 0;
}