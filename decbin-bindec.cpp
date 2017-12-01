//Convertidor numero a binario caracter
#include"stdio.h"
#include"conio.h"
#include"string.h"
#include"stdlib.h"
#include"iostream"
#include"math.h"

using namespace std;

double
bindec(char binario[18])
{
    double resultado = 0;
    int contador = 0;
    int largo = strlen(binario);
    for(contador = 0; contador<largo; contador++)
    {
        if(binario[contador]== '1')
        {
            resultado = pow(2,(largo-contador-1))+resultado;
        }             
    }

    return resultado;                     
}


char *
decbin (int dividendo, char binario[18])
{
     int divisor = 2;
     int cociente = 0;
     int residuo = 0;
     int contador = 0;
     int largo = 0;
     char resultado[18] = "1";

     while(dividendo>1)
     {
         cociente = dividendo/divisor;
         residuo = dividendo%divisor;
         if(residuo == 1)
         {
              resultado[contador]='1';
              contador++;    
         }
         else if(residuo == 0)
         {
             resultado[contador]='0';
             contador++;  
         }
         dividendo = cociente;             
     }
     if(dividendo == 1)
     {
         resultado[contador]='1';
         contador++;  
     }
     else if(dividendo == 0)
     {
         resultado[contador]='0';
         contador++;  
     }
     largo = strlen(resultado);
     for(contador = 0; contador<largo;contador++)
     {
         binario[contador]=resultado[largo-contador-1];    
     }
     return binario;
}

int
main (void)
{
    int dividendo = 0;
    double decimal = 0;
    char binario[18]="";
    printf("Numero= ");
    cin>>dividendo;
    
    decbin(dividendo, binario);
    decimal = bindec(binario);
    cout<<binario<<endl;
    cout<<decimal<<endl;
    getch();
    
    return 0;
}
     
