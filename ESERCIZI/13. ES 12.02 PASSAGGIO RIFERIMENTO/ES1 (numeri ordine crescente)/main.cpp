/*Creare una funzione che ordini (ordine crescente) il contenuto di due variabili che le sono
passate. Successivamente creare un programma che inseriti tre numeri da parte
dell’utente li stampi in ordine crescente usando la funzione precedentemente creata.
Esempi: Input: A = 4 B = 2 C = 3 Output: A = 2 B = 3 C = 4
Input: A = 1 B = 4 C = 3 Output: A = 1 B = 3 C = 4
Input: A = 3 B = 2 C = 3 Output: A = 2 B = 3 C = 3*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;



/*funzione che legge i numeri dell'utente

parametri formali:
string text

valore restituito:
int numero
*/
int leggiNumero(string text) {
    // dichiarazione variabili
    int numero;

    // input inserimento denaro
    cout << "inserisci il " << text << " numero: ";
    cin >> numero;

    return numero;
}





/*funzione che ordina i numeri in ordine CRESCENTE

parametri formali:
int numero

valore restituito:
null
*/
void ordineCrescente(int &A, int &B) {
    // per spostare i numeri in ordine crescente
    if (A > B) {
        swap(A, B);
    }
}





int main() {
    // dichiarazione variabili
    int num1;  // primo numero per la funzione di PROVA
    int num2;  // secondo numero per la funzione di PROVA
    int A;     // primo numero
    int B;     // secondo numero
    int C;     // terzo numero

    // inserimento dei 2 numeri per la funzione (PROVA)
    num1 = leggiNumero("primo");
    num2 = leggiNumero("secondo");

    // stampa in ordine crescente (PROVA)
    ordineCrescente(num1, num2);
    cout << "(PROVA) i numeri ordinati in ordine crescente: " << num1 << "  " << num2 << endl;
    cout << endl;


    // inserimento dei 3 numeri (A B C)
    A = leggiNumero("primo");
    B = leggiNumero("secondo");
    C = leggiNumero("terzo");

    // stampa in ordine crescente dei 3 numeri (A B C)
    ordineCrescente(A, B);
    ordineCrescente(B, C);
    ordineCrescente(A, B);
    cout << "i numeri ordinati in ordine crescente: " << A << "  " << B << "  " << C << endl;
    
    return 0;
}