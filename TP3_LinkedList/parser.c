#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"



int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;
    int maxId=0;
    char idStr[30];
    char nombreStr[30];
    char sueldoStr[30];
    char horasStr[30];
    int i=-1;


    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile)){
            i++;
            if(i==0){
                //fscanf(pFile, "%[^\n]\n",cabecera);
                //printf("cabecera: %s\n", cabecera);
                continue;
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr,nombreStr,horasStr,sueldoStr);
            auxEmployee=newEmpleadoParam(idStr, nombreStr, horasStr,sueldoStr);
            ll_add(pArrayListEmployee,auxEmployee);

            if(atoi(idStr)>maxId)///maxId se encuentra inicializada ya que sera usada como variable de retorno (los id tienen que ser positivos)
            {
                maxId=atoi(idStr);
            }

        }
        printf("Archivo cargado con Exito\n\n");
        fclose(pFile);

    }
    return maxId;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    Employee* employee;
    int maxId=0;
    int id;

    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {
        while(!feof(pFile))
        {
            if (feof(pFile)){
                break;
            }
            employee=newEmpleado();
            if(employee!=NULL)
            {
                if(fread(employee,sizeof(Employee),1,pFile)==1)
                {
                    ll_add(pArrayListEmployee,employee);
                    employee_getId(employee, &id);

                    if(id>maxId){
                        maxId=id;
                    }
                }
            }
        }
        fclose(pFile);
    }


    return maxId;
}


int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int size;
    int i;
    int retorno=0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        size=ll_len(pArrayListEmployee);

        for(i=0; i<size; i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee, i);
            fwrite(employee, sizeof(Employee),1,pFile);
        }
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* employee;
    int i;
    int size;
    int id;
    char nombre[100];
    int horas;
    int sueldo;
    int retorno=0;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

        size=ll_len(pArrayListEmployee);
        for(i=0; i<size; i++)
        {
            employee=(Employee*)ll_get(pArrayListEmployee, i);

            if(employee_getId(employee, &id)==1 && employee_getHorasTrabajadas(employee, &horas)==1 &&
               employee_getNombre(employee, nombre)==1 && employee_getSueldo(employee, &sueldo)==1)
            {
                retorno=1;
                fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
            }
        }
        fclose(pFile);

    }
    return retorno;
}
