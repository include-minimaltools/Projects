#include <C:\\TC20\\include\\stdio.h>;
#include <C:\\TC20\\include\\stdlib.h>;
#include <C:\\TC20\\include\\conio.h>;
#include <C:\\TC20\\include\\dos.h>;
#include <C:\\TC20\\include\\string.h>;
#include <C:\\TC20\\include\\time.h>;

void Date(int x1, int y1, int x2, int y2, int FirstColor, int SecondColor);
float Dollar_Value(void);

void main()
{
    float n;
    n = Dollar_Value();
    printf("%f",n);

	/*Date(20,10,20,20,4,6);*/
    getch();
}

float Dollar_Value(void)
{
    float Fixed_Dollar = 34.9380, NewPrice_Dollar = 0;
    float Monthly_Rise = 0.0795, Annual_Rise = 0.9541;
	int Fixed_Month = 2, Fixed_Year = 2021;
    int Current_Month = 0, Current_Year = 0, Month_Difference = 0, Year_Difference = 0;

    struct date d;
    struct time t;

    gettime(&t);
    getdate(&d);

    clrscr();

    Current_Month = d.da_mon;
    Current_Year = d.da_year;

    if (Current_Month >= Fixed_Month && Current_Year == Fixed_Year)
    {
        Month_Difference = Current_Month - Fixed_Month;
        NewPrice_Dollar = Fixed_Dollar + (Monthly_Rise * Month_Difference);
    }else if (Current_Month >= Fixed_Month && Current_Year > Fixed_Year)
    {
        Year_Difference = Current_Year - Fixed_Year;
        Month_Difference = Current_Month - Fixed_Month;
        NewPrice_Dollar = Fixed_Dollar + (Annual_Rise * Year_Difference) + (Monthly_Rise * Month_Difference);
    }else
    {
        NewPrice_Dollar = 0;
    }

    return NewPrice_Dollar;
}

void Date(int x1, int y1, int x2, int y2, int FirstColor, int SecondColor)
{
    struct date d;
    struct time t;
    int ejm = 0;

    while (ejm < 60)
    {
        gettime(&t);
        getdate(&d);

        gotoxy(x1, y1);
        textcolor(FirstColor);
        cprintf("Fecha : %d / %02d / %d \n", d.da_day, d.da_mon,d.da_year);

        gotoxy(x2,y2);
        textcolor(SecondColor);
        cprintf("Hora : %d: %d: %d", t.ti_hour, t.ti_min, t.ti_sec);

        ejm = t.ti_sec;

        sleep(1);

        if (ejm == 59)
        {
            ejm = 0;
            clrscr();
        }
    }
}
