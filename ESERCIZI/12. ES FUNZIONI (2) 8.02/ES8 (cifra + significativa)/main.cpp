/*Creare una funzione che calcoli la cifra più significativa di un numero intero.
Quindi nel programma principale leggere due numeri interi verificando se la cifra più
significativa del prodotto dei due numeri è minore di quella della loro somma.
Esempio: primo numero: 325 secondo numero 1216
prodotto: 3*1= 3 Somma: 3+1=4 minore è il prodotto.
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;




/*funzione che legge i numeri inseriti

parametri formali:
string text

valore restituito:
int numero
*/
int leggiNumero(string text) {

    // dichiarazione variabili
    int numero;

    // input utente
    cout << "inserisci il " << text << " numero: ";
    cin >> numero;

    return numero;
}





/*funzione legge il valore piu significativo dei numeri

parametri formali:
int numero

valore restituito:
int numero(solo una cifra)
*/
int valoreSignificativo(int numero) {

    // ciclo che prende il valore minore
    while (numero >= 10 || numero <= -10) {
        numero = numero / 10;
    }
    return numero;
}





/*funzione che fa la somma dei valori+significativi

parametri formali:
int numero

valore restituito:
int somma
*/
int sommaNumeri(int numero1, int numero2) {
    // dichiarazione variabili
    int somma;

    // inizializzazione variabili
    somma = 0;

    // calcolo somma
    somma = numero1 + numero2;

    return somma;
}





/*funzione che fa il prodotto dei valori + significativi

parametri formali:
int numero

valore restituito:
int prodotto
*/
int prodottoNumeri(int numero1, int numero2) {
    // dichiarazione variabili
    int prodotto;

    // inizializzazione variabili
    prodotto = 0;

    // calcolo somma
    prodotto = numero1 * numero2;

    return prodotto;
}





/*funzione che stampa il minore tra somma e prodotto

parametri formali:
int numero

valore restituito:
null
*/
void stampaMinore(int somma, int prodotto) {
    if (somma < prodotto) {
        cout << "\nla somma (" << somma << ") e MINORE rispetto al prodotto (" << prodotto << ")";
    } else {
        cout << "\nil prodotto (" << prodotto << ") e MINORE rispetto alla somma (" << somma << ")";
    }
}




int main() {
    // dichiarazione variabili
    int n1;       //1 numero
    int n2;       //2 numero
    int somma;    //somma dei 2 numeri
    int prodotto; //prodotto dei 2 numeri

    // leggi i 2 numeri inseriti
    n1 = leggiNumero("primo");
    n2 = leggiNumero("secondo");

    // prendi la cifra piu significativa di ogni numero
    n1 = valoreSignificativo(n1);
    n2 = valoreSignificativo(n2);

    // somma delle cifre + significative
    somma = sommaNumeri(n1, n2);

    // prodotto delle cifre + significative
    prodotto = prodottoNumeri(n1, n2);

    // stampa del risultato minore tra somma e prodotto
    stampaMinore(somma, prodotto);

    return 0;
}