#ifndef PROSTO_HH
#define PROSTO_HH
#include "Bryla.hh"
#include "Wektor.hh"

using namespace std;
class Prostopadloscian : public Bryla {
protected:

  SWektor<double, 3> wierzcholki[8];

public:
  Prostopadloscian(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> *tab): IObiektRysowalny(Obiekt){
    for(int i = 0; i<8; i++){
      wierzcholki[i] = tab[i];
    }
  };

/*Prostopadloscian(double x, double y, double z)
  {
    for(int i=0; i <= 1; i++) {
      vector<SWektor<double,3>> plaszczyzna;
     for (int j=0; j <= 1; j++){
       for (int k=0; k<=1; k++){
	 plaszczyzna.push_back(Wektor3D(i*x, j*y, k*z));
       }
     }
     wierzcholki.push_back(plaszczyzna);
    }
  }
*/

  void rysuj(){
    Obiekt->draw_polyhedron(vector<vector<drawNS::Point3D>>{{wierzcholki[0],wierzcholki[1],wierzcholki[2],wierzcholki[3]},{wierzcholki[4],wierzcholki[5],wierzcholki[6],wierzcholki[7]}},"blue")
      Obiekt->redraw();
  };
};
#endif
