#ifndef PROSTO_HH
#define PROSTO_HH
#include "Bryla.hh"
#include "Wektor.hh"
#include "MacierzOb.hh"

using namespace std;
class Prostopadloscian : public Bryla {
protected:
  SWektor<double,3> wierzcholki[8];
  
public:
  Prostopadloscian(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> * tab, SWektor<double,3> & srodek, MacierzOb & m1): Bryla(Obiekt, srodek, m1)
  {
    for(int i = 0; i<8; i++)
    {
      wierzcholki[i] = tab[i];
    }
  };

  void rysuj() //rysuje się dopiero w globalnym układzie wspolrzednych
  {
    Prostopadloscian temp(*this);//konstruktor kopiujący żeby nie zmienić wierzchołków
    for(int i = 0; i < 8; i++)
      {	
	temp.wierzcholki[i] = srodek + orientacja * wierzcholki[i];
      }
        index = Obiekt->draw_polyhedron(vector<vector<drawNS::Point3D>>{{temp.wierzcholki[0],temp.wierzcholki[1],temp.wierzcholki[2],temp.wierzcholki[3]},{temp.wierzcholki[4],temp.wierzcholki[5],temp.wierzcholki[6],temp.wierzcholki[7]}},"blue");    
	Obiekt->redraw();
  };

};
#endif
