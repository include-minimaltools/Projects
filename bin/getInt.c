#include<conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int bool = 0;
typedef char *string;

int get_int(string message,int x,int y);

int main()
{
    int recive = 0;
    clrscr();
   
    recive = get_int("Ingrese su numero: ",1,1);
    printf("\nEste es el nuevo %d",recive);
    getch();
    
    return 0;    
}
int get_int(string message,int x, int y)
{
    int max = 5;
    char assistant = ' ';
    int i = 0;
    long int  intiger = 0;
    char hold_intiger[6];
    fflush(stdin);
    textcolor(WHITE);
    gotoxy(x,y);
    clreol();
    cprintf("%s", message);

    /*if (bool==0)
    {
       gotoxy(x,y);
       clreol();
       cprintf("%s", message);
    }*/
   
    /*---------------Ciclo infinito------------*/
   
    /*si es positivo el arreglo tendra dimension de cinco y si es negativo 6*/

    for (;;)
    {
        assistant = getch();

        if (assistant> 47 && assistant < 58 && i < max) 
        {
            if (assistant==48 && hold_intiger[0]==45 && i == 1 ){}
            else
            {
              hold_intiger[i] = assistant;
              cprintf("%c", hold_intiger[i]);
              i++;
            }
        }
        /*Aqui solo se imprimira el negativo si no hay un numero antes*/
        else if (assistant==45 && i==0) 
        {
            hold_intiger[i] = assistant;
            cprintf("%c", hold_intiger[i]);
            max = 6;
            i++;
        }
        else if (assistant == 8 && i > 0)
        {
            hold_intiger[i] = '\0';
            cprintf("\b \b");
            i--;
        }
        else if (assistant == 13 && i == 1  && hold_intiger[0] != 45 )
        {
            hold_intiger[i]= '\0';
            break;
        }
        else if (assistant == 13 && i > 1)
        {
            hold_intiger[i]= '\0';
            break;
        }
        if (i==0)
        {
            max = 5;
        }

    }
    /*Fuera del ciclo preguntamos*/
    intiger = atol(hold_intiger);
     /*-32768 a 32767 Alcande del int */
    if( intiger > -32768 && intiger < 32767)
       return intiger;
    else
    {
      bool = 1;
      return (get_int(message,x,y)); 
    }
}   