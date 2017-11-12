#include<iostream>
#include<string>
#include<stack>
#include<stdlib.h>
#include <unistd.h>

using namespace std;
//Función que se encarga de evaluar en nuestra pila la cadena recibida
void evaluar(string cadena){
  int estado = 0; //Variable entera que controla el estado actual del autómata en donde estamos
  int i = 0; //Indice auxiliar para movernos por la cadena
  stack <string> expresion; //Pila en donde almacenaremos el Alfabeto de Pila
    //Siempre colocamos como primer elemento en la pila el Z0
    expresion.push("Z0");
	//Ciclo que iterará en toda la cadena
	  do{
            //Se realiza un switch para ver en qué estado estamos y verificar las reglas en él
	    switch(estado){
	      //Estado cero
	      case 0:
		cout << "\nEstado 0" << endl;
	        //Si tenemos como entrada a y en el tope de Pila Z0 entonces
		if(cadena.at(i) == 'a' && expresion.top() == "Z0"){
		  //Nos movemos al estado uno y metemos A en la pila
		  estado = 1;
		  cout << "Z0a|Z0A" << endl;
		  expresion.push("A");
		}
		//Si tenemos como entrada b y en el tope de Pila Z0 entonces
		else if(cadena.at(i) == 'b' && expresion.top() == "Z0"){
		  //Nos movemos al estado uno y metemos B en la pila
		  estado = 1;
		  cout << "Z0b|Z0B" << endl;
		  expresion.push("B"); 
		}
		else{
		  //Si no es ninguna regla pues cortamos el ciclo e indicamos que hubo error
		  cout << "No se contempla esta regla en el estado actual" << endl;
		  i = cadena.length();
		}
		break;
	      case 1:
		cout << "\nEstado 1" << endl;
		//Reglas encontradas en el estado uno
		//Si tenemos como entrada a y en el tope de Pila A entonces
		if(cadena.at(i) == 'a' && expresion.top() == "A"){
		  //Nos movemos al estado uno y metemos A en la pila
		  estado = 1;
		  cout << "Aa|AA" << endl;
		  expresion.push("A");
		}
		//Si tenemos como entrada b y en el tope de Pila B entonces
		else if(cadena.at(i) == 'b' && expresion.top() == "B"){
		  //Nos movemos al estado uno y metemos B en la pila
		  estado = 1;
		  cout << "Bb|BB" << endl;
		  expresion.push("B");
		}
		//Si tenemos como entrada a y en el tope de Pila B entonces
		else if(cadena.at(i) == 'a' && expresion.top() == "B"){
		  //Nos movemos al estado uno y sacamos el top en la pila
		  estado = 1;
		  cout << "Ba|ε" << endl;
		  expresion.pop();
		}
		//Si tenemos como entrada b y en el tope de Pila A entonces
		else if(cadena.at(i) == 'b' && expresion.top() == "A"){
		  //Nos movemos al estado uno y sacamos el top en la pila
		  estado = 1;
		  cout << "Ab|ε" << endl;
		  expresion.pop();
		} else {
		  //Si no es ninguna regla pues cortamos el ciclo e indicamos que hubo error
		  cout << "No se contempla esta regla en el estado actual" << endl;
		  i = cadena.length();
		}
		break;
	    }
	    i++;
	  }while(i < cadena.length());
	  //Si llegamos al final de cadena y en el top tenemos a Z0 llegamos al estado final
	  if(i == cadena.length() && expresion.top() == "Z0")
	    estado = 0;
	  //Si llegamos al estado final exitosamente entonces la cadena es válida
	  if(expresion.top() == "Z0" && estado == 0){
	    cout << "\nLa expresión dada es válida en este lenguaje\n" << endl;
          }
	  //Si no indicamos qué tenemos en el tope de la pila
	  else{
	    cout << "\nLa expresión no es válida" << endl;
	    cout << "Lo que se quedó en el tope de la pila es " << expresion.top() << endl;
	  }
	  //Borramos todo lo que quede en la pila al final
          while(!expresion.empty())
            expresion.pop();
      return;
}

int main(void){
  string cadena; //Cadena que evaluaremos
  bool continuar = true; //Booleano que nos permite repetir tantas veces se quiera el proceso
  while(continuar){
    cout << "\nEscriba por favor la cadena a evaluar" << endl;
    cout << "Si desea salir presione cero" << endl;
    cin >> cadena;
    //Si la cadena no es cero entonces la enviamos a Evaluación
    if(cadena.at(0) == '0')
      break;
    else
      evaluar(cadena);
    //Pausa de 3 segundos luego de mostrar resultados y limpiamos pantalla
    usleep(3000000);
    system("clear");
  }
  return 0;
}
