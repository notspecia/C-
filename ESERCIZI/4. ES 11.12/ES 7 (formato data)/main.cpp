/*Inserire una data nel formato ggmmaaaa mediante l’inserimento di tre numeri GG, MM e
AAAA .Verifica se la data inserita è corretta, cioè rappresenta una data vera.*/

#include <iostream>

using namespace std;

int main() {
    // inserimento variabili
    int anno;
    int mese;
    int giorno;

    // input utente ANNO
    cout << "inserisci anno (1000-2024): ";
    cin >> anno;

    while (anno < 1000 || anno > 2024) {
        cout << "inserisci un'anno valido!: ";
        cin >> anno;
    }

    // input utente mese
    cout << "inserisci mese: ";
    cin >> mese;

    while (mese < 1 || mese > 12) {
        cout << "inserisci un mese valido!: ";
        cin >> mese;
    }

    // input utente giorno
    if (mese == 1 || mese == 3 || mese == 5 || mese == 7 || mese == 8 || mese == 10 || mese == 12) {
        cout << "inserisci giorno: ";
        cin >> giorno;
        while (giorno < 1 || giorno > 31) {
            cout << "inserisci un giorno valido!: ";
            cin >> giorno;
        }
    }

    if (mese == 2) {
        cout << "inserisci giorno: ";
        cin >> giorno;
        while (giorno < 1 || giorno > 28) {
            cout << "inserisci un giorno valido!: ";
            cin >> giorno;
        }
    }

    if (mese == 4 || mese == 6 || mese == 9 || mese == 11) {
        cout << "inserisci giorno: ";
        cin >> giorno;
        while (giorno < 1 || giorno > 30) {
            cout << "inserisci un giorno valido!: ";
            cin >> giorno;
        }
    }

    cout << giorno << "," << mese << "," << anno;
    return 0;
}