/*Progettate un algoritmo che scriva tutte le coppie di numeri naturali la cui somma è 20.*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

//inserimento variabili
	int i; //iteratore e numero
	int N; //numero 2

//inizializzazione variabili
	N=20;
	cout<<"le coppie di numeri naturali la cui somma e 20 sono:"<<endl;
	
//ciclo per le coppie di numeri
	for(i=0; i<=10; i++) {

		cout<<N<<" + "<<i<<endl;
		N--;
	}

	return 0;
}