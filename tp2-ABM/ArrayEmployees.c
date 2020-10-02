
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
    int opcion = 0;
    int cont = 0;
    int employeeFlag =0;
    eEmployee listEmployees[T];



    char option;
    option= GetChar("Desea hardcodear el codigo?\nS para si, N para no :");
    while(option != 'S' && option !='N')
        {
            option = GetChar("Desea hardcodear el codigo?\nS para si, N para no :");
        }
        if(option =='S')
        {
            initEmployees(listEmployees, T);
            hardCodear(listEmployees);
            cont = 5;
            printf("ATENCION!!! Aun debe agregar un empleado para poder usar el resto del menu!!!!\n");
            system("pause");
            system("cls");
        }
        else
        {
            initEmployees(listEmployees, T);
            printf("Iniciara con el listado de empleados vacio\n");
            system("pause");
            system("cls");
        }

    do{
    opcion = menuUser("1. ALTA DE EMPLEADOS\n2. MODIFICAR EMPLEADOS\n3. BAJA DE EMPLEADOS\n4. INFORMAR\n5.SALIR\nELIJA UNA OPCION: ");
    system("cls");
    while(opcion > 6 || opcion < 1)
    {
        printf("OPCION INCORRECTA, REINGRESE UNA OPCION VALIDA\n");
        opcion = menuUser("1. ALTA DE EMPLEADOS\n2. MODIFICAR EMPLEADOS\n3. BAJA DE EMPLEADOS\n4. INFORMAR\n5.SALIR\nELIJA UNA OPCION: ");
    }
    switch(opcion)
    {
        case 1:
            cont++;
            if(addEmployees(listEmployees, T,cont) == 0)
            {
             printf("\nEMPLEADO INGRESADO CON EXITO\n");
             employeeFlag = 1;
             system("pause");
             system("cls");
            }else{
                printf("ERROR!!!!\n NO HAY ESPACIO PARA AGREGAR EMPLEADOS");
                system("pause");
                system("cls");
            }

        break;
        case 2:
            if(employeeFlag == 1)
                {
            printEmployees(listEmployees, T);
            if(modifyEmployee(listEmployees, T)==0)
            {
                printf("El empleado se modifico con exito\n");
            }
            else
            {
                printf("ATENCION!!!El Id no coincidio con ningun empleado o decidio salir sin modificar nada, volvera al menu anterior\n");
            }
            }else{
                printf("No se cargo un empleado, porfavor ingrese un empleado\n");
            }
            system("pause");
            system("cls");
            break;
            case 3:
            if(employeeFlag == 1){
                if(removeEmployee(listEmployees, T)==0)
                {
                    printf("El empleado se elimino con exito\n");
                }else
                {
                  printf("Error! No se pudo eliminar empleado, El Id estaba libre\n");
                }
            }else{
                printf("No se cargo un empleado, porfavor ingrese un empleado\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            if(employeeFlag == 1){
                printEmployees(listEmployees, T);
                fflush(stdin);
                opcion = menuUser("\nQUE DESEA INFORMAR:\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio\nElija una opcion: ");
                while(opcion > 2 || opcion < 1)
                {
                printf("OPCION INCORRECTA, REINGRESE UNA OPCION VALIDA\n");
                opcion = menuUser("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio\nElija una opcion:");
                }
                switch(opcion)
                {
                    case 1:
                        if(sortEmployees(listEmployees, T)== 0)
                        {
                            printf("\nLos empleados se ordenaron con exito\n");
                            printEmployees(listEmployees, T);
                        }
                        else
                        {
                            printf("\nLos empleados no pudieron ordenarse\n");
                        }

                    break;

                    case 2:

                        if(showSalary(listEmployees, T)==0)
                        {
                            printf("\nSe pudo mostrar el salario\n");
                        }else
                        {
                            printf("\nERROR! No se pudo mostrar el salario");
                        }
                    break;
                }
            }
                else{
                printf("No se cargo un empleado, porfavor ingrese un empleado\n");
            }
                system("pause");
                system("cls");
        break;
        case 5:
        break;

    }
    }while(opcion != 5);

}


int modifyEmployee(eEmployee listado[], int len)
{
    int id;
    int index = -1;
    int eleccion = 0;
    int i;

    id = findEmployeeById("\nIngrese el Id del empleado a modificar: ", listado, len);

    for(i = 0; i< len; i++)
    {
        if((listado[i].id == id) &&(listado[i].isEmpty == OCUPADO))
        {
            fflush(stdin);
            eleccion = menuUser("1. NOMBRE\n2. APELLIDO\n3.SALARIO\n4. SECTOR\n5. SALIR\nElija una opcion: ");
            while(eleccion >5 || eleccion < 1)
            {
                printf("Opcion incorrecta, Ingrese una opcion valida\n");
                fflush(stdin);
                eleccion = menuUser("1. NOMBRE\n2. APELLIDO\n3.SALARIO\n4. SECTOR\n5. SALIR\nElija una opcion: ");
            }
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
            break;}

        }
        }
        return index;

    }

int removeEmployee(eEmployee listado[], int len)
{
    int id;
    int i;
    int index = -1;
    id = findEmployeeById("\nIngrese el Id del empleado que desea eliminar: ", listado, len);
    for(i = 0; i<len; i++)
    {
        if(id == listado[i].id && listado[i].isEmpty == OCUPADO)
        {
            listado[i].isEmpty = BAJA;

            index = 0;
            break;
        }
    }
    return index;
}



void hardCodear(eEmployee listado[])
{
    int ids[5] = {1,2,3,4,5};
    float salary[5] = {9000.50,54841.64,10000.00,98410.15,5800.1};
    int sector[5] = {1,2,5,4,3};
    char name[5][20] ={"Pepe","lucia","ricardo","alex","fatiga"};
    char lastName[5][20] = {"Argento", "Gutierrez","Cosentino","Aprea","Argento"};
    int i;

    for(i = 0; i<5; i++)
    {
       listado[i].id = ids[i];
       listado[i].salary = salary[i];
       listado[i].sector = sector[i];
       strcpy(listado[i].name, name[i]);
       strcpy(listado[i].lastName, lastName[i]);
       listado[i].isEmpty = OCUPADO;
    }

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

int addEmployees(eEmployee listado[], int len, int cont)
{
    int indice;
    int index = -1;
    //int i;
    indice = searchFree(listado, len);
    if(indice != -1)
    {
        listado[indice] = createEmployee(cont);
        index = 0;
    }
    return index;

}
int printEmployees(eEmployee listado[], int len)
{
    int i;
    int index = -1;
    printf("   ID   \tNOMBRE      APELLIDO     SALARIO   SECTOR\n");
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
       printf("%4d %15s %15s \t%8.2f %4d\n",miEmployee.id,
                                                miEmployee.name,
                                                miEmployee.lastName,
                                                miEmployee.salary,
                                                miEmployee.sector);
}

eEmployee createEmployee(int id)
{
    eEmployee miEmployee;

    miEmployee.isEmpty = OCUPADO;

    miEmployee.id = id;

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

    for(i = 0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
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

int findEmployeeById(char message[],eEmployee listado[], int len)
{
    int auxGetId;
    auxGetId = GetInt("\nIngrese el ID del empleado: ");
    return auxGetId;
}
