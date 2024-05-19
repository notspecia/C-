/*Si vuole stampare in output la tabella di tutte le possibili somme che si possono ottenere
lanciando due dadi con N facce (N inserito in input).
*/

#include <iostream>

using namespace std;


int main() {

	//dichiarazione variabili
	int i; 		//primo dado
	int j; 		//secondo dado
	int N; 		//numero faccie dado

	//input utente
	do {
		cout<<"quante facciate hanno i dadi?: ";
		cin>>N;
	} while(N<=0);

	//ciclo che da il numero di possibilita disponibili
	for(i=1; i<=N; i++) {
		cout << endl;
		for(j=1; j<=N; j++)
			cout << i+j << " ";
	}
	return 0;
}