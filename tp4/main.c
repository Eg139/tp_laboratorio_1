#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

void menu();

int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = ll_newLinkedList();
    do
    {
        menu();
        printf("Ingrese una opcion: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            listaEmpleados2 = ll_subList(listaEmpleados,900,ll_len(listaEmpleados));
            employeList_compare(listaEmpleados,listaEmpleados2);
            break;
        case 9:
            sobreescribir_employee(listaEmpleados);
            break;
        case 10:
            controller_pop(listaEmpleados);
            break;
        case 11:
            if(controller_filter(listaEmpleados)==0)
            {
                printf("La lista se filtro con exito\n\n");
            }else{
                printf("La lista no se pudo filtrar\n\n");
            }

            break;
        case 12:
            controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 13:
            controller_saveAsBinary("data.bin",listaEmpleados);
            break;
        case 15:
            printf("Saliendo del programa....\n");
            break;
        default:
            printf("Opcion incorrecta, Ingrese una opcion valida\n");

        }
        system("pause");
        system("cls");
    }
    while(option != 15);
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
    printf("15. Salir \n\n");
}


