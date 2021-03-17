#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "c:\\TC20\\repos\\projects\\include\\STDBOOL.h"
#include "c:\\TC20\\repos\\projects\\include\\Tools.h"

float get_float(string Message);

void main()
{
    float a = 9999999;
    clrscr();


	/**scanf("%f",&a);*/
    
    printf("\n\n\n%f",a);
    getch();
    
}
/**/
float get_float(string Message)
{
    char number[14] = {'\0'};
    int integer = 0, decimal = 0, character = 0;
    bool isDecimal = false;

    while (character <= 9)
    {
        number[character] = getch();
        
        if(number[character] >= 48 && number[character] <= 57 && ((character < 9 && isDecimal==false)||(decimal < 6 && character < 9)))
        {
            putchar(number[character]);
            isDecimal ? decimal++ : integer++;
            character++;
        }
        else if(number[character] == 46 && character < 8 && character > 0)
        {
            putchar(number[character]);
            decimal++;
            character++;
            isDecimal = true;
        }
        else if (number[character] == 8 && character > 0)
        {
            number[character] = '\0';
            cprintf("\b \b");
            decimal > 0? decimal-- : integer--;
            character--;

            if (!decimal)
                isDecimal = false;
        }
        else if (number[character] == 13 && character >= 1)
        {
            number[character] = '\0';
            break;
        }
    }
    return atof(number);
}
/**/