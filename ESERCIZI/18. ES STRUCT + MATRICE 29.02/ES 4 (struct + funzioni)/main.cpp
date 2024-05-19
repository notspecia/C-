/*Rappresentare con una struttura le informazioni di una città: nome, numero di abitanti
attuale e numero di abitanti dello scorso anno. Costruire una funzione che permetta di
calcolare l’incremento (o decremento) degli abitanti. Scrivere un programma che permetta
di testare la funzione progettata, comprensivo di inserimento dati.
*/

#include <iostream>
#include <string>
using namespace std;

/*							     STRUCTS
--------------------------------------------------------------------*/

struct citta {
    string nome;
    int abitantiAttuali;
    int abitantiPrecedenti;
};


/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

void inserimentoDati(string nome, int &abitantiAttuali, int &abitantiPrecedenti);
void calcoloDifferenza(int abitantiAttuali, int abitantiPrecedenti, int &differenza);
void popolazioneNew(int differenza);


/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main() {
    // dichiarazione variabili
    citta citta;
    int differenza;  // differenza tra la popolazione attuale e quella dell'anno scorso

    // funzione che ci permette di inserire i dati della città (nome, abitOra, abitPrima)
    inserimentoDati(citta.nome, citta.abitantiAttuali, citta.abitantiPrecedenti);

    // funzione che calcola la differenza tra le popolazioni in differenti archi di tempo
    calcoloDifferenza(citta.abitantiAttuali, citta.abitantiPrecedenti, differenza);

    // funzione che stampa se c'è stato un incremento o un decremento della popolazione
    popolazioneNew(differenza);

    return 0;
}


/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che ci permette di inserire i dati della città (nome, abitOra, abitPrima)

parametri formali:
string nome, int &abitantiAttuali, int &abitantiPrecedenti,

valore restituito:
null
*/
void inserimentoDati(string nome, int &abitantiAttuali, int &abitantiPrecedenti) {
    cout << "\ninserisci il nome della citta: ";
    getline(cin, nome);

    // ciclo che chiede di inserire gli abitanti attuali e precedenti, + verifica che gli abitanti siano >= a 0
    do {
        cout << "\ninserisci il numero di abitanti attuale: ";
        cin >> abitantiAttuali;

        cout << "\ninserisci il numero di abitanti dell'anno scorso: ";
        cin >> abitantiPrecedenti;

    } while (abitantiAttuali < 0 || abitantiPrecedenti < 0);
}



/*funzione che calcola la differenza tra le popolazioni in differenti archi di tempo

parametri formali:
int abitantiAttuali, int abitantiPrecedenti, int &differenza

valore restituito:
null
*/
void calcoloDifferenza(int abitantiAttuali, int abitantiPrecedenti, int &differenza) {
    // inizializzazione delle variabili
    differenza = 0;

    // differenza della popolazione attuale e quella dell'anno scorso
    differenza = abitantiAttuali - abitantiPrecedenti;
}



/*funzione che stampa se c'è stato un incremento o un decremento della popolazione

parametri formali:
int differenza

valore restituito:
null
*/
void popolazioneNew(int differenza) {
    cout << "\n\n------------------------------------------------------------------";

    if (differenza == 0) {
        cout << "\nla popolazione è rimasta invariata";
    } else if (differenza > 0) {
        cout << "\nc'è stato un incremento della popolazione di " << differenza <<" persone";
    } else {
        cout << "\nc'è stato un decremento della popolazione di " << differenza << " persone";
    }
}