#include "Employee.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int employeeSortById(void* empleadoA, void* empleadoB)
{
    Profesor* auxEmployee1;
    Profesor* auxEmployee2;
    int id1;
    int id2;
    int ret;
    if(empleadoA != NULL && empleadoB != NULL)
    {
        auxEmployee1=(Profesor*)empleadoA;
        auxEmployee2=(Profesor*)empleadoB;

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
        employee_getNombre((Profesor*)empleadoA,nombreA);
        employee_getNombre((Profesor*)empleadoB,nombreB);

        retorno = strcmp(nombreA,nombreB);
    }

    return retorno;
}
int employeeSortByHorasTrabajadas(void* empleadoA, void* empleadoB)
{
    int retorno;
    int horasTrabadasA;
    int horasTrabadasB;
    Profesor* auxEmployee1;
    Profesor* auxEmployee2;


    if(empleadoA!=NULL && empleadoB != NULL)
    {
        auxEmployee1=(Profesor*)empleadoA;
        auxEmployee2=(Profesor*)empleadoB;

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
    Profesor* auxEmployee1;
    Profesor* auxEmployee2;


    if(empleadoA!=NULL && empleadoB != NULL)
    {
        auxEmployee1=(Profesor*)empleadoA;
        auxEmployee2=(Profesor*)empleadoB;

        employee_getSueldo(auxEmployee1, &sueldoA);
        employee_getSueldo(auxEmployee2, &sueldoB);

        if(sueldoA > sueldoB)
        {
            retorno=1;
        }
    }


    return retorno;
}

int employee_setId(Profesor* employee,int id)
{
        int todoOk =0;

   if(employee != NULL && id > 0)
    {
        employee ->id = id;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getId(Profesor* employeeList,int* id)
{
        int todoOk =0;

    if(employeeList != NULL)
    {
        *id = employeeList->id;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setNombre(Profesor* employee,char* nombre)
{
        int todoOk =0;

    if(employee != NULL && nombre != NULL)
    {
        strcpy(employee ->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}
int employee_getNombre(Profesor* employeeList,char* nombre)
{
    int todoOk =0;

    if(employeeList != NULL && nombre != NULL)
    {
        strcpy(nombre, employeeList->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Profesor* employee,int horasTrabajadas)
{
    int todoOk =0;

    if(employee != NULL && horasTrabajadas > 0)
    {
        employee ->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Profesor* employeeList,int* horasTrabajadas)
{
        int todoOk =0;

    if(employeeList != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = employeeList->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setSueldo(Profesor* employee,int sueldo)
{
    int todoOk =0;

    if(employee != NULL && sueldo > 0)
    {
        employee ->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getSueldo(Profesor* employeeList,int* sueldo)
{
        int todoOk =0;

    if(employeeList != NULL && sueldo != NULL)
    {
        *sueldo = employeeList->sueldo;
        todoOk = 1;
    }

    return todoOk;
}


Profesor* newEmpleado()
{
    Profesor* nuevoEmpleado = NULL;
    nuevoEmpleado = (Profesor*) malloc(sizeof(Profesor));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}

Profesor* newEmpleadoParam(char* id, char* nombre, char* horasTrabajadas, char* sueldo)
{
    Profesor* nuevoEmpleado = newEmpleado();

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

int mostrarEmpleado(Profesor* pEmp)
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
    Profesor* employee;
    int auxId;
    int i;
    int index=-1;
    int size;

    if(pArrayListEmployee != NULL)
    {
        size=ll_len(pArrayListEmployee);

        for(i=0; i<size; i++)
        {
            employee=(Profesor*)ll_get(pArrayListEmployee, i);
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
    Profesor* employee;
    char confirmation[100];

    if(pArrayListEmployee != NULL)
    {
            employee=(Profesor*)ll_get(pArrayListEmployee, index);
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
    Profesor* employee;
    char name[100];
    int hoursWorked;
    int salary;

    if(pArrayListEmployee != NULL)
    {
        employee=(Profesor*)ll_get(pArrayListEmployee, index);
        if(employee!=NULL)
        {
            employee_getHorasTrabajadas(employee, &hoursWorked);
            employee_getSueldo(employee, &salary);
            employee_getNombre(employee, name);

            do{
                printf("MENU DE MODIFICACIONES\n\n1.Nombre\n2.Horas trabajadas\n3.Salario\n4.Salir\n\n");
                utn_getNumeroEntero(&option,"Ingrese una opcion: ","Opcion invalida, Reingrese una opcion: ", 1,4,3);

                switch(option){
                    case 1:
                        utn_getString(name,"Ingrese nuevo nombre: ","Dato invalido, Reingrese un nombre: ",3);
                        employee_setNombre(employee, name);
                        break;
                    case 2:
                        utn_getNumeroEntero(&hoursWorked,"Ingrese nuevas horas trabajadas del empleado: ","Dato invalido, Reingrese una la carga horaria: ", 1,9000,3);
                        employee_setHorasTrabajadas(employee, hoursWorked);
                        break;
                    case 3:
                        utn_getNumeroEntero(&salary,"Ingrese nuevo salario del empleado: ","Salario invalido, Reingrese el nuevo dalario: ", 1,900000,3);
                        employee_setSueldo(employee, salary);
                        break;
                    case 4:
                        printf("Saliendo del Menu modificar\n\n");
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
    Profesor* aux;
    char name[20] = "Pepe";
    int horasTrabajadas = 999;
    int salario = 9999;



    if(this != NULL)
    {
        utn_getNumeroEntero(&indice,"Ingrese el ID que quiere sobreescribir: ","Id incorrecto, Ingrese un Id valido(0-1000): ",1,ll_len(this),4);
        aux = ll_get(this,indice);
        mostrarEmpleado(aux);
        printf("\nSe sobreescribira con: Nombre: %s\nHorasTrabajadas: %d\nSueldo: %d\n\n", name,horasTrabajadas,salario);

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
    Profesor* aux=NULL;

    if(emp != NULL)
    {
        aux = (Profesor*)emp;

        if(aux->horasTrabajadas > 300)
        {
            rta = 1;
        }
    }
    return rta;
}

/*
int filtrar_Sueldo(void* emp)
{
    int rta = 0;
    Profesor* aux=NULL;

    if(emp != NULL)
    {

        aux = (Profesor*)emp;

        if(aux->sueldo > 40000)
        {
            rta = 1;
        }
    }
    return rta;
}
*/
