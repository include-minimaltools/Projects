#include<conio.h>
#include <stdio.h>
/*todo que escriba el mensaje a mostrar y luego uq le permita ingresar su numero*/ 
typedef char *string;

int get_int(string message);

int main()
{
    int recive = 0;
    clrscr();
   
    recive = get_int("Ingrese su numero: ");

   /* ------Para confirmar la conversion de valor
   printf("\nEste es el nuevo %d",recive);
    getch();
    */
    return 0;    
}
int get_int(string message)
{
    int max = 6;
    char assistant = ' ';
    int i = 0; 
    int intiger = 0;
    char hold_intiger[6];

    cprintf("%s", message);
    

    fflush(stdin);
    textcolor(WHITE);
    /*---------------Ciclo infinito------------*/
    //-32768 a 32767 Alcande del int 
    // si es positivo el arreglo tendra dimension de cinco y si es negativo 6
   //ya esta lo de las direccionales, la conversion , falta hacer que si es negativo no le deje poner un cero, 
    for (;;)
    {
        assistant = getch();

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