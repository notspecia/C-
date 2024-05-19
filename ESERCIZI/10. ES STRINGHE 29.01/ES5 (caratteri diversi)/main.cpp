/*Si abbia in input una stringa, in output si vuole sapere quanti caratteri diversi tra loro contiene la stessa.
Esempio:
Input: aababaxayz caratteri diversi tra loro: x, y, z
Output: 3 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // inserimento variabili
    string str;     // stringa
    int i;          // iteratore
    int j;          // iteratore
    int count;      // conteggio dei singoli caratteri
    bool controllo; // verifica se ci sono caratteri singoli

    // inizializzazione variabili
    count = 0;

    // input utente
    cout << "inserisci la stringa: ";
    getline(cin, str);

    // ciclo per vedere se ci sono caratteri singoli
    for (i = 0; i < str.length(); i++)
    {
        for (j = 0; j < str.length(); j++)
        {
            if (j != i && str[i] == str[j])
            {
                controllo = true;
                count++;
                break;
            }
        }
        if (controllo == false)
        {
            count++;
        }
    }
    // stampa di quanti numeri hanno 1 solo carattere
    cout << "il totale di caratteri diversi tra loro, sono: " << count;

    return 0;
}