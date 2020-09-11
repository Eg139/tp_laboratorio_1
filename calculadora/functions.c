#include "functions.h"

/*------------------------------------------------Menu-------------------------------------------------------------------------*/

void menu(int a, int b)
{
    printf("\n\nBIENVENIDO AL MENU DE OPCIONES \n");
    printf("  Seleccione una opcion  \n");
    printf("1) Ingresar 1er valor (A= %d ) \n", a);
    printf("2) Ingresar 2do valor (B= %d ) \n", b);
    printf("3) Calcular todas las operaciones. \n");
    printf("        a) Calcular la suma de: (A= %d ) + (B= %d) \n", a, b);
    printf("        b) Calcular la resta de: (A= %d ) - (B= %d) \n", a, b);
    printf("        c) Calcular la division de: (A= %d ) / (B= %d) \n", a, b);
    printf("        d) Calcular la multiplicacion de: (A= %d) * (B= %d) \n", a, b);
    printf("        e) Calcular el factorial de: (A!= %d) \n", a);
    printf("        f) Calcular el factorial de: (B!= %d) \n", b);
    printf("4) Informar resultados \n");
    printf("5) Salir\n\n");
}
/*---------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------Opciones-------------------------------------------------------------------------*/

void eleccion(int a, int b)
{
    int opcion;
    int flagA = 0;
    int flagB = 0;
    int flagOperaciones = 0;
    int resultado_Suma;
    int resultado_Resta;
    int resultado_Multiplicacion;
    float resultado_Division;
    long int resultado_FactorialA;
    long int resultado_FactorialB;

    do
    {
        menu(a,b);
        opcion = get_int(opcion);
        switch(opcion)
        {
        case 1:
            a = get_int(a);
            flagA = 1;
            break;
        case 2:
            b = get_int(b);
            flagB = 1;
            break;
        case 3:
            if(flagA==1 && flagB==1)
            {
                resultado_Suma=sumar(a,b);
                resultado_Resta=restar(a,b);
                resultado_Multiplicacion=multiplicar(a,b);
                resultado_Division=dividir(a,b);
                resultado_FactorialA=factorial(a);
                resultado_FactorialB=factorial(b);
                flagOperaciones =1;
                printf("Se realizaron las operaciones con exito.\n");
            }
            else
            {
                printf("No se puede realizar operaciones si no ingresa los dos numeros.\n");
            }

            break;
        case 4:
            if(flagA==1 && flagB==1 && flagOperaciones == 1)
            {
                printf("El valor de la suma es: %d\n", resultado_Suma);
                printf("El valor de la resta es: %d\n", resultado_Resta);
                printf("El valor de la multiplicacion es: %d\n", resultado_Multiplicacion);
                if(b == 0)
                {
                    printf("No se puede dividir por 0");
                }
                else
                {
                    printf("El valor de la division es: %.2f\n", resultado_Division);
                }

                if(!factorial(a))
                {
                    printf("No se puede realizar factorial del numero A porque es negativo o mayor a 12 y ");
                }
                else
                {
                    printf("El factorial de A es: %ld y ",resultado_FactorialA);
                }

                if(!factorial(b))
                {
                    printf("No se puede realizar factorial de B porque es negativo o mayor a 12\n");
                }
                else
                {
                    printf("El factorial de B es: %ld\n",resultado_FactorialB);
                }
            }
            else
            {
                printf("No se puede mostar los resultados si no ingresa los dos numeros y ejecuta la opcion realizar operaciones.\n");
            }
            break;
        case 5:
            printf("\nSaliendo del programa\n\n");
            break;
            break;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion != 5);
}
/*---------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------Operaciones-----------------------------------------*/

int sumar(int a, int b)
{
    return a + b;
}

int restar(int a, int b)
{
    return a - b;
}

int multiplicar(int a, int b)
{
    return a * b;
}
float dividir(int a, int b)
{
    return (float)a / b;
}

long int factorial (int numero)
{
    long int resultado;
    resultado = 0;
    if (numero > -1 && numero < 13)
    {
        if (numero == 0)
        {
            resultado = 1;
        }
        else
        {
            resultado= (numero) * (factorial(numero - 1));
        }
    }

    return resultado;
}
/*---------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------Ingreso de datos----------------------------------------------*/
int get_int(int num)
{
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    return num;
}

/*--------------------------------------------------------------------------------------------------------------*/
