#include "gamelib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// Definizioni delle funzioni in gamelib.c.
// Piu altre funzioni di supporto.
// Le funzioni richiamabili in main.c non devono essere static.
// Le altre devono essere static (non visibili all'esterno).

char colore[10];
static Giocatore *giocatori;
static int *nome_random = NULL;
static int i = 0, j = 0;


const char* dammi_nome_giocatore(Nome_giocatore nome) //Questa funzione converte i numeri nei rispettivi nomi dei colori
{
   switch (nome) 
   {
        case rosso: return "rosso";
        case arancione: return "arancione";
        case giallo: return "giallo";
        case verde: return "verde";
        case ciano: return "ciano";
        case blu: return "blu";
        case viola: return "viola";
        case marrone: return "marrone";
        case bianco: return "bianco";
        case nero: return "nero";
   }
}

void imposta_gioco(){

    short int numero_giocatori;    
    
    do{
        printf("\n//Menù principale -> Imposta Gioco\\\\");
        printf("\nQuanti giocatori giocheranno? (minimo 4, massimo 10 giocatori)\n");
        scanf("%hd", &numero_giocatori);

        switch(numero_giocatori){
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                printf("Hai scelto di giocare con %hd giocatori!\n", numero_giocatori);
                break;
            default:
                printf("Numero sbagliato! ritenta\n");
                numero_giocatori = 0;
                break;
        }

    } while (numero_giocatori == 0);

    //alloco memoria per ogni giocatore e per un array di nomi che mi servirà per generare nomi casuali

    giocatori = (Giocatore *) calloc(numero_giocatori, sizeof(Giocatore)); 
    nome_random = (int *) calloc(numero_giocatori, sizeof(int));
    
    time_t t;
    srand((unsigned) time(&t));

    //il primo ciclo assegna ad ogni giocatore un nome
    //il secondo si assicura che siano diversi tra di loro
    
    for(i = 0;i<numero_giocatori;i++){
        nome_random[i] = rand() % numero_giocatori;
        for(j = 0; j < numero_giocatori; j++){
            if(nome_random[i] == nome_random[j] && j != i){
                nome_random[i] = rand() % numero_giocatori;
                j = -1;
            }
        }
        giocatori[i].Nome_giocatore = nome_random[i];
        printf("Il giocatore %d è %s\n",i+1,dammi_nome_giocatore(giocatori[i].Nome_giocatore));
    };
}


