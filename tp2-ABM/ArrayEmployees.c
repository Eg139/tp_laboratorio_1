
#include "ArrayEmployees.h"


int menuUser(char texto[])
{
    int opcion;
    printf("%s", texto);
    scanf("%d", &opcion);

    return opcion;
}


void menu()
{
    int opcion;
    int cont = 0;
    eEmployee listEmployees[T];
    initEmployees(listEmployees, T);
    do
    {
        opcion = menuUser("MENU DE ABM \n\n1. ALTA DE EMPLEADOS\n2. MODIFICAR EMPLEADOS\n3. BAJA DE EMPLEADOS\n4. INFORMAR\n5.SALIR\nELIJA UNA OPCION: ");
        switch(opcion)
        {
        case 1:
            cont++;
            if( cont > 0)
            {
                addEmployees(listEmployees, T);
                printf("\nEMPLEADO INGRESADO CON EXITO\n");
            }
            else
            {
                printf("ERROR!!!!\n NO HAY ESPACIO PARA AGREGAR EMPLEADOS");
            }

            break;
        case 2:
            if(cont > 0)
            {
                printEmployees(listEmployees, T);
                opcionDos(listEmployees,T);
            }
            else
            {
                printf("No se cargo un empleado, porfavor ingrese un empleado\n");
            }
            break;
        case 3:
            if(cont > 0)
            {
                if(removeEmployee(listEmployees, T)==0)
                {
                    printf("El empleado se elimino con exito\n");
                    cont--;
                }
                else
                {
                    printf("Error! No se pudo eliminar empleado, El Id estaba libre\n");
                }
            }
            else
            {
                printf("No se cargo un empleado, porfavor ingrese un empleado\n");
            }
            break;
        case 4:
            if(cont > 0)
            {
                printEmployees(listEmployees, T);
                opcionCuatro(listEmployees, T);
            }
            else
            {
                printf("No se cargo un empleado, porfavor ingrese un empleado\n");
            }
            break;
        case 5:
            break;
        default:
            printf("OPCION INCORRECTA, REINGRESE UNA OPCION VALIDA\n");
            break;

        }
        system("pause");
        system("cls");
    }
    while(opcion != 5);

}


int modifyEmployee(eEmployee listado[], int len, int id)
{
    int index = -1;
    int eleccion = 0;
    int i;

    for(i = 0; i< len; i++)
    {
        if((listado[i].id == id) &&(listado[i].isEmpty == OCUPADO))
        {
            do
            {
                fflush(stdin);
                eleccion = menuUser("1. NOMBRE\n2. APELLIDO\n3.SALARIO\n4. SECTOR\n5. SALIR\nElija una opcion: ");
                switch(eleccion)
                {
                case 1://name
                    GetString("Reingrese el nombre: ", listado[i].name, len);
                    index = 0;
                    break;

                case 2://lastName
                    GetString("Reingrese el apellido: ", listado[i].lastName, len);
                    index = 0;
                    break;

                case 3:
                    listado[i].salary = GetFloat("Reingrese el salario del empleado: ");
                    index = 0;
                    break;

                case 4: //sector
                    listado[i].sector = GetInt("Reingrese el sector del empleado: ");
                    index = 0;
                    break;
                case 5:
                    printf("Saliendo..\n");
                    break;
                default:
                    printf("Opcion incorrecta, Ingrese una opcion valida\n");
                    break;
                }
                system("pause");
                system("cls");
            }
            while(eleccion != 5);
        }
    }
    return index;

}

int removeEmployee(eEmployee listado[], int len)
{
    int id;
    int index = -1;
    id = GetInt("Ingrese el ID: ");
    int auxFree = findEmployeeById(listado,len,id);

    if(auxFree==0)
    {
        listado[id-1].isEmpty = LIBRE;
        index = 0;
    }
    return index;
}



int initEmployees(eEmployee listado[], int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        listado[i].isEmpty = LIBRE;
        index = 0;
    }
    return index;
}
int searchFree(eEmployee listado[], int len)
{
    int i;
    int indice = -1;
    for(i = 0; i < len; i++)
    {
        if(listado[i].isEmpty == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int addEmployees(eEmployee listado[], int len)
{
    int indice;
    int index = -1;
    //int i;
    indice = searchFree(listado, len);
    if(indice != -1)
    {
        listado[indice] = createEmployee(indice);
        index = 0;
    }
    return index;

}
int printEmployees(eEmployee listado[], int len)
{
    int i;
    int index = -1;
    printf("     ID\t\tNOMBRE      APELLIDO     SALARIO   SECTOR\n");
    for(i = 0; i < len; i++)
    {
        if(listado[i].isEmpty == OCUPADO)
        {
            printEmployee(listado[i]);
            index = 0;
        }
    }
    return index;
}

void printEmployee(eEmployee miEmployee)
{
    printf("%6d \t%12s %12s \t%8.2f %6d\n",miEmployee.id,
           miEmployee.name,
           miEmployee.lastName,
           miEmployee.salary,
           miEmployee.sector);
}

eEmployee createEmployee(int id)
{
    eEmployee miEmployee;

    miEmployee.isEmpty = OCUPADO;

    miEmployee.id = id+1;

    GetString("Ingrese el Nombre: ", miEmployee.name, id);
    GetString("Ingrese el Apellido: ", miEmployee.lastName, id);
    miEmployee.salary = GetFloat("Ingrese el Salario: ");
    miEmployee.sector = GetInt("Ingrese el sector del empleado entre 1 y 1000: ");
    return miEmployee;
}



int sortEmployees(eEmployee listado[], int len)
{
    int index = -1;
    int i;
    int j;
    eEmployee auxEmployee;

    for(i = 0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(strcmp(listado[i].lastName, listado[j].lastName)>0)
            {
                auxEmployee = listado[i];
                listado[i] = listado[j];
                listado[j] = auxEmployee;
            }
            else
            {
                if(strcmp(listado[i].lastName, listado[j].lastName)==0)
                {
                    if(listado[i].sector > listado[j].sector)
                    {
                        auxEmployee = listado[i];
                        listado[i] = listado[j];
                        listado[j] = auxEmployee;
                    }
                }
            }
        }
    }
    index = 0;
    return index;
}
int showSalary(eEmployee listado[], int len)
{
    int i;
    int index = -1;
    float acumulador = 0;
    int contador = 0;
    float promedio;
    for(i = 0; i<len; i++)
    {
        if(listado[i].isEmpty == OCUPADO)
        {
            acumulador = acumulador + listado[i].salary;
            contador++;
        }
    }
    promedio = acumulador/contador;

    index = 0;

    printf("   ID   \tNOMBRE      APELLIDO     SALARIO   SECTOR\n");
    for(i = 0; i< len; i++)
    {
        if(listado[i].salary > promedio && listado[i].isEmpty == OCUPADO)
        {
            printEmployee(listado[i]);
        }
    }

    printf("\nEl TOTAL DE LOS SALARIOS ES: %.2f Y EL PROMEDIO DE LOS MISMOS ES: %.2f \n", acumulador,promedio);

    return index;

}

int findEmployeeById(eEmployee listado[], int len, int id)
{
    int index = -1;
    int i;
    for(i=0; i<len; i++)
    {
        if(id == listado[i].id && listado[i].isEmpty == OCUPADO)
        {
            index =0;
        }
    }
    return index;
}


int opcionCuatro(eEmployee listado[],int len)
{
    int retorno = -1;
    int opcion;
    fflush(stdin);
    opcion = menuUser("\nQUE DESEA INFORMAR:\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio\nElija una opcion: ");
    switch(opcion)
    {
    case 1:
        if(sortEmployees(listado, len)== 0)
        {
            printf("\nLos empleados se ordenaron con exito\n");
            printEmployees(listado, len);
            retorno =0;
        }
        else
        {
            printf("\nLos empleados no pudieron ordenarse\n");
        }
        break;
    case 2:
        if(showSalary(listado, len)==0)
        {
            printf("\nSe pudo mostrar el salario\n");
            retorno = 0;
        }
        else
        {
            printf("\nERROR! No se pudo mostrar el salario");
        }
        break;
    default:
        printf("OPCION INCORRECTA, REGRESARA AL MENU\n");
        break;
    }
    return retorno;
}

int opcionDos(eEmployee listado[],int len)
{
    int retorno = -1;
    int id;
    id = GetInt("Ingrese el ID: ");
    if(modifyEmployee(listado, len,id)==0)
    {
        printf("El empleado se modifico con exito\n");
        retorno =0;
    }
    else
    {
        printf("ATENCION!!!El Id no coincidio con ningun empleado volvera al menu anterior\n");
    }
    return retorno;
}
