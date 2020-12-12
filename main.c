#include "gamelib.h"
#include <stdio.h>

// Questo file continene solo la definizione della funzione main
// con il menu principale 1-2-3

int main( ) {

    short int scelta_menu = 0;
    do{
        printf("\n//Menù principale\\\\");
        printf("\nPremi (1) per impostare il gioco");
        printf("\nPremi (2) per giocare");
        printf("\nPremi (3) per terminare il gioco\n");

        scanf("\n%hd", &scelta_menu);

        switch(scelta_menu){
        case 1:
            imposta_gioco();
            break;
        case 2:
            printf("Placeholder 2");
            break;
        case 3:
            printf("Placeholder 3");
            break;
        default:
            printf("Numero sbagliato! ritenta\n");
            scelta_menu = 0;
            break;
        }

    } while (scelta_menu == 0);



}



