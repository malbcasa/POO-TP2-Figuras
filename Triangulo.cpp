#include "Triangulo.h"
#include<cmath>
#include<iostream>
#include<vector>

void Triangulo::set_vertice(vector<vector<int>> V) {	
	
	for(int i=0;i<3;++i){
		vertice.push_back(V[i]);
	}
	
}

vector<vector<int>> Triangulo::get_vertice() {
	return vertice;
}


void Triangulo::calc_perimetro() {
	float l1,l2,l3;
	l1=sqrt(pow(vertice[0][0]-vertice[1][0],2)+pow(vertice[0][1]-vertice[1][1],2));
	l2=sqrt(pow(vertice[0][0]-vertice[2][0],2)+pow(vertice[0][1]-vertice[2][1],2));
	l3=sqrt(pow(vertice[1][0]-vertice[2][0],2)+pow(vertice[1][1]-vertice[2][1],2));
	set_perimetro(l1+l2+l3);
	
}


void Triangulo::calc_area() {
	
	float a = ((vertice[0][0]) * (vertice[1][1])+(vertice[0][1]) * (vertice[2][0])+(vertice[1][0]) * (vertice[2][1]))/2;
	a = abs(a -((vertice[1][1]) * (vertice[2][0])+(vertice[0][0]) * (vertice[2][1])+(vertice[0][1]) * (vertice[1][0]))/2);
	set_area(a);
}

Triangulo::Triangulo(vector<vector<int>> V){
	
	Triangulo::set_vertice(V);
	Triangulo::calc_area();
	Triangulo::calc_perimetro();
}
