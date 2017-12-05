/*Convertidor numero a binario caracter
COMPILACION: g++ decbin-bindec.cpp TADListaDobleLigada.c -o "Nombre del programa" */
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"iostream"
#include"math.h"
#include"TADLista.h"

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

lista *
Anadir_cinta(lista cintas[2], elemento auxiliar1, char binario1[18], char binario2[18])
{
    int contador = 0;
    for(contador = 0; contador < strlen(binario1); contador++)	//for para el primer numero
    {
	auxiliar1.c = binario1[contador];	//Ponemos el caracter que queremos poner en la cinta en un elemento
	Add (&cintas[0], auxiliar1);	//Lo añadimos a la cinta
	//cout<<auxiliar1.c<<endl;
    }
    auxiliar1.c='B';	//Espacio en blanco
    Add (&cintas[0], auxiliar1);	//Lo añadimos a la cinta
    for(contador = 0; contador < strlen(binario2); contador++)	//for para el segundo numero
    {
	auxiliar1.c = binario2[contador];	//Ponemos el caracter que queremos poner en la cinta en un elemento
	Add (&cintas[0], auxiliar1);	//Lo añadimos a la cinta
	//cout<<auxiliar1.c<<endl;
    }
    for(contador = 0; contador < 25; contador++)	//for para la segunda cinta que tiene el resultado
    {//Por ahorita puse B para solo crear los espacios, puede ser cualquier letra
	auxiliar2.c = B;	//Ponemos el caracter que queremos poner en la cinta en un elemento
	Add (&cintas[1], auxiliar1);	//Lo añadimos a la cinta 2
	//cout<<auxiliar1.c<<endl;
    }
    return cintas;

}

int
main (void)
{
    int dividendo1 = 0;	//Numero 1 que introduce el usuario
    int dividendo2 = 0;	//Numero 2 que introduce el usuario
    int contador = 0;	//Contador auxiliar
    double decimal1 = 0;	//Decimal transformado del primer binario del usuario
    double decimal2 = 0;	//Decimal transformado del segundo binario del usuario
    char binario1[18]="";	//Arreglo que guarda el binario del primer numero que da el usuario
    char binario2[18]="";	//Arreglo que guarda el binario del segundo numero que da el usuario
    lista cintas[2];	//Arreglo de listas que son las cintas
    elemento auxiliar1;	//Elemento que nos ayuda a introducir caracteres a las cintas
    elemento auxiliar2;	//Elemento que nos ayuda a introducir caracteres a las cintas

    for(contador = 0; contador < 2; contador++)
	Initialize (&cintas[contador]);	//Se inicializa cada cinta
 
    //Recibe los numeros a restar donde siempre numero 1 > numero 2
    printf("Numero 1 = ");
    cin>>dividendo1;
    printf("Numero 2 = ");
    cin>>dividendo2;

    //Transforma los numeros a binario mediante los residuos de las divisiones
    decbin(dividendo1, binario1);
    decbin(dividendo2, binario2);
    //Los agregamos a la primera cinta
    Anadir_cinta(cintas, auxiliar1, binario1, binario2);


/*
//Codigo para probar el correcto funcionamiento de que se agregan correctamente los numeros a la cinta
cout<<"Binario "<<binario1<<endl;
cout<<"Binario "<<binario2<<endl;
cout<<"Binario de la lista ";
for(contador = 1; contador < strlen(binario1)+strlen(binario2)+2; contador++)
{
auxiliar1= Element(&cintas[0], contador);
cout<<auxiliar1.c;
}
decimal1 = bindec(binario1);
decimal2 = bindec(binario2);
cout<<binario1<<endl;
cout<<decimal1<<endl;
cout<<binario2<<endl;
cout<<decimal2<<endl;*/

    getchar();
    
    return 0;
}
  
