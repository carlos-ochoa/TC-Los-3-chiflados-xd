/*
AUTORES: 
Mendez Alvarez Jorge Luis
Ochoa Ginera Carlos Armando
Rodriguez Casas Erik Emmanuel. 
Fecha: Diciembre 04, 2017
VERSIÓN: 2.0

DESCRIPCIÓN: Programa que simula una maquina de Turing la cual se
encarga de restar numeros binarios, usa 3 cintas, 2 para los numeros
del usuario y la tercera para el resultado.
	
OBSERVACIONES: La entrada de estos es en decimal para la facilidad 
del usuario y el resultado esta dado en binario y decimal. El numero
limite es 131071 y obligatoriamente el primer numero debe ser mayor 
al segundo
*/
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"iostream"
#include"math.h"
#include"conio.h"
#include <vector>

using namespace std;

vector <char> cinta1;
    vector <char> cinta2;
    vector <char> cinta3;

double
bindec(vector <char> c)
{
    double resultado = 0;
    int contador = 0;
    int largo = c.size();
    for(contador = 0; contador<largo; contador++)
    {
        if(c.at(contador) == '1')
        {
            resultado = pow(2,(largo-contador-1))+resultado;
        }             
    }

    return resultado;                     
}


vector <char>
decbin (int dividendo, vector <char> cinta)
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
         cinta.push_back(resultado[largo-contador-1]);    
         //cout << cinta.at(contador);
     }
     return cinta;
}

vector <char>
aumentarCeros(vector <char> cinta, int diferencia){
	vector<char> aux;
	for(int i = 0; i < diferencia; i++){
		aux.push_back('0');
	}
	aux.insert( aux.end(), cinta.begin(), cinta.end() );
	return aux;
}

/*
Funcion que evalua el automata, manda como resultado la cinta con el resultado de la maquina.
Recibe las 3 cintas para realizar el algoritmo de la maquina.
*/
vector <char>
evaluar(vector <char> c1, vector <char> c2, vector <char> c3){
	int cabezal = c1.size() - 1;	//Colocamos el cabezal en la cinta.
	int acarreo = 0;	//Entero que se usa para tener encuenta el acarreo de las restas y evitar resultados raros
	char aux = '1';		//Caracter auxiliar para los vectores
    	int estado = 2;		//Entero que marca donde estamos dentro del automata
        do{
            //Case 2 sirve para el estado donde hace la resta y el acarreo es cero
            switch(estado){
                case 2:	//Resta de 0-0, se queda en el estado 2 ya que no se genera acarreos
                        if(c1.at(cabezal) == '0' && c2.at(cabezal) == '0' && acarreo == 0){
                            c3.insert(c3.begin(), '0');	//Inserta al principio de la cinta 3 el resultado de la resta
                            estado = 2;	//Y seguimos en el estado 2.
                            acarreo = 0;
                        }//Resta de 0-1, aqui se genera un acarreo y se va al estado 3
                        else if(c1.at(cabezal) == '0' && c2.at(cabezal) == '1' && acarreo == 0){
                                c3.insert(c3.begin(), '1');	//Inserta al principio de la cinta 3 el resultado de la resta
                                acarreo = 1;
                                estado = 3;	//Nos movemos al estado 3
                        }//Resta de 1-0, se queda en el estado 2 ya que no se generan acarreos
                        else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '0' && acarreo == 0){
                                c3.insert(c3.begin(), '1');	//Inserta al principio de la cinta 3 el resultado de la resta
                                estado = 2;	//Y seguimos en el estado 2.
                                acarreo = 0;
                        }//Resta de 1-1, se queda en el estado 2 ya que no se generan acarreos
                        else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '1' && acarreo == 0){
                                c3.insert(c3.begin(), '0');	//Inserta al principio de la cinta 3 el resultado de la resta
                                estado = 2;	//Y seguimos en el estado 2.
                                acarreo = 0;
                        }//En caso de que sea 0-0 con un acarreo nos trasladamos al estado 3
                        else if(c1.at(cabezal) == '0' && c2.at(cabezal) == '0' && acarreo == 1){
                            cabezal++;
                            estado = 3;
                        }//En caso de que sea 0-1 con un acarreo nos trasladamos al estado 3
                        else if(c1.at(cabezal) == '0' && c2.at(cabezal) == '1' && acarreo == 1){
                                cabezal++;
                                estado = 3;
                        }//En caso de que sea 1-0 con un acarreo nos trasladamos al estado 3  
                        else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '0' && acarreo == 1){
                                cabezal++;
                                estado = 3;
                        }//En caso de que sea 1-1 con un acarreo nos trasladamos al estado 3
                        else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '1' && acarreo == 1){
                                cabezal++;
                                estado = 3;
                        }
                cabezal--;	//Movemos el cabezal de lugar para continuar con la siguiente resta
                break;	//En el case 3 se realizan las restas con acarreo
                case 3://Resta de 0-0 sin acarreo, aqui se genera uno y se va al estado 2
                    }//Resta de 0-0 con acarreo, aqui se genera uno y se va al estado 2
                    if(c1.at(cabezal) == '0' && c2.at(cabezal) == '0'){
                                    c3.insert(c3.begin(), '1');
                                    estado = 2;
                                    acarreo = 1;
                    }//Resta de 0-1 con acarreo, aqui se genera uno y se va al estado 2                          
                    else if(c1.at(cabezal) == '0' && c2.at(cabezal) == '1'){
                                        c3.insert(c3.begin(), '0');
                                        estado = 2;
                                        acarreo = 1;
                    }//Resta de 1-0 con acarreo, aqui se genera uno y se va al estado 2                                    
                    else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '0'){
                                        c3.insert(c3.begin(), '0');
                                        estado = 2;
                                        acarreo = 0;
                    }//Resta de 1-1 con acarreo, aqui se genera uno y se va al estado 2                                 
                    else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '1'){
                                      c3.insert(c3.begin(), '1');
                                      estado = 2;
                                      acarreo = 1;
                    }
                    cabezal--;	//Movemos el cabezal de lugar para continuar con la resta
                    break;
                }
        }while(cabezal >= 0);    //Si no se llega al final de la resta continua el algoritmo del automata    
	return c3;	//Regresa la cinta con el resultado.
}

int
main (void)
{
    int dividendo1 = 0;	//Numero 1 que introduce el usuario
    int dividendo2 = 0;	//Numero 2 que introduce el usuario
    int contador = 0;	//Contador auxiliar
    double decimal1 = 0;	//Decimal transformado del primer binario del usuario
    double decimal2 = 0;	//Decimal transformado del segundo binario del usuario
 	double resultado = 0;
 	
    //Recibe los numeros a restar donde siempre numero 1 > numero 2
    printf("Numero 1 = ");
    cin>>dividendo1;
    printf("Numero 2 = ");
    cin>>dividendo2;

    //Transforma los numeros a binario mediante los residuos de las divisiones
    cinta1 = decbin(dividendo1, cinta1);
    cinta2 = decbin(dividendo2, cinta2);
    cout << "CINTAS 1 Y 2" << endl;	//Imprimimos en binario la cinta 1 introducida por el usuario. 
    for(int i = 0; i < cinta1.size(); i++){
    	cout << cinta1.at(i);
	}
	cout << "\n";
    /*En caso de que la cinta 1 sea mayor a la cinta 2, la rellenamos de 
    ceros al principio para evitar conflictos en la evaluacion en el automata.
    Es decir, si cinta 1 es 1001 y cinta 2 es 101, cinta 2 sera 0101 para
    que sean del mismo tamaño y no afecte su funcionamiento.*/
    if(cinta1.size() > cinta2.size()){
		cinta2 = aumentarCeros(cinta2, cinta1.size() - cinta2.size());
	}
    for(int i = 0; i < cinta2.size(); i++){ //Imprimimos en binario la cinta 2 modificada introducida por el usuario.
    	cout << cinta2.at(i);
	}
	cout << "\n";
	cinta3 = evaluar(cinta1, cinta2, cinta3);	//Empezamos la evaluacion de la resta.
	cout << "\n";
	for(int i = 0; i < cinta3.size(); i++){	//Se imprime el resultado en binario
		cout << cinta3.at(i);
	}
	cout << "\n";
	resultado = bindec(cinta3);	//Se transforma el resultado en decimal
	cout << "El resultado de la resta es " << resultado << endl;	//Se imprime el resultado en decimal
    getch();
    
    return 0;
}
