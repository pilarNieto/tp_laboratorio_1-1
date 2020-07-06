#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int cant;
    Employee* emp;
    int retorno = 0;
    char id[20];
    char nombre[20];
    char horas[20];
    char sueldo[20];

    if (pFile != NULL  && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            emp = employee_new();
            cant = fscanf(pFile,"%[^,] , %[^,], %[^,], %[^\n]\n", id, nombre, horas, sueldo);

            if(cant == 4)
            {
                emp = employee_newParametros(id, nombre, horas,  sueldo);
                ll_add(pArrayListEmployee, emp);
                retorno = 1;
            }
            else
            {
                break;
            }
        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* emp;
    int retorno = 0;

    if (pFile != NULL  && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            emp = employee_new();

            if(fread(emp, sizeof(Employee), 1, pFile) == 1)
            {
                ll_add(pArrayListEmployee, emp);
                retorno = 1;
            }
            else
            {
                break;
            }
        }
    }

    return retorno;

}
