// Dichiarazione delle funzioni da chiamare in main.c
// Definizione dei tipi necessari alla libreria

void imposta_gioco();
void gioca();
void termina_gioco();

typedef enum {astronauta,impostore,assassinato,defenestrato} Stato_giocatore;
typedef enum {rosso,arancione,giallo,verde,ciano,blu,viola,marrone,bianco,nero} Nome_giocatore;
typedef enum  {vuota, quest_semplice, quest_complicata, botola} Tipo_stanza;
typedef enum {falso,vero} boolean;

typedef struct  {
    struct Stanza *posizione;
    Stato_giocatore Stato_giocatore;
    Nome_giocatore Nome_giocatore;
} Giocatore;

typedef struct  {
    struct Stanza *avanti;
    struct Stanza *sinistra;
    struct Stanza *destra;
    struct Stanza *stanza_precedente;
    Tipo_stanza Tipo_stanza;
    boolean emergenza_chiamata;
} Stanza;




