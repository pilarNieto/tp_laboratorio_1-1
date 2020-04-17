#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <stdio_ext.h>

int main()
{
    //SE DEFINEN VARIABLES
    int respuesta = 0;
    int operador1;
    int operador2;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDiv;
    int resultadoMult;
    int resultadoFact1;
    int resultadoFact2;
    int opcion = menu();
    int triggerA = 0;
    int triggerB = 0;
    int triggerCalcular = 0;


    //INICIO DEL WHILE GENERAL
    do
    {
        switch (opcion)
        {
        case 1: // SE INGRESA EL PRIMER OPERANDO
            system("clear");
            printf("\n\n --> INGRESE EL PRIMER OPERANDO: ");
            scanf("%d", &operador1);
            triggerA = 1;
            opcion = menuA(operador1);
            break;

        case 2: // SE INGRESA EL SEGUNDO OPERANDO
            if ( triggerA == 1)
            {
                system("clear");
                printf("\n\n --> INGRESE EL SEGUNDO OPERANDO: ");
                scanf("%d", &operador2);
                triggerB = 1;
                opcion = menuB(operador1, operador2);
                break;
            }
            else // SE RECHAZA SI NO INGRESO EL PRIMER OPERANDO
            {
                system("clear");
                printf("\x1b[32m");
                printf("   ==========================================================\n");
                printf("  ║                                                          ║\n");
                printf("  ║ \x1b[33mNO PUEDE INGRESAR EL SEGUNDO OPERANDO ANTES DEL PRIMERO.\x1b[32m ║\n");
                printf("  ║                                                          ║\n");
                printf("   ==========================================================\n\n\n");
                printf("  \x1b[33m--> Presione ENTER para continuar: ");
                getchar();
                opcion = menu();
                break;
            }

        case 3:// SE REALIZAN TODAS LAS OPERACIONES
            system("clear");
            if (triggerB == 1)
            {
                resultadoSuma = sumar(operador1, operador2);
                resultadoResta = restar(operador1, operador2);
                resultadoDiv = dividir(operador1, operador2);
                resultadoMult = multiplicar(operador1, operador2);
                resultadoFact1 = factorial(operador1);
                resultadoFact2 = factorial(operador2);
                printf("   =============================================\n");
                printf("  ║                                             ║\n");
                printf("  ║      \x1b[32m¡SE HAN REALIZADO LAS OPERACIONES!\x1b[33m     ║\n");
                printf("  ║                                             ║\n");
                printf("   =============================================\n\n\n");
                printf("  \x1b[32m--> Presione ENTER para continuar: ");
                getchar();
                triggerCalcular = 1;
                opcion = menuB(operador1, operador2);
            }
            else // SE RECHAZA SI NO SE INGRESARON LOS OPERANDOS 1 Y 2. VUELVE AL MENU INICIAL
            {
                printf("\x1b[32m");
                printf("   ====================================================================\n");
                printf("  ║                                                                    ║\n");
                printf("  ║ \x1b[33mNO PUEDE REALIZAR LAS OPERACIONES SI NO INGRESO LOS DOS OPERANDOS.\x1b[32m ║\n");
                printf("  ║                                                                    ║\n");
                printf("   ====================================================================\n\n\n");
                printf("  \x1b[33m--> Presione ENTER para continuar: ");
                getchar();
                opcion = menu();
            }
            break;

        case 4: // SE MUESTRAN LOS RESULTADOS CON SUS VALIDACIONES (DIVISION POR CERO, FACTORIAL NEGATIVO)

            system("clear");
            if (triggerCalcular == 1)
            {
                printf("\x1b[32m");
                printf("         =============================================\n");
                printf("        ║                                             ║\n");
                printf("        ║                 \x1b[33mRESULTADOS\x1b[32m                  ║\n");
                printf("        ║                                             ║\n");
                printf("         =============================================\n\n");
                printf("  ============================================================\n\n");
                printf("\x1b[33m");
                printf("        -La suma entre el numero %d y el numero %d es %d.          \n\n", operador1, operador2,resultadoSuma);
                printf("       -La resta entre el numero %d y el numero %d es %d.         \n\n", operador1, operador2,resultadoResta);
                if (operador2 != 0)
                {
                printf("      -La division entre el numero %d y el numero %d es %.2f.    \n\n", operador1, operador2,resultadoDiv);
                }
                else
                {
                printf("                    -No se puede dividir por 0.\n\n");
                }
                printf("  -La multiplicacion entre el numero %d y el numero %d es %d.\n\n", operador1, operador2,resultadoMult);
                if (operador1 >= 0 && operador2 >= 0)
                {
                printf("      -El factorial de %d es %d y el factorial de %d es %d.         \n\n", operador1, resultadoFact1, operador2, resultadoFact2);
                }
                else if(operador1 >= 0 && operador2 < 0)
                {
                printf("     -El factorial de %d es %d y el factorial de %d no existe.  \n\n", operador1, resultadoFact1, operador2);
                }
                else if(operador1 < 0 && operador2 >= 0)
                {
                printf("    -El factorial de %d no existe y el factorial de %d es %d.  \n\n", operador1, operador2, resultadoFact2);
                }
                else
                {
                printf("            No existen factoriales de numeros negativos.             \n\n");
                }
                printf("\x1b[32m");
                printf("  ===========================================================\n\n\n\n");
                printf("\x1b[33m");
                printf("    --> Presione ENTER para continuar: ");
                getchar();
                __fpurge(stdin);
                triggerA = 0;
                triggerB = 0;
                triggerCalcular = 0;
                opcion = menu();
                break;
            }
            else
            {   // SE RECHAZA SI NO SE HICIERON LAS OPERACIONES PREVIAS Y VUELVE AL MENU INICIAL
                printf("\x1b[32m");
                printf("   ================================================================\n");
                printf("  ║                                                                ║\n");
                printf("  ║ \x1b[33mNO SE PUEDEN MOSTRAR RESULTADOS SI NO REALIZO LAS OPERACIONES.\x1b[32m ║\n");
                printf("  ║                                                                ║\n");
                printf("   ================================================================\n\n\n");
                printf("\x1b[33m");
                printf("  --> Presione ENTER para continuar: ");
                getchar();
                opcion = menu();
            }

            break;

        case 5: // SE SALE DEL SWITCH Y DEL WHILE
            system("clear");
            respuesta = 1;
            printf("\x1b[32m");
            printf("   =============================================\n");
            printf("  ║                                             ║\n");
            printf("  ║         \x1b[33mHA FINALIZADO LAS OPERACIONES.\x1b[32m      ║\n");
            printf("  ║                                             ║\n");
            printf("   =============================================\n\n\n");
            printf("  \x1b[33m");
            break;

        default: // SE RECHAZA SI NO INGRESA NINGUNA OPCION CORRECTA DEL SWITCH Y VUELVE AL MENU INICIAL
            system("clear");
            printf("\x1b[32m");
            printf("   =============================================\n");
            printf("  ║                                             ║\n");
            printf("  ║       \x1b[33mHA INGRESADO UNA OPCION INVALIDA.\x1b[32m     ║\n");
            printf("  ║                                             ║\n");
            printf("   =============================================\n\n\n");
            printf("  \x1b[33m");
            printf("  --> Presione ENTER para continuar: ");
            getchar();
            opcion = menu();
        }

    }
    while (respuesta == 0);
    // FIN DEL WHILE

    return 0;
}

