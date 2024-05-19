/*Creare una funzione che calcoli il fattoriale di un numero.
Il programma principale presenta un menu’ di scelta con tre opzioni:
1. Chiede due numeri naturali N e M in input (N < M)
2. Stampa del fattoriale della differenza M-N
3. Stampa il fattoriale dei numeri compresi tra N e M
4. Uscita */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;



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
    cout << "\nDIGITANDO 1 ti verra chiesto di inserire 2 numeri naturali." << endl;
    cout << "DIGITANDO 2 ti verra stampatato il fattoriale della differenza (M-N)." << endl;
    cout << "DIGITANDO 3 ti verra stampato il fattoriale dei numeri compresi tra N e M." << endl;
    cout << "DIGITANDO 4 potrai uscire dal menu.\n"
         << endl;

    // inserimento scelta
    cout << "scegli cosa vuoi fare: ";
    cin >> scelta;

    return scelta;
}





/*funzione che legge i numeri naturali

parametri formali:
int scelta

valore restituito:
int N, int M
*/
int leggiNumero(string text) {
    // dichiarazione variabile
    int num;

    // inserimento numero
    cout << "\ninserisci il " << text << " numero naturale: ";
    cin >> num;
    while (num < 0) {
        cout << "reinserisci il " << text << " numero naturale (>0!): ";
        cin >> num;
    }
    return num;
}





/*funzione che stampa il fattoriale della differenza tra M - N

parametri formali:
int scelta
int N, int M

valore restituito:
null
*/
void leggiDifferenza(int N, int M) {
    // dichiarazione variabili
    int differenza;
    int fattoriale;
    int i;

    // inizializzazione variabili
    differenza = 0;
    fattoriale = 1;

    // calcolo differenza
    differenza = M - N;

    // calcolo fattoriale
    for (i = 1; i <= differenza; i++)
        fattoriale *= i;

    // stampa risultato
    cout << differenza << "! = " << fattoriale << endl;
}





/*funzione che stampa i fattoriali dei numeri compresi tra N ed M

parametri formali:
int scelta
int N, int M

valore restituito:
null
*/
void leggiNumerifatt(int N, int M) {
    // dichiarazione variabili
    int j;
    int fattoriale;
    int i;

    // inizializzazione variabili
    j = 0;
    i = N;

    // cicli per stampare i fattoriali dei numeri COMPRESI tra N ed M
    for (i; i <= M; i++) {
        int fattoriale = 1;
        for (j = 1; j <= i; j++) {
            fattoriale *= j;
        }
        cout << i << "! = " << fattoriale << endl;
    }
}



int main() {
    // dichiarazione variabili
    int menu;        // schermata menu
    int N;           // primo numero
    int M;           // secondo numero
    bool controllo;  // controllo se prima si inseriscono i numeri
    bool flag;       // se confermi l'uscita o meno

    // inizializzazione variabili
    flag = false;
    controllo = false;

    do {
        // opzioni menu di scelta
        menu = leggiMenu();

        // in base alla scelta effettuata dell'utente
        switch (menu) {
            
            // inserimento dei 2 numeri naturali (N ed M)
            case 1:
                N = leggiNumero("primo (N)");
                M = leggiNumero("secondo (M)");
                if (N > M) {
                    cout << "M deve essere > di N!, reinserisci\n";
                } else {
                    controllo = true;
                }
                break;

            // stampa fattoriale differenza tra N ed M
            case 2:
                if (controllo == false) {
                    cout << "inserisci prima i numeri naturali!\n";
                } else {
                    leggiDifferenza(N, M);
                }
                break;

            // stampa fattoriali numeri compresi tra N ed M
            case 3:
                if (controllo == false) {
                    cout << "inserisci prima i numeri naturali!\n";
                } else {
                    leggiNumerifatt(N, M);
                }
                break;

            // uscita dal menu
            case 4:
                flag = true;
                break;

            // se inserisce un numero al di fuori della scelta
            default:
                cout << "inserisci una scelta valida!\n";
        }

    } while (flag != true);

    return 0;
}
