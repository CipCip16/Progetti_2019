//Nome: Stricescu Ciprian
//Data: 20191005
//Note: Scrivere un programma C che mostri l�utilizzo di tutti gli operatori studiati.
//      Il programma deve inoltre mostrare il comportamento scorretto che si ottiene utilizzando tipi
//      non appropriati alla dimensione delle variabili, quello che si ottiene usando pi� operatori con
//      side effects all�interno della stessa istruzione, quello che si ottiene quando le regole di
//      conversione implicita sono applicate e quando si supera il range dei valori disponibili per un tipo di dato.
//      Il programma deve poi mostrare l�utilizzo di tutte le funzioni matematiche della libreria math.h.


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    unsigned short int a=5,b=2,f=0,g=1; //operatore assegnamento
    int c;
    unsigned int x=1,y=2,w,z;
    printf("***Blocco operatori--------------------------------------------------------------------------------------\n");
    printf("                                                |                                       \t\t|\n");
    printf("-Valore iniziale variabili intere x,y:\t%d|%d\t|                                       \t\t|\n",x,y);
    printf("-Valore iniziale variabili intere a,b:\t%d|%d\t|  -Valore iniziale variabili intere f,g:\t%d|%d\t|\n",a,b,f,g);
    c=a+b;           //operatore somma
    printf("Risultato somma a+b:\t%18d\t|  Risultato op. unario a++:\t%18d\t|\n",c,a++);   //operatore unario incremento postfisso
    a=5;c=a-b;       //operatore sottrazione
    printf("Risultato sottrazione a-b:\t %9d\t|  Risultato op. unario ++b:\t%18d\t|\n",c,++b);  //operatore unario incremento prefisso
    b=2;c=a*b;       //operatore moltiplicazione
    printf("Risultato moltiplicazione a*b:\t  %8d\t|  Risultato op. unario --a:\t%18d\t|\n",c,--a);     //operatore unario decremento prefisso
    a=5;c=a/b;       //operatore divisione
    printf("Risultato divisione a/b:\t %9d\t|  Risultato op. unario b--:\t%18d\t|\n",c,b--);   //operatore unario decremento postfisso
    b=2;c=a%b;       //operatore resto

    //operatori logici.Queste operazioni restituiscono necessariamente 1 quando sono vere e 0 quando sono false
    printf("Risultato divisione (resto) a/b:\t %d\t|  Risultato AND logico f&&g:\t%18d\t|\n",c,f&&g);  //a && b assume valore zero se a o b valgono zero, uno nel caso entrambi valgano uno.
    printf("Risultato espressione (a++,b+a):\t %d\t|  Risultato OR logico f||g:\t%18d\t|\n",(a++,b+a),f||g); //operatore virgola,l�espressione a || b assume valore uno se e solo se a o b valgono uno, mentre vale zero se entrambi gli operandi valgono zero
    a=5;
    printf("Risultato espressione a<b:\t\t %d\t|  Risultato espressione a>b:\t\t%10d\t|\n",a<b,a>b);
    printf("Risultato espressione a<=4:\t\t %d\t|  Risultato espressione a>=5:\t\t%10d\t|\n",a<=4,a>=5);    //operatori relazionali,restituiscono 1 se vero ,0 se falso
    printf("Risultato espressione a!=b:\t\t %d\t|  Risultato espressione a==5:\t\t%10d\t|\n",a!=b,a==5);    //NOT uguale a
    w=x&y;  //AND bit a bit
    z=x|y;  //OR bit a bit

    //operatori bit a bit
    printf("Risultato AND bit a bit a&b:\t %9d\t|  Risultato OR bit a bit a|b:\t%18d\t|\n",w,z);
    w=x^y;
    printf("Risultato NOT bit a bit ~y:\t %9d\t|  Risultato XOR bit a bit a^b:\t%18d\t|\n",~y,w);
    w=x>>2;
    z=y<<1;
    printf("Risultato Spost. dx bit a bit x>>2:\t %d\t|  Risultato Spost. sx bit a bit y<<1:\t%10d\t|\n",w,z);
    printf("                                                |                                       \t\t|\n");
    printf("Per proseguire con il prossimo blocco inserire un carattere:                            \t\t|");
    getchar();
    fflush(stdin);
    printf("---------------------------------------------------------------------------------------------------------\n");

    //comportamento scorretto che si ottiene utilizzando tipi non appropriati alla dimensione delle variabili e quando si supera il range dei valori disponibili per un tipo di dato
    char d='h';
    d=292;
    a=5;
    printf("                                                                                                        |\n");

    printf("                                                                                                        |\n");
    printf("***Blocco comportamento scorretto \t\t\t\t\t\t\t\t\t|\n");
    printf("                                                                                                        |\n");
    printf("Dichiaro una variabile char d a cui assegno il valore 292 cosi superando il suo range,                  |\n");
    printf("questa arrivata al valore 255 poi ricomincia da 0 fino ad attivare al valore n=LIM_MAX_CHAR-255.        |\n");
    printf("Valore variabile char:\t%c                                                                               |\n",d);
    printf("                                                                                                        |\n");

    //comportamento scorretto che si ottiene utilizzando pi� operatori con side effects all�interno della stessa istruzione
    printf("Comportamento indefinito utilizzando piu operatori con side effects nell'espressione a=1;a=a++;         |\n");
    //b=a++*a;
    a=1;a=a++;
    printf("Valore variabile a:\t%d                                                                               |\n",a);

    //il comportamento scorretto che si ottiene quando le regole di conversione implicita sono applicate
    float e=3.13;
    printf("                                                                                                        |\n");
    printf("Comportamento scoretto dovuto alla conversione implicita assegnando ad una variabile di tipo (c) int    |\n");
    printf("un valore float 3.13                                                                                    |\n");
    c=e;
    printf("Valore variabile c:\t%d                                                                               |\n",c);
    printf("                                                                                                        |\n");
    printf("Per proseguire con il prossimo blocco inserire un carattere:                                            |");
    getchar();
    fflush(stdin);
    printf("-----------------------------------------------------------------------------------------------------------------\n");

    //mostrare l�utilizzo di tutte le funzioni matematiche della libreria math.h
    printf("                                                |                                                       \t|\n");
    printf("                                                |                                                       \t|\n");
    printf("***Blocco funzioni libreria math.h              |\t\t\t\t\t\t\t\t|\n");
    printf("                                                |                                                       \t|\n");
    printf("Valore arcocoseno di 1:\t        %f\t|  Valore arcoseno di 1:\t                    %f\t|\n",acos(1),asin(1));
    printf("Valore arcotangente di 1:\t%f        |  Valore arcotangente di due parametri (1,1):\t    %f\t|\n",atan(1),atan2(1,1));
    printf("Valore coseno di 60 gradi:\t%f\t|  Valore intero non minore del parametro (1):\t    %f\t|\n",cos(M_PI/3),ceil(1));
    printf("Valore seno di 60 gradi:\t%f\t|  Valore intero non maggiore del parametro (1):    %f\t|\n",sin(M_PI/3),floor(1));
    printf("Valore tangente di 60 gradi:\t%f\t|  Valore coseno iperbolico di 0:\t\t    %f\t|\n",tan(M_PI/3),cosh(0));
    printf("Valore seno iperbolico di 0:\t%f\t|  Valore tangente iperbolica do 0:\t\t    %f\t|\n",sinh(0),tanh(0));
    printf("Valore funzione e^2:\t\t%f\t|  Valore assoulto di -7:\t\t\t    %f\t|\n",exp(2),fabs(-7));
    printf("Valore resto:\t\t\t%f\t|  Valore logaritmo naturale di 1:\t\t    %f\t|\n",fmod(M_PI,2.17),log(1));
    //printf("Valore frazione e potenza di due:\t%f\n",frexp(4,a));
    //manca anche ldexp
    printf("Valore potenza 3^2:\t\t%f\t|  Valore logaritmo in base 10 di 100:\t\t    %f\t|\n",pow(3,2),log10(100));
    printf("Valore radice quadrata di 4:\t%f\t|                                                               |\n",sqrt(4));
    printf("                                                |                                                       \t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("Per terminare il programma inserire un carattere\t");
    getchar();
    return 0;
}
