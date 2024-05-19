/*n pos verifica se non ce*/

/*Si abbiano in input due stringhe, in output si vuole sapere quante volte la seconda stringa è contenuta nella prima.*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // inserimento variabili
    string str;  // prima parola
    string str2; // seconda parola
    int count;   // conteggio di quante volta la 2 parola è contenuta nella 1
    int pos;

    // inizializzazione variabili
    count = 0;

    // input utente
    cout << "Inserisci la prima stringa di testo: ";
    getline(cin, str);

    cout << "Inserisci la seconda stringa di testo: ";
    getline(cin, str2);

    // trovare stringa 2 in stringa 1
    pos = str.find(str2);
    while (pos != string::npos)
    {
        count++;
        pos = str.find(str2, pos + 1);
    }

    // stampa di quante volte è contenuta stringa 2 in stringa 1
    cout << "La seconda stringa è contenuta nella prima stringa " << count << " volte." << endl;

    return 0;
}