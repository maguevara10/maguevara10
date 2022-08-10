/*Universidad de las Fuerzas Armadas - ESPE
TAREA #1 - Parcial 3: 
Realizar un algoritmo para dar solucion al problema de las 8 reinas.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 03/08/2022
FECHA DE MODIFICACIÓN: 09/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#include "IngresoDatosEntero.h"
#define LONGITUD 10

IngresoDatos::IngresoDatos(){

}

char *IngresoDatos::ingresoDatosEntero(const char *msj){
    char *dato=new char[LONGITUD+1];
    char c;
    printf("%s",msj);
    int i=0;
    while(c = getch()){
		if (c==13){
			dato[i]='\0';
			break;
		}
		else if (c == 8){ //backspace
			if (i>0){
				i--;
				printf("\b \b");
			}	
		}
		else{
			if (i<LONGITUD && c>='0'&& c<='9') //limite de longitud
			{
				printf("%c",c);
				dato[i]=c;
				i++;
			}
			
		}
	}

	return dato;

}

int IngresoDatos::convertirEntero(){
    char dato[10];
	int valor=0;
	strcpy(dato,ingresoDatosEntero(""));
	valor=atoi(dato);
	return valor;

	
}
