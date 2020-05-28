#ifndef PRZESZKODA_PROSTO_HH
#define PRZESZKODA_PROSTO_HH

#include "Prostopadloscian.hh"

using namespace std;
class Przeszkoda_p : public Prostopadloscian {
public:
  Przeszkoda_p(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> * tab, SWektor<double,3> & srodek, MacierzOb & m1): Prostopadloscian(Obiekt, tab, srodek, m1){}

  void rysuj() {Prostopadloscian::rysuj();}
  
};

#endif
