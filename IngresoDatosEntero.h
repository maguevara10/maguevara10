/*Universidad de las Fuerzas Armadas - ESPE
TAREA #1 - Parcial 3: 
Realizar un algoritmo para dar solucion al problema de las 8 reinas.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 03/08/2022
FECHA DE MODIFICACIÓN: 09/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#ifndef INGRESODATOSENTERO_H
#define INGRESODATOSENTERO_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
using namespace std;


class IngresoDatos{
    public:
        IngresoDatos();
        virtual char *ingresoDatosEntero(const char*);
        virtual int convertirEntero();
};


#endif