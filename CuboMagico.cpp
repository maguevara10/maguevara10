/*Universidad de las Fuerzas Armadas - ESPE
TAREA #1 - Parcial 3: 
Realizar un algoritmo para dar solucion al problema de las 8 reinas.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 03/08/2022
FECHA DE MODIFICACIÓN: 09/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#pragma once
#include "CuboMagico.h"

Cuma::CuboMagico(int _dim)
{
	this->dim=_dim;
	
	inicMat();
}

void Cuma::inicMat()
{
	mat= new int*[dim];
	
	for(int i=0;i<dim;i++)
	{
		*(mat+i) = new int[dim];
	}
	encerar();
}


void Cuma::mostrar()
{	system("cls");
	
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			cout<<"\t|\t"<<*(*(mat+j)+i);
		}
		cout<<endl;
	}
}

void Cuma::resYanez()
{//mitad
    int suma=0;
    for(int y=1;y<=9;y++){	
        suma+=y;
    }
    int mitad=suma/9;
    *(*(mat+1)+1)=mitad;
    int numMag=suma/3;
    	
    //esquinas
    if (numMag%2!=0){//es impar, esquinas pares 
        *(*(mat+0)+0)=2;
        *(*(mat+0)+2)=4;
        *(*(mat+2)+0)=6;
        *(*(mat+2)+2)=8;
        
    }
    else{//es par, esquinas impares
        *(*(mat+0)+0)=1;
        *(*(mat+0)+2)=3;
        *(*(mat+2)+0)=5;
        *(*(mat+2)+2)=7;
    }
	
    //primera fila
    int sumaf=0;
    for(int c=0;c<3;c++){	
    sumaf+=*(*(mat+0)+c);
    }
    int falta=numMag-sumaf;
    *(*(mat+0)+1)=falta;
    
    //columnas
    for(int c=0;c<3;c++){	
        int sumac=0;
        for(int f=0;f<3;f++){	
            sumac+=*(*(mat+f)+c);
        }
        falta=numMag-sumac;
        for(int f=0;f<3;f++){	
            if (*(*(mat+f)+c)==0)
            {
                *(*(mat+f)+c)=falta;
            } 
        }
    }
	
}

void Cuma::encerar()
{
	for(int i=0;i<dim;i++)
	{
		for(int j=0;j<dim;j++)
		{
			*(*(mat+i)+j)=0;
		}
	}
}

void Cuma::resRivera()
{
	int xO = dim/2, yO=dim-1;
	
	for(int i=1;i<=dim*dim;i++)
	{
		*(*(mat+xO)+yO)=i;
		xO-=1;
		yO+=1;
		
		if(xO<0 && yO>=dim)
		{
			xO=0;
			yO=dim-2;
		}
		else
		{
			if(xO<0)
			{
				xO=dim-1;
			}
			if(yO>=dim)
			{
				yO=0;
			}
		}
		if(*(*(mat+xO)+yO)!=0)
		{
			xO+=1;
			yO-=2;
			while(*(*(mat+xO)+yO)!=0)
			{
				if(xO<0)
				{
					xO=dim-1;
				}
				if(yO>=dim)
				{
					yO=0;
				}
				if(xO<0 && yO>=dim)
				{
					xO=0;
					yO=dim-2;
				}
				if(*(*(mat+xO)+yO)!=0)
				{
					xO+=1;
					yO-=2;
				}
			}
		}
		
		
	}
}

void Cuma::resTituana(int centi, int patron)
{
	int N=dim, n=N/2, m=(N+(2*n));
	float m2=(m/2.0f);
	int filaIni=0,coluIni=round(m2)-1, contador=1 ,filas=0, colum=coluIni;
	int **aux,** matriz;
	aux= new int *[m];
	matriz= new int *[N];
	
	for(int i=0;i<m;i++){
		*(aux+i)= new int [m];
	}
	
	for(int i=0;i<N;i++){
		*(matriz+i)= new int [N];
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			*(*(aux+j)+i)=0;
		}
	}

	for (int i=0;i < N*N ;i++){
		*(*(aux+colum)+filas)=centi;
		centi+=patron;
		
		
		if(contador==N){
			filaIni+=1;
			coluIni-=1;
			contador=0;
			filas=filaIni-1;
			colum=coluIni-1;
		}
		filas++;
		colum++;
		contador++;
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if((*(*(aux+j)+i)!=0) && (((i>(m2+n)) || ((m2-n-1)>i)) || ((j>(m2+n)) || ((m2-n-1)>j)))){
				if((m2-n-1)>i && (j>(m2-n-1) && (j<(m2+n)))){
					*(*(aux+j)+i+N) = *(*(aux+j)+i);
					*(*(aux+j)+i)=0;
					
				}else if((m2+n)<i && (j>(m2-n-1) && (j<(m2+n)))){
					*(*(aux+j)+i-N) = *(*(aux+j)+i);
					*(*(aux+j)+i)=0;
					
				}else if((m2-n-1)>j && (i>(m2-n-1) && (i<(m2+n)))){
					*(*(aux+j+N)+i) = *(*(aux+j)+i);
					*(*(aux+j)+i)=0;
					
				}else if((m2+n)<j && (i>(m2-n-1) && (i<(m2+n)))){
					*(*(aux+j-N)+i) = *(*(aux+j)+i);
					*(*(aux+j)+i)=0;
				}
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			*(*(mat+j)+i)=*(*(aux+j+n)+i+n);
			//cout<<"\t"<<*(*(matriz+j)+i);
		}
		//cout<<endl;
	}
}

