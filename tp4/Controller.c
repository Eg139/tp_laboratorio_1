#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


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


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Profesor* employee;
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    if(pArrayListEmployee != NULL)
    {
        employee = newEmpleado();
        if(employee != NULL)
        {

            id = ll_len(pArrayListEmployee);
            printf("Su id es: %d\n", id);
            utn_getString(nombre,"Ingrese un nombre: ","Ingrese un valor valido, Porfavor ingrese un nombre: ",3);
            utn_getNumeroEntero(&horasTrabajadas,"Ingrese las horas trabajadas: ","No es un numero, Porfavor ingrese las horas trabajadas: ",1,1000,3);
            utn_getNumeroEntero(&sueldo,"Ingrese el sueldo: ","Valor incorrecto, ingrese un sueldo valido ",1,900000,3);
            if(employee_setId(employee, id)==1 &&
               employee_setNombre(employee, nombre)==1 &&
               employee_setHorasTrabajadas(employee, horasTrabajadas)==1 &&
               employee_setSueldo(employee, sueldo)==1)
            {
                ll_add(pArrayListEmployee, employee);
                retorno=1;
                printf("Empleado agregado con exito\n");
            }

        }
    }


    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int index;

    if(pArrayListEmployee != NULL)
    {
        utn_getNumeroEntero(&id,"Ingrese el id a modificar: ","Porfavor ingrese un id valido, reingrese el Id: ",1,ll_len(pArrayListEmployee),5);
        index= employee_buscarId(pArrayListEmployee, id);

        if(index != -1)
        {
            retorno=employee_edit(pArrayListEmployee, index);
        }

    }else{
        retorno=0;
    }
    return retorno;

}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int index;
    int id;

    if(pArrayListEmployee != NULL)
    {
        utn_getNumeroEntero(&id,"Ingrese el id a eliminar: ","Porfavor ingrese un id valido, reingrese el Id: ",1,ll_len(pArrayListEmployee),5);
        index= employee_buscarId(pArrayListEmployee, id);
        if(index!=-1)
        {
            retorno=employee_delete(pArrayListEmployee, index);
        }
    }else{
        retorno=0;
    }
    return retorno;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int retorno=0;
    int size;
    Profesor* aux;

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
                aux =(Profesor*)ll_get(pArrayListEmployee, i);
                mostrarEmpleado(aux);
            }
                printf("|__________|____________________|_____________|__________|\n");
            retorno=1;
        }else{
            retorno=-1;
        }
    }
    return retorno;
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
        utn_getNumeroEntero(&option,"Ingrese una opcion valida: ","Porfavor ingrese una opcion valida, reingrese la opcion: ",1,5,3);
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
            printf("Archivo guardado con exito\n");
        }
    }else{
        printf("No se pudo guardar el archivo\n");
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
            printf("Archivo guardado con exito\n");
        }
    }else{
        printf("No se pudo guardar el archivo\n");
    }

    return retorno;
}

int controller_pop(LinkedList* this)
{
    int retorno = 0;
    int index;
    utn_getNumeroEntero(&index,"Ingrese el Id que desea eliminar 0 a 1000: ","Id fuera de lo indicado, Reingrese el Id: ",1,ll_len(this),3);

    if(this != NULL)
    {
        retorno = (int)ll_pop(this,index);
    }


    return printf("\nLa direccion de memoria borrado por ll_pop es: %d\n\n",  retorno);
}


int controller_filter(LinkedList* this)
{
    LinkedList* aux=NULL;

    int retorno = 1;
    if(this != NULL)
    {
        aux = ll_filter(this,filtrar_horasTrabajadas);
        if(aux != NULL)
        {
            controller_ListEmployee(aux);
            retorno = 0;
        }

    }


    return retorno;
}
