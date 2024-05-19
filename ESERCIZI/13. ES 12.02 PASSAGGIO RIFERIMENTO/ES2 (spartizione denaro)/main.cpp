/*Due persone hanno una quantità di denaro x e y. Richiamare una funzione che “livelli” le
quantità di denaro in maniera tale da equilibrare tale quantità tra i due.
Esempio: se la persona A possiede 30€ e la persona B 70€, una
volta utilizzata la funzione la persona A e B possiederanno
entrambe 50 €.*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;




/*funzione che legge le somme di denaro delle 2 persone

parametri formali:
string text

valore restituito:
int denaro
*/
float letturaDenaro(string text)
{

    // dichiarazione variabili
    float denaro;

    // input inserimento denaro
    cout << "inserisci il denaro che possiede la " << text << " persona: ";
    cin >> denaro;

    while (denaro < 0)
    {
        cout << "reinserisci il denaro che possiede la " << text << " persona (>0): ";
        cin >> denaro;
    }
    return denaro;
}





/*funzione che legge i numeri inseriti E TRASFORMA LE VARIABILI DEL MAIN SENZA IL RETURN

parametri formali:
int denaro

valore restituito:
null
*/
void spartizioneDenaro(float &persona1, float &persona2)
{

    // dichiarazione variabili
    float spartizione;

    // inizializzazione variabili
    spartizione = 0;

    // calcolo della spartizione tra le 2 persone e trasformazione delle variabili nel main (grazie a &)
    spartizione = (persona1 + persona2) / 2;
    cout << "\na ogni persona va: " << spartizione << " euro" << endl;

    persona1 = spartizione;
    persona2 = spartizione;

}




int main()
{
    // dichiarazione variabili
    float persona1;
    float persona2;

    // lettura di quanto denaro possiedono x e y
    persona1 = letturaDenaro("prima");
    persona2 = letturaDenaro("seconda");

    // spartizione del denaro tra le 2 persone
    spartizioneDenaro(persona1, persona2);

    // controllo che i soldi siano spartiti correttamente
    cout << "\npersona1: " << persona1 << "\npersona2: " << persona2 << endl;

    return 0;
}