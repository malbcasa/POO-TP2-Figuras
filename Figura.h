#ifndef _FIGURA_H
#define _FIGURA_H


#include <string>
#include <tuple>
#include <list>
#include <vector>

using namespace std;

class Mapa;
class Archivo;

class Figura {
  private:
    string color;

    float perimetro;

    float area;

    string tipo;
	
	vector<vector<int>> coordenadas;


  public:
	void set_tipo(string tip);

    string get_tipo();

	void set_color(vector<string> colv);

	void set_color(string colstr);
	
	string get_color();
	
	void set_area(float sup);
	
	void set_perimetro(float perim);
	
	float get_perimetro();
	
	float get_area();
	
	void set_coordenadas(vector<int> centro, int radio);
	
	void set_coordenadas(vector<int> vertice, int base, int altura);
	
	void set_coordenadas(vector<vector<int>> vertices);
	
	vector<vector<int>> get_coordenadas();
	

};
#endif
