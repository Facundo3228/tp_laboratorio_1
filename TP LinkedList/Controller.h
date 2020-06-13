#include "LinkedList.h"
#include "Employee.h"
#include "funcionesGet.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
  * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -    1 si funciona correctamente.
 *             -   -1 si no funciona correctamente.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
  * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -    1 si funciona correctamente.
 *             -   -1 si no funciona correctamente.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Incremento del ID
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -   1 si funciona correctamente.
 *             -   0 si no funciona correctamente.
 */
int controller_nextID(LinkedList* pArrayListEmployee);


/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -  -1 si funciona correctamente.
 *             -   0 si no funciona correctamente.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -  -1 si funciona correctamente.
 *             -   0 si no funciona correctamente.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -  -1 si funciona correctamente.
 *             -   0 si no funciona correctamente.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -  -1 si funciona correctamente.
 *             -   0 si no funciona correctamente.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -  -1 si funciona correctamente.
 *             -   0 si no funciona correctamente.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -  -1 si funciona correctamente.
 *             -   0 si no funciona correctamente.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* Lista de empleados donde se carga/guarda la informacion.
 * \return int -  -1 si funciona correctamente.
 *             -   0 si no funciona correctamente.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
