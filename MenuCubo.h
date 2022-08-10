/*Universidad de las Fuerzas Armadas - ESPE
TAREA #1 - Parcial 3: 
Realizar un algoritmo para dar solucion al problema de las 8 reinas.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 03/08/2022
FECHA DE MODIFICACIÓN: 09/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/
#if !defined(__Class_Diagram_1_MenuProyectoUnidad_h)
#define __Class_Diagram_1_MenuProyectoUnidad_h
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstring>
#include<windows.h>
#include <thread>
using namespace std;
class MenuCubo
{
	public:
   	int menuCursor(const char* titulo, const char* opciones[], int n);
   	void gotoxy(int x, int y);
   	void presentarMenu(void);
};

#endif