//Conversion a decimal
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Para regresar el valor de un char.
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

//Funcion para convertir a decimal
int ConvDec(char *str, int baseA)
{
    int longitudA = strlen(str);
    int potencia = 1; //Iniciar la potencia para la base
    int numA = 0;  // iniciar el resultado
    int i;

    // Decimal equivalente
    for (i = longitudA - 1; i >= 0; i--)
    {
        // Los digitos de la entrada deben ser menores a la base
        if (val(str[i]) >= baseA)
        {
           printf("NUMERO INVALIDO, NO ES POSIBLE HACER EL CALCULO\n");
           exit(-1);
        }

        numA += val(str[i]) * potencia;
        potencia = potencia * baseA;
    }

    return numA;
}

// Ejecutable
int main()
{
    char str[10];
    int baseA;
    printf("Escribe el numero a convertir:\n");
    scanf("%s",&str);
    printf("Escribe la base del numero:\n");
    scanf("%d",&baseA);


// Convercion de decimal a otra base

// Para regresar un valor tipo char
char regreso(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Funcion para invertir una cadena (string)
void inversa(char *entrada)
{
    int longitudB = strlen(entrada);
    int k;
    for (k = 0; k < longitudB/2; k++)
    {
        char temp = entrada[k];
        entrada[k] = entrada[longitudB-k-1];
        entrada[longitudB-k-1] = temp;
    }
}

//Funcion para convertir a la base declarada
char* DecConv(char res[], int baseB, int entrada)
{
    // Iniciar el indice del resultado
    int indice = 0;

    // Para convertir el numero de entrada se divide por la
    //base repetidamente y tomando el residuo

    while (entrada > 0)
    {
        res[indice++] = regreso(entrada % baseB);
        entrada /= baseB;
    }
    res[indice] = '\0';

    //Invertir el resultado
    inversa(res);

    return res;
}
    int entrada = ConvDec(str, baseA);
    int baseB;
    printf("Escribe a la base final:\n");
    scanf("%d",&baseB);
    char res[100];
    printf("El equivalente de %s en base %d a base %d es: "
           " %s\n", str, baseA, baseB, DecConv(res, baseB, entrada));
    return 0;
}
