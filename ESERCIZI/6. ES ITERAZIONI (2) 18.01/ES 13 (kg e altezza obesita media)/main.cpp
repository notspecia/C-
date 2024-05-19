/*Date N persone, di ciascuna sono dati il peso (kg) e l'altezza (m). Calcolare per ognuna l'indice di massa corporea (IMC) secondo la seguente formula: obesità = peso / altezza^2.
Si conti man mano il numero di quelle persone che hanno IMC maggiore di un valore K dato in input.*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

//inserimento variabili
	int N; //numero persone
	float kg; //peso della persona
	float m; //altezza della persona
	int i; //iteratore
	float IMC; //indice di massa corporea
	float k; //valore da comparare all'IMC
	int cont; //conteggio delle persone che hanno un IMC>k

//inizializzazione variabili
	IMC=0;
	cont=0;

//input utenti
	cout<<"inserisci il numero di persone: ";
	cin>>N;

	if(N<=0) {
		cout<<"inserisci una quantita valida!!"<<endl;

	} else {
		cout<<"\ninserisci la media della massa corporea generale: ";
		cin>>k;

//inizio ciclo che richiede peso e altezza delle persone
		for(i=0; i<N; i++) {

			cout<<"\ninserisci il peso della "<<i+1<<" persona(kg): ";
			cin>>kg;
			cout<<"inserisci l'altezza della "<<i+1<<" persona(m): ";
			cin>>m;
			
			//calcolo IMC
			IMC= kg/(m*m);
			cout<<"IMC della "<<i+1<<"^ persona, e pari a: "<<IMC<<endl;
			
			//se l'IMC di quella persona è maggiore alla media generale... +1
			if(IMC>k) {
				cont++;
			}
		}

//stampaggio di quante persone hanno un imc>k
		cout<<"\ndopo aver calcolato l'IMC di "<<N<<" person*, possiamo dire che "<<cont<<" persone hanno un IMC superiore rispetto alla media generale."<<endl;
	}
	return 0;
}