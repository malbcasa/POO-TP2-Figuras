#ifndef _RECTANGULO_H
#define _RECTANGULO_H


#include "Figura.h"
#include <string>
#include <vector>
using namespace std;

class Rectangulo : public Figura {
  private:
    vector<int> vertice;

    int base;

    int altura;


  public:
	Rectangulo(vector<int> vert,int b, int h);
	
    void set_vertice(vector<int> v);

    void set_base(int b);

    void set_altura(int a);

    vector<int> get_vertice();

    int get_base();

    int get_altura();

    void calc_perimetro();

    void calc_area();

};
#endif
