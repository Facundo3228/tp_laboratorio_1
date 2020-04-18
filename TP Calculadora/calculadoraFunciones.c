
#include <stdio.h>
#include <stdlib.h>
#include "calculadoraFunciones.h"

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

int getSuma(int numeroA, int numeroB){
  int resultadoSuma;

  resultadoSuma = numeroA + numeroB;

  return resultadoSuma;
}

int getResta(int numeroA, int numeroB){
  int resultadoResta;

  resultadoResta = numeroA - (numeroB);

  return resultadoResta;
}

int getMultiplicacion(int numeroA, int numeroB){
  int resultadoMultiplicacion;

  resultadoMultiplicacion = numeroA * numeroB;

  return resultadoMultiplicacion;
}

float getDivision(int numeroA, int numeroB, char mensajeError[]){
   float resultadoDivision;

  if(numeroB != 0){
    resultadoDivision = (float)numeroA / numeroB;
  }else{
    printf("%s", mensajeError);
  }
  return resultadoDivision;
}

double getFactorial(int numero){
  double valor = 1;
  int i;
  for(i=1; i<=numero; i++){
    valor *=i;
  }
  return valor;
}




