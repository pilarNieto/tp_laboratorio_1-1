#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "stdio_ext.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    FILE* f;

    if( path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path, "r");

        if(f != NULL)
        {
            if(parser_EmployeeFromText(f, pArrayListEmployee))
            {
                retorno = 1;
            }
            fclose(f);
        }
    }
    else
        {
            printf("No se pudo inicializar el array.");
        }

    return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    FILE* f;

    if( path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path, "rb");

        if(f != NULL)
        {
            if(parser_EmployeeFromBinary(f, pArrayListEmployee))
            {
                retorno = 1;
            }
            fclose(f);
        }
    }
    else
        {
            printf("No se pudo inicializar el array.");
        }

    return retorno;

}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp = NULL;

    char id[20];
    char nombre[20];
    char horas[20];
    char sueldo[20];
    int id2;
    int sueldo2;
    int horas2;
    int retorno = 0;
    system("clear");

    printf("***** ALTA DE EMPLEADO *****\n\n");
    emp = employee_new();


    if(emp != NULL)
    {
        if((utn_getNombre(nombre, 20, "Ingrese el nombre: ", "Error. Ingreso un nombre invalido", 2) == 0) &&
           (utn_getNumero(&horas2, "Ingrese las horas trabajadas: ", "\nError. Ingreso un numero invalido.", 0, 999999, 2)) == 0 &&
           (utn_getNumero(&sueldo2, "Ingrese el sueldo: ", "\nError. Ingreso un sueldo invalido.", 0, 999999, 2)) == 0)
        {

           obtenerId(&id2);
           sprintf(id, "%d", id2);
           sprintf(horas, "%d", horas2);
           sprintf(sueldo, "%d", sueldo2);

           emp = employee_newParametros(id, nombre, horas, sueldo);
           ll_add(pArrayListEmployee, emp);
           actualizarId(id2);
           printf("\n\nSe ha agredado correctamente al empleado.\n\n");
           retorno = 1;
        }
        else
            {
            printf("No se pudo agregar al empleado.\n");
            employee_delete(emp);
            }
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int idEmpleado;
    int indice;
    Employee* emp;

    controller_ListEmployee(pArrayListEmployee);

    printf("\n\n          *** MODIFICAR EMPLEADO ***\n");

    if(utn_getNumero(&idEmpleado, "\n\nIngrese el ID del empleado para modificar: ", "Error, ingreso un Id invalido.\n", 1, 2000, 2) == 0 )
    {
    indice = buscarEmpleadoPorID(pArrayListEmployee, idEmpleado);
    emp = (Employee*) ll_get(pArrayListEmployee, indice);

        if( pArrayListEmployee != NULL)
        {
            system("clear");
            printf("\n\n          *** MODIFICAR EMPLEADO ***\n\n");
            printf(" _______________________________________________\n");
            printf("│      │                      │        │        │\n");
            printf("│  ID  │           NOMBRE     │  HORAS │ SUELDO │  \n");
            printf("│______│______________________│________│________│\n");
            showEmployee(emp);
            printf("│______│______________________│________│________│\n");
        }
          if(modificarEmpleado(pArrayListEmployee, idEmpleado) == 1)
          {
            retorno = 1;
          }
    }
    else
    {
        printf("\n\nNo se encontro empleado con el ID ingresado.\n\n");
    }
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int idEmpleado;
    int indice;
    char confirma = 's';
    Employee* emp;

    controller_ListEmployee(pArrayListEmployee);

    printf("\n\n          *** BAJA EMPLEADO ***\n");

    if(utn_getNumero(&idEmpleado, "\n\nIngrese el ID del empleado para dar de baja: ", "Error, ingreso un Id invalido.\n", 1, 2000, 2) == 0 )
    {
    indice = buscarEmpleadoPorID(pArrayListEmployee, idEmpleado);
    emp = (Employee*) ll_get(pArrayListEmployee, indice);

        if( pArrayListEmployee != NULL && emp != NULL)
        {
            system("clear");
            printf("\n\n          *** BAJA EMPLEADO ***\n\n");
            printf(" _______________________________________________\n");
            printf("│      │                      │        │        │\n");
            printf("│  ID  │           NOMBRE     │  HORAS │ SUELDO │  \n");
            printf("│______│______________________│________│________│\n");
            showEmployee(emp);
            printf("│______│______________________│________│________│\n");

            printf("\n\nIngrese 's' para confirmar baja: ");
            __fpurge(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                ll_remove(pArrayListEmployee, indice);
                printf("\n\nSe ha anulado correctamente.\n\n");
                retorno = 1;
            }
            else
            {
                printf("\n\nLa anulacion ha sido cancelada.\n\n");
            }

        }
         getchar();
    }
    else
    {
        printf("\n\nNo se encontro empleado con el ID ingresado.\n\n");
    }

    return retorno;
}


int controller_ListEmployee(LinkedList *pArrayListEmployee)
{

    int retorno = 1;
    Employee* emp;

    if( pArrayListEmployee != NULL)
    {
        retorno = 1;

        system("clear");
        printf(" _______________________________________________\n");
        printf("│      │                      │        │        │\n");
        printf("│  ID  │           NOMBRE     │  HORAS │ SUELDO │  \n");
        printf("│______│______________________│________│________│\n");

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            emp = (Employee*) ll_get(pArrayListEmployee, i);
            if (emp  != NULL && ll_len(pArrayListEmployee) > 0)
            {
                showEmployee(emp);
            }
        // 898???
        }
        printf("│______│______________________│________│________│\n");
    }

    return retorno;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int orden;
    int retorno = 0;

    printf("\n ***** ORDENAMIENTO POR NOMBRE *****\n");

    if(utn_getNumero(&orden, "\n\n1. Ascendente\n2. Descendente\n\nIngrese el orden a efectuar: ","Error, ingreso un numero invalido.", 0,2, 2) == 0)
    {
        if( pArrayListEmployee != NULL)
        {
                ll_sort(pArrayListEmployee, ordenarPorNombre, orden);
                controller_ListEmployee(pArrayListEmployee);
                retorno = 1;
        }   else
            {
                printf("\nNo se pudo realizar el ordenamiento\n");
            }

    }
    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"w") ;
    Employee* emp;
    int retorno = 0;

    if(f != NULL && pArrayListEmployee != NULL && path != NULL)
    {
        fprintf(f,"  ID                NOMBRE  HORAS TRABAJADAS          SUELDO \n");

        for (int i =0; i < ll_len(pArrayListEmployee); i++)
        {
            emp = (Employee*) ll_get(pArrayListEmployee, i);

            if (emp != NULL)
            {
                fprintf(f, "%d,%s,%d,%d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
                retorno = 1;
            }
        }
        fclose(f);
        ll_clear(pArrayListEmployee);

    }
    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path, "wb");

	Employee *emp;

	int retorno = 0;

	if ( f != NULL && pArrayListEmployee != NULL && path != NULL)
	{
		for (int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			emp = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(emp, sizeof(Employee), 1, f);
            retorno = 1;
		}

		fclose(f);
		ll_clear(pArrayListEmployee);
	}
	return retorno;
}

