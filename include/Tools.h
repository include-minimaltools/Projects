#ifndef stdbool.h
#include "c:\\TC20\\repos\\projects\\include\\STDBOOL.h"
#endif

typedef char *string;

enum allowed_characters
{
    Alls,
    OnlyNumbers,
    OnlyLetters,
    LettersAndSymbols,
    NumbersAndSymbols
};

int allowed_characters;
bool isPassword;
int MaxStrLn = 80;
int MinStrLn = 2;
int charPassword = 42;

string get_string(string message)
{
    int letter = 0;
    char temp_string[80]={'\0'};

    cprintf("%s", message);
    if(strcmp(message,'\0')==0)
    {
        textcolor(WHITE);
        clrscr();
        cprintf("Error: Debe pasar un parametro a la funcion _getstring()");
        getch();
        exit(-1);
    }
        
        
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