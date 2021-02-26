#include <C:\\TC20\\include\\stdio.h>;
#include <C:\\TC20\\include\\stdlib.h>;
#include <C:\\TC20\\include\\conio.h>;
#include <C:\\TC20\\include\\dos.h>;
#include <C:\\TC20\\include\\string.h>;
#include <C:\\TC20\\include\\time.h>;

void Date(int x1, int y1, int x2, int y2, int FirstColor, int SecondColor);

void main()
{
    Date(20,10,20,20,4,6);
    getch();
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

        clrscr();

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
        }
    }
}
