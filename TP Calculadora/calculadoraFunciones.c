
#include <stdio.h>
#include <stdlib.h>
#include "calculadoraFunciones.h"

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

int getMenuCalculadora(char mensaje[], char mensajeError[], int min, int max, int intentos){
  int valor;
  int contador = 0;

  printf("%s", mensaje);
  scanf("%d", &valor);

  while(valor < min || valor > max){
    contador++;
    printf("%s", mensajeError);
    scanf("%d", &valor);

    if(contador == intentos){
      printf("Usastes todos tus intentos...");
      valor = max;
    }
  }

  return valor;
}

/** \brief Ingreso y verifico el numero ingresado por el usuario.
 *
 * \param mensaje[] char Mensaje de ingreso de dato.
 * \param mensajeError[] char Mensaje de error de dato.
 * \param min int Numero minimo.
 * \param max int Numero maximo.
 * \return int Devuelvo el dato numerico ingresado.
 *
 */
int getIgresoDatos(char mensaje[], char mensajeError[], int min, int max){
  int valor;
  printf("%s", mensaje);
  scanf("%d", &valor);

  while(valor < min || valor > max){
    printf("%s", mensajeError);
    scanf("%d", &valor);
  }

  return valor;
}

/** \brief Sumo con los datos numericos ingresados por el usuario.
 *
 * \param numeroA int Numero 1.
 * \param numeroB int Numero 2.
 * \return int Entrego el resultado de la suma.
 *
 */
int getSuma(int numeroA, int numeroB){
  int resultadoSuma;

  resultadoSuma = numeroA + numeroB;

  return resultadoSuma;
}

/** \brief Resto con los datos numericos ingresados por el usuario.
 *
 * \param numeroA int Numero 1.
 * \param numeroB int Numero 2.
 * \return int Entrego el resultado de la resta.
 *
 */
int getResta(int numeroA, int numeroB){
  int resultadoResta;

  resultadoResta = numeroA - (numeroB);

  return resultadoResta;
}

/** \brief Multiplico con los datos numericos ingresados por el usuario.
 *
 * \param numeroA int Numero 1.
 * \param numeroB int Numero 2.
 * \return int Entrego el resultado de la multiplicacion.
 *
 */
int getMultiplicacion(int numeroA, int numeroB){
  int resultadoMultiplicacion;

  resultadoMultiplicacion = numeroA * numeroB;

  return resultadoMultiplicacion;
}

/** \brief Divido con los datos numericos ingresados por el usuario.
 *
 * \param numeroA int Numero 1.
 * \param numeroB int Numero 2.
 * \param mensajeError[] char Mensaje de error por vividir por cero.
 * \return int Entrego el resultado de la divicion.
 *
 */
float getDivision(int numeroA, int numeroB, char mensajeError[]){
   float resultadoDivision;

  if(numeroB != 0){
    resultadoDivision = (float)numeroA / numeroB;
  }else{
    printf("%s", mensajeError);
  }
  return resultadoDivision;
}

/** \brief Factorial de uno de los datos numericos ingresados por el usuario.
 *
 * \param numero int Ingresado por el usiario.
 * \return El factorial del numero ingresado por el usuario.
 *
 */
double getFactorial(int numero){
  double valor = 1;
  int i;
  for(i=1; i<=numero; i++){
    valor *=i;
  }
  return valor;
}




