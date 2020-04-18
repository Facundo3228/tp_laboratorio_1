#include <stdio.h>
#include <stdlib.h>
#include "calculadoraFunciones.h"



int main()
{
  int opcionesMenu;
  int flagA=0;
  int flagB=0;
  int numeroA;
  int numeroB;
  int auxSuma;
  int auxResta;
  int auxMultiplicacion;
  float auxDivision;
  double auxFactorialA;
  double auxFactorialB;

  do{
      printf("\n------------------------Menu de opciones------------------------------\n");

      opcionesMenu = getMenuCalculadora("\n1. Ingrese numero A: \n2. Ingrese numero B: \n3. Calculo de operaciones: \n4. Resultados de operaciones: \n5. Salir \n\n------------------------Menu de opciones------------------------------  \nIngrese una opcion: ", "Error!!!...\n No es una opcion valida reintente: ", 0, 5, 3);


      getchar();
      //system("PAUSE");
      system("clear");

      switch(opcionesMenu){
        case 1:
             //printf("Estoy pidiendo el numero A \n");
             if(flagA != 1){
                numeroA = getIgresoDatos("Ingrese el primer numero A: ", "Error, Ingrese el primer numero A: ", -1000, 1000);
                printf("\t\t\nA = %d\n", numeroA);
                flagA=1;
             }else{
                printf("\t\t\nYa cargaste un numero A=%d\n", numeroA);
             }
        break;

        case 2:
             //printf("Estoy pidiendo el numero B \n");
             if(flagA == 1 && flagB != 1){
                numeroB = getIgresoDatos("Ingrese el segundo numero B: ", "Error, Ingrese el segundo numero B: ", -1000, 1000);
                printf("\t\t\nB = %d\n", numeroB);
                flagB=1;
             }else{
                if(flagB == 1){
                   printf("\t\t\nYa cargaste un numero B=%d\n", numeroB);
                }else{
                  printf("\t\t\ningresa la opcion de cargar numero A\n");
                }
             }

        break;

        case 3:
             printf("-----------------Realizando operaciones------------------------------ \n\n");

             if(flagA == 1 && flagB == 1){
                 printf("\t\t\tEstoy sumando \n");
                 auxSuma = getSuma(numeroA, numeroB);

                 printf("\t\t\tEstoy restando \n");
                 auxResta = getResta(numeroA, numeroB);

                 printf("\t\t\tEstoy multiplicando \n");
                 auxMultiplicacion = getMultiplicacion(numeroA, numeroB);

                 printf("\t\t\tEstoy dividiendo \n");
                 auxDivision = getDivision(numeroA, numeroB, "\t\t\t¡¡¡ No se puede dividir por cero !!!\n");

                 printf("\t\t\tEstoy Factorizando numero A \n");
                 auxFactorialA = getFactorial(numeroA);

                 printf("\t\t\tEstoy Factorizando numero B \n\n");
                 auxFactorialB = getFactorial(numeroB);
             }else{
               printf("\t\tIngrese el numero A y numero B para calcular\n\n");
             }

             printf("-----------------Operaciones realizadas------------------------------ \n\n");

        break;

        case 4:
             printf("-----------------Resultado de todas las operaciones------------------ \n\n");

             if(flagA == 1 && flagB == 1){
                 printf("\t\t\tLa suma de %d + %d = %d\n", numeroA, numeroB, auxSuma);

                 printf("\t\t\tLa resta de %d - %d = %d\n", numeroA, numeroB, auxResta);

                 printf("\t\t\tLa multiplicacion de %d * %d = %d\n", numeroA, numeroB, auxMultiplicacion);

                 printf("\t\t\tLa division de %d / %d = %.2f\n", numeroA, numeroB, auxDivision);

                 printf("\t\t\tEl factorial del Numero A %d! = %f\n", numeroA, auxFactorialA);

                 printf("\t\t\tEl factorial del Numero B %d! = %f\n\n", numeroB, auxFactorialB);

                 //Cambio el valor de flagA y flagB
                 flagA=0;
                 flagB=0;

             }else{
               printf("\t\tIngrese el numero A y numero B para calcular\n\n");
             }

             printf("-----------------Operaciones realizadas------------------------------ \n\n");
        break;

        case 5:
             printf("\n\n---------------------------------Salgo de la aplicacion-------------------------------- \n\n");
             printf("\tEsta aplicacion fue creada por Facundo Aldo Rodriguez, pertenece al TP1.");
        break;

        default:
              printf("\n------------------------- Opcion no valida --------------------------- \n");
        break;
      }

  }while(opcionesMenu != 5);

    getchar();
    //system("PAUSE");
    system("clear");

    printf("\n***************** Gracias por usar esta calculadora *****************\n");
    return 0;
}
