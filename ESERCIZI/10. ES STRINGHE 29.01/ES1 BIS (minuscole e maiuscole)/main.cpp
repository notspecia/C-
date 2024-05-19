/*Si abbia in input una stringa, si vuole in output la stessa stringa con le lettere minuscole
trasformate in maiuscole e le minuscole in maiuscole.*/

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
    cin >> parola;

    // elaborazione per trasformare maiuscole in minuscole e viceversa
    for (i = 0; i < parola.length(); i++)
    {
        if (islower(parola[i]))
        {
            parola[i] = toupper(parola[i]);
        }
        else
        {
            parola[i] = tolower(parola[i]);
        }
    }
    cout << "la nuova parola trasformata e: " << parola;
    return 0;
}