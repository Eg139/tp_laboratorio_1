#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    if(path != NULL && pArrayListEmployee!=NULL)
    {
        FILE* f = fopen(path, "r");
        parser_EmployeeFromText(f,pArrayListEmployee);


        fclose(f);
        todoOk = 1;
    }else{
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }


    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int option=0;
    int aux;
    LinkedList* auxiliar;
    auxiliar = ll_clone(pArrayListEmployee);

    if(pArrayListEmployee != NULL && auxiliar != NULL)
    {
        retorno = 0;

        do
        {
        system("cls");

        printf("Ordenar de forma ascendente 1, Ordenar de forma descendente 0\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &aux);
        printf("\n\n");
        while(aux!=1 && aux!=0)
        {
            printf("Opcion invalida ,Ordenar de forma ascendente 1, Ordenar de forma descendente 0\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &aux);
        }

        printf("  ****  Menu de Ordenamiento ****\n\n 1. Ordenar por ID.\n2. Ordenar por Nombre.\n3. Ordenar por Horas trabajadas\n4. Ordenar por sueldo\n5. Salir \n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            ll_sort(auxiliar,employeeSortById,aux);
            break;
        case 2:
            ll_sort(auxiliar,employeeSortByName,aux);
            break;
        case 3:
            ll_sort(auxiliar,employeeSortByHorasTrabajadas,aux);
            break;
        case 4:
            ll_sort(auxiliar,employeeSortBySueldo,aux);
            break;
        case 5:
            printf("Saliendo del menu de ordenamiento\n");
            break;
        default:
            printf("Opcion incorrecta, Ingrese una opcion valida\n");

        }
        if(option==5)
        {
            controller_ListEmployee(auxiliar);
        }
        system("pause");
        system("cls");
    }
    while(option != 5);
    ll_deleteLinkedList(auxiliar);
    }



    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

