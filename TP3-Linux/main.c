#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "string.h"
#include "utn.h"
#include "stdio_ext.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    float sueldo;
} eEmpleado;

int main()
{

    LinkedList* listaEmpleados = ll_newLinkedList();

    char seguir = 's';
    char confirma;
    int triggerCarga = 0;

    do{
        switch(menu())
        {
           case 1:
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("\nSe han cargado los datos correctamente.");
                    triggerCarga = 1;
                }
                else
                    {
                    printf("\nNo se pudo cargar los datos.");
                    }
                break;

           case 2:
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("\nSe han cargado los datos correctamente.\n");
                    triggerCarga = 1;
                }
                else
                    {
                    printf("\nNo se pudo cargar los datos.");
                    }
                break;

           case 3:
                if (controller_addEmployee(listaEmpleados) == 1)
                {
                    triggerCarga = 1;
                }
                break;

           case 4:
                if (triggerCarga == 1)
                {
                controller_editEmployee(listaEmpleados);
                }
                else
                    {
                    printf("\n\nNo se puede editar un empleado si no cargo uno.\n\n");
                    }
                break;

           case 5:
                if (triggerCarga == 1)
                {
                controller_removeEmployee(listaEmpleados);
                 }
                else
                    {
                    printf("\n\nNo se puede dar de baja un empleado si no cargo uno.\n\n");
                    }
                break;

           case 6:
                if (triggerCarga == 1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                    {
                        printf("\n\nNo se puede listar empleados si no cargo uno.\n\n");
                    }
                break;

           case 7:
                if (triggerCarga == 1)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                    {
                        printf("\n\nNo se puede ordenar empleados si no cargo uno.\n\n");
                    }
                break;

           case 8:
            if (triggerCarga == 1)
                {
                    if (controller_saveAsText("data.csv", listaEmpleados) == 1)
                    {
                        printf("\n\nSe ha guardado correctamente como texto.\n\n");
                    }
                     else
                        {
                        printf("\nNo se pudieron guardar los datos.\n");
                        }
                 }
                else
                    {
                        printf("\n\nNo se puede guardar la lista si no cargo uno.\n\n");
                    }
                break;

           case 9:
            if (triggerCarga == 1)
                {
                    if(controller_saveAsBinary("data.bin",listaEmpleados) == 1)
                    {
                        printf("\n\nSe ha guardado correctamente como binario.");
                    }
                    else
                        {
                        printf("\nNo se pudieron guardar los datos.\n");
                        }
                 }
                 else
                    {
                        printf("\n\nNo se puede guardar la lista si no cargo uno.\n\n");
                    }
                break;

           case 10:
                printf("Ingrese 's' para confirmar salida: ");
                __fpurge(stdin);
                scanf("%c", &confirma);

                if(confirma == 's')
                {
                    seguir = 'n';
                    printf("\nHa finalizado el programa\n");
                }
                break;
        }
        getchar();

    }while(seguir == 's');



    //ll_deleteLinkedList(listaEmpleados);
    return 0;
}





















