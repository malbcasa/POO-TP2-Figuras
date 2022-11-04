#ifndef _ARCHIVO_H
#define _ARCHIVO_H
#include "Figura.h"
#include "Mapa.h"

#include <string>
#include<list>
#include<vector>
#include <fstream>
using namespace std;

class Figura;
class Mapa;


class Archivo:public fstream {
	
  private:
    string nombre;

    string contenido;

    int lineas;
	
	ofstream _fichero;
	
	Mapa* m;


  public:

	
    void set_nom();

    string get_nom();

    void set_cont(string cont);
	
	string get_cont();
	
	void* open();
	
	void write(string msg);
	
	void close(Archivo* fich);
	
	string set_mapa(Archivo& fich_in);
	
	Mapa get_mapa();
	
	int get_lineas() ;

};
#endif
