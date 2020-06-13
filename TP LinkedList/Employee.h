#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define TAMNOMBRE 100


typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;



/** \brief Construye un nuevo empleado.
 *
 * \param  void
 * \return -NULL si no hay memoria.
 *         -Employee* si funciona correctamente.
 */
Employee* employee_new();



/** \brief Construye un nuevo empleado - carga los campos con datos.
 *
 * \param idStr char* contiene el id
 * \param nombreStr char* contiene el nombre
 * \param horasTrabajadasStr char* contiene el sueldo
 * \param sueldoStr char* contiene las horas trabajadas
 * \return -NULL si no hay memoria.
 *         -Employee* si funciona correctamente.
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);



/** \brief Elimina un empleado.
 *
 * \param this Employee* empleado a eliminar
 * \return void
 */
void employee_delete(Employee* this);



/** \brief Crea el id de un empleado.
 *
 * \param this Employee* empleado.
 * \param id int Crea el id
 * \return int -   0 si funciona correctamente.
 *             -  -1 si no funciona correctamente.
 */
int employee_setId(Employee* this,int id);



/** \brief Obtiene el id de un empleado.
 *
 * \param this Employee* empleado.
 * \param id int* obtiene el id
 * \return int -   0 si funciona correctamente.
 *             -  -1 si no funciona correctamente.
 */
int employee_getId(Employee* this,int* id);



/** \brief Crea el nombre de un empleado.
 *
 * \param this Employee* empleado.
 * \param nombre char* Crea el nombre
 * \return int -   0 si funciona correctamente.
 *             -  -1 si no funciona correctamente.
 */
int employee_setNombre(Employee* this,char* nombre);



/** \brief Obtiene el nombre de un empleado.
 *
 * \param this Employee* empleado.
 * \param nombre char* Obtiene el nombre
 * \return int -   0 si funciona correctamente.
 *             -  -1 si no funciona correctamente.
 */
int employee_getNombre(Employee* this,char* nombre);



/** \brief Crea las horas trabajadas de un empleado.
 *
 * \param this Employee* empleado.
 * \param horasTrabajadas int Crea las horas trabajadas
 * \return int -   0 si funciona correctamente.
 *             -  -1 si no funciona correctamente.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);



/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param this Employee* empleado.
 * \param horasTrabajadas int* Obtiene las horas trabajadas
 * \return int -   0 si funciona correctamente.
 *             -  -1 si no funciona correctamente.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);



/** \brief Crea el sueldo de un empleado.
 *
 * \param this Employee* empleado.
 * \param sueldo int Crea el sueldo
 * \return int -   0 si funciona correctamente.
 *             -  -1 si no funciona correctamente.
 */
int employee_setSueldo(Employee* this,int sueldo);



/** \brief Obtiene el sueldo de un empleado.
 *
 * \param this Employee* empleado.
 * \param sueldo int* Obtiene el sueldo
 * \return int -   0 si funciona correctamente.
 *             -  -1 si no funciona correctamente.
 */
int employee_getSueldo(Employee* this,int* sueldo);



/** \brief Ordena la lista de empleados.
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -   0 si funciona correctamente.
 *             -  -1 si no funciona correctamente.
 */
int employee_sortEmployee(LinkedList* pArrayListEmployee);



/** \brief Ordena la lista de empleados por id.
 *
 * \param thisUno void* objeto generico uno
 * \param thisDos void* objeto generico dos
 * \return int -  -1 si funciona correctamente.
 *             -  0 si no funciona correctamente.
 */
int employee_ordenarPorId(void* thisUno, void* thisDos);



/** \brief Ordena la lista de empleados por sueldo.
 *
 * \param thisUno void* objeto generico uno
 * \param thisDos void* objeto generico dos
 * \return int -  -1 si funciona correctamente.
 *             -  0 si no funciona correctamente.
 */
int employee_ordenarPorSueldo(void* thisUno, void* thisDos);



/** \brief Ordena la lista de empleados por nombre.
 *
 * \param thisUno void* objeto generico uno
 * \param thisDos void* objeto generico dos
 * \return int -  -1 si funciona correctamente.
 *             -  0 si no funciona correctamente.
 */
int employee_ordenarPorNombre(void* thisUno, void* thisDos);



/** \brief Ordena la lista de empleados por horas trabajadas.
 *
 * \param thisUno void* objeto generico uno
 * \param thisDos void* objeto generico dos
 * \return int -  -1 si funciona correctamente.
 *             -  0 si no funciona correctamente.
 */
int employee_ordenarPorHoras(void* thisUno, void* thisDos);


#endif // employee_H_INCLUDED
