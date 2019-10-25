//Nome: Stricescu Ciprian, Magnani Francesco, Enrica Contrini, Livia del Gaudio
//Note: Scrivere un programma C che legga da tastiera un testo terminato dal carattere # e poi stampi le statistiche relative al numero di spazi,
//      al numero di caratteri di nuova linea, al numero di caratteri letti, al numero di quelli maiuscoli, etc. utilizzando almeno una volta tutte le funzioni dell’header ctype.h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define carattere '#'

int main()
{
    unsigned char testo[300];
    int i=0;

    //dichiarazione variabili contatore

    unsigned int conta_spazi=0,conta_newline=0,conta_char=0,conta_upper=0,conta_lower=0,conta_alnum=0,conta_digit=0,conta_graph=0,conta_print=0,conta_punct=0,conta_xdigit=0;
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Inserire un testo terminato dal carattere #,ti faro vedere tutte le statistiche piu interessanti!\n");

    //funzione memset usata per riempire l'array con null in modo da evitare caratteri random nella stringa
    memset(testo,'\0',sizeof(testo));

    printf("\n->Text:\t");
    //uso di uno scanf() che ammette tutti i char ad eccetto di # +uso del puntatore per la stringa testo
    scanf("%[^#]",&*testo);
    fflush(stdin);

    //ciclo di controllo carattere per carattere
    for(i=0; testo[i]!='\0'; i++)
    {
        //le funzioni della libreria ctype restituiscono valori diversi da 0 se risultano true
        if((iscntrl(testo[i])!=0)&&(testo[i]!='\0')) //controllo caratteri new line (tolgiendo il null)
            conta_newline++;
        if((isspace(testo[i])!=0)&&(iscntrl(testo[i])==0))  //controllo caratteri spazio (togliendo quelli di controllo)
            conta_spazi++;
        if(isalpha(testo[i])!=0)    //controllo caratteri
            conta_char++;
        if(islower(testo[i])!=0)    //controllo caratteri in minuscolo
            conta_lower++;
        if(isupper(testo[i])!=0)    //controllo caratteri in maiuscolo
            conta_upper++;
        if(isalnum(testo[i])!=0)    //controllo caratteri alfanumerici
            conta_alnum++;
        if(isdigit(testo[i])!=0)    //controllo numeri
            conta_digit++;
        if(isgraph(testo[i])!=0)    //controllo caratteri grafici
            conta_graph++;
        if(isprint(testo[i])!=0)    //controllo caratteri stampabili
            conta_print++;
        if(ispunct(testo[i])!=0)    //controllo caratteri punteggiatura
            conta_punct++;
        if(isxdigit(testo[i])!=0)   //controllo caratteri esadecimali (0-F)
            conta_xdigit++;
    }

    //blocco stampa dei contatori
    printf("\nHo trovato:               Quantita:");
    printf("\n-\\n:\t%23d\n",conta_newline);
    printf("-Spazi:\t%23d\n",conta_spazi);
    printf("-Caratteri:%20d\n",conta_char);
    printf("-Caratteri minuscoli:%10d\n",conta_lower);
    printf("-Caratteri maiuscoli:%10d\n",conta_upper);
    printf("-Caratteri alfanumerici:%7d\n",conta_alnum);
    printf("-Numeri:%23d\n",conta_digit);
    printf("-Caratteri grafici:%12d\n",conta_graph);
    printf("-Caratteri stampabili:%9d\n",conta_print);
    printf("-Punteggiatura:%16d\n",conta_punct);
    printf("-Caratteri esadecimali:%8d\n",conta_xdigit);
    printf("\nOra convertiro' tutte le lettere minuscole in maiuscole!\n");


    //ciclo carattere per carattere per usare la funzione toupper
    for(i=0; testo[i]!='\0' ;i++)
    {
        testo[i]=toupper(testo[i]);  //restiuisce il carattere in maiuscolo se non lo è già
    }

    printf("->Text:\t%s\n",testo);

    printf("\nOra convertiro' tutte le lettere maiuscole in minuscole!\n");

    //ciclo carattere per carattere per usare la funzione tolower
    for(i=0; testo[i]!='\0'; i++)
    {
        testo[i]=tolower(testo[i]);  //restiuisce il carattere in minuscolo se non lo è già
    }


    printf("->Text:\t%s\n",testo);
    getchar();
    fflush(stdin);
    //printf("\nTesto inserito:%s",testo[4]);  //se metto in input "ciao#" il 6 elemento dell'array è null
    return 0;
}
