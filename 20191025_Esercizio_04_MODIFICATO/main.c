//Nome: Stricescu Ciprian, Magnani Francesco, Enrica Contrini, Livia del Gaudio
//Data: 20191023
//Note: L’utente pensa ad un numero e il computer lo deve indovinare

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    unsigned int valmin,valmax;
    int scelta=0;

    //blocco per inserimento valori limite
    printf("----------------------------------------------------------------------------------------\n");
    printf("Salve utente!\nProviamo un gioco!\nPensa ad un numero compreso in un intervallo (estremi inclusi) a tua scelta e io provero ad indovinarlo!\n");
    printf("\n->Inserisci il valore minimo dell'intervallo:\t ");
    scanf("%u",&valmin);
    fflush(stdin);
    printf("\n->Inserisci il valore massimo dell'intervallo:\t ");
    scanf("%u",&valmax);
    fflush(stdin);

    //blocco controllo del corretto inserimento dei valori limite
    while((valmin>valmax)||(valmin==valmax))
    {
        if(valmin==valmax)
        {
            printf("\nI due estremi dell'intervallo sono uguali,cosi il gioco non e divertente!\n");
        }
        else if (valmin>valmax)
        {
            printf("\nIl valore minimo e' piu grande di quello massimo,errore!\n->Vuoi scambiare i due valori o reinserirli entrambi? (0 | 1):\t");
            scanf("%d",&scelta);
            fflush(stdin);

            if(scelta==0) //scambia i valori del range
            {
                unsigned int temp=0;
                temp=valmax;
                valmax=valmin;
                valmin=temp;
                break;
            }
        }

        printf("->Reinserisci il valore minimo dell'intervallo:\t");
        scanf("%u",&valmin);
        fflush(stdin);
        printf("\n->Reinserisci il valore massimo dell'intervallo:\t");
        scanf("%u",&valmax);
        fflush(stdin);

    }

    unsigned int ncpu = 0;  //il numero generato dal computer
    unsigned int num=1;     //variabile di controllo per la generazione di un numero random diverso ad ogni ciclo
    char risp='n';          //risposta dell'utente

    printf("\nOra pensa a un numero tra %u e %u\n", valmin, valmax);
    printf("Ok,siamo pronti ad iniziare!\n");
    printf("----------------------------------------------------------------------------------------\n");

    srand(time(NULL));     //inizializzazione del seed
    ncpu = rand() % (valmax - valmin+1) + valmin;      //il +1 indica l'inclusione di valmax nel range

    while(risp!= 'y')      //ciclo che ripete la generazione del numero casuale entro i valori limite
    {
         //aggiornamento variabile controllo
         num=ncpu;


        if(valmax==valmin)  //caso limite in cui i due valori sono uguali
        {
            printf("\nLo so! Il numero che hai pensato e' %u!\n",valmax);
            break;          //fine ciclo essendo il numero da indovinare ovvio
        }

        printf("\nE %u il numero a cui hai pensato? (s|n)\t",ncpu);
        risp=getchar();
        fflush(stdin);

        if (risp =='s')
        {
            printf("\nHo indovinato!");  //fine gioco
            break;
        }
        else
        {
            printf("\nIl numero a cui hai pensato e maggiore o minore? (>|<)\t");
            risp=getchar();
            fflush(stdin);

            if (risp=='<')
            {
                printf ("\nQuindi viene prima!");
                valmax = num-1;   //cambio valore limite massimo (il -1 serve a fare in modo che il numero estratto in questo ciclo non venga riestratto)
            }
            else
            {
                printf ("\nQuindi viene dopo!");
                valmin = num+1;   //cambio valore limite minimo  (il +1 serve a fare in modo che il numero estratto in questo ciclo non venga riestratto)
            }
            printf("\nAllora dammi un secondo per riprovare!\n");

        }

        //ciclo che evita il ripetersi dello stesso numero ad ogni ciclo

        do
        {
           ncpu = rand() % (valmax - valmin+1) + valmin;         //nuovo numero random entro il range aggiornato
        }
        while(num==ncpu); //ciclo che evita la ripetizione dello stesso numero
    }

    printf("\nPremi invio per terminare il programma\n");
    getchar();
    return 0;
}
