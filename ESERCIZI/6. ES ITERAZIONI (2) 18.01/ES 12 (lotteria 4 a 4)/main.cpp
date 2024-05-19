/*Dati N numeri, sommali 4 a 4, e,ovviamente stampa i risultati.*/

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
//inserimento variabili
    int N; //q.di numeri da inserire basta che siano un multiplo di 4
    float numero; //numero inserito
    int somma; //la somma dei numeri
    int i; //iteratore
    int c; // secondo iteratore
    
//iniziallizzazione delle variabili
    somma=0;
    
//input dell'utente
    cout<<"inserisci quanti numeri vuoi inserire (inserisci pero un multiplo di 4!): ";
    cin>>N;

    if(N<0 || N%4!=0) {
        cout<<"quantità inserita non valida!: ";
    } else {

//cicli per sommare 4 a 4
        for(c=0; c<N/4; c++) {
            for(i=0; i<4; i++) {
                cout<<"inserisci "<<i+1<<" numero: ";
                cin>>numero;
                somma+=numero;
            }
            cout<<"il totale della "<<c+1<<" somma e: "<<somma<<endl;
            cout<<endl;

			//reset della somma
            somma-=somma;
        }
        
    }
    return 0;
}