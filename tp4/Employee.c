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
    int retorno;
    int horasTrabadasA;
    int horasTrabadasB;
    Employee* auxEmployee1;
    Employee* auxEmployee2;


    if(empleadoA!=NULL && empleadoB != NULL)
    {
        auxEmployee1=(Employee*)empleadoA;
        auxEmployee2=(Employee*)empleadoB;

        employee_getHorasTrabajadas(auxEmployee1, &horasTrabadasA);
        employee_getHorasTrabajadas(auxEmployee2, &horasTrabadasB);

        if(horasTrabadasA > horasTrabadasB)
        {
            retorno=1;
        }
        else if(horasTrabadasA < horasTrabadasB){
            retorno=-1;
        }else{
            retorno = 0;
        }
    }




    return retorno;
}

int employeeSortBySueldo(void* empleadoA, void* empleadoB)
{
    int retorno=0;
    int sueldoA;
    int sueldoB;
    Employee* auxEmployee1;
    Employee* auxEmployee2;


    if(empleadoA!=NULL && empleadoB != NULL)
    {
        auxEmployee1=(Employee*)empleadoA;
        auxEmployee2=(Employee*)empleadoB;

        employee_getSueldo(auxEmployee1, &sueldoA);
        employee_getSueldo(auxEmployee2, &sueldoB);

        if(sueldoA > sueldoB)
        {
            retorno=1;
        }
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

    if(employeeList != NULL)
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

int employee_buscarId(LinkedList* pArrayListEmployee, int id)
{
    Employee* employee;
    int auxId;
    int i;
    int index=-1;
    int size;

    if(pArrayListEmployee != NULL)
    {
        size=ll_len(pArrayListEmployee);

        for(i=0; i<size; i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(employee, &auxId);

            if(id == auxId){
                index=i;
                break;
            }
        }
    }
    return index;

}

int employee_delete(LinkedList* pArrayListEmployee, int index)
{
    int retorno=-2;
    Employee* employee;
    char confirmation[100];

    if(pArrayListEmployee != NULL)
    {
            employee=(Employee*)ll_get(pArrayListEmployee, index);
            mostrarEmpleado(employee);

            printf("Seguro que desea eliminar al empleado? si o no\n");
            fflush(stdin);
            gets(confirmation);
            if(stricmp(confirmation, "si")==0)
            {
                retorno=1;
                ll_remove(pArrayListEmployee, index);
            }
    }else{
        retorno=0;
    }
    return retorno;
}


int employee_edit(LinkedList* pArrayListEmployee, int index)
{
    int retorno=-2;
    int option;
    Employee* employee;
    char name[100];
    int hoursWorked;
    int salary;

    if(pArrayListEmployee != NULL)
    {
        employee=(Employee*)ll_get(pArrayListEmployee, index);
        if(employee!=NULL)
        {
            employee_getHorasTrabajadas(employee, &hoursWorked);
            employee_getSueldo(employee, &salary);
            employee_getNombre(employee, name);

            do{
                printf("MENU DE MODIFICACIONES\n\n1.Nombre\n2.Horas trabajadas\n3.Salario\n4.Salir\n\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &option);

                switch(option){
                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(name);
                        employee_setNombre(employee, name);
                        break;
                    case 2:
                        printf("Ingrese nuevas horas trabajadas del empleado: ");
                        scanf("%d", &hoursWorked);
                        employee_setHorasTrabajadas(employee, hoursWorked);
                        break;
                    case 3:
                        printf("Ingrese nuevo salario del empleado: ");
                        scanf("%d", &salary);
                        employee_setSueldo(employee, salary);
                        break;
                    case 4:
                                retorno=0;
                        break;

                }
            system("pause");
            system("cls");

            }while(option != 4);
        }else{
            retorno=0;
        }
    }
    return retorno;
}

int employeList_compare(LinkedList* this, LinkedList* this2)
{
    int retorno = -1;

    if(this != NULL && this2 != NULL)
    {
     if(ll_containsAll(this,this2)==1)
     {
         retorno = 0;
         printf("La lista 2 pertenece a la lista 1\n");
     }else{
         printf("La lista 2 no pertenece a la lista 1\n");
         retorno = 1;
     }
    }
    return retorno;
}
int sobreescribir_employee(LinkedList* this)
{
    int retorno = 1;
    int indice;
    Employee* aux;
    char name[20] = "Pepe";
    int horasTrabajadas = 999;
    int salario = 9999;



    if(this != NULL)
    {
        printf("Ingrese el ID que quiere sobreescribir: ");
        scanf("%d", &indice);
        aux = ll_get(this,indice);
        aux->id = indice;
        strcpy(aux->nombre,name);
        aux->horasTrabajadas = horasTrabajadas;
        aux->sueldo = salario;


        ll_push(this,indice,aux);
        retorno = 0;
    }


    return retorno;
}

int filtrar_horasTrabajadas(void* emp)
{
    int rta = 0;

    Employee* aux=NULL;

    if(emp != NULL)
    {
        aux = (Employee*)emp;

        if(aux->horasTrabajadas > 300)
        {
            rta = 1;
        }
    }
    return rta;
}
