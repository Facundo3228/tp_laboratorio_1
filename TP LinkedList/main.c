#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();

    int option;
    int validarController;
    int validarAdd;
    int validarEdit;
    int validarRemove;
    int validarList;
    int validarSort;
    int validarSave;
    int validarCargarTexto = 0;
    int validarCargarBinario = 0;

    do
    {
        printf("\n\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MENU PRINCIPAL <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("\n\t\t_________________________________________________________________________________________\n");
        printf("\n\t\t|  (1) CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO TEXTO)   \t|\n");
        printf("\n\t\t|  (2) CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.BIN (MODO BINARIO) \t|\n");
        printf("\n\t\t|  (3) ALTA DE EMPLEADO                                                           \t|\n");
        printf("\n\t\t|  (4) MODIFICAR DATOS DE EMPLEADOS                                               \t|\n");
        printf("\n\t\t|  (5) BAJA DE EMPLEADOS                                                          \t|\n");
        printf("\n\t\t|  (6) LISTAR EMPLEADOS                                                           \t|\n");
        printf("\n\t\t|  (7) ORDENAR EMPLEADOS                                                          \t|\n");
        printf("\n\t\t|  (8) GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATA.CSV (MODO TEXTO)     \t|\n");
        printf("\n\t\t|  (9) GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATA.BIN (MODO BINARIO)   \t|\n");
        printf("\n\t\t| (10) SALIR                                                                      \t|\n");
        printf("\n\t\t|_______________________________________________________________________________________|\n");

        option = getIntLimit("\n\t\t INGRESE UNA OPCION DEL MENU: ", "\n\t\t ERROR. \n\t\t INGRESE UNA OPCION DEL MENU: ", 1, 10, 3);

        switch(option)
        {
        case 1:
            if(validarCargarTexto == 0)
            {
                validarController = controller_loadFromText("data.csv", listaEmpleados);
                if(validarController == 1)
                {
                    printf("\n\t\t EL ARCHIVO FUE CARGADO EXITOSAMENTE \n");
                }
                else
                {
                    printf("\n\t\t ERROR. EL ARCHIVO NO SE PUDO CARGADO \n");
                }
            validarCargarTexto = 1;
            }
            else if(validarCargarTexto == 1)
            {
                printf("\n\t\t EL ARCHIVO YA FUE CARGADO \n");
            }
            break;

        case 2:
            if(validarCargarBinario == 0)
            {
                validarController = controller_loadFromBinary("data.bin", listaEmpleados);
                if(validarController == 1)
                {
                    printf("\n\t\t EL ARCHIVO FUE CARGADO EXITOSAMENTE \n");
                }
                else
                {
                    printf("\n\t\t ERROR. EL ARCHIVO NO SE PUDO CARGADO \n");
                }
            validarCargarBinario = 1;
            }
            else if(validarCargarBinario == 1)
            {
                printf("\n\t\t EL ARCHIVO YA FUE CARGADO \n");
            }
            break;

        case 3:
            validarAdd = controller_addEmployee(listaEmpleados);
            if(validarAdd == 0)
            {
                printf("\n\t\t EL EMPLEADO FUE CARGADO EXITOSAMENTE \n");
            }
            else
            {
                printf("\n\t\t ERROR. EL EMPLEADO NO PUDO SER CARGADO \n");
            }
            break;

        case 4:
            validarEdit = controller_editEmployee(listaEmpleados);
            if(validarEdit == 0)
            {
                printf("\n\t\t EL EMPLEADO FUE MODIFICADO EXITOSAMENTE \n");
            }
            else
            {
                printf("\n\t\t ERROR. EL EMPLEADO NO PUDO SER MODIFICADO \n");
            }
            break;

        case 5:
            validarRemove = controller_removeEmployee(listaEmpleados);
            if(validarRemove == -1)
            {
                printf("\n\t\t ERROR. EL ID NO SE ENCONTRO \n");
            }
            else if(validarRemove == -2)
            {
                printf("\n\t\t ERROR. EL EMPLEADO NO PUDO SER ELIMINADO \n");
            }
            else
            {
                printf("\n\t\t EL EMPLEADO FUE ELIMINADO EXITOSAMENTE \n");
            }
            break;

        case 6:
            validarList = controller_ListEmployee(listaEmpleados);
            if(validarList == 0)
            {
                printf("\n\t\t LA LISTA FUE MOSTRADA EXITOSAMENTE \n");
            }
            else
            {
                printf("\n\t\t ERROR. LA LISTA NO PUDO SER MOSTRADA \n");
            }
            break;

        case 7:
            validarSort = controller_sortEmployee(listaEmpleados);
            if(validarSort == -1)
            {
                printf("\n\t\t ERROR. LA LISTA NO PUDO SER ORDENADA \n");
            }
            else if(validarSort == -5)
            {
               printf("\n\t\t EL ORDEN DE LA LISTA FUE CANCELADO \n");
            }
            else
            {
               printf("\n\t\t LA LISTA FUE ORDENADA EXITOSAMENTE \n");
            }
            break;

        case 8:
            validarSave = controller_saveAsText("data.csv", listaEmpleados);
            if(validarSave == -1)
            {
                printf("\n\t\t EL ARCHIVO FUE GUARDADO EXITOSAMENTE \n");
            }
            else
            {
                printf("\n\t\t ERROR. EL ARCHIVO NO PUDO SER GUARDADO \n");
            }
            break;

        case 9:
            validarSave = controller_saveAsBinary("data.bin",listaEmpleados);
            if(validarSave == -1)
            {
                printf("\n\t\t EL ARCHIVO FUE GUARDADO EXITOSAMENTE \n");
            }
            else
            {
                printf("\n\t\t ERROR. EL ARCHIVO NO PUDO SER GUARDADO \n");
            }
            break;

        case 10:
            option = 10;
            printf("\n\t\t SALIR \n");
            break;

        default:
            printf("\n\t\t ERROR. OPCION NO IMPLEMENTADA \n");
        }

        system("pause");
        system("cls");

    }while (option != 10);

    //LIBERAR LA MEMORIA
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
