#include "Validate.h"

int Validate_String(char string[])
{
    int i=0;
    int retorno=1;
    while(string[i]!='\0')
    {
        if((string[i]!=' ') && (string[i]<'a' || string[i]>'z') && (string[i]<'A' || string[i]>'Z'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}

int Validate_Integer(char string[])
{
    int i=0;
    int retorno=1;
    while(string[i]!='\0')
    {
        if((string[0]=='\n' || string[i]==' ' )&& (string[i]<'0' || string[i]>'9'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}

int Validate_IntID(char string[])
{
    int i=0;
    int retorno=1;
    while(string[i]!='\0')
    {
        if((string[0]=='\n' || string[i]==' ' )&& (string[i]<'0' || string[i]>'9'))
        {
            retorno=0;
        }
        i++;
    }
    return retorno;
}
