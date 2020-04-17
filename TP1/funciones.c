#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int menu()
{

    int opcion;
    system("clear");
    printf("\x1b[32m");
    printf("   =============================================\n");
    printf("  ║                                             ║\n");
    printf("  ║              \x1b[33mMENU DE OPCIONES\x1b[32m               ║\n");
    printf("  ║                                             ║\n");
    printf("   =============================================\n\n");
    printf("\x1b[33m");
    printf("             <<     SUMA       >>\n");
    printf("             <<     RESTA      >>\n");
    printf("             <<    DIVISION    >>\n");
    printf("             << MULTIPLICACION >>\n");
    printf("             <<   FACTORIAL    >>\n\n");
    printf("\x1b[32m");
    printf("   =============================================\n");
    printf("  ║                                             ║\n");
    printf("  ║\x1b[33m  1 --> Ingresar el primer operando: \x1b[32mA =   X ║\n");
    printf("  ║\x1b[33m  2 --> Ingresar el segundo operando: \x1b[32mB =  Y ║\n");
    printf("  ║\x1b[33m  3 --> Calcular las operaciones.\x1b[32m            ║\n");
    printf("  ║\x1b[33m  4 --> Informar resultados.\x1b[32m                 ║\n");
    printf("  ║\x1b[33m  5 --> Salir.\x1b[32m                               ║\n");
    printf("  ║                                             ║\n");
    printf("   =============================================\n\n\n");
    printf("\x1b[33m");
    printf("      --> ESCRIBA LA OPCION ELEGIDA: ");

    scanf("%d", &opcion);
    __fpurge(stdin);

    return opcion;

}

int menuA(int a)
{
    int opcion;

    system("clear");
    printf("\x1b[32m");
    printf("   =============================================\n");
    printf("  ║                                             ║\n");
    printf("  ║              \x1b[33mMENU DE OPCIONES\x1b[32m               ║\n");
    printf("  ║                                             ║\n");
    printf("   =============================================\n\n");
    printf("\x1b[33m");
    printf("             <<     SUMA       >>\n");
    printf("             <<     RESTA      >>\n");
    printf("             <<    DIVISION    >>\n");
    printf("             << MULTIPLICACION >>\n");
    printf("             <<   FACTORIAL    >>\n\n");
    printf("\x1b[32m");
    printf("   ==============================================\n");
    printf("                                                \n");
    printf("\x1b[33m    1 --> Ingresar el primer operando: \x1b[32mA =  (%d) \n", a);
    printf("\x1b[33m    2 --> Ingresar el segundo operando: \x1b[32mB =   Y \n");
    printf("\x1b[33m    3 --> Calcular las operaciones.             \n");
    printf("    4 --> Informar resultados.                  \n");
    printf("    5 --> Salir.                                \n");
    printf("                                                \n");
    printf("\x1b[32m");
    printf("   ==============================================\n\n\n");
    printf("\x1b[33m");
    printf("   --> ESCRIBA LA OPCION ELEGIDA: ");

    scanf("%d", &opcion);
    __fpurge(stdin);

    return opcion;

}

int menuB(int a, int b)
{
    int opcion;


    system("clear");
    printf("\x1b[32m");
    printf("   =============================================\n");
    printf("  ║                                             ║\n");
    printf("  ║              \x1b[33mMENU DE OPCIONES\x1b[32m               ║\n");
    printf("  ║                                             ║\n");
    printf("   =============================================\n\n");
    printf("\x1b[33m");
    printf("             <<     SUMA       >>\n");
    printf("             <<     RESTA      >>\n");
    printf("             <<    DIVISION    >>\n");
    printf("             << MULTIPLICACION >>\n");
    printf("             <<   FACTORIAL    >>\n\n");
    printf("\x1b[32m");
    printf("   ==============================================\n");
    printf("                                                \n");
    printf("\x1b[33m    1 --> Ingresar el primer operando: \x1b[32mA =  (%d) \n", a);
    printf("\x1b[33m    2 --> Ingresar el segundo operando: \x1b[32mB =   (%d) \n", b);
    printf("\x1b[33m    3 --> Calcular las operaciones.             \n");
    printf("    4 --> Informar resultados.                  \n");
    printf("    5 --> Salir.                                \n");
    printf("                                                \n");
    printf("\x1b[32m");
    printf("   ==============================================\n\n\n");
    printf("\x1b[33m");
    printf("   --> ESCRIBA LA OPCION ELEGIDA: ");
    scanf("%d", &opcion);
    __fpurge(stdin);

    return opcion;

}

int sumar(int a, int b)
{
    int rta;
    rta = a + b;

    return rta;
}

int restar(int a, int b)
{
    int rta;
    rta = a - b;

    return rta;
}

float dividir(int a, int b)
{
    float rta;

    if (b != 0)
    {
    rta = (float)a / b;
    }

    return rta;
}

int multiplicar(int a, int b)
{
    int rta;
    rta = a * b;

    return rta;
}

int factorial(int a)
{
   int fact = 1;

    if (a >= 0)
    {
        for (int i = 1; i <= a; i++)
        {
           fact = fact * i;
        }
    } else{
        fact = 0;
    }

    return fact;
}
