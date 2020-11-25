#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

void menu();

int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = ll_newLinkedList();
    int flag=0;
    do
    {
        menu();
        utn_getNumeroEntero(&option,"Ingrese una opcion: ","Opcion incorrecta, Ingrese una opcion valida\n",1,14,3);
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            flag =1;
            break;
        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            flag =1;
            break;
        case 3:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                controller_addEmployee(listaEmpleados);
            }

            break;
        case 4:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                controller_editEmployee(listaEmpleados);
            }
            break;
        case 5:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                controller_removeEmployee(listaEmpleados);
            }

            break;
        case 6:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
            }

            break;
        case 7:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                controller_sortEmployee(listaEmpleados);
            }

            break;
        case 8:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                listaEmpleados2 = ll_subList(listaEmpleados,980,ll_len(listaEmpleados));
                controller_ListEmployee(listaEmpleados2);
                employeList_compare(listaEmpleados,listaEmpleados2);
            }

            break;
        case 9:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                sobreescribir_employee(listaEmpleados);
            }

            break;
        case 10:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                controller_pop(listaEmpleados);
            }

            break;
        case 11:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                if(controller_filter(listaEmpleados)==0)
                {
                    printf("La lista se filtro con exito para empleados que trabajaron mas de 300 horas\n\n");
                }
                else
                {
                    printf("La lista no se pudo filtrar\n\n");
                }
            }

            break;
        case 12:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                controller_saveAsText("data.csv",listaEmpleados);
            }

            break;
        case 13:
            if(flag==0)
            {
                printf("Debe cargar la Lista antes de poder iterar\n");
            }
            else
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }

            break;
        case 14:
            printf("Saliendo del programa....\n");
            break;
        default:
            printf("Opcion incorrecta, Ingrese una opcion valida\n");

        }
        system("pause");
        system("cls");
    }
    while(option != 14);
    free(listaEmpleados);
    free(listaEmpleados2);
    return 0;
}

void menu()
{

    printf("  ****  Menu  ****\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Verificar si la lista clonada pertenece a la lista original\n");
    printf("9. Sobreescribir empleado con ll_push\n");
    printf("10. Usar ll_pop\n");
    printf("11. Filtrar por horas trabajadas\n");
    printf("12. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("13. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("14. Salir \n\n");
}


