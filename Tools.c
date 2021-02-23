/* Herramientas para l trabajo de strings */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <BOOL.h>

#define MaxStrLen 10

struct
{
    bool isPassword;
    bool allowLetters;
    bool allowNumbers;
    bool allowSymbols;
} string_options;

void getstring(char string[]);

void main()
{
    char text[MaxStrLen];

    string_options.allowLetters = true;
    string_options.isPassword = true;
    string_options.allowSymbols = true;
    getstring(text);

    clrscr();
    printf("%s",text);
}

void getstring(char string[])
{
    int letter = 0;
    while (letter < MaxStrLen)
    {
        string[letter] = getch();

        if (string_options.allowSymbols == true && ((string[letter] >= 33 && string[letter] <= 47) || (string[letter] >= 58 && string[letter] <= 64) || (string[letter] >= 91  && string[letter] <= 96) || (string[letter] >= 123 && string[letter] <= 126)))
        {
            if(string_options.isPassword)
                cprintf("*");
            else
                cprintf("%c",string[letter]);

            letter++;
        }
        else if (string[letter] >= 48 && string[letter] <= 57 && letter < MaxStrLen-1 && string_options.allowNumbers == true)
        {
            if(string_options.isPassword)
                cprintf("*");
            else
                cprintf("%c",string[letter]);

            letter++;
        }
        else if (((string[letter]>=65 && string[letter]<=90) || (string[letter]>=97 && string[letter]<=122) || (string[letter]>=48 && string[letter]<=57)) && letter < MaxStrLen-1 && string_options.allowLetters == true)
        {
            if(string_options.isPassword)
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