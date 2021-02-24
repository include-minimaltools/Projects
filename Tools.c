/* Herramientas para trabajo de strings en modo texto */

#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <dos.h>;
#include <string.h>;
#include <BOOL.h>


#define maxStrLen 10

struct
{
    bool isPassword;
	bool allowLetters;
    bool allowNumbers;
    bool allowSymbols;
    
} String;


void getstring(char string[]);

void main()
{
    char text[maxStrLen];

    clrscr();

    String.allowLetters = false;
    String.allowSymbols = true;

    gotoxy(10,1);
    textcolor(LIGHTBLUE);
    textbackground(WHITE);
    getstring(text);

    clrscr();
    printf("%s",text);
}

void getstring(char string[])
{
    int letter = 0;
    while (letter < maxStrLen)
    {

        string[letter] = getch();

        if (String.allowSymbols == true && letter < maxStrLen-1 && ((string[letter] >= 33 && string[letter] <= 47) || (string[letter] >= 58 && string[letter] <= 64) || (string[letter] >= 91  && string[letter] <= 96) || (string[letter] >= 123 && string[letter] <= 126)))
        {
            if(String.isPassword)
                cprintf("*");
            else
                cprintf("%c",string[letter]);

            letter++;
        }
        else if (string[letter] >= 48 && string[letter] <= 57 && letter < maxStrLen-1 && String.allowNumbers == true)
        {
            if(String.isPassword)
                cprintf("*");
            else
                cprintf("%c",string[letter]);

            letter++;
        }
        else if (((string[letter]>=65 && string[letter]<=90) || (string[letter]>=97 && string[letter]<=122) || (string[letter]>=48 && string[letter]<=57)) && letter < maxStrLen-1 && String.allowLetters == true)
        {
            if(String.isPassword)
                cprintf("*");
            else
                cprintf("%c",string[letter]);

            letter++;
        }
        else if(string[letter]==8 && letter>0)
        {
            string[letter]='\0';
            cprintf("\b%c\b",0);
            letter-=1;
        }
        else if(string[letter]==13||string[letter]==27)
        {
            string[letter]='\0';
            break;
        }
    }
}

/**/
/*funciones viejas *

void getString(int x, int y, int isPassword,char string[MaxStrLn])
{   
    int i;

    for(i=0;i<MaxStrLn;i++)
        string[i]='\0';
    
    i=0;
    while(i<MaxStrLn-1)
    {
        gotoxy(x+i,y);
        do
            string[i] = getch();
        while((string[i]<65 || string[i]>90) && (string[i]<97 || string[i]>122) && string[i]!=13 && string[i]!=8 && string[i]!=27);

        if((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i]<=122) || (string[i]>=48 && string[i]<=57))
        {
            if(isPassword)
                cprintf("%c",42);
            else
                cprintf("%c",string[i]);

            i++;
        }
        else if(string[i]==8 && i>0)
        {
            string[i]='\0';
            gotoxy(x+i-1,y);
            cprintf("%c",0);
            i-=1;
        }
        else if(string[i]==13||string[i]==27)
        {
            string[i]='\0';
            break;
        }
            
    }
}

/*La que use para las letras --Mitch*/

void validando(char validar[], int x, int y)
{ //Ingrese su nombre:
    char Reciv_tecla = ' ';
    int i = 0;
    fflush(stdin);
    textcolor(WHITE);
VAL:
    fflush(stdin);
    gotoxy(x, y);
    clreol();
    for (i = 0; i < 17; i++)
    {
        validar[i] = ' ';
    } 
    i = 0;
llenar:
 
    while (Reciv_tecla = getch())
    {

        if (Reciv_tecla > 64 && Reciv_tecla < 91 && i < 16 || Reciv_tecla > 96 && Reciv_tecla < 123 && i < 16)
        {
            Reciv_tecla = toupper(Reciv_tecla);
            validar[i] = Reciv_tecla;
            cprintf("%c", validar[i]);
            i++;
            goto llenar;
        }
        if (Reciv_tecla == '\b')
        {
            goto VAL;
        }
        if (i == 2 && Reciv_tecla == '\r')
        {
            goto VAL;
        }
        if (i < 2 && Reciv_tecla == '\r')
        {
            goto VAL;
        }
        if (i > 2 && i < 17 && Reciv_tecla == '\r')//-------Si todo esta bien 
        {
            validar[i] = '\0';
            break;
        }
    } 
    if (validar[i] == '\0')
    {
    }
    else
    {
        goto VAL;
    }
}
/**/