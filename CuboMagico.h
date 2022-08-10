/*Universidad de las Fuerzas Armadas - ESPE
TAREA #1 - Parcial 3: 
Realizar un algoritmo para dar solucion al problema de las 8 reinas.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 03/08/2022
FECHA DE MODIFICACIÓN: 09/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#pragma once
#include <stdio.h>
#include <windows.h>
using namespace std;

class CuboMagico
{
	typedef CuboMagico Cuma;
	private:
		int dim;
		int **mat;
	public:
		void inicMat();
		CuboMagico(int);
		void encerar();
		void resRivera();
		void resYanez();
		void resTituana(int, int);
		void mostrar();
	
};typedef CuboMagico Cuma;