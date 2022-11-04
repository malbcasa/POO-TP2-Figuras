#ifndef _TRIANGULO_H
#define _TRIANGULO_H


#include "Figura.h"
#include<vector>

using namespace std;

class Triangulo : public Figura {
  private:
    vector<vector<int>> vertice;
	


  public:
	Triangulo(vector<vector<int>> V);
	
	void set_vertice(vector<vector<int>> V);

    vector<vector<int>> get_vertice();

    void calc_perimetro();

    void calc_area();

};
#endif
