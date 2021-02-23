#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <dos.h>;
#include <string.h>;

#define MAX_STRLN 256
#define enye 164
#define up 72
#define down 80
#define enter 13

typedef struct
{
    char user[MAX_STRLN];
    int password;
} accounts;

void Start(void);
void Menu(void);
void Exit(void);
void Exit_Option(void);
void Presentation(void);
void Recargas(void);
void ATM(void);

int RemainingAttemps = 3, Balance = 0;

accounts assigned;

void main()
{
    strcpy(assigned.user, "luis");
    assigned.password = 1402;
    Start();
}

void Start(void)
{
    accounts c1;

    clrscr();

    if (RemainingAttemps == 0)
    {
        Exit();
    }
    else
    {
        
        gotoxy(10, 6);
        printf("Usuario : ");
        scanf("%s", &c1.user);

        gotoxy(10, 8);
        printf("Contrase%ca : ", enye);
        scanf("%d", &c1.password);

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

            getch();
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && c1.password == assigned.password)
        {
            gotoxy(10, 10);
            printf("Usuario Incorrecto");

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(10, 12);
            printf("Le restan %d intentos", RemainingAttemps);

            getch();
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && c1.password != assigned.password)
        {
            gotoxy(10, 10);
            printf("Usuario y Contrase%ca Incorrectos", enye);

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(10, 12);
            printf("Le restan %d intentos", RemainingAttemps);

            getch();
            Start();
        }
    }
}

void Menu(void)
{
    int i, opc, tecla = 0, option = 1, exit = 0;
    char *menu_options[] = {"Presentacion", "Cajero ATM-UNI", "Recargas Tigo-Claro", "Salir", "\0"};
    int PosY[4] = {8,10,12,14}; 
    do
    {
        clrscr();
		textcolor(BLUE);
        gotoxy(30,6);
        cprintf("MENU PRINCIPAL");

        for (i = 0; i < 4; i++)
        {
            textcolor(3+i);
            gotoxy(28, PosY[i]);
            cprintf("%c %s",i+1 == option ? 16 : 0, menu_options[i]);
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
                    option = 4;
                break;
            case down:
                option++;
                if (option > 4) 
                    option = 1;
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
    int i,j = 0;
    char *Presentation_Elements[] = {"NOMBRE  :", "FECHA   :", "GRUPO   :", "PROFE   :", "CARRERA :","\0"};
    char *Presentation_Complements[] = {"Luis Joseph","26/02/2021", "2M1-CO", "Alejandro Ortiz - Aliz","Ing. Computacion","\0"};

    clrscr();

    textcolor(BLUE);
    gotoxy(20,4);
    cprintf("UNIVERSIDAD NACIONAL DE INGENIERIA - UNI");

    for (i = 0; i < 5; i++)
    {
        textcolor(BLUE);
        gotoxy(25, 8 + j);
        cprintf("%s",Presentation_Elements[i]);
        textcolor(CYAN);
        gotoxy(35, 8 + j);
        cprintf("%s",Presentation_Complements[i]);
        j = j + 3;
    }
    getch();
    Menu();
}

void ATM(void)
{
    int i,opt,t = 0,option = 1, ex = 0;
    int Deposit = 0, Retirement = 0;
    char *Options[] = {"Ingresar Saldo","Retirar Saldo","Consultar Saldo","Atras","\0"};

    do
    {
        clrscr();

        gotoxy(24, 6);
        printf("BIENVENIDO A ATM-UNI");

        for (i = 0; i < 4; i++)
        {
            gotoxy(24, 8 + i);
            printf("%c %s",i + 1 == option ? 16 : 0,Options[i]);
        }
        
        do
        {
            t = getch();
        } while (t != up && t != down && t != enter);
        
        switch (t)
        {
        case up:
            option--;
            if (option < 1) 
                option = 4;
            break;
        case down:
            option++;
            if (option > 4)
                option = 1;
            break;
        case enter:
            ex = 1;
        default:
            break;
        }
    } while (ex == 0);
    
    opt = option;

    switch (opt)
    {
    case 1:
        do
        {
            clrscr();
            fflush(stdin);
            printf("Digite la cantidad a Depositar\n");
            scanf("%d", &Deposit);
        } while (Deposit <= 0 || Deposit > 30000);

        Balance = Balance + Deposit;

        printf("Se ha depositado correctamente la cantidad de C$%d netos",Deposit);
        getch();
        ATM();
        break;
    case 2:
        if (Balance == 0)
        {
            clrscr();
            printf("No tiene saldo en la cuenta");
        }else
        {
            do 
            {
                clrscr();
                fflush(stdin);
                printf("Digite la cantidad a Retirar\n");
                scanf("%d", &Retirement);
			}while (Retirement <= 0 || Retirement > Balance);

            Balance = Balance - Retirement;

            printf("Se ha retirado correctamente la cantidad de C$%d netos",Retirement);
        }
        getch();
        ATM();
        break;
    case 3:
        clrscr();
        printf("Su saldo es %d", Balance);
        getch();
        ATM();
        break;
    case 4:
        Menu();
    default:
        break;
    }}

void Recargas(void)
{
    int Amount_Entered = 0;
    long int CellPhone_Number = 0;
    float Four_Numbers = 0;
    char Company[MAX_STRLN];

    if (Balance == 0)
    {
        clrscr();
        printf("No tiene saldo en la cuenta");
        getch();
    }else
    {
        clrscr();
        fflush(stdin);
        printf("Ingrese su numero telefonico\n");
        scanf("%ld",&CellPhone_Number);

        Four_Numbers = CellPhone_Number / 10000;

        if (Four_Numbers > 5500 && Four_Numbers < 5999)
        {
            strcpy(Company,"Claro");
            printf("Su numero %ld es %s",CellPhone_Number,Company);
            getch();
        }else if (Four_Numbers > 7700 && Four_Numbers < 8700)
        {
            strcpy(Company,"Tigo");
            printf("Su numero %ld es %s",CellPhone_Number,Company);
            getch();
        }else
        {
            printf("\nNumero no encontrado");
            getch();
            Recargas();
        }

        while(Amount_Entered == 0)
        {
            clrscr();
            fflush(stdin);
            printf("Ingrese la cantidad a recargar\n");
            scanf("%d",&Amount_Entered);

            if (Amount_Entered > Balance)
            {
                clrscr();
                printf("La cantidad a recargar supera el saldo actual\n");
                printf("Su saldo actual es : %d",Balance);
                Amount_Entered = 0;
                getch();
            }else if (Amount_Entered <= 0)
            {
                clrscr();
                printf("La cantidad a recargar es negativa o nula\n");
                printf("Su saldo actual es : %d",Balance);
                Amount_Entered = 0;
                getch();
            }else
            {
                Balance = Balance - Amount_Entered;
                printf("\nSe ha realizado la recarga con exito al numero %li de la compa%cia %s",CellPhone_Number,enye,Company);
                getch();
            }
        }
    }
    Menu();
}

void Exit_Option(void)
{
    clrscr();
    printf("Fue un placer atenderle...\n");
    printf("Hacer su transacción aqui es seguro, rapido y sencillo\n");
    printf("Le esperamos nuevamente :D "),
    getch();
}

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