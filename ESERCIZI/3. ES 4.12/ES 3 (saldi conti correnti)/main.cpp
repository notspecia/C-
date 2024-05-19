/*Si hanno in input N saldi di conti correnti bancari. Si vuole in output la media armonica dei
soli conti correnti che hanno un saldo negativo.*/

#include <iostream>

using namespace std;

int main() {
	//dichiarazione variabili
	int N; 			//quantità di conti correnti
	float CC; 		// conto corrente
	int i;			//iteratore
	float somma;	//somma dei conti correnti
	float mediaH;	//media armonica
	int saldoNeg; 	//accumulatore dei saldi negativi

	//inizializzazione variabili
	somma=0;
	mediaH=0;
	saldoNeg=0;

	//inserimento Q. di conti bancari
	do {
		cout <<"quanti conti bancari vuoi inserire?: ";
		cin>>N;
	} while(N<=0);
	cout<<endl;

	//ciclo che leggi i conti correnti
	for(i=0; i<N; i++) {
		cout<<"\ninserisci il saldo: ";
		cin>>CC;

		if(CC<0) {
			somma+=1/CC;
			saldoNeg++;
		}
	}

	//elaborazione e stampa della media armonica
	if(saldoNeg>0) {
		mediaH = saldoNeg/somma;
		cout<<"\nLa media armonica dei saldi negativi e di: "<<mediaH<<endl;

	//se non ci sono saldi negativi...
	} else {
		cout <<"\nnon hai inserito saldi negativi!"<<endl;
	}

	return 0;
}