/*Creare una funzione che ricevuti tre importi di denaro sposti gli eventuali debiti (si
considerino debiti gli importi negativi) sul primo importo.
Creare un main per testare la funzione.
Esempio:
se gli importi sono 5 -1 -2 gli importi dopo l’applicazione
della funzione saranno 2 0 0.
se gli importi sono -3 4 -2 gli importi dopo l’applicazione
della funzione saranno -5 4 0.
se gli importi sono 4 -2 -2 gli importi dopo l’applicazione
della funzione saranno 0 0 0.
se gli importi sono 6 -4 -3 gli importi dopo l’applicazione
della funzione saranno -1 0 0*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;




/*funzione che legge i gli importi dell'utente

parametri formali:
string text

valore restituito:
int denaro;
*/
float leggiImporto(string text) {
    // dichiarazione variabili
    float denaro;

    // input utente e controllo che sia > 0
    cout << "inserisci il " << text << " importo: ";
    cin >> denaro;   

    return denaro;
}





/*funzione che legge i gli importi nuovi (&) dopo aver effettuato le operazioni richieste

parametri formali:
int importi

valore restituito:
null
*/
void contoFinale(float &importo1, float &importo2, float &importo3) {

    // se importo 2 e importo 3 sono minori, addebitati al primo conto
    if (importo2 < 0) {
        importo1 += importo2;
        importo2 = 0;
    }
    if (importo3 < 0) {
        importo1 += importo3;
        importo3 = 0;
    }
}




int main() {
    // dichiarazione variabili
    float importo1;  // primo importo
    float importo2;  // secondo importo
    float importo3;  // terzo importo

    // lettura degli importi
    importo1 = leggiImporto("primo");
    importo2 = leggiImporto("secondo");
    importo3 = leggiImporto("terzo");
    cout << "\n";
    cout << "gli importi iniziali sono:  " << importo1 << "  " << importo2 << "  " << importo3 << "  " << endl;

    // lettura e spostamento dei debiti al primo importo correttamente
    contoFinale(importo1, importo2, importo3);
    cout << "gli importi elaborati sono: " << importo1 << "  " << importo2 << "  " << importo3 << "  " << endl;

    //
    return 0;
}