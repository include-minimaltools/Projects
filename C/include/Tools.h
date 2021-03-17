/*************************************/
/* Definir las librerias necesarias  */
/* el funcionamiento correcto de la  */
/* libreria                          */
/*************************************/
#ifndef stdbool.h
#include "c:\\TC20\\repos\\projects\\include\\STDBOOL.h"
#endif
#ifndef stdio.h
#include "c:\\TC20\\include\\stdio.h"
#endif
#ifndef string.h
#include "c:\\TC20\\include\\string.h"
#endif
#ifndef conio.h
#include "c:\\TC20\\include\\conio.h"
#endif

/*************************************/
/*Definir strings como tipos de datos*/
/*************************************/
typedef char *string;


/*************************************/
/*      Caracteres restringidos      */
/*************************************/
enum allowed_characters
{
    Alls,
    OnlyNumbers,
    OnlyLetters,
    LettersAndSymbols,
    NumbersAndSymbols
};

/*************************************/
/*  Variables globales para la       */
/*  configuracion del get_string     */
/*************************************/
int allowed_characters;
bool isPassword;
int MaxStrLn = 80;
int MinStrLn = 2;
int charPassword = 42;

/*************************************/
/*  Obtiene un string ingresado por  */
/*  el usuario e imprime un mensaje  */
/*  al momento de pedirlo            */
/*************************************/
void get_string(string message, string result)
{
    int letter = 0;
    char temp_string[80]={'\0'};

    cprintf("%s", message); 
        
    while (letter < MaxStrLn)
    {
        temp_string[letter] = getch();

        if ((allowed_characters == LettersAndSymbols || allowed_characters == NumbersAndSymbols || allowed_characters == Alls) && letter < MaxStrLn - 1 && ((temp_string[letter] >= 33 && temp_string[letter] <= 47) || (temp_string[letter] >= 58 && temp_string[letter] <= 64) || (temp_string[letter] >= 91 && temp_string[letter] <= 96) || (temp_string[letter] >= 123 && temp_string[letter] <= 126)))
        {
            cprintf("%c", isPassword ? charPassword : temp_string[letter]);
            letter++;
        }
        else if ((allowed_characters == OnlyNumbers || allowed_characters == Alls) && letter < MaxStrLn - 1 && temp_string[letter] >= 48 && temp_string[letter] <= 57)
        {
            cprintf("%c", isPassword ? charPassword : temp_string[letter]);
            letter++;
        }
        else if ((allowed_characters == OnlyLetters || allowed_characters == LettersAndSymbols || allowed_characters == Alls) && letter < MaxStrLn - 1 && ((temp_string[letter] >= 65 && temp_string[letter] <= 90) || (temp_string[letter] >= 97 && temp_string[letter] <= 122) || (temp_string[letter] >= 48 && temp_string[letter] <= 57)))
        {
            cprintf("%c", isPassword ? charPassword : temp_string[letter]);
            letter++;
        }
        else if (temp_string[letter] == 32)
        {
            cprintf(" ");
            letter++;
        }
        else if (temp_string[letter] == 8 && letter > 0)
        {
            temp_string[letter] = '\0';
            cprintf("\b \b");
            letter--;
        }
        else if (temp_string[letter] == 13 && letter >= MinStrLn)
        {
            temp_string[letter] = '\0';
            break;
        }
    }
    strcpy(result, temp_string);
    return result;
}