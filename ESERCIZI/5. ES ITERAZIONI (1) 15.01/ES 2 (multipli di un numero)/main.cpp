/* Si abbiano in input due numeri interi A e N. Stampare tutti i multipli di A minori di N.*/
#include <iostream>

using namespace std;


int main(int argc, char** argv) {

	int A; //primo numero
	int N; //secondo numero
	int multipli; //tiene conto dei multipli
	int i; //iteratore

	//inserimento dei 2 numeri
	cout<<"inserisci un numero (A): ";
	cin>>A;

	cout<<"inserisci un numero (N): ";
	cin>>N;

	//controllo che i due numeri non siano <=0
	if(A<=0||N<=0) {
		cout<<"inserisci numero/i valid*"<<endl;

	//se il primo numero è minore del secondo (corretto) ciclo che stampa i multipli
	} else if(A<N) {
		cout<<"i multipli di "<<A<<" inferiori di "<<N<<", sono: ";
		
		for(i=1; multipli<N; i++) {
			multipli=A*i;
			cout<<multipli<<endl;
    }
	//se il primo numero è > del secondo
	} else {
		cout<<"ERRORE"<<endl;
	}

	return 0;
}