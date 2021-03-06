#ifndef GRANIASTO6_HH
#define GRANIASTO6_HH

#include "Bryla.hh"
#include "Wektor.hh"
#include "MacierzOb.hh"

using namespace std;
class Graniasto6 : public Bryla {
protected:
  SWektor<double, 3> wierzcholki[12];

public:
  Graniasto6(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> *tab, SWektor<double,3> & srodek, MacierzOb & m1): Bryla(Obiekt,srodek,m1)
  {
    for(int i = 0; i<12; i++)
      {
	wierzcholki[i] = tab[i];
      }
  };
  virtual ~Graniasto6() {}

  void rysuj()
  {
    Graniasto6 temp(*this);
    for(int i = 0; i < 12; i++)
      {
	temp.wierzcholki[i] = srodek + orientacja * wierzcholki[i];
      }
    index = Obiekt->draw_polyhedron(vector<vector<drawNS::Point3D>>{{temp.wierzcholki[0],temp.wierzcholki[1],temp.wierzcholki[2],temp.wierzcholki[3],temp.wierzcholki[4],temp.wierzcholki[5]},{temp.wierzcholki[6],temp.wierzcholki[7],temp.wierzcholki[8],temp.wierzcholki[9],temp.wierzcholki[10],temp.wierzcholki[11]}}, "blue");
    Obiekt->redraw();
  };
  
};

#endif
