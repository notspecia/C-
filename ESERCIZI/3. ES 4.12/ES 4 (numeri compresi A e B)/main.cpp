/*Si hanno in input due numeri reali A e B e una successione di numeri reali che termina con
il valore 0. Si vuole in output la somma dei soli numeri compresi tra A e B*/

#include <iostream>

using namespace std;

int main() {

	//dichiarazione variabili
	int A;		//primo valore
	int B;		//secondo valore
	int somma;  //somma dei numeri compresi tra A e B
	int numeri; //sequenza numeri reali
	bool flag;  //diventa vero con '0'

	//inizializzazione variabili
	flag=false;
	somma=0;

	//input utente
	cout<<"inserisci il primo valore (A): ";
	cin>>A;

	cout<<"inserisci il secondo valore (B): ";
	cin>>B;

	//inserimento dei numeri reali
	while(flag==false) {

		cout<<"\ninserisci dei numeri reali (termina l'inserimento se premi 0): ";
		cin>>numeri;

		if(numeri==0) {
			flag=true;

		} else if(numeri>= A && numeri <=B) {
			somma+=numeri;
		}
	}

	//stampa della somma dei valori compresi tra A e B
	cout<<endl<<"\nla somma dei numeri che hai inserito compresi tra A e B, sono: "<<somma;

	return 0;
}