#include<iostream>
#include<string>
#include<stack>
#include<stdlib.h>
#include <unistd.h>
#include"TADPilaDin.h"

using namespace std;

void evaluar(string cadena){
  int estado = 0;
  int i = 0;
  stack <string> expresion;
    expresion.push("Z0");
    cout << expresion.top() << endl;
	  do{
	    switch(estado){
	      case 0:
		cout << "\nEstado 0" << endl;
		if(cadena.at(i) == 'a' && expresion.top() == "Z0"){
		  estado = 1;
		  cout << "Z0a|Z0A" << endl;
		  expresion.push("A");
		}
		else if(cadena.at(i) == 'b' && expresion.top() == "Z0"){
		  estado = 1;
		  cout << "Z0b|Z0B" << endl;
		  expresion.push("B"); 
		}
		else{
		  cout << "No se contempla esta regla en el estado actual" << endl;
		  i = cadena.length();
		}
		break;
	      case 1:
		cout << "\nEstado 1" << endl;
		//Reglas encontradas en el estado uno
		if(cadena.at(i) == 'a' && expresion.top() == "A"){
		  estado = 1;
		  cout << "Aa|AA" << endl;
		  expresion.push("A");
		}
		else if(cadena.at(i) == 'b' && expresion.top() == "B"){
		  estado = 1;
		  cout << "Bb|BB" << endl;
		  expresion.push("B");
		}
		else if(cadena.at(i) == 'a' && expresion.top() == "B"){
		  estado = 1;
		  cout << "Ba|ε" << endl;
		  expresion.pop();
		}
		else if(cadena.at(i) == 'b' && expresion.top() == "A"){
		  estado = 1;
		  cout << "Ab|ε" << endl;
		  expresion.pop();
		} else {
		  cout << "No se contempla esta regla en el estado actual" << endl;
		  i = cadena.length();
		}
		break;
	    }
	    i++;
	  }while(i < cadena.length());
	  if(i == cadena.length() && expresion.top() == "Z0")
	    estado = 0;
	  if(expresion.top() == "Z0" && estado == 0){
	    cout << "\nLa expresión dada es válida en este lenguaje\n" << endl;
          }
	  else{
	    cout << "\nLa expresión no es válida" << endl;
	    cout << "Lo que se quedó en el tope de la pila es " << expresion.top() << endl;
	  }
          while(!expresion.empty())
            expresion.pop();
      return;
}

int main(void){
  string cadena;
  bool continuar = true;
  while(continuar){
    cout << "\nEscriba por favor la cadena a evaluar" << endl;
    cout << "Si desea salir presione cero" << endl;
    cin >> cadena;
    if(cadena.at(0) == '0')
      break;
    else
      evaluar(cadena);
    usleep(3000000);
    system("clear");
  }
  return 0;
}
