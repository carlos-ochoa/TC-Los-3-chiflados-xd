/*Convertidor numero a binario caracter
COMPILACION: g++ decbin-bindec.cpp TADListaDobleLigada.c -o "Nombre del programa" */
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"iostream"
#include"math.h"
//#include"TADLista.h"
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
decbin (int dividendo, /*char binario[18]*/ vector <char> cinta)
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

/*lista *
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

}*/

vector <char>
aumentarCeros(vector <char> cinta, int diferencia){
	vector<char> aux;
	for(int i = 0; i < diferencia; i++){
		aux.push_back('0');
	}
	aux.insert( aux.end(), cinta.begin(), cinta.end() );
	return aux;
}

vector <char>
evaluar(vector <char> c1, vector <char> c2, vector <char> c3){
	int cabezal = c1.size() - 1;
	char aux = '1';
    int estado = 2;
	/*cout << "A EVALUAR"<< endl;
	for(int i = 0; i < cinta1.size(); i++){
		cout << c1.at(i);
	}
	for(int i = 0; i < cinta1.size(); i++){
		cout << c2.at(i);
	}
	cout << "Cinta 3" << endl;
	for(int i = 0; i < cinta1.size(); i++){
		
		cout << c3.at(i);
	}*/
    //switch(estado){
        
        //case 2:
        do{
            
            switch(estado){
                case 2:
                        if(c1.at(cabezal) == '0' && c2.at(cabezal) == '0'){
                            c3.insert(c3.begin(), '0');
                            estado = 2;
                        }
                        else if(c1.at(cabezal) == '0' && c2.at(cabezal) == '1'){
                                c3.insert(c3.begin(), '1');
                                estado = 3;
                        }
                            
                        else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '0'){
                                c3.insert(c3.begin(), '1');
                                estado = 2;
                        }
                            
                        else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '1'){
                                c3.insert(c3.begin(), '0');
                                estado = 2;
                        }
                        cabezal--;
                        break;
                case 3:
                    if(c1.at(cabezal) == '0' && c2.at(cabezal) == '0'){
                                    c3.insert(c3.begin(), '1');
                                    estado = 2;
                    }                          
                    else if(c1.at(cabezal) == '0' && c2.at(cabezal) == '1'){
                                        c3.insert(c3.begin(), '0');
                                        estado = 2;
                    }
                                    
                    else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '0'){
                                        c3.insert(c3.begin(), '0');
                                        estado = 2;
                    }
                                    
                                else if(c1.at(cabezal) == '1' && c2.at(cabezal) == '1'){
                                        c3.insert(c3.begin(), '1');
                                        estado = 3;
                                }
                                cabezal--;
                                break;
                }
        }while(cabezal >= 0);
        
        
                
          //  break;
            
        //case 3:
                
      //      break;
    //}
	
	
	return c3;
}

int
main (void)
{
    int dividendo1 = 0;	//Numero 1 que introduce el usuario
    int dividendo2 = 0;	//Numero 2 que introduce el usuario
    int contador = 0;	//Contador auxiliar
    double decimal1 = 0;	//Decimal transformado del primer binario del usuario
    double decimal2 = 0;	//Decimal transformado del segundo binario del usuario
    //char binario1[18]="";	//Arreglo que guarda el binario del primer numero que da el usuario
    //char binario2[18]="";	//Arreglo que guarda el binario del segundo numero que da el usuario
    //lista cintas[2];	//Arreglo de listas que son las cintas
    
    //elemento auxiliar1;	//Elemento que nos ayuda a introducir caracteres a las cintas
    //elemento auxiliar2;	//Elemento que nos ayuda a introducir caracteres a las cintas

    //for(contador = 0; contador < 2; contador++)
	//Initialize (&cintas[contador]);	//Se inicializa cada cinta
 	double resultado;
    //Recibe los numeros a restar donde siempre numero 1 > numero 2
    printf("Numero 1 = ");
    cin>>dividendo1;
    printf("Numero 2 = ");
    cin>>dividendo2;

    //Transforma los numeros a binario mediante los residuos de las divisiones
    cinta1 = decbin(dividendo1, cinta1);
    cinta2 = decbin(dividendo2, cinta2);
    cout << "CINTAS 1 Y 2" << endl;
    for(int i = 0; i < cinta1.size(); i++){
    	
    	cout << cinta1.at(i);
	}
	cout << "\n";
	
    //Los agregamos a la primera cinta
    //Anadir_cinta(cintas, auxiliar1, binario1, binario2);
    if(cinta1.size() > cinta2.size()){
		cinta2 = aumentarCeros(cinta2, cinta1.size() - cinta2.size());
	}
    for(int i = 0; i < cinta2.size(); i++){
    	cout << cinta2.at(i);
	}
    cout << "\n";
	/*for(int i = 0; i < cinta1.size(); i++){
		cinta3.push_back('0');
		cout << cinta3.at(i);
	}*/
	cout << "\n";
	cinta3 = evaluar(cinta1, cinta2, cinta3);
	cout << "\n";
	for(int i = 0; i < cinta3.size(); i++){
		
		cout << cinta3.at(i);
	}
	cout << "\n";
	resultado = bindec(cinta3);
	cout << "El resultado de la resta es " << resultado << endl;

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
