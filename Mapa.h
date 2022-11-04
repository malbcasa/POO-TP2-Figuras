#ifndef _MAPA_H
#define _MAPA_H


#include <list>
#include <vector>
#include <string>
using namespace std;
class Figura;
class Circulo;
class Rectangulo;
class Triangulo;
class Archivo;

class Mapa {
  private:
    vector<int> resolucion;

    string  codigo;
	
	vector <Figura> figuras;

  public:
    void set_resolu(int resolx, int resoly);

    vector<int> get_resolu();

    void append_figura(Figura f);
	void append_figura(Circulo circ);
	void append_figura(Rectangulo rect);
	void append_figura(Triangulo tri);

    vector <Figura> get_figuras();

    int set_validez(Circulo circ);
	
	int set_validez(Rectangulo rect);
	
	int set_validez(Triangulo tri);
	
   

    void set_codigo(string marcador);

    string get_codigo();
	
	void show(int figtoshow);
	
	

};
#endif
