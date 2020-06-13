#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    char idAux[100];
    char nombreAux[100];
    char horasTrabajadasAux[100];
    char sueldoAux[100];

    int retorno = -1;
    int bandera = 1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(bandera)
            {
                fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
                bandera = 0;
            }

            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            printf("\n\t\t %s - %s - %s - %s \n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            pEmployee = employee_newParametros(idAux, nombreAux, horasTrabajadasAux, sueldoAux);

            if(pEmployee != NULL)
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno = 0;
            }
        }
    }
    return retorno;
}



int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;
    int retorno = -1;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            pEmployee = employee_new();

            if(fread(pEmployee,sizeof(Employee),1,pFile))
            {
                ll_add(pArrayListEmployee, pEmployee);
            }
        }
        retorno = 0;
    }
    return retorno;
}
