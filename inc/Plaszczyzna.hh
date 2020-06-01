#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH
#include "IObiektRysowalny.hh"

using std::vector;

class Plaszczyzna : public IObiektRysowalny {
protected:
  SWektor<double,3> p[49];
public:
  Plaszczyzna(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> * tab): IObiektRysowalny(Obiekt)
  {
    for(int i = 0; i < 49; i++)
      {
	p[i] = tab[i];
      }
  };
  
  virtual void rysuj() = 0;

};
#endif
