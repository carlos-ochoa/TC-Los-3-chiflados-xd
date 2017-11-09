https://codeshare.io/5oLz0M


#include<iostream>
#include<string>
#include"TADPilaDin.h"

using namespace std;

int main(void){
  string cadena;
  elemento tope;
  elemento alf_pila;
  pila expresion;
  Initialize(&expresion);
  cout << "Escriba por favor la cadena a evaluar" << endl;
  cin >> cadena;
  for(int i = 0; i < cadena.length() ; i++){
    if(cadena.at(i) == "a" && Top(&expresion).c == "Z0"){
      alf_pila.s = "A";
      Push(&expresion, alf_pila);
    }
    else if(cadena.at(i) == "b" && Top(&expresion).c == "Z0"){
      alf_pila.s = "B";
   		Push(&expresion, alf_pila); 
    }
    else if(cadena.at(i) == "a" && Top(&expresion).c == "A"){
      alf_pila.s = "A";
   		Push(&expresion, alf_pila);
    }
    else if(cadena.at(i) == "b" && Top(&expresion).c == "B"){
      alf_pila.s = "B";
   		Push(&expresion, alf_pila);
    }
    else if(cadena.at(i) == "a" && Top(&expresion).c == "B"){
           Pop(&expresion);
    }
    else if(cadena.at(i) == "b" && Top(&expresion).c == "A"){
           Pop(&expresion);
    }
    else {
      
      cout << "La cadena no es válida en este lenguaje" << endl;
      break;
    }
  }
	  return 0;
}
