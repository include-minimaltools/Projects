#include <C:\\TC20\\include\\stdio.h>;
#include <C:\\TC20\\include\\stdlib.h>;
#include <C:\\TC20\\include\\conio.h>;
#include <C:\\TC20\\include\\dos.h>;
#include <C:\\TC20\\include\\string.h>;
#include "C:\\TC20\\repos\\Projects\\include\\TOOLS.H"

#define MAX_STRLN 256
#define enye 164
#define up 72
#define down 80
#define enter 13
#define blok 219

typedef struct
{
    string user;
    string password;
} accounts;

void Start(void);
void Menu(void);
void Exit(void);
void Exit_Option(void);
void Presentation(void);
void Recargas(void);
void ATM(void);
void Remove_Cursor(int x, int y);
void Frame(int lineas);

int RemainingAttemps = 3, Balance = 0;

accounts assigned;

void main()
{
    assigned.user = "luis";
    assigned.password = "2302";
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
        Frame(1);
        textcolor(RED);
        gotoxy(18, 6);
        cprintf("Project IDEDIM - Inspirado DEl DIno de la Mitch :D");
        gotoxy(18, 7);

        textcolor(BLUE);
        gotoxy(24, 10);
        MinStrLn = 2;
        MaxStrLn = 7;
        isPassword = false;
        c1.user = get_string("Usuario: ");
        
        textcolor(BLUE);
        gotoxy(24, 14);
        MinStrLn = 3;
        MaxStrLn = 6;
        isPassword = true;
        c1.password = get_string("Contra: ");

        if (strcmp(c1.user, assigned.user) == 0 && strcmp(c1.password, assigned.password) == 0)
        {
            Menu();
        }
        else if (strcmp(c1.user, assigned.user) == 0 && strcmp(c1.password, assigned.password) != 0)
        {
            textcolor(WHITE);
            gotoxy(24, 17);
            cprintf("Contrase%ca Incorrecta", enye);

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(24, 19);
            cprintf("Le restan %d intentos", RemainingAttemps);
            getch();
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && strcmp(c1.password, assigned.password) == 0)
        {
            textcolor(WHITE);
            gotoxy(24, 17);
            cprintf("Usuario Incorrecto");

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(24, 19);
            cprintf("Le restan %d intentos", RemainingAttemps);
            getch();
            Start();
        }
        else if (strcmp(c1.user, assigned.user) != 0 && strcmp(c1.password, assigned.password) != 0)
        {
            textcolor(WHITE);
            gotoxy(24, 17);
            cprintf("Usuario y Contrase%ca Incorrectos", enye);

            RemainingAttemps = RemainingAttemps - 1;

            gotoxy(24, 19);
            cprintf("Le restan %d intentos", RemainingAttemps);
            getch();
            Start();
        }
    }
    
}

void Menu(void)
{
    int i, opc, tecla = 0, option = 1, exit = 0;
    char *menu_options[] = {"Presentacion", "Cajero ATM-UNI", "Recargas Tigo-Claro", "Salir", "\0"};
    int PosY[4] = {10,12,14,16}; 
    do
    {
        clrscr();
        Frame(1);

        textcolor(RED);
        gotoxy(5,3);
        cprintf("Usuario : %s",assigned.user);
        gotoxy(5,4);
        cprintf("Saldo : C$ %d",Balance);

		textcolor(BLUE);
        gotoxy(30,7);
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
    Frame(2);
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
    int Deposit = 0, Retirement = 0, PosY[4] = {10,12,14,16};
    char *Options[] = {"Ingresar Saldo","Retirar Saldo","Consultar Saldo","Atras","\0"};

    do
    {
        clrscr();
        Frame(1);

        textcolor(RED);
        gotoxy(5,3);
        cprintf("Usuario : %s",assigned.user);

        textcolor(4);
        gotoxy(28, 7);
        cprintf("BIENVENIDO A ATM-UNI");

        for (i = 0; i < 4; i++)
        {
            textcolor(5+i);
            gotoxy(28, PosY[i]);
            cprintf("%c %s",i + 1 == option ? 16 : 0,Options[i]);
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
            textcolor(BLUE);
            printf("Digite la cantidad a Depositar\n");
            printf("C$ ");
            scanf("%d", &Deposit);
        } while (Deposit <= 0 || Deposit > 30000);

        Balance = Balance + Deposit;

        textcolor(WHITE);
        cprintf("\nSe ha depositado correctamente la cantidad de C$ %d netos",Deposit);
        getch();
        ATM();
        break;
    case 2:
        if (Balance == 0)
        {
            clrscr();
            textcolor(BLUE);
            cprintf("No tiene saldo en la cuenta");
        }else
        {
            do 
            {
                clrscr();
                fflush(stdin);
                textcolor(BLUE);
                printf("Digite la cantidad a Retirar\n");
                printf("C$ ");
                scanf("%d", &Retirement);
			}while (Retirement <= 0 || Retirement > Balance);

            Balance = Balance - Retirement;

            cprintf("\nSe ha retirado correctamente la cantidad de C$ %d netos",Retirement);
        }
        getch();
        ATM();
        break;
    case 3:
        clrscr();
        textcolor(BLUE);
        cprintf("Su saldo es C$ %d", Balance);
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
        textcolor(BLUE);
        clrscr();
        cprintf("No tiene saldo en la cuenta");
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
            printf("C$ ");
            scanf("%d",&Amount_Entered);

            if (Amount_Entered > Balance)
            {
                clrscr();
                printf("La cantidad a recargar supera el saldo actual\n");
                printf("Su saldo actual es : C$ %d",Balance);
                Amount_Entered = 0;
                getch();
            }else if (Amount_Entered <= 0)
            {
                clrscr();
                printf("La cantidad a recargar es negativa o nula\n");
                printf("Su saldo actual es : C$ %d",Balance);
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
    printf("Hacer su transaccion aqui es seguro, rapido y sencillo\n");
    printf("Le esperamos nuevamente :D "),
    getch();
}

void Exit(void)
{
    clrscr();
    printf("Ha agotado sus 3 intentos\n\n");
    printf("-------------------------\n\n");
    printf("Estimado Usuario : %s\n\n",assigned.user);
    printf("Su cuenta sera bloqueada por 24 horas por motivos de seguridad\n\n");
    printf("Gracias por su comprension");
    getch();
}

void Remove_Cursor(int x, int y)
{
    textcolor(BLACK);
    gotoxy(x,y);
    cprintf("%c",blok);
    gotoxy(x,y);
}

void Frame(int lineas)
{
    int i;
    char lineaH=196, lineaV=179, esquinaNW=218, esquinaNE=191, esquinaSW=192, esquinaSE=217;

    if(lineas!=1)
    {
        lineaH = 205;
        lineaV = 286;
        esquinaNW = 201;
        esquinaNE = 187;
        esquinaSW = 200;
        esquinaSE = 188;
    }

    textcolor(CYAN);
    for(i=2;i<=79;i++)
    {
        gotoxy(i,1);
        if(i!=2&&i!=79)
            cprintf("%c",lineaH);
        else if(i==2)
            cprintf("%c",esquinaNW);
        else
            cprintf("%c",esquinaNE);
        
        gotoxy(i,25);
        if(i!=2&&i!=79)
            cprintf("%c",lineaH);
        else if(i==2)
            cprintf("%c",esquinaSW);
        else
            cprintf("%c",esquinaSE);
        
        if(i>=2&&i<=24)
        {
            gotoxy(2,i);
            cprintf("%c",lineaV);
            
            gotoxy(79,i);
            cprintf("%c",lineaV);
        }
    }
}