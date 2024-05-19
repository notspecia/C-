/*Scrivi un programma che esegua il calcolo delle soluzioni di un’equazione di secondo
grado nella forma ax2 + bx + c = 0 . Il programma deve mostrare il seguente menù di scelta:
1. Inserimento coefficienti (a,b,c)
2. Calcolo del discriminante (delta = b*b -4*a*c)
3. Calcolo delle soluzioni
4. Uscita
Quando si seleziona una voce di calcolo stampare il risultato calcolato.*/

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

/*							FUNCTION SIGNATURE
--------------------------------------------------------------------*/

int leggiMenu();
float leggiNumero(string);
void calcoloDelta(float, float, float);
void calcoloSoluzioni(float, float, float);

/*						 PROGRAMMA MAIN PRINCIPALE
--------------------------------------------------------------------*/

int main()
{
    // dichiarazione variabili
    int menu; // interfaccia menu
    float a; // 1 coefficiente
    float b; // 2 coefficiente
    float c; // 3 coefficiente

    // inizializzazione variabili
    a = 0;

    // opzioni menu di scelta
    do
    {
        menu = leggiMenu();
        switch (menu)
        {
        // inserimento dei 3 coefficenti (a,b,c)
        case 1:
            cout << endl;
            a = leggiNumero("coeddicente a: ");
            b = leggiNumero("coeddicente b: ");
            c = leggiNumero("coeddicente c: ");
            break;

        // calcolo e stampa del DELTA
        case 2:
            if (a != 0)
            {
                calcoloDelta(a, b, c);
            }
            else
            {
                cout << "ERRORE (A=0!)\n";
            }
            break;

        // calcolo e stampa delle soluzioni
        case 3:
            if (a != 0)
            {
                calcoloSoluzioni(a, b, c);
            }
            else
            {
                cout << "ERRORE (A=0!)\n";
            }
            break;

        // uscita dal menu
        case 4:
            break;

        // se inserisce un numero al di fuori della scelta
        default:
            cout << "inserisci un'opzione valida!\n";
        }

    } while (menu != 4);

    return 0;
}

/*								FUNZIONI
--------------------------------------------------------------------*/

/*funzione che apre il menu di scelta

parametri formali:
null

valore restituito:
int scelta
*/
int leggiMenu()
{
    // dichiarazione variabile
    int scelta;

    // schermata menu
    cout << "\n\nDIGITANDO 1 ti verra chiesto di inserire i coefficienti (a,b,c)." << endl;
    cout << "DIGITANDO 2 ti verra calcolato e stampato il delta" << endl;
    cout << "DIGITANDO 3 ti verra fatto il calcolo e la stampa delle soluzioni" << endl;
    cout << "DIGITANDO 4 potrai uscire dal menu.\n"
         << endl;

    // inserimento scelta
    cout << "scegli cosa vuoi fare: ";
    cin >> scelta;

    return scelta;
}

/*funzione che legge i coefficienti

parametri formali:
int scelta, string text

valore restituito:
int numero
*/
float leggiNumero(string text)
{
    // dichiarazione variabile
    float num;

    // inserimento numero
    cout << "inserisci il " << text;
    cin >> num;

    return num;
}

/*funzione che calcola e stampa il delta

parametri formali:
int a, int b, int c

valore restituito:
null
*/
void calcoloDelta(float a, float b, float c)
{
    // dichiarazione variabili
    float delta;

    // calcolo del delta
    delta = (b * b) - 4 * (a * c);

    cout << "il delta di questa equazione e: " << delta << endl;
}

/*funzione che calcola e stampa le soluzioni in base al delta (<0 =0 >0)

parametri formali:
int a, int b, int c

valore restituito:
null
*/
void calcoloSoluzioni(float a, float b, float c)
{
    // dichiarazione variabili
    float delta;
    float soluzione;
    float soluzione2;

    // calcolo delta
    delta = (b * b) - 4 * (a * c);

    // controllo del delta ed elaborazione delle souluzioni
    if (delta < 0)
    {
        cout << "impossibile trovare soluzioni reali" << endl;
    }
    else if (delta == 0)
    {
        soluzione = -(b) / (2 * a);
        cout << "(delta = 0)\nla soluzione e uguale a: " << soluzione << endl;
    }
    else
    {
        soluzione = (-(b) + sqrt(delta)) / (2 * a);
        soluzione2 = (-(b)-sqrt(delta)) / (2 * a);
        cout << "(delta > 0)\nX1 e uguale a: " << soluzione << endl;
        cout << "X2 e uguale a: " << soluzione2 << endl;
    }
}
