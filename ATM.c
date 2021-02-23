/**/
#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <dos.h>;
#include <string.h>;

#define MAX_SRTLN 256
#define enye 164
#define up 72
#define down 80
#define enter 13

typedef struct
{
    char user[MAX_SRTLN];
    int password;
} accounts;

void Start(void);
void Menu(void);
void RemoveCursor(int x, int y);
void Exit(void);
void Exit_Option(void);
void Presentation(void);
void Recargas(void);
void ATM(void);

int RemainingAttemps = 3;

void main()
{
    Start();
}

void Start(void)
{
    accounts assigned, c1;
    strcpy(assigned.user, "luis");
    assigned.password = 1402;

    clrscr();

    if (RemainingAttemps == 0)
    {
        Exit();
    }
    else
    {
        
        gotoxy(10, 6);
        printf("Usuario : ");
<<<<<<< HEAD
        scanf("%s", &c1.user);
        gotoxy(10, 8);
        printf("Contrase%ca : ", enye);
        scanf("%d", &c1.password);

        /*fflush(stdin);*/
=======
        scanf("%s",&c1.user);

        gotoxy(10,8);
        printf("Contrase%ca : ",enye);
        scanf("%d",&c1.password);
>>>>>>> 731f5c54f27fa59ad26888e020a59b4f55ee89ea

        if (strcmp(c1.user, assigned.user) == 0 && c1.password == assigned.password)
        {
            Menu();
        }
        else if (strcmp(c1.user, assigned.user) == 0 && c1.password != assigned.password)
        {
            gotoxy(10, 10);
            printf("Contrase%ca Incorrecta", enye);
            RemainingAttemps = RemainingAttemps - 1;
            gotoxy(10, 12);
            printf("Le restan %d intentos", RemainingAttemps);
            sleep(2);
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && c1.password == assigned.password)
        {
            gotoxy(10, 10);
            printf("Usuario Incorrecto");
            RemainingAttemps = RemainingAttemps - 1;
            gotoxy(10, 12);
            printf("Le restan %d intentos", RemainingAttemps);
            sleep(2);
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && c1.password != assigned.password)
        {
            gotoxy(10, 10);
            printf("Usuario y Contrase%ca Incorrectos", enye);
            RemainingAttemps = RemainingAttemps - 1;
            gotoxy(10, 12);
            printf("Le restan %d intentos", RemainingAttemps);
            sleep(2);
            Start();
        }
    }
}

void Menu(void)
{
    int i, tecla = 0, opc, option = 1, exit = 0;
    char *menu_options[] = {"Presentacion", "Cajero ATM-UNI", "Recargas Tigo-Claro", "Salir", "\0"};
    do
    {
        clrscr();

        for (i = 0; i < 4; i++)
        {
            gotoxy(10, 12 + i);
            printf("%c %s",i+1 == option ? 16 : 0, menu_options[i]);
        }

        do
        {
            tecla = getch();
        } while (tecla != enter && tecla != up && tecla != down);

        switch (tecla)
        {
            case up:
                option--;
                if (option < 1)
                {
                    option = 4;
                }
                break;
            case down:
                option++;
                if (option > 4)
                {
                    option = 1;
                }
                break;
            case enter:
                exit = 1;
            default:
                break;
        }
    } while (exit == 0);

    opc = option;

    switch (opc)
    {
    case 1:
        Presentation();
        break;
    case 2:
        ATM();
        break;
    case 3:
        Recargas();
        break;
    case 4:
        Exit_Option();
        break;
    default:
        break;
    }
}

void Presentation(void)
{
    clrscr();
    printf("Gabriel");
    getch();
    Menu();
}

void ATM(void)
{
    clrscr();
    printf("Hola numero 2");
    getch();
    Menu();
}

void Recargas(void)
{
    clrscr();
    printf("Hola numero 3");
    getch();
    Menu();
}

void Exit_Option(void)
{
    clrscr();
    printf("Hola numero 4");
    getch();
}

<<<<<<< HEAD
void RemoveCursor(int x, int y)
{
    textcolor(BLACK);
    gotoxy(x, y);
    cprintf("%c", 219);
    gotoxy(x, y);
}

=======
>>>>>>> 731f5c54f27fa59ad26888e020a59b4f55ee89ea
void Exit(void)
{
    clrscr();
    printf("Ha agotado sus 3 intentos\n");
    printf("-------------------------\n");
    printf("Estimado Usuario : luis\n");
    printf("Su cuenta sera bloqueada por 24 horas por motivos de seguridad\n");
    printf("Gracias por su comprension");
    getch();
}