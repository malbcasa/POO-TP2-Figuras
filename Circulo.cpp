
#include "Circulo.h"

#include <string>
#include<vector>
#include "bits/stdc++.h"
using namespace std;

void Circulo::set_centro(vector<int> c) {
	centro.push_back(c[0]);
	centro.push_back(c[1]);
}

void Circulo::set_radio(int r) {
	radio = r;
}

vector<int> Circulo::get_centro() {
	return centro;
}

int Circulo::get_radio() {
	return radio;
}


void Circulo::calc_perimetro() {
	double pi = 2 * acos(0.0);
	float perim = 2*pi*radio;
	set_perimetro(perim);
}

void Circulo::calc_area() {
	double pi = 2 * acos(0.0);
	float a = pi*(pow(radio,2));
	set_area(a);
}

Circulo::Circulo(vector<int> c, int r){
	Circulo::set_centro(c);
	Circulo::set_radio(r);
	Circulo::calc_area();
	Circulo::calc_perimetro();
}
