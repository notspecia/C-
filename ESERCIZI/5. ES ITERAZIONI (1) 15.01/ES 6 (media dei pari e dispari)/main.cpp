/*Dati N numeri calcolare la media aritmetica dei valori pari e quella dei valori dispari.*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int N; //q.numeri inseriti
	int num; //numeri
	int i; //iteratore
	int pari; //contatore dei numeri pari
	int dispari; //contatore dei numeri dispari
	float sommapari; //somma dei numeri pari
	float sommadispari; //somma dei numeri dispari
	float mediapari; //media dei numeri pari
	float mediadispari; //media dei numeri dispari

    //inizializzazione variabili
	pari=0;
	dispari=0;

	sommapari=0,
	sommadispari=0;

	mediapari=0;
	mediadispari=0;

	//inserimento Q numeri da inserire
	cout<<"inserisci la quantita di numeri di inserire: ";
	cin>>N;
	
	//ciclo che controlla ogni numero e da il valore pari o dispari
	if(N>0) {

		for(i=0; i<N; i++) {

			cout<<"inserisci il "<<i+1<<" numero: ";
			cin>>num;

			if(num%2==0) {
				pari++;
				sommapari+=num;
				mediapari= sommapari/pari;
			} else {
				dispari++;
				sommadispari+=num;
				mediadispari= sommadispari/dispari;
			}
		}
		
		//stampa della media dei pari e della media dei dispari
		cout<<"la media aritmetica dei numeri pari e di: "<<mediapari<<endl<<"la media aritmetica dei numeri dispari e di: "<<mediadispari;
	} else {
		cout<<"inserisci una quantita valida!!"<<endl;
	}

	return 0;
}