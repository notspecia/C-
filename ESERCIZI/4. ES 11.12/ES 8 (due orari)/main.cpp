/*Scrivere un programma che legga 2 orari in ore minuti e secondi e dica quale viene prima
dei due. (Si provi a risolvere l’esercizio senza trasformare tutto in secondi).*/

#include <iostream>

using namespace std;

int main() {

	//dichiarazione variabili
	int ora1; //prima ora
	int ora2; //seconda ora
	int min1; //primi minuti
	int min2; //secondi minuti
	int sec1; //primi secondi
	int sec2; //secondi secondi :)
	int tempo1; //il primo orario convertito totalmente in secondi
	int tempo2; //il secondo orario convertito totalmente in secondi

	//inizializzazione variabili
	tempo1=0;
	tempo2=0;


	//inserimento del primo orario

	//inserimento ora
	cout<<"inserisci le ore del primo orario: ";
	cin>>ora1;

	while(ora1<0||ora1>23) {
		cout<<"reinserisci le ore del primo orario: ";
		cin>>ora1;
	}

	//inserimento minuti
	cout<<"\ninserisci i minuti del primo orario: ";
	cin>>min1;

	while(min1<0||min1>59) {
		cout<<"reinserisci i minuti del primo orario: ";
		cin>>min1;
	}

	//inserimento secondi
	cout<<"\ninserisci i secondi del primo orario: ";
	cin>>sec1;

	while(sec1<0||sec1>59) {
		cout<<"reinserisci i secondi del primo orario: ";
		cin>>sec1;
	}

	//trasformazione e stampa 1 orario in secondi
	tempo1=(ora1*3600)+(min1*60)+sec1;
	cout<<"\nl'orario ha in totale: "<<tempo1<<" secondi\n\n";



	//inserimento secondo orario

	//inserimento ora
	cout<<"\ninserisci le ore del secondo orario: ";
	cin>>ora2;

	while(ora2<0||ora2>23) {
		cout<<"reinserisci le ore del secondo orario: ";
		cin>>ora2;
	}

	//inserimento minuti
	cout<<"\ninserisci i minuti del secondo orario: ";
	cin>>min2;

	while(min2<0||min2>59) {
		cout<<"reinserisci i minuti del secondo orario: ";
		cin>>min2;
	}

	//inserimento secondi
	cout<<"\ninserisci i secondi del secondo orario: ";
	cin>>sec2;

	while(sec2<0||sec2>59) {
		cout<<"reinserisci i secondi del secondo orario: ";
		cin>>sec2;
	}

	//trasformazione e stampa 1 orario in secondi
	tempo2=(ora2*3600)+(min2*60)+sec2;
	cout<<"\nl'orario ha in totale: "<<tempo2<<" secondi\n\n";



	//stampa di qual'è l'orario più alto
	if(tempo1>tempo2) {
		cout<<"\ntra i due orari che hai inserito, il primo orario e quello piu alto.";
	} else if(tempo1<tempo2) {
		cout<<"\ntra i due orari che hai inserito, il secondo orario e quello piu alto.";
	} else {
		cout<<"\ni due orari che hai inserito, sono uguali.";
	}

	return 0;
}