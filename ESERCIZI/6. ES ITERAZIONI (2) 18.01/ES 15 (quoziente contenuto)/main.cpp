/*Calcolare il quoziente fra due numeri dati in input, applicando il metodo delle sottrazioni ripetute.*/

#include <iostream>

using namespace std;

int main() {

	//dichiarazione variabili
	int num1;
	int num2;
	int count;

	//inizializzazione variabili
	count=0;

	//inserimento numeri e verifica > 0
	cout<<"inserisci il primo quoziente: ";
	cin>>num1;

	while(num1<=0) {
		cout<<"reinserisci il primo quoziente (>0!): ";
		cin>>num1;
	}

	cout<<"\ninserisci il secondo quoziente: ";
	cin>>num2;

	while(num2<=0) {
		cout<<"reinserisci il secondo quoziente (>0!): ";
		cin>>num2;
	}

	//aumenenta il counter(quante volte è contenuto n2) fino a quando n1>n2
	while(num1>=num2) {
		count++;
		num1-=num2;
	}

	cout<<"\nil quoziente2 in quoziente1, e contenuto "<<count<<" volte"; 






	return 0;
}