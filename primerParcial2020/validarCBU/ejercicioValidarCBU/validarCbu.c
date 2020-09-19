#include"my.h"

// el CBU de prueba es el que paso carlos a lo ultimo de todos
// 2990077207711695570011

int main (void)
{
    
    char claveUnica[TAM];
    int valido;
    
    printf("ingrese CBU a validar\n");
    scanf("%s",claveUnica);
    valido = cbu_validar (claveUnica);

    switch (valido)
    {
        case -1:
            printf("no ingreso los 22 caracteres\n");
            break;
        case -2:
            printf("tienen que ser todos números\n");
            break;
        case -3:
            printf("no verifica D0\n");
            break;
        case -4:
            printf("no verifica D1\n");
            break;
        case 0:
            printf("el CBU ingresado es %s\n",claveUnica);
            break;
        default :
            break;
    }
    
}

