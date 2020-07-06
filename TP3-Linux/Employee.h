#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Menu de opciones

 * \return opcion elegida del menu
 */
int menu();


/** \brief Crea espacio para un empleado

 * \return Espacio para un empleado
 */
Employee* employee_new();

/** \brief Agregar los parametros para un empleado
 * \param id char*
 * \param nombre char*
 * \param horas char*
 * \param sueldo char*
 * \return Empleado con parametros
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);


/** \brief Elimina espacio creado para un empleado
 *
 * \param puntero al empleado
 */
 void employee_delete(Employee* this);


 /** \brief Copia el id recibido al id del empleado
 *
 * \param puntero al empleado que recibirá el id
 * \param id que sera copiado
 * \return int
 */
int employee_setId(Employee* this,int id);

/** \brief Copia el id del empleado recibido a otra varible int
 *
 * \param puntero al empleado
 * \param int que recibira el id del empleado
 * \return int 1 si pudo asignar correctamente, retorna 0 si no se realizo la copia

 */
int employee_getId(Employee* this,int* id);


/** \brief Copia el nombre recibido a nombre del puntero al empleado
 *
 * \param puntero al empleado
 * \param nombre que sera copiado
 * \return int 1 si pudo asignar correctamente, retorna 0 si no se realizo la copia
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Copia el nombre del empleado recibido a otra varible char
 *
 * \param puntero al empleado
 * \param char que recibira el nombre del empleado
 * \return int 1 si pudo asignar correctamente, retorna 0 si no se realizo la copia
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief Copia la hora recibida a la hora del puntero al empleado
 *
 * \param puntero al empleado
 * \param hora que sera copiada
 * \return int 1 si pudo asignar correctamente, retorna 0 si no se realizo la copia
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief copia la hora del empleado recibido a otra variable int
 *
 * \param puntero al empleado
 * \param int que recibira la hora del empleado
 * \return int 1 si pudo asignar correctamente, retorna 0 si no se realizo la copia
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Copia el sueldo recibido en el sueldo del puntero al empleado
 *
 * \param puntero al empleado
 * \param sueldo que sera copiado
 * \return int 1 si pudo asignar correctamente, retorna 0 si no se realizo la copia
 */
int employee_setSueldo(Employee* this,int sueldo);


/** \brief copia el sueldo del empleado recibido a otra variable int
 *
 * \param puntero al empleado
 * \param int que recibira el sueldo del empleado
 * \return int 1 si pudo asignar correctamente, retorna 0 si no se realizo la copia
 */
int employee_getSueldo(Employee* this,int* sueldo);


/** \brief Obtiene el id del archivo guardado, si no existe el archivo lo crea
 *
 * \param id del archivo guardado
 * \return int 1 si pudo obtener el id correctamente, retorna 0 si no lo obtuvo
 */
int obtenerId(int* id);


/** \brief Guarda el ultimo id de la lista en un archivo
 *
 * \param ultimo id de la lista
 * \return int 1 si pudo guardar correctamente, retorna 0 si no slo guardo
 */
int actualizarId(int id);


/** \brief Busca un empleado por id
 *
 * \param puntero a la lista de los empleados
 * \param id del empleado a buscar
 * \return int 1 si pudo encontrar el id, retorna 0 si no lo encontro
 */
int buscarEmpleadoPorID(LinkedList* pArrayListEmployee, int id);


/** \brief ordena la lista por nombre de menor a mayor (A-Z)
 *
 * \param primer empleado a comparar
 * \param segundo empleado a comparar
 * \return int 1 si pudo ordenar correctamente, retorna 0 si no se pudo
 *
 */
int ordenarPorNombre(void *emp1, void *emp2);


/** \brief Imprimi un empleado
 *
 * \param puntero al empleado que se quiere mostrar
 * \return int 1 si pudo imprimir al empleado, retorna 0 si no lo imprimio
 */
int showEmployee(Employee* this);


/** \brief Modifica los datos de un empleado: nombre, horas, sueldo
 *
 * \param puntero a la lista de los empleados
 * \param id del empleado a modificar
 * \return int 1 si pudo hacer la modificacion, retorna 0 si no se modifico
 */
int modificarEmpleado(LinkedList* pArrayListEmployee, int id);

#endif // employee_H_INCLUDED
