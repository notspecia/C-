/*Si abbia in input una stringa, si vuole in output la stessa stringa con le lettere minuscole
trasformate in maiuscole*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // inserimento variabili
    string parola; // parola da inserire
    int i;         // iteratore

    // input utente
    cout << "inserisci una parola: ";
    getline(cin, parola);

    // ciclo per trasformare le lettere da minuscole a maiuscole
    for (i = 0; i < parola.length(); i++)
    {
        parola[i] = toupper(parola[i]);
    }

    cout << "la parola finale trasformata, e: " << parola;
    return 0;
}