/*Chiedere in input un numero N. Stampare i numeri pari minori di N.*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	int N; //numero inserito
	int i; //iteratore
	
	//inserimento numero
	cout<<"inserisci un numero: ";
	cin>>N;

	cout<<"i numeri minori di "<<N<<" e che sono pari,sono: "<<endl;
	
	//ciclo che stampa i numeri < N pari
	for(i=0; i<N; i+=2) {
		cout<<i<<endl;
	}
	
	return 0;
}