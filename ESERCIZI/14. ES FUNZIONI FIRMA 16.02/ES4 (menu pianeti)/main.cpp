/*Creare una funzione che data l’altezza calcoli in quanto tempo un oggetto cade al livello
del suolo. Si faccia in modo che la funzione possa operare con la gravità del pianeta in cui
ci si trova.

Si crei una funzione per impostare il pianeta in cui ci si trova:
● passando 0 ci si troverà sulla Terra (g =9,81 m/s^2),
● passando 1 ci si troverà sulla Luna (g= 1,62 m/s^2),
● passando 2 ci si troverà su Marte (g = 3,71 m/s^2),
passando altri valori ci si troverà sempre sulla Terra.

Creare un programma in cui si chiede all’utente il pianeta in cui ci si trova (puoi
implementare un menù di scelta), l’altezza (in metri) .
Stampare in output il tempo (in secondi) che impiegherà per arrivare al suolo.

Suggerimento: si utilizzi la seguente formula per calcolare il tempo di caduta dell'oggetto:
tempo = sqrt(2*altezza/g) g è l'accelerazione di gravità
*/

#include <cmath>
#include <iostream>
#include <string>
using namespace std;


/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

int leggiMenu();
void leggiAltezza(double &);
void calcoloTempo(double, double);



/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main() {
    // dichiarazione variabili
    double altezza;  // altezza registrata dall'utente
    double g;        // gravità del pianeta
    int menu;        // interfaccia menu

    // opzioni menu di scelta
    menu = leggiMenu();
    switch (menu) {
        // TERRA
        case 0:
            leggiAltezza(altezza);
            g = 9.81;
            calcoloTempo(altezza, g);
            break;

        // LUNA
        case 1:
            leggiAltezza(altezza);
            g = 1.62;
            calcoloTempo(altezza, g);
            break;

        // MARTE
        case 2:
            leggiAltezza(altezza);
            g = 3.71;
            calcoloTempo(altezza, g);
            break;

        // se inserisce un numero al di fuori della scelta (TERRA)
        default:
            leggiAltezza(altezza);
            g = 9.81;
            calcoloTempo(altezza, g);
            break;
    }
    return 0;
}



/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che apre il menu di scelta

parametri formali:
null

valore restituito:
int scelta
*/
int leggiMenu() {
    // dichiarazione variabile
    int scelta;

    // schermata menu
    cout << "\nDIGITANDO 0 ci si trovera sulla terra." << endl;
    cout << "DIGITANDO 1 ci si trovera sulla luna." << endl;
    cout << "DIGITANDO 2 ci si trovera su marte." << endl;
    cout << "DIGITANDO qualsiasi numero ci si trovera sulla terra.\n"
         << endl;

    // inserimento scelta
    cout << "scegli su che pianeta vivi: ";
    cin >> scelta;
    cout << "---------------------------------------------------------" << endl;

    return scelta;
}



/*funzione che legge e restituisce l'altezza

parametri formali:
null

valore restituito:
double &altezza
*/
void leggiAltezza(double &altezza) {
    // inserimento dell'altezza
    cout << "\ninserisci l'altezza (m): ";
    cin >> altezza;
    while (altezza <= 0) {
        cout << "reinserisci l'altezza (m >0!): ";
        cin >> altezza;
    }
}



/*funzione che calcola e stampa il tempo che ci impiega l'oggetto a cadere su suolo del pianeta

parametri formali:
double altezza, double g

valore restituito:
null
*/
void calcoloTempo(double altezza, double g) {
    // dichiarazione variabili
    double tempo;  // tempo che ci impiega a cadere l'oggetto (secondi)

    // calcolo del tempo
    tempo = sqrt(2 * altezza / g);

    // stampa del tempo impiegato (secondi)
    cout << "\nl'oggetto ci impiega per toccare il suolo: " << tempo << " second*";
}

