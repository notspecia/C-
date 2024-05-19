/*Dati N numeri contare quanti sono positivi, negativi e uguali a zero.*/

#include <iostream>

using namespace std;


int main(int argc, char** argv) {
	int N; //quantita di numeri
	float num; //numero inserito
	int positivo; //q. numeri positivi
	int negativo; // q. numeri negativi
	int uguale; //q.numeri uguali a 0
	int i; //iteratore


//inizilizzazione delle variabili
	positivo=0;
	negativo=0;
	uguale=0;

	cout<<"quanti numeri vuoi inserire?: ";
	cin>>N;

	if(N>0) {

		for(i=0; i<N; i++) {
			cout<<"inserisci il "<<i+1<< " numero: ";
			cin>>num;

			if(num>0) {
				positivo++;
			} else if(num<0) {
				negativo++;
			} else {
				uguale++;
			}
		}
		
		cout<<"hai inserito "<<N<<" numeri"<<endl<<"i numeri positivi sono: "<<positivo<<endl<<"i numeri negativi sono: "<<negativo<<endl<<"i numeri uguali a 0 sono: "<<uguale;
	} else {
		cout<<"inserisci una quantita valida!!";
	}
	return 0;
}