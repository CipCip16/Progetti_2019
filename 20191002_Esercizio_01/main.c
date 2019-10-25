//Nome: Stricescu Ciprian
//Data:02/10/2019
/*Note:Scrivere un programma C che dichiari una variabile per ogni tipo studiato
       (usando anche i qualificatori short, long, signed e unsigned), ne stampi
        il valore e l’occupazione di memoria in byte. Utilizzare TUTTI gli argomenti della funzione printf()
        studiati e TUTTE le diverse varianti (modificatore, campoMinimo, precisione, modificatoreLunghezza).
        Per ogni chiamata alla funzione printf(), mostrare a video anche il numero di caratteri che quest’ultima ha stampato.
        Stampare inoltre il valore minimo e il valore massimo ammissibile per ogni tipo utilizzato.
*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  //libreria usata per i valori massimi e minimi delle variabili tipo int e char (+varianti)
#include <float.h>  //libreria usata per i valori massimi e minimi delle variabili tipo float e double
int main()
{
    //Blocco dichiarazioni variabili di tipo intero+qualificatori
    signed int Num_01=-25;
    short int Num_02=1;
    unsigned short int Num_03=2700;
    unsigned int Num_04=28;
    long int Num_05=12345;
    unsigned long int Num_06=3000000;
    int CharStpPf;  //variabile usata per contare i caratteri stampati dal printf()

    //Blocco stampa valore a schermo e occupazione di memoria in byte
    printf("\n\n*****************************************BLOCCO VARIABILI TIPO INT*****************************************\n\n");
    CharStpPf=printf("Valore variabile signed int:\t%15d\n",Num_01);                               //Stampa il valore e grazie al campo minimo stampera almeno 15 caratteri -> ho spazi davanti a 25
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    CharStpPf=printf("Occupazione di memoria in byte:\t%15d\n",sizeof(Num_01));                    //Stampa il numero di byte che occupa la variabile
    //sizeof è un operatore che determina quanta memoria viene usata (in byte) per memorizzare un certo valore
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    printf("--------------------------------------------------------\n");
    CharStpPf=printf("Valore variabile short int:\t%015hd\n",Num_02);
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    CharStpPf=printf("Occupazione di memoria in byte:\t%15d\n",sizeof(Num_02));
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    printf("---------------------------------------------------------\n");
    CharStpPf=printf("Valore variabile unsigned short int:\t% 7hd\n",Num_03);                       //il modificatore di lunghezza h indica un short int o unsigned short int + il flag spazio fa precedere il numero positivo da uno spazio
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    CharStpPf=printf("Occupazione di memoria in byte:\t%15d\n",sizeof(Num_03));
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    printf("---------------------------------------------------------\n");
    CharStpPf=printf("Valore variabile unsigned int:\t%+15d\n",Num_04);                             //il flag + fa apparire il segno davanti a tutti i numeri (solo i numeri negativi lo fanno di default)
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    CharStpPf=printf("Occupazione di memoria in byte:\t%15d\n",sizeof(Num_04));
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    printf("---------------------------------------------------------\n");
    CharStpPf=printf("Valore variabile long int (uso del flag -):  %-ld\n",Num_05);                //il flag - mi allinea a sinistra il valore e il modificatore di lunghezza l mi indica che si tratta di un unsigned long int o long int
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    CharStpPf=printf("Occupazione di memoria in byte:\t%15d\n",sizeof(Num_05));
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    printf("---------------------------------------------------------\n");
    CharStpPf=printf("Valore variabile unsigned long int:\t%ld\n",Num_06);                          //il modificatore di lunghezza l indica un long int o unsigned long int
    printf("Caratteri stampati dal printf():\t%7d\n",CharStpPf);
    CharStpPf=printf("Occupazione di memoria in byte:\t%15d\n",sizeof(Num_06));
    printf("Caratteri stampati dal printf():\t%7d\n\n",CharStpPf);
    printf("Per proseguire con il prossimo blocco inserire un carattere\t");
    getchar(); //usata al posto di system("pause") per bloccare il programma prima di un nuovo blocco,aspetta l'inserimento di un carattere per continuare
    fflush(stdin);  //ripulisce la memoria prima del prossimo input

    //Blocco variabili di tipo char
    signed char carattere_01='a';
    unsigned char carattere_02='b';
    printf("\n\n*****************************************BLOCCO VARIABILI TIPO CHAR****************************************\n\n");
    //uso %c per stampare a schermo un carattere e %d per il suo valore decimale (tabella ASCII)
    CharStpPf=printf("Valore variabile signed char (numero e carattere):   %d|%c\n",carattere_01,carattere_01);
    printf("Caratteri stampati dal printf():\t%16d\n",CharStpPf);
    CharStpPf=printf("Occupazione di memoria in byte:\t%24d\n",sizeof(carattere_01));
    printf("Caratteri stampati dal printf():\t%16d\n",CharStpPf);
    printf("-----------------------------------------------------------------\n");
    CharStpPf=printf("Valore variabile unsigned char (numero e carattere): %d|%c\n",carattere_02,carattere_02);
    printf("Caratteri stampati dal printf():\t%16d\n",CharStpPf);
    CharStpPf=printf("Occupazione di memoria in byte:\t%24d\n",sizeof(carattere_02));
    printf("Caratteri stampati dal printf():\t%16d\n\n",CharStpPf);
    printf("Per proseguire con il prossimo blocco inserire un carattere\t");
    getchar();
    fflush(stdin);

    //Blocco variabili di tipo float/double
    float num_virgola_01=3.1500f;
    double num_virgola_02=856.1234567;
    //long double num_virgola_03=89.1542L;
    printf("\n\n*****************************************BLOCCO VARIABILI TIPO FLOAT\\DOUBLE*********************************\n\n");
    CharStpPf=printf("Valore variabile float (virgola fissa):%30.3f\n",num_virgola_01);              //Esempio uso campo precisone (.nf) argomento di printf()-->stampa 3 cifre dopo la virgola
    printf("Caratteri stampati dal printf():\t%26d\n",CharStpPf);
    CharStpPf=printf("Valore variabile float (notazione scientifica):\t\t\t%.3e\n",num_virgola_01);            //%e stampa il numero in notazione scientifica
    printf("Caratteri stampati dal printf():\t%26d\n",CharStpPf);
    CharStpPf=printf("Valore variabile float (notazione scientifica\\virgola fissa):\t%g\n",num_virgola_01);   //%g stampa il numero in notazione scientifica o virgola fissa a seconda del numero
    printf("Caratteri stampati dal printf():\t%26d\n",CharStpPf);
    CharStpPf=printf("Occupazione di memoria in byte:\t%33d\n",sizeof(num_virgola_01));
    printf("Caratteri stampati dal printf():\t%26d\n",CharStpPf);
    printf("-------------------------------------------------------------------------------------\n");
    CharStpPf=printf("Valore variabile double (virgola fissa):%34f\n",num_virgola_02);
    printf("Caratteri stampati dal printf():\t%26d\n",CharStpPf);
    CharStpPf=printf("Valore variabile double (notazione scientifica):\t\t%.8e\n",num_virgola_02);
    printf("Caratteri stampati dal printf():\t%26d\n",CharStpPf);
    CharStpPf=printf("Valore variabile double (notazione scientifica\\virgola fissa):\t%.10g\n",num_virgola_02);   //il valore della precisione mi indica il numero di cifre significative
    CharStpPf=printf("Occupazione di memoria in byte:\t%33d\n",sizeof(num_virgola_02));
    printf("Caratteri stampati dal printf():\t%26d\n\n",CharStpPf);
    printf("Per proseguire con il prossimo blocco inserire un carattere\t");
    getchar();
    fflush(stdin);

    //Blocco valori numeri ottali e esadecimali
    unsigned int num_ottale=15;
    unsigned int num_esadecimale=26;
    printf("\n\n*****************************BLOCCO VARIABILI TIPO INT OTTALE\\ESADECIMALE************************************\n\n");
    CharStpPf=printf("Valore variabile int (ottale):%#11o\n",num_ottale);                     //il flag # fa iniziare i numeri ottali con uno 0 mentre i numeri esadecimali diversi da zero iniziano con 0x o 0X
    //%o stampa il numero ma lo converte in ottale
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("----------------------------------------------------\n");
    CharStpPf=printf("Valore variabile int (esadecimale):%#7x\n",num_esadecimale);
    //%x stampa il numero ma lo converte in esadecimale
    printf("Caratteri stampati dal printf():%8d\n\n",CharStpPf);
    printf("Per proseguire con il prossimo blocco inserire un carattere\t");
    getchar();
    fflush(stdin);

    //Blocco valori MAX e MIN tipi dato
    printf("\n\n**********************************BLOCCO VALORI MAX E MIN TIPI DATO******************************************\n\n");
    CharStpPf=printf("Valore MAX e MIN int:\t  %d  ||  %d\n",INT_MAX,INT_MIN);
    //INT_MAX e INT_MIN sono già definiti dalla libreria limits.h
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("\n-----------------------------------------------------------------\n\n");
    CharStpPf=printf("Valore MAX unsigned int:\t%16u\n",UINT_MAX);
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("\n-----------------------------------------------------------------\n\n");
    CharStpPf=printf("Valore MAX e MIN signed char:\t %d  ||  %d\n",SCHAR_MAX,SCHAR_MIN);
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("\n-----------------------------------------------------------------\n\n");
    CharStpPf=printf("Valore MAX unsigned char:\t%9d\n",UCHAR_MAX);
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("\n-----------------------------------------------------------------\n\n");
    CharStpPf=printf("Valore MAX e MIN short int:    %d  ||  %d\n",SHRT_MAX,SHRT_MIN);
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("\n-----------------------------------------------------------------\n\n");
    CharStpPf=printf("Valore MAX unsigned short int:\t%11d\n",USHRT_MAX);
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("\n-----------------------------------------------------------------\n\n");
    CharStpPf=printf("Valore MAX e MIN long int:\t %ld  ||  %ld\n",LONG_MAX,LONG_MIN);
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("\n-----------------------------------------------------------------\n\n");
    CharStpPf=printf("Valore MAX unsigned long int:\t%16u\n",ULONG_MAX);
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("\n-----------------------------------------------------------------\n\n");
    CharStpPf=printf("Valore MAX e MIN float:\t  %.10e  ||  %.10e\n",FLT_MAX,FLT_MIN);
    //FLT_MAX e FLT_MIN sono già definiti dalla libreria float.h
    printf("Caratteri stampati dal printf():%8d\n",CharStpPf);
    printf("\n-----------------------------------------------------------------\n\n");
    CharStpPf=printf("Valore MAX e MIN double:  %.10e  ||  %.10e\n",DBL_MAX,DBL_MIN);
    printf("Caratteri stampati dal printf():%8d\n\n",CharStpPf);
    printf("Per terminare il programma inserire un carattere\t");
    getchar();

    return(0);
}
