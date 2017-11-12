#include<iostream>
#include<string>
#include"TADPilaDin.h"

using namespace std;

int main(void){
  string cadena;
  int estado;
  int i;
  bool continuar = true;
  elemento alf_pila;
  pila expresion;
  while(continuar){
    Initialize(&expresion);
    i = 0;
    estado = 0;
    cout << "\nEscriba por favor la cadena a evaluar" << endl;
    cout << "Si desea salir presione cero" << endl;
    cin >> cadena;
    if(cadena.at(i) == '0')
      break;
	  do{
	    switch(estado){
	      case 0:
		cout << "\nEstado 0" << endl;
		if(cadena.at(i) == 'a' && Top(&expresion).c == "Z0"){
		  estado = 1;
		  alf_pila.c = "A";
		  cout << "Z0a|Z0A" << endl;
		  Push(&expresion, alf_pila);
		}
		else if(cadena.at(i) == 'b' && Top(&expresion).c == "Z0"){
		  estado = 1;
		  alf_pila.c = "B";
		  cout << "Z0b|Z0B" << endl;
		  Push(&expresion, alf_pila); 
		}
		else{
		  cout << "No se contempla esta regla en el estado actual" << endl;
		  i = cadena.length();
		}
		break;
	      case 1:
		cout << "\nEstado 1" << endl;
		//Reglas encontradas en el estado uno
		if(cadena.at(i) == 'a' && Top(&expresion).c == "A"){
		  estado = 1;
		  alf_pila.c = "A";
		  cout << "Aa|AA" << endl;
		  Push(&expresion, alf_pila);
		}
		else if(cadena.at(i) == 'b' && Top(&expresion).c == "B"){
		  estado = 1;
		  alf_pila.c = "B";
		  cout << "Bb|BB" << endl;
		  Push(&expresion, alf_pila);
		}
		else if(cadena.at(i) == 'a' && Top(&expresion).c == "B"){
		  estado = 1;
		  cout << "Ba|ε" << endl;
		  Pop(&expresion);
		}
		else if(cadena.at(i) == 'b' && Top(&expresion).c == "A"){
		  estado = 1;
		  cout << "Ab|ε" << endl;
		  Pop(&expresion);
		} else {
		  cout << "No se contempla esta regla en el estado actual" << endl;
		  i = cadena.length();
		}
		break;
	    }
	    i++;
	  }while(i < cadena.length());
	  if(i == cadena.length() && Top(&expresion).c == "Z0")
	    estado = 0;
	  if(Top(&expresion).c == "Z0" && estado == 0){
	    cout << "\nLa expresión dada es válida en este lenguaje\n" << endl;
            Destroy(&expresion);
          }
	  else{
	    cout << "\nLa expresión no es válida" << endl;
	    cout << "Lo que se quedó en el tope de la pila es " << Top(&expresion).c << endl;
            Destroy(&expresion);
	  }
    }
	  return 0;
}
