#include<conio.h> /*aaaammmmmmm seguro estas compilando asi que F xD*/
#include <stdio.h>
#define max 7
/*todo que escriba el mensaje a mostrar y luego uq le permita ingresar su numero*/ 
typedef char *string;
int get_int();
int main()
{
    
    int recive = 0;
    clrscr();
   
    recive = get_int("Ingrese un numero: ");
    
    return 0;    
}
int get_int(string message)
{
    char assistant = ' ';
    int i = 0;
    int intiger = 0;
    char hold_intiger[max];

    cprintf("%s", message);

    fflush(stdin);
    textcolor(WHITE);
    
    while(assistant=getch())
    {
        if (assistant> 47 && assistant < 58 && i < max) 
        {
            hold_intiger[i] = assistant;
            cprintf("%c", hold_intiger[i]);
            i++;
        }
        /*Aqui solo se imprimira el negativo si no hay un numero antes*/
        else if (assistant==45 && i==0) 
        {
            hold_intiger[i] = assistant;
            cprintf("%c", hold_intiger[i]);
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

    }
    intiger = atoi(hold_intiger);
    return intiger; 
}



