#ifndef _CIRCULO_H
#define _CIRCULO_H


#include "Figura.h"
#include <string>
#include <vector>
using namespace std;

class Circulo : public Figura {
  private:
    vector<int> centro;

    int radio;


  public:
	Circulo(vector<int> c, int r);
	
    void set_centro(vector<int> c);

    void set_radio(int r);

    vector<int> get_centro();

    int get_radio();

    void calc_perimetro();


    void calc_area();

};
#endif
