/*Dati N numeri determinare il valore maggiore e quante volte esso ricorre.*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	int N; //quantita di numeri da inserire
	float num; //numero da inserire
	float valoremax; //il numero con il valore + alto
	int nvolte; //numero di volte del cambiamento del numero massimo
	int i; //iteratore

	//inizializzazione varibili
	nvolte=0;

	//inserimento Q. numeri
	cout<<"quanti numeri devi inserire?: ";
	cin>>N;

	if(N>0) {
		cout<<"inserisci il 1 numero: ";
		cin>>valoremax;

		//ciclo per verificare qual'è il nuovo numero + alto
		for(i=1; i<N; i++) {
			cout<<"inserisci il "<<i+1<<" numero: ";
			cin>>num;

			if(num>valoremax) {
				valoremax=num;
				nvolte++;
			}

		}

		cout<<"il valore piu alto tra i numeri che hai inserito e: "<<valoremax<<endl<<"invece, il numero di volte che e cambiato il valore massimo: "<<nvolte;

	} else {
		cout<<"inserisci una quantita valida!!";
	}
	return 0;
}