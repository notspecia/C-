/*Creare un programma che presenti il seguente menù di scelta:
1. Inserisci una FRASE e una PAROLA
2. Stampa lunghezza FRASE
3. Stampa lunghezza PAROLA
4. Stampa FRASE e PAROLA
5. Ricerca numero di volte che PAROLA si ripete in FRASE
6. Inserisci due carattere CAR_A e CAR_B, sostituisci ogni occorrenza di CAR_A in
FRASE con CAR_B
7. Uscita*/

#include <iostream>
#include <string>

using namespace std;




/*funzione che apre il menu di scelta

parametri formali:
null

valore restituito:
int scelta
*/
int leggiMenu()
{
    // dichiarazione variabile
    int scelta; // scelta dell'utente

    // schermata menu
    cout << "\nDIGITANDO 1 ti verra chiesto di inserire una frase e una parola" << endl;
    cout << "DIGITANDO 2 ti verra stampatata la lunghezza della frase" << endl;
    cout << "DIGITANDO 3 ti verra stampatata la lunghezza della parola" << endl;
    cout << "DIGITANDO 4 potrai visualizzare la frase e la parola" << endl;
    cout << "DIGITANDO 5 potrai vedere quante volte parola si ripete in frase" << endl;
    cout << "DIGITANDO 6 potrai dire ciao" << endl;
    cout << "DIGITANDO 7 uscirai dal programma\n"
         << endl;

    // inserimento scelta
    cout << "scegli cosa vuoi fare: ";
    cin >> scelta;

    return scelta;
}






/*funzione che legge la parola

parametri formali:
int scelta

valore restituito:
string parola
*/
string leggiParola()
{
    // dichiarazione variabili
    string parola;

    // input utente
    cout << "inserisci la parola: ";
    cin >> parola;

    return parola;
}






/*funzione che legge la frase

parametri formali:
int scelta

valore restituito:
string frase
*/
string leggiFrase()
{
    // dichiarazione variabili
    string frase;

    // input utente
    cin.ignore();
    cout << "inserisci la frase: ";
    getline(cin, frase);
    cout << "\n";

    return frase;
}






/*funzione che stampa la lunghezza della frase dell'utente

parametri formali:
int scelta
string frase

valore restituito:
null
*/
void lunghezzaFrase(string frase)
{
    cout << "la lunghezza della frase che hai inserito, e di: " << frase.length() << "\n"
         << endl;
}






/*funzione che stampa la lunghezza della parola
parametri formali:
int scelta
string parola

valore restituito:
null
*/
void lunghezzaParola(string parola)
{
    cout << "la lunghezza della parola che hai inserito, e di: " << parola.length() << "\n"
         << endl;
}









/*funzione che stampa la parola e la frase inserita
parametri formali:
int scelta
string parola
string frase

valore restituito:
null
*/
void stampaParolaFrase(string frase, string parola)
{
    cout << "frase: " << frase << endl;
    cout << "parola: " << parola << "\n"
         << endl;
}






/*funzione che stampa quante volte è contenuta parola in frase
parametri formali:
int scelta
string parola
string frase

valore restituito:
null
*/
void parolaINfrase(string parola, string frase)
{
    // dichiarazione variabili
    int pos;
    int cont;

    // inizializzazione variabili
    cont = 0;
    pos = frase.find(parola);

    // ciclo per vedere quante volte parola è contenuta in frase
    while (pos != string::npos)
    {
        cont++;
        pos = frase.find(parola, pos + 1);
    }
    cout << parola << " e contenuta in totale " << cont << " volte in " << frase << "\n"
         << endl;
}









/*funzione che sostituisce CAR_A in CAR_B della frase che si inserisce
parametri formali:
int scelta
string frase

valore restituito:
null
*/
void sostituzioneFrase(string frase)
{
    // dichiarazione variabili
    char a; // carattere a
    char b; // carattere b
    int i;  // iteratore

    // input utente
    cout << "inserisci il primo carattere (sostiuisce): ";
    cin >> a;
    cout << "inserisci il secondo carattere (sostituito): ";
    cin >> b;

    // sostituzione nella frase del carattere B con carattere A
    for (i = 0; i < frase.length(); i++)
    {
        if (frase[i] == b)
        {
            frase[i] = a;
        }
    }
    cout << "la nuova frase e: " << frase << "\n"
         << endl;
}




int main()
{
    // dichiarazione variabili
    int menu;       // menu di scelta
    string parola;  // la parola inserita
    string frase;   // la frase inserita
    bool flag;      // permette l'uscita dal programma
    bool controllo; // controllo se si è effetutata la 1 scelta

    // inizializzazione variabili
    flag = false;
    controllo = false;

    do
    {
        // opzioni menu di scelta
        menu = leggiMenu();

        // in base alla scelta effettuata dell'utente
        switch (menu)
        {
        // inserimento di parola e frase
        case 1:
            parola = leggiParola();
            frase = leggiFrase();
            controllo = true;
            break;

        // stampa della lunghezza frase
        case 2:
            if (controllo == false)
            {
                cout << "inserisci prima parola e frase!\n";
            }
            else
            {
                lunghezzaFrase(frase);
            }
            break;

        // stampa della lunghezza parola
        case 3:
            if (controllo == false)
            {
                cout << "inserisci prima parola e frase!\n";
            }
            else
            {
                lunghezzaParola(parola);
            }
            break;

        // stampa della parola e della frase
        case 4:
            if (controllo == false)
            {
                cout << "inserisci prima parola e frase!\n";
            }
            else
            {
                stampaParolaFrase(frase, parola);
            }
            break;

        // N di volte in cui parola si ripete in frase
        case 5:
            if (controllo == false)
            {
                cout << "inserisci prima parola e frase!\n";
            }
            else
            {
                parolaINfrase(parola, frase);
            }
            break;

        // sostituisci ogni occorrenza di CAR_A in FRASE con CAR_B
        case 6:
            if (controllo == false)
            {
                cout << "inserisci prima parola e frase!\n";
            }
            else
            {
                sostituzioneFrase(frase);
            }
            break;

        // uscita dal programma
        case 7:
            flag = true;
            break;

        // se inserisce un numero al di fuori della scelta
        default:
            cout << "inserisci una scelta valida!\n";
        }

    } while (flag != true);

    return 0;
}