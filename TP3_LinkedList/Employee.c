#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int employeeSortById(void* empleadoA, void* empleadoB)
{
    Employee* auxEmployee1;
    Employee* auxEmployee2;
    int id1;
    int id2;
    int ret;
    if(empleadoA != NULL && empleadoB != NULL)
    {
        auxEmployee1=(Employee*)empleadoA;
        auxEmployee2=(Employee*)empleadoB;

        employee_getId(auxEmployee1, &id1);
        employee_getId(auxEmployee2, &id2);

        if(id1 > id2)
        {
            ret=1;
        }
        else if(id1 < id2){
            ret=-1;
        }else{
            ret = 0;
        }



    }
    return ret;
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

int employee_setId(Employee* employee,int id)
{
        int todoOk =0;

   if(employee != NULL && id > 0)
    {
        employee ->id = id;
        todoOk = 1;
    }

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

int employee_setNombre(Employee* employee,char* nombre)
{
        int todoOk =0;

    if(employee != NULL && nombre != NULL)
    {
        strcpy(employee ->nombre, nombre);
        todoOk = 1;
    }

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

int employee_setHorasTrabajadas(Employee* employee,int horasTrabajadas)
{
    int todoOk =0;

    if(employee != NULL && horasTrabajadas > 0)
    {
        employee ->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

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

int employee_setSueldo(Employee* employee,int sueldo)
{
    int todoOk =0;

    if(employee != NULL && sueldo > 0)
    {
        employee ->sueldo = sueldo;
        todoOk = 1;
    }

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


Employee* newEmpleado()
{
    Employee* nuevoEmpleado = NULL;
    nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}

Employee* newEmpleadoParam(char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
    Employee* nuevoEmpleado = newEmpleado();

    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado,atoi(id))
                && employee_setNombre(nuevoEmpleado,nombre)
                && employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadas))
                && employee_setSueldo(nuevoEmpleado,atoi(sueldo))))
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }

    }


    return nuevoEmpleado;
}

int mostrarEmpleado(Employee* pEmp)
{
    int error = 0;

    int id;
    char name[50];
    int hoursWorked;
    int salary;

    if(pEmp!=NULL)
    {
        if(employee_getId(pEmp, &id)==1 && employee_getSueldo(pEmp, &salary)==1 &&
           employee_getHorasTrabajadas(pEmp, &hoursWorked)==1 &&employee_getNombre(pEmp, name)==1 )
        {
            printf("|%10d|%20s|%13d|%10d|\n", id, name, hoursWorked, salary);
            error=1;
        }
    }
    printf("\n");


    return error;
}
