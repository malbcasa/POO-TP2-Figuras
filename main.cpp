#include<iostream>
#include<cmath>

#include "Archivo.h"
#include "Mapa.h"
#include"Figura.h"
#include"Rectangulo.h"
#include "Triangulo.h"
#include"Circulo.h"

using namespace std;

int main (int argc, char *argv[]) {
	cout << "El programa está pensado para trabajar con 2 archivos definidos por el usuario. ";
	cout << "El primer nombre de archivo que se pide, hace alusión al archivo de datos. ";
	cout << "El segundo nombre de archivo, indica un nombre para crear el reporte. ";
	cout << "Además, se crea un archivo, dibujo.txt, donde se muestra la figura seleccionada, ";
	cout << "la cual se verá  ligeramente distorsionada en sentido vertical debido al interlineado\n";
	
	Archivo file_in;
	file_in.set_nom();
	Archivo file_out;
	file_out.set_nom();
	int figtoshow = 0 ;
	
	cout << file_in.get_cont();

	
	cout << file_out.set_mapa(file_in);	
	
	cout << "\n\nIngrese el numero de figura a mostrar (la lista comienza en 0)\n";
	cin >> figtoshow;
	
	
	Mapa mapashow = file_out.get_mapa();
		
	mapashow.show(figtoshow);

	return 0;
}

