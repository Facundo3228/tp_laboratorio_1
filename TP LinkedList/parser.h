
/** \brief Parsea los datos desde el archivo data.csv (modo texto).
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -  -1 si funciona correctamente.
 *             -  0 si no funciona correctamente.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);



/** \brief Parsea los datos desde el archivo data.bin (modo binario).
 *
 * \param pArrayListEmployee LinkedList* Puntero a la lista de empleados.
 * \return int -  -1 si funciona correctamente.
 *             -  0 si no funciona correctamente.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
