#ifndef PROSTO_HH
#define PROSTO_HH
#include "Bryla.hh"
#include "Wektor.hh"
#include "Wektor3D.hh"

using namespace std;
class Prostopadloscian : public Bryla {
protected:
  Wektor3D wierzcholki[8];
  
public:
  Prostopadloscian(drawNS::APIGnuPlot3D * Obiekt, Wektor3D *tab, Wektor3D srodek/*, Macierz<double, 3> m1*/): Bryla(Obiekt, srodek/*, m1*/)
  {
    for(int i = 0; i<8; i++)
    {
      wierzcholki[i] = tab[i];
    }
  };

  void rysuj(){

     Obiekt->draw_polyhedron(vector<vector<drawNS::Point3D>>{{wierzcholki[0],wierzcholki[1],wierzcholki[2],wierzcholki[3]},{wierzcholki[4],wierzcholki[5],wierzcholki[6],wierzcholki[7]}},"blue");
    
     Obiekt->redraw();
  };

  void ruch(double odleglosc, double kat)
  {
    
  };

  void obrot(double kat);
  {
    
  };
};
#endif
