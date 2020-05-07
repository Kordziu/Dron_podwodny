#ifndef BRYLA_HH
#define BRYLA_HH
#include "IObiektRysowalny.hh"
#include "Wektor3D.hh"

using std::vector;

class Bryla : public IObiektRysowalny { 
protected:
  Wektor3D srodek;
  // MacierzOb orientacja;

public:
  Bryla(drawNS::APIGnuPlot3D * Obiekt, Wektor3D w1/*, MacierzOb m1*/): IObiektRysowalny(Obiekt), srodek(w1)/*, orientacja(m1)*/{}
  virtual void rysuj() = 0;
  virtual ~Bryla(){}
};
#endif
