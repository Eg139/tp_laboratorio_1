#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    FILE* f;
    if(path != NULL && pArrayListEmployee!=NULL)
    {
        f = fopen(path, "r");
        parser_EmployeeFromText(f,pArrayListEmployee);


        fclose(f);
        todoOk = 1;
    }else{
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }


    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* binaryFile;
    int retorno=-1;

    if(path!=NULL && pArrayListEmployee!= NULL)
    {
        ll_clear(pArrayListEmployee);
        printf("Se ha limpiado la lista\n");
        binaryFile=fopen(path, "rb");
        if(binaryFile!=NULL)
        {
            retorno=parser_EmployeeFromBinary(binaryFile, pArrayListEmployee);
        }
        else
        {
            printf("Archivo inexistente, se procederá a crear una carpeta\n");
            binaryFile=fopen(path, "wb");
            if(binaryFile!=NULL)
            {
                retorno=-2;
            }
        }
    }else{
        retorno=0;
    }
    return retorno;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int sigID)
{
    int retorno = 0;
    Employee* employee;
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL)
    {
        employee = newEmpleado();
        if(employee != NULL)
        {
            id= sigID;
            printf("Su id es: %d\n", id);
            printf("Ingrese un nombre: ");
            fflush(stdin);
            puts(nombre);
            printf("Ingrese las horas trabajadas: ");
            scanf("%d", &horasTrabajadas);
            printf("Ingrese el sueldo: ");
            scanf("%d", &sueldo);

            if(employee_setId(employee, id)==1 &&
               employee_setNombre(employee, nombre)==1 &&
               employee_setHorasTrabajadas(employee, horasTrabajadas)==1 &&
               employee_setSueldo(employee, sueldo)==1)
            {
                ll_add(pArrayListEmployee, employee);
                retorno=1;
            }

        }
    }


    return retorno;
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


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
        int i;
    int ret=0;
    int size;
    Employee* aux;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);
        if(size!=0)
        {
            printf("__________________________________________________________\n"
                   "|    ID    |       NOMBRE       |HORAS TRABAJO|  SALARIO |\n"
                   "|__________|____________________|_____________|__________|\n");
            for(i=0; i<size; i++)
            {
                aux =(Employee*)ll_get(pArrayListEmployee, i);
                mostrarEmpleado(aux);
            }
                printf("|__________|____________________|_____________|__________|\n");
            ret=1;
        }else{
            ret=-1;
        }
    }
    return ret;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 1;
    int option=0;
    LinkedList* auxiliar;
    auxiliar = ll_clone(pArrayListEmployee);

    if(pArrayListEmployee != NULL && auxiliar != NULL)
    {
        retorno = 0;

        do
        {
        system("cls");

        printf("  ****  Menu de Ordenamiento ****\n\n 1. Ordenar por ID.\n2. Ordenar por Nombre.\n3. Ordenar por Horas trabajadas\n4. Ordenar por sueldo\n5. Salir \n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            ll_sort(auxiliar,employeeSortById,0);
            break;
        case 2:
            ll_sort(auxiliar,employeeSortByName,1);
            break;
        case 3:
            ll_sort(auxiliar,employeeSortByHorasTrabajadas,1);
            break;
        case 4:
            ll_sort(auxiliar,employeeSortBySueldo,1);
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


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* textFile;
    int retorno=0;

    if(pArrayListEmployee != NULL && path != NULL && ll_isEmpty(pArrayListEmployee)==0)
    {
        textFile=fopen(path, "w");
        if(textFile!= NULL)
        {
            retorno=parser_EmployeeToText(textFile, pArrayListEmployee);
        }
    }
    return retorno;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* binaryFile;
    int retorno=0;

    if(path!=NULL && pArrayListEmployee!= NULL && ll_isEmpty(pArrayListEmployee)==0)
    {
        binaryFile=fopen(path, "wb");
        if(binaryFile!=NULL)
        {
            retorno=parser_EmployeeToBinary(binaryFile, pArrayListEmployee);
        }
    }

    return retorno;
}

