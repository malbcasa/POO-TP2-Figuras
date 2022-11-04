
#include "Mapa.h"
#include "Figura.h"
#include "Archivo.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"

#include <string>
#include <list>
#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>

using namespace std;

void Mapa::set_resolu(int resolx, int resoly) {
	resolucion.push_back(resolx);
	resolucion.push_back(resoly);
}

vector<int> Mapa::get_resolu() {
	return resolucion;
}

void Mapa::append_figura(Circulo circ) {

	figuras.insert(figuras.end(), circ);
}
void Mapa::append_figura(Rectangulo rect) {
	
	figuras.insert(figuras.end(), rect);
}
void Mapa::append_figura(Triangulo tri) {
	
	figuras.insert(figuras.end(), tri);
}
void Mapa::append_figura(Figura f){
	figuras.insert(figuras.end(), f);
}


vector <Figura> Mapa::get_figuras() {
	
	return figuras;
}

int Mapa::set_validez(Circulo circ) {

		vector<int> centro = circ.get_centro();
		int radio = circ.get_radio();
		size_t x = 0;
		size_t y = 1;	
		if(((centro[x] +radio) <= resolucion[x] ) && ((centro[y] +radio)<=resolucion[y])){
			return 0;
		}else{
			return 1;
		}
	
}
int Mapa::set_validez(Rectangulo rect){
	vector<int> verti = rect.get_vertice();
	int b = rect.get_base();
	int h = rect.get_altura();
	size_t x = 0;
	size_t y = 1;	
	if(((verti[x] + b) <= resolucion[x] ) && ((verti[y] + h )<=resolucion[y])){
		return 0;
	}else{
		return 1;
	}
}

int Mapa::set_validez(Triangulo tri){
	vector<vector<int>> verti = tri.get_vertice();
	size_t x = 0;
	size_t y = 1;	
	size_t z = 2;
	if((verti[x][x] <= resolucion[x] ) && (verti[x][y]<=resolucion[y])){
		if((verti[y][x] <= resolucion[x] ) && (verti[y][y]<=resolucion[y])){
			if((verti[z][x] <= resolucion[x] ) && (verti[z][y]<=resolucion[y])){
				return 0;
			}else{
				return 1;
			}
		}else{
			return 1;
		}
		
	}else{
		return 1;
	}
	
}


void Mapa::set_codigo(string marcador) {
	codigo = marcador;
}

string Mapa::get_codigo() {
	return codigo;
}


void Mapa::show(int numfig){

	
	vector<vector<int>> coord = this->figuras[numfig].get_coordenadas();
	string** showmat = new string*[this->resolucion[1]];
	for (int i =0 ; i < this->resolucion[1] ; i++){
		showmat[i]=new string[this->resolucion[0]];
	}
	ofstream dibujo ("dibujo.txt");
	
	string color = this->figuras[numfig].get_color();
	if(color.size() > 1){
		color = color.substr(2,1);
	}
	
	
	for(int i = 0; i < this->resolucion[1]; i++){
		for(int j = 0; j < this->resolucion[0] ; j++){
			
			showmat[i][j] = "0";
			
		}	
		
	}
	
	for(int i = 0; i < coord.size(); i++){
		
		if( ((coord[i][0])) < ((this->resolucion[0]))  && ( ((coord[i][1])) < ((this->resolucion[1]))) ) {
			showmat[coord[i][1]][coord[i][0]] = color;
		}
				
	}
	
	for(int i = this->resolucion[1]-1 ; i >= 0 ; i--){
		for(int j = 0; j < this->resolucion[0] ; j++){
				dibujo << showmat[i][j] ;
		}	
		dibujo << "\n";
	}
	
	
	dibujo.close();
	
	
};

