#include "functions.h"

/*------------------------------------------------Menu-------------------------------------------------------------------------*/

void menu(int a, int b, int flagA, int flagB)
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
    int resultado_Suma;
    int resultado_Resta;
    int resultado_Multiplicacion;
    float resultado_Division;
    long long int resultado_FactorialA;
    long long int resultado_FactorialB;

    do{
    menu(a,b, flagA, flagB);
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
        resultado_Suma=sumar(a,b);
        resultado_Resta=restar(a,b);
        resultado_Multiplicacion=multiplicar(a,b);
        resultado_Division=dividir(a,b);
        resultado_FactorialA=factorial(a);
        resultado_FactorialB=factorial(b);
        printf("Se realizaron las operaciones con exito.\n");
    break;
    case 4:
        printf("El valor de la suma es: %d\n", resultado_Suma);
        printf("El valor de la resta es: %d\n", resultado_Resta);
        printf("El valor de la multiplicacion es: %d\n", resultado_Multiplicacion);
        if(b == 0)
        {
            printf("No se puede dividir por 0");
        }else{
            printf("El valor de la division es: %.2f\n", resultado_Division);
        }

        if(!factorial(a))
        {
        printf("No se puede realizar factorial del numero A porque es negativo o mayor a 15 y ");
        }else
        {
        printf("El factorial de A es: %lld y ",resultado_FactorialA);
        }

        if(!factorial(b))
        {
        printf("No se puede realizar factorial de B porque es negativo o mayor a 15\n");
        }else{
        printf("El factorial de B es: %lld\n",resultado_FactorialB);
        }
    break;
    case 5:
    break;
    default:
    break;
    }
    system("pause");
    system("cls");
    }while(opcion != 5);
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

long long int factorial (int numero)
{
  long long int resultado;
  if (numero > -1 && numero < 16)
    {
        if (numero == 0)
    	{
    		resultado = 1;
    	}else{
    		resultado= (numero) * (factorial(numero - 1));
    	}
    	return resultado;
    }
  else
    {
      return 0;
    }
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
