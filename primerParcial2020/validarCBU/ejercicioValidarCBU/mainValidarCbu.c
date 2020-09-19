#include"my.h"
    
    
int cbu_validar ( char *dataPtr)
{
    char longitud,error=0;
    int R0,R1,D0,D1,i;
    
    longitud = strlen(dataPtr);
    if(longitud != 22)
    {
        error = -1;
    }

    for(i=0 ; *(dataPtr+i) != '\0' ; i++)
    {
        if( *(dataPtr+i)<='0' && *(dataPtr+i)>='9')
        {
            error=-2;
        }
    }
    

    R0=(*(dataPtr+0)-'0')*7 + (*(dataPtr+1)-'0')*1 + (*(dataPtr+2)-'0')*3 + (*(dataPtr+3)-'0')*9 + (*(dataPtr+4)-'0')*7 + (*(dataPtr+5)-'0')*1 + (*(dataPtr+6)-'0')*3;
    D0= 10-(R0 % 10);
    
    if(D0 != (*(dataPtr+7)-'0'))
    {
        error=-3;
    }
    
    R1=(*(dataPtr+8)-'0')*3 + (*(dataPtr+9)-'0')*9 + (*(dataPtr+10)-'0')*7 + (*(dataPtr+11)-'0')*1 + (*(dataPtr+12)-'0')*3 + (*(dataPtr+13)-'0')*9 + (*(dataPtr+14)-'0')*7 + (*(dataPtr+15)-'0')*1 + (*(dataPtr+16)-'0')*3 + (*(dataPtr+17)-'0')*9 + (*(dataPtr+18)-'0')*7 + (*(dataPtr+19)-'0')*1 + (*(dataPtr+20)-'0')*3;

    D1= 10-(R1 % 10);

    if(D1 != (*(dataPtr+21)-'0'))
    {
        error=-4;
    }
    
    
    return error;
}
    
