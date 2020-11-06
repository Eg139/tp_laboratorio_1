#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int idA;
    int idB;

    if(empleadoA!=NULL && empleadoB != NULL)
    {
        employee_getId((Employee*)empleadoA,&idA);
        employee_getId((Employee*)empleadoB,&idB);


        retorno = idA -idB;
    }

    return retorno;
}
int employeeSortByName(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    char nombreA[20];
    char nombreB[20];

    if(empleadoA!=NULL && empleadoB != NULL)
    {
        employee_getNombre((Employee*)empleadoA,nombreA);
        employee_getNombre((Employee*)empleadoB,nombreB);

        retorno = strcmp(nombreA,nombreB);
    }

    return retorno;
}
int employeeSortByHorasTrabajadas(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int horasTrabadasA;
    int horasTrabadasB;

    if(empleadoA!=NULL && empleadoB != NULL)
    {
        employee_getHorasTrabajadas((Employee*)empleadoA,&horasTrabadasA);
        employee_getHorasTrabajadas((Employee*)empleadoB,&horasTrabadasB);


        retorno = horasTrabadasA - horasTrabadasB;
    }

    return retorno;
}

int employeeSortBySueldo(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int sueldoA;
    int sueldoB;

    if(empleadoA!=NULL && empleadoB != NULL)
    {
        employee_getSueldo((Employee*)empleadoA,&sueldoA);
        employee_getSueldo((Employee*)empleadoB,&sueldoB);


        retorno = sueldoA - sueldoB;
    }

    return retorno;
}

int employee_setId(Employee* this,int id)
{
        int todoOk =0;

   /* if(pEmp != NULL && legajo > 0)
    {
        pEmp ->legajo = legajo;
        todoOk = 1;
    }
*/
    return todoOk;
}
int employee_getId(Employee* employeeList,int* id)
{
        int todoOk =0;

    if(employeeList != NULL && id != NULL)
    {
        *id = employeeList->id;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
        int todoOk =0;

    /*if(pEmp != NULL && nombre != NULL)
    {
        strcpy(pEmp ->nombre, nombre);
        todoOk = 1;
    }*/

    return todoOk;
}
int employee_getNombre(Employee* employeeList,char* nombre)
{
    int todoOk =0;

    if(employeeList != NULL && nombre != NULL)
    {
        strcpy(nombre, employeeList->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
            int todoOk =0;

    /*if(pEmp != NULL && nombre != NULL)
    {
        strcpy(pEmp ->nombre, nombre);
        todoOk = 1;
    }*/

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* employeeList,int* horasTrabajadas)
{
        int todoOk =0;

    if(employeeList != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = employeeList->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
            int todoOk =0;

    /*if(pEmp != NULL && nombre != NULL)
    {
        strcpy(pEmp ->nombre, nombre);
        todoOk = 1;
    }*/

    return todoOk;
}
int employee_getSueldo(Employee* employeeList,int* sueldo)
{
        int todoOk =0;

    if(employeeList != NULL && sueldo != NULL)
    {
        *sueldo = employeeList->sueldo;
        todoOk = 1;
    }

    return todoOk;
}
