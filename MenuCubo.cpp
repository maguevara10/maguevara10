/*Universidad de las Fuerzas Armadas - ESPE
TAREA #1 - Parcial 3: 
Realizar un algoritmo para dar solucion al problema de las 8 reinas.
AUTORES: David Guarderas Leal, Mathias Guevara, Shared Tinoco, Sebastián Torres
FECHA DE CREACIÓN: 03/08/2022
FECHA DE MODIFICACIÓN: 09/08/2022
GRUPO 2
GITHUB: CalculadoraPrePost
*/

#include "MenuCubo.h"
#include "CuboMagico.cpp"
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
#include "IngresoDatosEntero.cpp"
int ingresoDim();
////////////////////////////////////////////////////////////////////////
// Name:       MenuProyectoUnidad::menuCursor(const char* titulo, const char* opciones[], int n)
// Purpose:    Implementation of MenuProyectoUnidad::menuCursor()
// Parameters:
// - titulo
// - opciones[]
// - n
// Return:     int
////////////////////////////////////////////////////////////////////////

void imprimirArbol(int cant) 
{
	HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SHORT ancho, alto,posi1=3,posi2=3;
    int alto1=0;
    GetConsoleScreenBufferInfo(conhandler, &csbi);
    ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    alto = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    //SetConsoleCursorPosition(conhandler, { 0, 4 });
    
    while(alto1<cant){
    	std::string text="x: ";
    	text+= (std::to_string((alto1++)+1));
    	
    	std::string temp = text;
        text.erase(text.length(), 1);
        text += temp[text.length()];
        
    	CHAR_INFO* buff = (CHAR_INFO*)calloc(ancho+1, sizeof(CHAR_INFO));
    	
    	for (int i = 0; i < text.length(); i++) {
            buff[i].Char.AsciiChar = text.at(i);
            buff[i].Attributes = 15;
        }
        
    	SMALL_RECT pos = { 10, 2, ancho, alto };
        WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &pos);
        
        if((alto1%2)!=0)
        {
        	SMALL_RECT posAux1 = { 5, posi1, ancho, alto };
        	WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &posAux1);
        	posi1++;
		}else if((alto1%2)==0)
		{
			SMALL_RECT posAux2 = { 25, posi2, ancho, alto };
        	WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &posAux2);
        	posi2++;
		}
			
		free(buff);
		
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    	
	}
    
}

int MenuCubo::menuCursor(const char* titulo, const char* opciones[], int n)
{
   	int opcionSeleccionada = 1;
	int tecla;
	bool repite = true;
	
	do
	{
		system("cls");
		
	    gotoxy(5, 3 + opcionSeleccionada); cout << "==>";
	    
	    //Imprime el título
	    gotoxy(15,2); cout << titulo;
	    
	    //Imprime las opciones
	    int i;
	    
	    for((i=0);(i<n);(i++))
	    {
	    	gotoxy(10, 4 + i); cout << i+1 << ") " << opciones[i];
		}
		
		do
		{
			tecla = getch();
		}
		while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);
		
		switch(tecla)
		{
			case TECLA_ARRIBA:
				opcionSeleccionada --;
				
				if (opcionSeleccionada < 1)
				{
					opcionSeleccionada = n;
				}
				
				break;
			
			case TECLA_ABAJO:
				opcionSeleccionada ++;
				
				if (opcionSeleccionada > n)
				{
					opcionSeleccionada = 1;
				}
				
				break;
				
			case ENTER:
				repite = false;
				break;
		}
    }
    while(repite);
	
	return opcionSeleccionada;
}

////////////////////////////////////////////////////////////////////////
// Name:       MenuProyectoUnidad::gotoxy(int x, int y)
// Purpose:    Implementation of MenuProyectoUnidad::gotoxy()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void MenuCubo::gotoxy(int x, int y)
{
   	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	
	SetConsoleCursorPosition(hCon, dwPos);
}

////////////////////////////////////////////////////////////////////////
// Name:       MenuProyectoUnidad::presentarMenu()
// Purpose:    Implementation of MenuProyectoUnidad::presentarMenu()
// Return:     void
////////////////////////////////////////////////////////////////////////

void MenuCubo::presentarMenu(void)
{
	const char *tituloGeneral = "CUBO MAGICO\n\tPrueba realizada por Mathias Guevara";
	const char *opcionesGeneral[] = {"Algoritmo Cubo Magico.","Salir."};	
//	const char *subTituloArbol = "SELECCIONE LA OPCION";
//	const char *opcionesSubA[] = {"Insertar.", "Eliminar.","Buscar","Imprimir","Retornar al menu Principal."};
//	const char *tituloArchivos = "SELECCIONE EL TIPO DE ARCHIVO";
//	const char *opcionesArchivos[] = {"Formato PDF.", "Formato Txt.","Retornar al menu Principal."};	
	int op=0,nGenerales=2/*opSubA=0,nSubA=5,opArchivos=0,nArchivos=3*/;	
	do{	 
		op=menuCursor(tituloGeneral,opcionesGeneral,nGenerales);
		switch(op){
			case 1: {	
				system("cls");
				int opi=ingresoDim();
				int centi=0,patron=0;
				cout<<"\nIngrese el centinela: ";
				cin>>centi;
				cout<<"Ingrese el patron: ";
				cin>>patron;
				Cuma cu(opi);
				cu.resTituana(centi, patron);
				cu.mostrar(); 
				system("pause");				
				break;
			}
			case 2:{
				system("cls");
				cout<<"\nGracias por usar nuestro programa."<<endl;
				exit(EXIT_SUCCESS);
				break;
			}	
			default:
				{
					printf("\nComando no reconocido. Vuelva a intentar.\n");
					system("pause");
					break;
				}
			}			
		}while(op!=4);
}

int ingresoDim(){
	
	bool impar=false;
	do{
		IngresoDatos ingreso;
		system("cls");
		cout<<"Ingrese la dimension del cuadrado: "<<endl;
		int dim=ingreso.convertirEntero(); 	
		if(dim%2!=0){
			impar=true;
			return dim;
		}
	}while(impar==false);
}