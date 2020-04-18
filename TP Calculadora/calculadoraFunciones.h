#ifndef CALCULADORAFUNCIONES_H_INCLUDED
#define CALCULADORAFUNCIONES_H_INCLUDED

/** \brief Ingreso y verifico el numero ingresado por el usuario dandole una cantidad de intentos.
 *
 * \param mensaje[] char Mensaje de ingreso de dato.
 * \param mensajeError[] char Mensaje de error de dato.
 * \param min int Numero minimo.
 * \param max int Numero maximo.
 * \param intentos int Intentos por el usuario.
 * \return int Devuelvo el dato numerico ingresado.
 *
 */
int getMenuCalculadora(char[], char[], int, int, int);

/** \brief Ingreso y verifico el numero ingresado por el usuario.
 *
 * \param mensaje[] char Mensaje de ingreso de dato.
 * \param mensajeError[] char Mensaje de error de dato.
 * \param min int Numero minimo.
 * \param max int Numero maximo.
 * \return int Devuelvo el dato numerico ingresado.
 *
 */
int getIgresoDatos(char[], char[], int, int);

/** \brief Sumo con los datos numericos ingresados por el usuario.
 *
 * \param numeroA int Numero 1.
 * \param numeroB int Numero 2.
 * \return int Entrego el resultado de la suma.
 *
 */
int getSuma(int, int);

/** \brief Resto con los datos numericos ingresados por el usuario.
 *
 * \param numeroA int Numero 1.
 * \param numeroB int Numero 2.
 * \return int Entrego el resultado de la resta.
 *
 */
int getResta(int, int);

/** \brief Multiplico con los datos numericos ingresados por el usuario.
 *
 * \param numeroA int Numero 1.
 * \param numeroB int Numero 2.
 * \return int Entrego el resultado de la multiplicacion.
 *
 */
int getMultiplicacion(int, int);

/** \brief Divido con los datos numericos ingresados por el usuario.
 *
 * \param numeroA int Numero 1.
 * \param numeroB int Numero 2.
 * \param mensajeError[] char Mensaje de error por vividir por cero.
 * \return int Entrego el resultado de la divicion.
 *
 */
float getDivision(int, int, char[]);

/** \brief Factorial de uno de los datos numericos ingresados por el usuario.
 *
 * \param numero int Ingresado por el usiario.
 * \return El factorial del numero ingresado por el usuario.
 *
 */
double getFactorial(int);

#endif // CALCULADORAFUNCIONES_H_INCLUDED
