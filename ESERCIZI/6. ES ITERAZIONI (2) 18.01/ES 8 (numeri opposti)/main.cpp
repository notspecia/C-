/*Date N coppie di numeri contare e stampare quelle che hanno i valori l'uno l'opposto dell'altro.*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

//inserimento variabili
	int N; //numero coppie
	float n1; //primo valore
	float n2; //secondo valore
	int i; //iteratore
	int conteggio; //conteggio di quante volte sono opposti

//inizializzazione variabili
	conteggio=0;

//inserimento dati dell'user
	cout<<"quante coppie di numeri vuoi inserire?: ";
	cin>>N;

	if(N<=0) {
		cout<<"inserisci una quantita valida!"<<endl;
	} else {

//elaborazione e verifica se i numeri nelle coppie sono opposti
		for(i=0; i<N; i++) {
			cout<<"inserisci il 1^ valore: ";
			cin>>n1;
			cout<<"inserisci il 2^ valore: ";
			cin>>n2;
			
			//se si inserisce 0 e 0, non sono opposti
			if(n1==0 && n2==0) {
				cout<<"non sono opposti!"<<endl;
				cout<<endl;
			}
			
			// se i numeri sono opposti (-2,2)
			else if(n1+n2==0) {
				cout<<"sono opposti!"<<endl;
				cout<<endl;
				conteggio ++;
				
			//se i numeri non sono opposti (7,2)	
			} else {
				cout<<"non sono opposti!"<<endl;
				cout<<endl;
			}
		}
		
		//conteggio di quante volteci numeri sono opposti
		cout<<"N^ di volte il cui i numeri sono opposti: "<<conteggio;
	}

	return 0;
}