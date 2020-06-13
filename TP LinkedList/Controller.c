#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "funcionesGet.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path, "r");

    if(pArchivo!=NULL)
    {
        parser_EmployeeFromText(pArchivo, pArrayListEmployee);
        retorno = 1;
    }
    fclose(pArchivo);

    return retorno;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pArchivo;
    int retorno = -1;

    pArchivo = fopen(path, "rb");

    if(pArchivo != NULL)
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        retorno = 1;
    }
    fclose(pArchivo);

    return retorno;
}



int controller_nextID(LinkedList* pArrayListEmployee)
{
    Employee* employeeAux;

    int i;
    int aux;
    int id= 0;
    int listLen;
    int idAnterior;

    if(pArrayListEmployee != NULL)
    {
        listLen = ll_len(pArrayListEmployee);
        if(listLen > 0)
        {
            for(i = 0; i<listLen; i++)
            {
                employeeAux = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(employeeAux,&aux);
                if(aux > id)
                {
                    idAnterior = id;
                    id = aux;
                    if(idAnterior + 1 != id)
                    {
                        id = idAnterior;
                        break;
                    }
                }
            }
            id++;
        }
        else
        {
            id = 1;
        }
    }
    return id;
}



int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    pEmpleado = employee_new();

    int retorno= -1;
    int idAux;
    int horasCharAux;
    int sueldoCharAux;

    char nombreChar[100];
    char sueldoChar[100];
    char horasChar[100];

    if(pArrayListEmployee != NULL)
    {
        idAux = controller_nextID(pArrayListEmployee);
        printf("\n\t\t INGRESE EL NOMBRE: ");
        fflush(stdin);
        gets(nombreChar);

        while(esSoloLetras(nombreChar)==0)
        {
            printf("\n\t\t EL INGRESO ES INCORRECTO INTENTE NUEVAMENTE.\n\t\t INGRESE EL NOMBRE: ");
            fflush(stdin);
            gets(nombreChar);
        }
        stringToUpper(nombreChar);


        printf("\n\t\t INGRESE LAS HORAS TRABAJADAS: ");
        fflush(stdin);
        gets(horasChar);

        while(esNumerico(horasChar) == 0)
        {
            printf("\n\t\t EL INGRESO ES INCORRECTO INTENTE NUEVAMENTE.\n\t\t INGRESE LAS HORAS TRABAJADAS: ");
            fflush(stdin);
            gets(horasChar);
        }
        horasCharAux = atoi(horasChar);


        printf("\n\t\t INGRESE EL SUELDO: ");
        fflush(stdin);
        gets(sueldoChar);

        while(esNumerico(sueldoChar) == 0)
        {
            printf("\n\t\t EL INGRESO ES INCORRECTO INTENTE NUEVAMENTE.\n\t\t INGRESE EL SUELDO: ");
            fflush(stdin);
            gets(sueldoChar);
        }
        sueldoCharAux = atoi(sueldoChar);


        if(pEmpleado != NULL)
        {
            employee_setId(pEmpleado, idAux);
            employee_setNombre(pEmpleado, nombreChar);
            employee_setHorasTrabajadas(pEmpleado, horasCharAux);
            employee_setSueldo(pEmpleado, sueldoCharAux);
            ll_add(pArrayListEmployee, pEmpleado);
            retorno = 0;
        }
    }
    return retorno;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;

    int i;
    int retorno = -1;
    int idCharAux;
    int idObtenido;
    int opcionCharAux;
    int sueldoCharAux;
    int horasCharAux;

    char idChar[100];
    char opcionChar[100];
    char nombreChar[100];
    char sueldoChar[100];
    char horasChar[100];

    if(pArrayListEmployee != NULL)
    {
        printf("\n\t\t INGRESE EL ID DEL EMPLEADO: ");
        fflush(stdin);
        gets(idChar);

        while(esNumerico(idChar) == 0)
        {
            printf("\n\t\t ERROR. INGRESE EL ID DEL EMPLEADO: ");
            fflush(stdin);
            gets(idChar);
        }
        idCharAux = atoi(idChar);

        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            employee_getId(empleado, &idObtenido);

            if(idObtenido == idCharAux)
            {

                printf("\n\t\t>>>>> MENU DE MODIFICACION DE EMPLEADO <<<<<\n");
                printf("\n\t\t____________________________________________\n");
                printf("\n\t\t| (1) MODIFICAR NOMBRE                   \t|\n");
                printf("\n\t\t| (2) MODIFICAR HORAS TRABAJADAS         \t|\n");
                printf("\n\t\t| (3) MODIFICAR SUELDO                   \t|\n");
                printf("\n\t\t| (4) CANCELAR MODIFICACION              \t|\n");
                printf("\n\t\t|__________________________________________|\n");


                printf("\n\t\t INGRESE UNA OPCION DEL MENU: ");
                fflush(stdin);
                gets(opcionChar);

                while(esNumerico(opcionChar ) == 0)
                {
                    printf("\n\t\t ERROR. \n\t\t INGRESE UNA OPCION DEL MENU: ");
                    fflush(stdin);
                    gets(opcionChar);
                }
                opcionCharAux = atoi(opcionChar);

                switch(opcionCharAux)
                {
                case 1:
                    printf("\n\t\t INGRESE UNA NUEVO NOMBRE: ");
                    fflush(stdin);
                    gets(nombreChar);

                    while(esSoloLetras(nombreChar) == 0)
                    {
                        printf("\n\t\t ERROR. INGRESE UNA NUEVO NOMBRE: ");
                        fflush(stdin);
                        gets(nombreChar);
                    }
                    stringToUpper(nombreChar);
                    employee_setNombre(empleado, nombreChar);
                    retorno = 0;
                    break;

                case 2:
                    printf("\n\t\t INGRESE LA NUEVAS HORAS TRABAJADAS: ");
                    fflush(stdin);
                    gets(horasChar);

                    while(esNumerico(horasChar) == 0)
                    {
                        printf("\n\t\t ERROR. INGRESE LA NUEVAS HORAS TRABAJADAS: ");
                        fflush(stdin);
                        gets(horasChar);
                    }
                    horasCharAux= atoi(horasChar);
                    employee_setHorasTrabajadas(empleado, horasCharAux);
                    retorno = 0;
                    break;

                case 3:
                    printf("\n\t\t INGRESE UNA NUEVO SUELDO: ");
                    fflush(stdin);
                    gets(sueldoChar);

                    while(esNumerico(sueldoChar) == 0)
                    {
                        printf("\n\t\t ERROR. INGRESE UNA NUEVO SUELDO: ");
                        fflush(stdin);
                        gets(sueldoChar);
                    }

                    sueldoCharAux= atoi(sueldoChar);
                    employee_setSueldo(empleado, sueldoCharAux);
                    retorno = 0;
                    break;

                case 4:
                    opcionCharAux=4;
                    printf("\n\t\t OPERACION CANCELADA \n");
                    break;

                default:
                    printf("\n\t\t ERROR. OPCION NO IMPLEMENTADA \n");
                }
            }
        }
    }
    return retorno;
}



int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int i;
    char idChar[100];
    int idCharAux;
    int idObtenido;
    int opcionAConfirmar;
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("\n\t\t INGRESE EL ID DEL EMPLEADO: ");
        fflush(stdin);
        gets(idChar);

        while(esNumerico(idChar) == 0)
        {
            printf("\n\t\t ERROR. INGRESE EL ID DEL EMPLEADO: ");
            fflush(stdin);
            gets(idChar);
        }
        idCharAux = atoi(idChar);

        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &idObtenido);

            if(idObtenido == idCharAux)
            {
                printf("\n\t\t>>>>> MENU DE ELIMINACION DE EMPLEADO <<<<<<\n");
                printf("\n\t\t____________________________________________\n");
                printf("\n\t\t| (1) ELIMINAR  UN EMPLEADO              \t|\n");
                printf("\n\t\t| (2) CANCELAR OPERACION DE ELIMINACION  \t|\n");
                printf("\n\t\t|__________________________________________|\n");

                opcionAConfirmar = getIntLimit("\n\t\t INGRESE UNA OPCION DEL MENU: ", "\n\t\t ERROR. \n\t\t INGRESE UNA OPCION DEL MENU: ", 1, 2, 3);

                switch(opcionAConfirmar)
                {
                case 1:
                    employee_delete(pEmployee);
                    ll_remove(pArrayListEmployee, i);
                    retorno = 0;
                    break;

                case 2:
                    retorno = -2;
                    break;

                default:
                    printf("\n\t\t ERROR. OPCION NO IMPLEMENTADA \n");
                    retorno = -2;
                    break;
                }
            }
        }
    }
    return retorno;
}



int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    int retorno = -1;
    int i;
    int id;
    int sueldo;
    int horasTrabajadas;

    char nombre[128];

    if(pArrayListEmployee != NULL)
    {
        printf("\n\t\t ID \t\t\t NOMBRE \t HORAS TRABAJADAS \t SUELDO \n");
        retorno = 0;

        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee, i);
            employee_getId(pEmpleado, &id);
            employee_getNombre(pEmpleado, nombre);
            employee_getHorasTrabajadas(pEmpleado, &horasTrabajadas);
            employee_getSueldo(pEmpleado, &sueldo);
            printf("%19d %27s %25d %13d \n", id, nombre, horasTrabajadas, sueldo);
        }
    }
    return retorno;
}



int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        employee_sortEmployee(pArrayListEmployee);
        retorno = 0;
    }
    return retorno;
}



int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* empleadoAux;

    int i;
    int* idAux;
    char* nombreAux;
    int* sueldoAux;
    int* horasAux;
    int retorno = -1;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        idAux = malloc(sizeof(int));
        nombreAux = malloc(sizeof(char)*100);
        horasAux = malloc(sizeof(int));
        sueldoAux = malloc(sizeof(int));

        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"ID,NOMBRE,HORASTRABAJADAS,SUELDO\n");

        for(i = 0; i< ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = ll_get(pArrayListEmployee, i);
            employee_getId(empleadoAux, idAux);
            employee_getNombre(empleadoAux, nombreAux);
            employee_getHorasTrabajadas(empleadoAux, horasAux);
            employee_getSueldo(empleadoAux, sueldoAux);
            fprintf(pArchivo,"%d, %s, %d, %d\n", *idAux, nombreAux, *horasAux, *sueldoAux);
        }

        //LIBERO LA MEMORIA
        free(idAux);
        free(nombreAux);
        free(horasAux);
        free(sueldoAux);
        fclose(pArchivo);
    }
    return retorno;
}



int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* empleadoAux;

    int retorno = -1;
    int i = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pArchivo = fopen(path,"wb");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(empleadoAux, sizeof(Employee),1,pArchivo);
        }
        fclose(pArchivo);
    }
    return retorno;
}
