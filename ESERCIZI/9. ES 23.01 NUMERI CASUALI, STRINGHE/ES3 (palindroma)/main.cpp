/*Data una stringa in input indicare in output se la stringa e palindorma oppore no.

Esempio:
input: ANNA output: PALINDROMA
input: CIAO output: NON PALINDROMA*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;   // prima stringa
    string str2;  // seconda stringa

    // input utente
    cout << "Inserisci la stringa per vedere se è palindorma:";
    getline(cin, str);

    // mettiamo le 2 stringhe uguali
    str2 = str;

    // funzione per invertire la frase (marco -> ocram)
    reverse(str.begin(), str.end());

    if (str2 == str) {
        cout << "è palindroma";
    } else {
        cout << "non è palindroma";
    }

    return 0;
}