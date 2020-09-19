#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 30

int rot_13(char* , char *);        

int main(void)
{
    char dataPtr[TAM], *dataPtrCodificada;        
    int devuelve,longitud,i;

    printf("Ingrese texto a codificar\n");
    fgets(dataPtr,TAM,stdin);
// longitud cuenta el valor del 0x0A y me da la longitud como si fuese un string con el null    
    for (i=0;dataPtr[i]!='\0';i++){     // busco el valor de i donde esta el null
    }
    dataPtr[i-1]='\0';                  // elimino el 0x0A (line fine) poniendo el null
    longitud = strlen(dataPtr);         

// reservo espacio para guardar el dato codificado    
    dataPtrCodificada = (char *) malloc ( (longitud+1) * sizeof(char)); 

    devuelve = rot_13(dataPtr , dataPtrCodificada);         
    if (devuelve == -1){
        printf("el mensaje contiene un caracter distinto de una letra o un espacio\n");
    }else{
        printf("el mensaje %s fue codificado a %s\n",dataPtr, dataPtrCodificada);
        printf("la cantidad intercambiada fue de: %d\r\n",devuelve);
    }
    free(dataPtrCodificada);
    return (0);
}


int rot_13(char *dataPtr , char *dataPtrCodificada)
{
    int i,flag=0;        
    int contador=0;

    while (*(dataPtr+i) != '\0') {        
        if ( ((*(dataPtr+i) >= 'A' && *(dataPtr+i) < 'N')) || ((*(dataPtr+i) >= 'a' && *(dataPtr+i) < 'n')) ) {                
            *(dataPtrCodificada+i) = *(dataPtr+i) + 13;               
            contador++;
        } else if(((*(dataPtr+i)>='N' && *(dataPtr+i)<='Z')) || ((*(dataPtr+i)>='n' && *(dataPtr+i) <= 'z'))){
            *(dataPtrCodificada+i) = *(dataPtr+i) - 13;               
            contador++;
        } else if(*(dataPtr+i)==' '){
            *(dataPtrCodificada+i)=' ';
        }else{
            flag=-1;
        }
        i++;        
    }
    *(dataPtrCodificada+i)='\0';
    if (flag == -1){
        contador = flag;
    }
    return(contador);
}