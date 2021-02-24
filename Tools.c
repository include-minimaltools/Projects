#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <BOOL.h>

#define maxStrLen 10

typedef char * string;

enum allowed_characters 
{
    Alls,
    OnlyNumbers,
    OnlyLetters,
    LettersAndSymbols,
    NumbersAndSymbols
};

string get_string(char *message);

int characters;
bool isPassword;
int MaxStrLn = 20;
int MinStrLn = 2;

void main()
{
    string text;

    clrscr();
    text = get_string("");

    printf("\n\n%s",text);

    getch();
}

string get_string(char *message)
{
    string text;
    int letter = 0;
    char temp_string[maxStrLen];
    printf("%s",message);
    while (letter < maxStrLen)
    {
        temp_string[letter] = getch();

        if ((characters == LettersAndSymbols || characters == NumbersAndSymbols || characters == Alls) && letter < maxStrLen-1 && ((temp_string[letter] >= 33 && temp_string[letter] <= 47) || (temp_string[letter] >= 58 && temp_string[letter] <= 64) || (temp_string[letter] >= 91  && temp_string[letter] <= 96) || (temp_string[letter] >= 123 && temp_string[letter] <= 126)))
        {
            if(isPassword)
                cprintf("*");
            else
                cprintf("%c",temp_string[letter]);

            letter++;
        }
        else if ((characters == OnlyNumbers || characters == Alls) && letter < maxStrLen-1  && temp_string[letter] >= 48 && temp_string[letter] <= 57)
        {
            if(isPassword)
                cprintf("*");
            else
                cprintf("%c",temp_string[letter]);

            letter++;
        }
        else if ((characters == OnlyLetters || characters == LettersAndSymbols || characters == Alls) && letter < maxStrLen-1 && ((temp_string[letter]>=65 && temp_string[letter]<=90) || (temp_string[letter]>=97 && temp_string[letter]<=122) || (temp_string[letter]>=48 && temp_string[letter]<=57)))
        {
            if(isPassword)
                cprintf("*");
            else
                cprintf("%c",temp_string[letter]);

            letter++;
        }
        else if(temp_string[letter]==8 && letter > 0)
        {
            temp_string[letter]='\0';
            cprintf("\b%c\b",0);
            letter-=1;
        }
        else if(temp_string[letter]==13 && letter >= MinStrLn)
        {
            temp_string[letter]='\0';
            break;
        }

    }

    memcpy(text,temp_string,sizeof(temp_string));
    return text;
}