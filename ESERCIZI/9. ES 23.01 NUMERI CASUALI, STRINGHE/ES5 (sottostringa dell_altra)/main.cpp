/*Leggi due stringhe e verifica se una è una sottostringa dell’altra (ovvero se è contenuta nell’altra).*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // inserimento variabili
    string parola1;
    string parola2;

    // input utente
    cout << "inserisci prima parola: ";
    getline(cin, parola1);

    cout << "\ninserisci seconda parola: ";
    getline(cin, parola2);

    // cotrollo se parola 2 è contenuta in parola 1 IMPORTANTE!!
    if (parola1.find(parola2) != string::npos) {
        cout << "e contenuta.";
    } else {
        cout << "non e contenuta.";
    }
    return 0;
}