
#include "Figura.h"
#include "Mapa.h"
#include "Archivo.h"
#include <cmath> 
#include <iostream> 
#include <algorithm>



void Figura::set_tipo(string tip) {
	tipo= tip;
}

string Figura::get_tipo() {
	
	return tipo;
}

void Figura::set_color(vector<string> colv) {
	color = colv[0];
}

void Figura::set_color(string colstr) {
	color = colstr;
}

string Figura::get_color() {
	if( color.find("#") != string::npos){
		return color.substr(color.find("#")+1);
	}else{
		return "9";
	}
}

void Figura::set_area(float sup){
	area = sup;
}

float Figura::get_area(){
	return area;
}

void Figura::set_perimetro(float perim){
	perimetro = perim;
}

float Figura::get_perimetro(){
	return perimetro;
}

void Figura::set_coordenadas(vector<int> centro, int radio){
	int limxsup = centro[0] + radio;
	int limxinf = centro[0] - radio;
	int limysup = centro[1] + radio;
	int limyinf = centro[1] - radio;
	int dist =0;
		
		
	for (int i=limxinf ; i <=limxsup; i++){
		for(int j = limyinf; j <= limysup ; j++){
			dist = sqrt(pow(i-centro[0],2)+pow(j-centro[1],2));
			if (dist >= (0.985*radio) && dist<=(1.015*radio)){
				this->coordenadas.push_back({i,j});
			}
		}
		
	}
	
}


void Figura::set_coordenadas(vector<int> vertice, int base, int altura){
	int limxsup = vertice[0] + base;
	int limxinf = vertice[0];
	int limysup = vertice[1] + altura;
	int limyinf = vertice[1];
	
	for (int i=limxinf ; i <= limxsup; i++){
		for(int j = limyinf; j <= limysup ; j++){
			if ((i <= limxsup) && (j == limyinf || j==limysup)){
				this->coordenadas.push_back({i,j});
			}else if ((j <= limysup) && (i == limxinf || i==limxsup)){
				this->coordenadas.push_back({i,j});
			}
		}
		
	}
}


void Figura::set_coordenadas(vector<vector<int>> vertices){
	sort(vertices.begin(), vertices.end(), [](const vector<int> a, const vector<int>  b){ return a < b; });
	
	int pendiente = 0;
	int deltay = 0;
	int deltax = 0;
	int modulo = 0;
	
	for (int k = 0 ; k < 2 ; k++){
		deltay = vertices[k+1][1] - vertices[k][1];
		deltax = vertices[k+1][0] - vertices[k][0];
		
		for (int i = 0; i<= max(abs(deltay),abs(deltax)) ; i++){
			if(deltax == 0){
				coordenadas.push_back({vertices[k][0],vertices[k][1]+i});
			}else if(deltay == 0){
				coordenadas.push_back({vertices[k][1]+i,vertices[k][1]});
			}else{
				if(deltay >= deltax){
					pendiente = deltay/deltax ;
					modulo = ceil(float(abs(deltay))/float(abs(deltax)));
					
				}else{
					pendiente = deltax/deltay ;
					modulo = ceil(float(abs(deltax))/float(abs(deltay)));
					
				}
				
				int j = 0;
				while( j < modulo){
					coordenadas.push_back({(vertices[k][0]+i),((i*pendiente)+vertices[k][1])});
					//cout << "Coord " << coordenadas[coordenadas.size()-1][0] << ", " << coordenadas[coordenadas.size()-1][1] << "\n";
					j++;
				}
				
			}
		}
	}
	
	deltay = vertices[2][1] - vertices[0][1];
	deltax = vertices[2][0] - vertices[0][0];
	
	
	
	for (int i = 0; i<= max(abs(deltay),abs(deltax)) ; i++){
		if(deltax == 0){
			coordenadas.push_back({vertices[0][0],vertices[0][1]+i});
		}else if(deltay == 0){
			coordenadas.push_back({vertices[0][1]+i,vertices[0][1]});
		}else{
			if(deltay >= deltax){
				pendiente = deltay/deltax ;
				modulo = ceil(float(abs(deltay))/float(abs(deltax)));
			
			}else{
				pendiente = deltax/deltay ;
				modulo = ceil(float(abs(deltax))/float(abs(deltay)));
				
			}
			
			int j = 0;
			while( j < modulo){
				coordenadas.push_back({vertices[0][0]+i,((vertices[0][0]+i)*pendiente)+vertices[0][1]});
				
				j++;
			}
			
		}
	}
	
}


vector<vector<int>> Figura::get_coordenadas(){
	return this->coordenadas;
}
