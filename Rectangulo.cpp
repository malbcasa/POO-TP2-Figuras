
#include "Rectangulo.h"
#include<vector>
#include<iostream>
void Rectangulo::set_vertice(vector<int> v) {
	vertice.push_back(v[0]);
	vertice.push_back(v[1]);
}

void Rectangulo::set_base(int b) {
	base = b;
}

void Rectangulo::set_altura(int h) {
	altura = h;
}

vector<int> Rectangulo::get_vertice() {
	return vertice;
}

int Rectangulo::get_base() {
	return base;
}

int Rectangulo::get_altura() {
	return altura;
}


void Rectangulo::calc_perimetro() {
	float perim = (base*2)+(altura*2);
	set_perimetro(perim);
}

void Rectangulo::calc_area() {
	float a = base*altura;
	set_area(a);
}

Rectangulo::Rectangulo(vector<int> vert,int b, int h){
	
	Rectangulo::set_vertice(vert);
	Rectangulo::set_base(b);
	Rectangulo::set_altura(h);
	Rectangulo::calc_perimetro();
	Rectangulo::calc_area();
}
