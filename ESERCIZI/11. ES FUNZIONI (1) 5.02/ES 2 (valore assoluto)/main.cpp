/*Creare una funzione che calcoli e restituisca il valore assoluto di un numero intero.
Nel programma main andare a provare la funzione implementata provandola con due numeri
differenti.*/

#include <iostream>
#include <string>

using namespace std;





/*funzione legge i numeri

parametri formali:
string text

valore restituito:
int num
*/

int leggiNum(string text) {

	//dichiarazione variabili
	int num;

	//input inserimento numero
	cout<<"inserisci il "<<text<<" numero: ";
	cin>>num;

	return num;

}





/*funzione elabora num1, num2 e stampa valore assouluto

parametri formali:
int num

valore restituito:
null
*/

void controlloNum(int pluto) {


	//nel caso il numero è positivo
	if(pluto>=0) {
		cout<<"\nil valore assoulto e: "<<pluto;

	//nel caso il numero è negativo:
	} else {
	 	pluto *= -1;
		cout<<"\nil valore assoluto e: "<<pluto;
	}
}





int main() {

	//dichiarazione variabili
	int num1; //1 numero
	int num2; //2 numero

	//lettura numero
	num1=leggiNum("primo");
	num2=leggiNum("secondo");

	//controllo e stampa, se il numero è negativo trasformazione in positivo
	controlloNum(num1);
	controlloNum(num2);

	return 0;
}