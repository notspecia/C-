/*Creare una funzione che restituisca se un carattere è una vocale.
Creare un programma che faccia inserire la lunghezza di due parole (le due parole
possono avere lunghezze diverse) e poi faccia inserire le due parole un carattere alla volta.
Alla fine il programma stampa per ogni parola quante vocali contiene.
Esempio:
INPUT: lungh. prima parola: 4 lungh. seconda parola: 8
prima parola: CIAO seconda parola: RIUNIONE
OUTPUT: Vocali prima parola: 3 Vocali seconda parola: 5
Suggerimento: creare una funzione che richieda di inserire una parola e che restituisca il
numero di vocali.*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/*funzione lettura della parola

parametri formali:
text string

valore restituito:
string parola
*/
string letturaParola(string text)
{
    // dichiarazione variabili
    string parola;

    // input utente
    cout << "inserisci la " << text << " parola: ";
    getline(cin, parola);

    return parola;
}

/*funzione cicla le vocali e la parola

parametri formali:
string parola

valore restituito:
int cont
*/
int letturaVocali(string parola, int cont)
{

    // dichiarazione variabili
    int i;
    int j;
    string vocali;

    // inizializzazione variabili
    cont = 0;
    vocali = "aeiouAEIOU";

    // ciclo per trovare le vocali
    for (i = 0; i < parola.length(); i++)
    {
        for (j = 0; j < vocali.length(); j++)
        {
            if (vocali[j] == parola[i])
            {
                cont++;
            }
        }
    }
    return cont;
}

/*funzione stampa del numero di vocali

parametri formali:
int count

valore restituito:
null
*/
void stampaVocali(int cont1, int cont2)
{
    cout << "la prima parola ha in totale: " << cont1 << " vocali" << endl;
    cout << "la seconda parola ha in totale: " << cont2 << " vocali";
}

int main()
{
    // dichiarazione variabili
    string parola1; // prima parola
    string parola2; // seconda parola
    int cont1;      // conteggio delle prime vocali
    int cont2;      // conteggio delle secondi vocali

    // lettura delle 2 parole
    parola1 = letturaParola("prima");
    parola2 = letturaParola("seconda");

    // utilizzo ciclo per trovare le vocali nelle parole
    cont1 = letturaVocali(parola1, cont1);
    cont2 = letturaVocali(parola2, cont2);

    // stampa del conteggio delle vocali nelle 2 parole
    cout << endl;
    stampaVocali(cont1, cont2);

    return 0;
}