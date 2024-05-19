/*Trovare i divisori di un numero intero positivo.*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

//inizzializzazione variabili
	int N; //numero da inserire
	int i; //iteratore

//input dell'utente
	cout<<"inserire un numero intero e positivo: ";
	cin>>N;

	if(N<=0) {
		cout<<"inserisci un numero valido!!";
	} else {

//ciclo per trovare i divisori di N
		cout<<"i divisori di "<<N<<" sono:"<<endl;
		for(i=1; i<=N; i++) {

			//ricerca e stampa dei divisori di quel numero
			if(N%i==0) {
				cout<<i<<endl;
			}
		}
	}
	return 0;
}