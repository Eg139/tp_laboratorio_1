#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"
#include <ctype.h>
#include "Validate.h"
void GetString(char message[],char input[],int len)
{
    printf("%s",message);
    fflush(stdin);
    gets(input);
    while(Validate_String(input)!=1 || input[0]=='\0' || input[0]==' ' || (strlen(input)<3))
    {
        printf("Ingresa un dato valido: ");
        fflush(stdin);
        gets(input);
    }
    input[0]=toupper(input[0]);
    for(int i=1; i< input[i]; i++){
        if (input[i-1] == ' ')
        {
            input[i]=toupper(input[i]);
        }
        else
        {
            input[i]=tolower(input[i]);
        }
    }
}

int GetOption(char message[])
{
    int num;
    char auxNum[11];
    printf("%s",message);
    fflush(stdin);
    gets(auxNum);
    while(Validate_Integer(auxNum)!=1 || auxNum[0]=='\0')
    {
        printf("Ingresa una opcion valida: ");
        fflush(stdin);
        gets(auxNum);
    }
    num=atoi(auxNum);
    return num;
}

int GetInt(char message[])
{
    int num;
    printf("%s",message);
    scanf("%d", &num);
    while(num > 1001 || num < 0)
    {
    printf("%s",message);
    scanf("%d", &num);
    }
    return num;
}

float GetFloat(char message[])
{
    float salary;
    printf("%s",message);
    scanf("%f",&salary);
    while(salary < 0)
        {
            printf("%s",message);
            scanf("%f",&salary);
        }
    return salary;
}

char GetChar(char message[])
{
    char letter;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&letter);
    while((letter<'a' || letter>'z') && (letter<'A' || letter>'Z'))
    {
        printf("Ingresa un caracter valido: ");
        fflush(stdin);
        scanf("%c",&letter);
    }
    return letter;
}
