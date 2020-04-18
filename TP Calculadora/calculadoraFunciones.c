
#include <stdio.h>
#include <stdlib.h>
#include "calculadoraFunciones.h"

int getMenuCalculadora(char mensaje[], char mensajeError[], int valorMin, int valorMax, int valorIntentos){
  int valor;
  int contador = 0;

  printf("%s", mensaje);
  scanf("%d", &valor);

  while(valor < valorMin || valor > valorMax){
    contador++;
    printf("%s", mensajeError);
    scanf("%d", &valor);

    if(contador == valorIntentos){
      printf("No son opciones validas, terminamos");
      valor = valorMax;
    }
  }

  return valor;
}

int getIgresoDatos(char mensaje[], char mensajeError[], int numeroMin, int numeroMax){
  int valor;
  printf("%s", mensaje);
  scanf("%d", &valor);

  while(valor < numeroMin || valor > numeroMax){
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




