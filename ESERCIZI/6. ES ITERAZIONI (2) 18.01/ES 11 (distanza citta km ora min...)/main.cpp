/*Dato un elenco di N città con la loro distanza in km da Roma, stampa il tempo impiegato da un mezzo avente velocità media di 120 km/h per raggiungere Roma*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {

	int N; //quantita di città da inserire
	float km; //distanza i kilometri
	float m; //distanza in metri
	string citta; //nome della città
	float velocita; //velocita media
	float velocitaM; //velocita in metri al secondo
	int tempoS; //quanto tempo ci mettiamo in secondi
	int ore; //tempo in ore
	int minuti; //tempo in minuti
	int secondi; //tempo in secondi
	int i; //iteratore

//inizializzazione variabili
	velocita=120;

//dati dell'user
	cout<<"quante citta vuoi inserire?: ";
	cin>>N;
	cout<<endl;

	if(N<=0) {
		cout<<"inserisci una quantita valida!!: ";

//chiediamo ora all'utente il nome della città e la sua distaza da roma (verrà convertita in metri).
	} else {
		for(i=0; i<N; i++) {

			cout<<"inserisci il nome della citta: ";
			cin>>citta;

			cout<<"quanti km dista "<<citta<<" da Roma?: ";
			cin>>km;

			if(km<=0) {
				cout<<"distanza non valida!!"<<endl;

			} else {
				m= km*1000;
				velocitaM= velocita/3.6;
				tempoS= m/velocitaM;

//ora andremo a dire all'utente quanto tempo ci metterà per arrivare a Roma (formato: ore,minuti,secondi).
				ore= tempoS/3600;
				minuti= (tempoS%3600)/60;
				secondi= tempoS%60;

//stampiamo il tempo che ci mettera per arrivare da Ncitta a Roma
				cout<<"da "<<citta<<" a Roma ci impiegherai: "<<ore<<" ore "<<minuti<<" minuti "<<secondi<<" secondi"<<endl;
			}

		}

	}

	return 0;
}