#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"


Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee = (Employee*)malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->sueldo = 0;
        newEmployee->horasTrabajadas = 0;
    }

    return newEmployee;
}



Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();

    int auxId;
    int auxHoras;
    int auxSueldo;

    auxId = atoi(idStr);
    auxHoras = atoi(horasTrabajadasStr);
    auxSueldo = atoi(sueldoStr);

    if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setId(newEmployee, auxId);
        employee_setNombre(newEmployee, nombreStr);
        employee_setSueldo(newEmployee, auxSueldo);
        employee_setHorasTrabajadas(newEmployee, auxHoras);
    }

    return newEmployee;
}


void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}



int employee_setId(Employee* this,int id)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            retorno = 0;
        }
    }
    return retorno;
}



int employee_getId(Employee* this, int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}



int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}



int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}



int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            retorno = 0;
        }
    }
    return retorno;
}



int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}



int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}



int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}



int employee_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno = -1;

    if(pArrayListEmployee != NULL)
<<<<<<< HEAD
    {

        printf("\n\t\t>>>>>>>>>>>>>>>>>>>>> MENU DE ORDENAMIENTO <<<<<<<<<<<<<<<<<<<<<<\n");
        printf("\n\t\t_________________________________________________________________\n");
=======
    {

        printf("\n\t\t>>>>>>>>>>>>>>>>>>>>> MENU DE ORDENAMIENTO <<<<<<<<<<<<<<<<<<<<<<\n");
        printf("\n\t\t_________________________________________________________________\n");
>>>>>>> 2400a0a17c5597ff1b458f267490943ca1aab411
        printf("\n\t\t| (1) ORDENAR LISTA DE EMPLEADOS POR ID                       \t|\n");
        printf("\n\t\t| (2) ORDENAR LISTA DE EMPLEADOS POR NOMBRE                   \t|\n");
        printf("\n\t\t| (3) ORDENAR LISTA DE EMPLEADOS POR SUELDO                   \t|\n");
        printf("\n\t\t| (4) ORDENAR LISTA DE EMPLEADOS POR HORAS TRABAJADAS         \t|\n");
<<<<<<< HEAD
        printf("\n\t\t| (5) CANCELAR ORDENAMIENTO                                   \t|\n");
        printf("\n\t\t|_______________________________________________________________|\n");


      do
      {
          opcion = getIntLimit("\n\t\t INGRESE UNA OPCION DEL MENU: ", "\n\t\t ERROR. \n\t\t INGRESE UNA OPCION DEL MENU: ", 1, 5, 3);

        switch(opcion)
        {
        case 1:
            printf("\n\t\t LA LISTA SE ORDENO POR ID \n");
            ll_sort(pArrayListEmployee, employee_ordenarPorId, 1);
            retorno = 0;
            break;

        case 2:
            printf("\n\t\t LA LISTA SE ORDENO POR NOMBRE \n");
            ll_sort(pArrayListEmployee, employee_ordenarPorNombre, 1);
=======
        printf("\n\t\t| (5) CANCELAR ORDENAMIENTO                                   \t|\n");
        printf("\n\t\t|_______________________________________________________________|\n");


      do
      {
          opcion = getIntLimit("\n\t\t INGRESE UNA OPCION DEL MENU: ", "\n\t\t ERROR. \n\t\t INGRESE UNA OPCION DEL MENU: ", 1, 5, 3);

        switch(opcion)
        {
        case 1:
            printf("\n\t\t LA LISTA SE ORDENO POR ID \n");
            ll_sort(pArrayListEmployee, employee_ordenarPorId, 1);
            retorno = 0;
            break;

        case 2:
            printf("\n\t\t LA LISTA SE ORDENO POR NOMBRE \n");
            ll_sort(pArrayListEmployee, employee_ordenarPorNombre, 1);
>>>>>>> 2400a0a17c5597ff1b458f267490943ca1aab411
            retorno = 0;
            break;

        case 3:
            printf("\n\t\t LA LISTA SE ORDENO POR SUELDO \n");
<<<<<<< HEAD
            ll_sort(pArrayListEmployee, employee_ordenarPorSueldo, 1);
=======
            ll_sort(pArrayListEmployee, employee_ordenarPorSueldo, 1);
>>>>>>> 2400a0a17c5597ff1b458f267490943ca1aab411
            retorno = 0;
            break;

        case 4:
            printf("\n\t\t LA LISTA SE ORDENO POR HORAS TRABAJADAS \n");
<<<<<<< HEAD
            ll_sort(pArrayListEmployee, employee_ordenarPorHoras, 1);
=======
            ll_sort(pArrayListEmployee, employee_ordenarPorHoras, 1);
>>>>>>> 2400a0a17c5597ff1b458f267490943ca1aab411
            retorno = 0;
            break;

        case 5:
<<<<<<< HEAD
            printf("\n\t\t OPERACION CANCELADA \n");
=======
            printf("\n\t\t OPERACION CANCELADA \n");
>>>>>>> 2400a0a17c5597ff1b458f267490943ca1aab411
            retorno = -5;
            break;

        default:
<<<<<<< HEAD
            printf("\n\t\t ERROR. OPCION NO IMPLEMENTADA \n");

        }

      }while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);
=======
            printf("\n\t\t ERROR. OPCION NO IMPLEMENTADA \n");

        }

      }while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);
>>>>>>> 2400a0a17c5597ff1b458f267490943ca1aab411
    retorno = -5;
    }
    return retorno;
}

int employee_ordenarPorId(void* thisUno, void* thisDos)
{
    int idUno;
    int idDos;
    int retorno = 0;

    employee_getId(thisUno, &idUno);
    employee_getId(thisDos, &idDos);

    if(idUno > idDos)
    {
        retorno = 1;
    }
    else if(idUno < idDos)
    {
        retorno = -1;
    }

    return retorno;
}

int employee_ordenarPorSueldo(void* thisUno, void* thisDos)
{
    int sueldoUno;
    int sueldoDos;
    int retorno = 0;

    employee_getSueldo(thisUno, &sueldoUno);
    employee_getSueldo(thisDos, &sueldoDos);

    if(sueldoUno > sueldoDos)
    {
        retorno = 1;
    }
    else if(sueldoUno < sueldoDos)
    {
        retorno = -1;
    }

    return retorno;
}



int employee_ordenarPorNombre(void* thisUno, void* thisDos)
{
    char nombreUno[50];
    char nombreDos[50];
    int retorno = 0;

    employee_getNombre(thisUno, nombreUno);
    employee_getNombre(thisDos, nombreDos);

    if(strcmp(nombreUno, nombreDos) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreUno, nombreDos) < 0)
    {
        retorno = -1;
    }

    return retorno;
}



int employee_ordenarPorHoras(void* thisUno, void* thisDos)
{
    int horasUno;
    int horasDos;
    int retorno = 0;

    employee_getHorasTrabajadas(thisUno, &horasUno);
    employee_getHorasTrabajadas(thisDos, &horasDos);

    if(horasUno > horasDos)
    {
        retorno = 1;
    }
    else if(horasUno < horasDos)
    {
        retorno = -1;
    }

    return retorno;
}
