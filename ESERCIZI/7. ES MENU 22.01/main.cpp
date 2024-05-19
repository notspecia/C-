#include <iostream>

using namespace std;


int main(int argc, char** argv) {

//variabili
	int opzione; //scelta del comando
	float x; //primo numero
	float y; //secondo numero
	float z; //terzo numero
	float max; //numero + alto
	float min; //numero - alto
	float media; //media dei 3 numeri
	bool tripletta; //per verificare se i numeri sono stati inseriti (vero o falso), chiamata FLAG per vedere se siamo passati una volta nell'opzione 1

//inizializzazione variabili
	tripletta=false;
	x=0;
	y=0;
	z=0;
	max=0;
	min=0;

	do {
		system("CLS");

//apparizione del menu all'utente
		cout<<"DIGITANDO 1 ti verra richiesto di inserire tre numeri."<<endl;
		cout<<"DIGITANDO 2 ti veranno stampati la tripletta di numeri."<<endl;
		cout<<"DIGITANDO 3 ti verra stampato il massimo."<<endl;
		cout<<"DIGITANDO 4 ti verra stampato il minimo."<<endl;
		cout<<"DIGITANDO 5 ti verra stampata la media dei numeri."<<endl;
		cout<<"DIGITANDO 6 ti verranno stampati i numeri in ordine crescente."<<endl;
		cout<<"DIGITANDO 7 ti verranno stampati i numeri in ordine decrescente."<<endl;
		cout<<"DIGITANDO 8 potrai uscire dal menu."<<endl;
		cout<<"----------------------------------------------------------------"<<endl;
		cout<<"DIGITANDO 0 spegnerai la macchina."<<endl;
		cout<<endl;


//inserimento opzione utente
		cout<<"scegli l'opzione: ";
		cin>>opzione;

//system cls per pulire ogni volta la schermata
		system("CLS");

//insieme di opzioni
		switch(opzione) {
			case 0:
				break;

			//inserimento numeri + cambiamento in true del booleano
			case 1:
				cout<<"inserisci il primo numero: ";
				cin>>x;
				cout<<"inserisci il secondo numero: ";
				cin>>y;
				cout<<"inserisci il terzo numero: ";
				cin>>z;
				tripletta=true;
				break;

			//stampa dei numeri (x,y,z)
			case 2:
				if(tripletta==false) {
					cout<<"inserisci dei valori ai numeri, per farlo, torna al menu e premi 1."<<endl;
				} else {
					cout<<x<<","<<y<<","<<z<<endl;
				}
				break;

			//trovato e stampato valore massimo
			case 3:
				if(tripletta==false) {
					cout<<"inserisci dei valori ai numeri, per farlo, torna al menu e premi 1."<<endl;
				} else {
					max=x;
					if(y>max) {
						max=y;
					}
					if(z>max) {
						max=z;
					}
					cout<<max<<endl;
				}
				break;

			//trovato e stampato valore minimo
			case 4:
				if(tripletta==false) {
					cout<<"inserisci dei valori ai numeri, per farlo, torna al menu e premi 1."<<endl;
				} else {
					min=x;
					if(y<min) {
						min=y;
					}
					if(z<min) {
						min=z;
					}
					cout<<min<<endl;
				}
				break;

			//media aritmetica dei numeri
			case 5:
				if(tripletta==false) {
					cout<<"inserisci dei valori ai numeri, per farlo, torna al menu e premi 1."<<endl;
				} else {
					media=(x+y+z)/3;
					cout<<media<<endl;
				}
				break;

			//stampa in ordine CRESCENTE dei numeri
			case 6:
				if(tripletta==false) {
					cout<<"inserisci dei valori ai numeri, per farlo, torna al menu e premi 1."<<endl;
				} else {
					if(x>y) {
						swap(x,y);
					}
					if(y>z) {
						swap(y,z);
					}
					if(x>y) {
						swap(x,y);
					}
					cout<<x<<","<<y<<","<<z<<endl;
				}
				break;

			//stampa in ordine DECRESCENTE DEI NUMERI
			case 7:
				if(tripletta==false) {
					cout<<"inserisci dei valori ai numeri, per farlo, torna al menu e premi 1."<<endl;
				} else {
					if(x<y) {
						swap(y,x);
					}
					if(y<z) {
						swap(z,y);
					}
					if(x<y) {
						swap(y,x);
					}
					cout<<x<<","<<y<<","<<z<<endl;
				}
				break;

			//chiedere conferma se si vuole uscire
			case 8:
				cout<<"sei sicuro di uscire? per CONFERMARE premi 0, per DECLINARE digita qualsiasi numero: ";
				cin>>opzione;
				break;

			//nel caso si inserisce un valore diverso tra 0 e 8
			default:
				cout<<"opzione inserita non valida!"<<endl;

		}
		system("pause");

	} while(opzione!=0);

	return 0;
}