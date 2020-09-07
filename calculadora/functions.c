#include "functions.h"

void menu(float a, float b)
{
    printf("\n\nBIENVENIDO AL MENU DE OPCIONES \n");
	printf("  Seleccione una opcion  \n");
	printf("1) Ingresar 1er valor (A= %.2f ) \n", a);
	printf("2) Ingresar 2do valor (B= %.2f ) \n", b);
	printf("3) Calcular todas las operaciones. \n");
	printf("        a) Calcular la suma de: (A= %.2f ) + (B= %.2f) \n", a, b);
	printf("        b) Calcular la resta de: (A= %.2f ) - (B= %.2f) \n", a, b);
	printf("        c) Calcular la division de: (A= %.2f ) / (B= %.2f) \n", a, b);
	printf("        d) Calcular la multiplicacion de: (A= %.2f ) * (B= %.2f) \n", a, b);
	printf("        e) Calcular el factorial de: (A!= %.2f) \n", a);
	printf("        f) Calcular el factorial de: (B!= %.2f) \n", b);
	printf("4) Informar resultados \n");
	printf("5) Salir\n\n");
}

void eleccion(float a, float b)
{
    int opcion;
    float resultado_Suma;
    float resultado_Resta;
    float resultado_Multiplicacion;
    float resultado_Division;
    int resultado_FactorialA;
    int resultado_FactorialB;

    do{
    menu(a,b);
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
    printf("Ingrese el valor de a: ");
    scanf("%f", &a);
    break;
    case 2:
    printf("Ingrese el valor de b: ");
    scanf("%f", &b);
    break;
    case 3:
        resultado_Suma=sumar(a,b);
        resultado_Resta=restar(a,b);
        resultado_Multiplicacion=multiplicar(a,b);
        resultado_Division=dividir(a,b);
        resultado_FactorialA=factorial(a);
        resultado_FactorialB=factorial(b);
    break;
    case 4:
        printf("El valor de la suma es: %f\n", resultado_Suma);
        printf("El valor de la resta es: %f\n", resultado_Resta);
        printf("El valor de la multiplicacion es: %f\n", resultado_Multiplicacion);
        printf("El valor de la division es: %f\n", resultado_Division);
        if(!factorial(a))
        {
        printf("No se puede realizar factorial de numeros negativos o con coma\n");
        }else
        {
        printf("El factorial de A es: %d\n",resultado_FactorialA);
        }
        if(!factorial(b))
        {
        printf("No se puede realizar factorial de numeros negativos o con coma\n");
        }else{
        printf("El factorial de B es: %d\n",resultado_FactorialB);
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


float sumar(float a, float b)
{
    return a + b;
}

float restar(float a, float b)
{
    return a - b;
}

float multiplicar(float a, float b)
{
    return a * b;
}
float dividir(float a, float b)
{
    return a / b;
}

int factorial (float numero)
{
  int validacion;
  int resultado;
  validacion = numero - (int)numero;
  if (validacion == 0 && numero>=0)
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
