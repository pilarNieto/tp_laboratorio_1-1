#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "string.h"
#include "utn.h"
#include "stdio_ext.h"


int menu()
{
    int opcion;
    system("clear");
    printf("***** MENU DE OPCIONES *****\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado.\n");
    printf("4. Modificar datos de empleado.\n");
    printf("5. Baja de empleado.\n");
    printf("6. Listar empleados.\n");
    printf("7. Ordenar empleados.\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir.\n\n");
    __fpurge(stdin);
    utn_getNumero(&opcion, "Ingrese una opcion: ", "Error: Ingreso una opcion invalida.\n", 1, 10,1);

    return opcion;
}

Employee* employee_new()
{
    Employee* emp;

    emp = (Employee*) malloc(sizeof(Employee));

    return emp;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo)
{
    Employee* emp = NULL;

    emp = employee_new();

    if(emp != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldo != NULL)
    {
        if((employee_setId(emp, atoi(idStr)) == 0) ||
           (employee_setNombre(emp, nombreStr) == 0) ||
           (employee_setHorasTrabajadas(emp, atoi(horasTrabajadasStr)) == 0)||
           (employee_setSueldo(emp, atoi(sueldo)) == 0))
           {
            employee_delete(emp);
            emp = NULL;
           }
    }
    else
    {
        printf("No se pudieron agregar los nuevos parametros.");
    }
    return emp;
}


int employee_setId(Employee* this, int id)
{
    int retorno = 0;

    if (this != NULL && id >= 0)
    {
        retorno = 1;
        this->id = id;
    }
    return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int retorno = 0;

    if(this != NULL && id!= NULL)
    {
        *id = this-> id;
        retorno = 1;
    }

    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;

    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre, nombre, 20);
        retorno = 1;
    }

    return retorno;
}


int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = 0;

    return retorno;
}


int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = 0;

    if (this != NULL && horasTrabajadas >=0)
    {
        retorno = 1;
        this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = 0;

    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}


int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = 0;

    if (this != NULL && sueldo >=0)
    {
        retorno = 1;
        this->sueldo = sueldo;
    }
    return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;

    if (this != NULL && sueldo >= 0)
    {
        retorno = 1;
        sueldo = this->sueldo;
    }
    return retorno;
}


void employee_delete(Employee* this )
{
    if (this != NULL)
    {
        free(this);
    }
}


int showEmployee(Employee* this)
{
    int retorno = 0;

    if(this != NULL)
    {
        printf("│% 5d │ %20s │ %6d │ %6d │\n", this->id, this->nombre, this-> horasTrabajadas, this->sueldo);
        retorno = 1;
    }
    return retorno;
}

int modificationMenu()
{
    int opcion;

    printf("\n**** MENU DE MODIFICACIONES ****\n\n");
    printf("1.  Modificar nombre.\n");
    printf("2.  Modificar horas trabajadas.\n");
    printf("3.  Modificar sueldo.\n");
    printf("4.  Salir.\n");
    __fpurge(stdin);
    utn_getNumero(&opcion, "\n\nIngrese una opcion: ", "Error: Ingreso una opcion invalida.\n", 1, 4,2);

    return opcion;
}

int obtenerId(int* id)
{
    int retorno = 0;
    *id = 1001;

    FILE* f;
    f = fopen("proximoId.bin", "rb");
    if(f != NULL)
    {
        //printf("\nEntre al IF del obtener id: %d\n", id);
        fread(id, sizeof(int), 1, f);
        fclose(f);
        retorno = 1;
        //printf("\nSali del If del obtenerId: %d\n", id);
    }

    return retorno;
}

int actualizarId(int id)
{
    int retorno = 0;
    id++;
    //printf("\nId del actualizaID: %d\n", id);
    //getchar();
    FILE* f = fopen("proximoId.bin", "wb");

    if(f != NULL)
    {
        fwrite(&id, sizeof(int), 1, f);
        fclose(f);
        retorno = 1;
    }

    return retorno;
}

int buscarEmpleadoPorID(LinkedList* pArrayListEmployee, int id)
{
    int indice = 0;
    int idAux;
    Employee* emp;

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        emp = ll_get(pArrayListEmployee, i);

        if(employee_getId(emp, &idAux)  &&  idAux == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int modificarEmpleado(LinkedList* pArrayListEmployee, int id)
{
    int retorno = 0;
    char seguir= 's';
    int indice;
    char nuevoNombre[20];
    int nuevasHoras;
    int nuevoSueldo;
    Employee* emp;

    if (emp != NULL)
    {
        do{
            switch(modificationMenu())
            {
               case 1:
                   if (utn_getNombre(nuevoNombre, 20, "\n\nIngrese el nuevo nombre: ", "\nError, ingreso un nombre invalido", 2) == 0)
                   {
                       indice = buscarEmpleadoPorID(pArrayListEmployee, id);
                       emp = (Employee*) ll_get(pArrayListEmployee, indice);
                       employee_setNombre(emp, nuevoNombre);
                       printf("\n\nSe ha modificado el nombre.\n");
                       retorno = 1;
                    }
                    else
                        {
                        printf("\nNo se pudo cambiar el nombre.\n");
                        }
                    seguir = 'n';
                    break;

               case 2:
                   if (utn_getNumero(&nuevasHoras,"\n\nIngrese las nuevas horas: ", "\nError, ingreso datos invalidos",0, 99999, 2) == 0)
                   {
                       indice = buscarEmpleadoPorID(pArrayListEmployee, id);
                       emp = (Employee*) ll_get(pArrayListEmployee, indice);
                       employee_setHorasTrabajadas(emp, nuevasHoras);
                       printf("\n\nSe ha modificado las horas.\n");
                       retorno = 1;
                    }
                    else
                        {
                        printf("\nNo se pudo cambiar las horas.\n");
                        }
                    seguir = 'n';
                    break;

               case 3:
                    if (utn_getNumero(&nuevoSueldo,"\n\nIngrese el nuevo sueldo: ", "\nError, ingreso datos invalidos",0, 99999, 2) == 0)
                    {
                       indice = buscarEmpleadoPorID(pArrayListEmployee, id);
                       emp = (Employee*) ll_get(pArrayListEmployee, indice);
                       employee_setSueldo(emp, nuevoSueldo);
                       printf("\n\nSe ha modificado el sueldo.\n");
                       retorno = 1;
                    }
                    else
                        {
                        printf("\nNo se pudo cambiar el sueldo.\n");
                        }
                    seguir = 'n';
                    break;

               case 4:
                    seguir = 'n';
                    printf("\nHa finalizado el programa\n");
                    break;
            }
        }while(seguir == 's');
    }

    return retorno;
}

int ordenarPorNombre(void *emp1, void *emp2)
{
	int retorno = 0;

    char nombre1[20];
	char nombre2[20];

	employee_getNombre(emp1, nombre2);
	employee_getNombre(emp2, nombre2);

	if (strcmp(nombre1, nombre2) > 0)
	{
		retorno = 1;
	}
	else if (strcmp(nombre1, nombre2) < 0)
        {
            retorno = -1;
        }
	return retorno;
}






