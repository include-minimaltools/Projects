#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "c:\\TC20\\repos\\projects\\include\\STDBOOL.h"

typedef char *string;

enum allowed_characters
{
    Alls,
    OnlyNumbers,
    OnlyLetters,
    LettersAndSymbols,
    NumbersAndSymbols
};

string get_string(char *message);

int allowed_characters;
bool isPassword;
int MaxStrLn = 80;
int MinStrLn = 2;
int charPassword = 42;

void main()
{
    string user, password;
    int i;

    clrscr();

    user = get_string("\nUsuario: ");
    password = get_string("\nContra: ");

    printf("\n\nUsuario: %s  Contra:%s",user,password);


/**
    text = get_string("\nEscriba su nombre: ");
    text2 = get_string("\nEscriba su apellido: ");

    printf("\n\nSu nombre es %s %s",text,text2);

    text3 = get_string("\n\nEscriba su nombre nuevamente: ");
    text4 = get_string("\n\nEscriba su apellido nuevamente: ");
    
    if(strcmp(text,text3)==0)
        printf("Su nombre es correcto");

    if(strcmp(text2,text4)==0)
        printf("Su apellido es correcto");

/**/
    getch();
}

string get_string(string message)
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
    strcpy(message, temp_string);
    return message;
}