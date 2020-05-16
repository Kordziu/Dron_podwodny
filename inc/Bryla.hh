#ifndef BRYLA_HH
#define BRYLA_HH
#include "IObiektRysowalny.hh"
#include "MacierzOb.hh"

using std::vector;

class Bryla : public IObiektRysowalny { 
protected:
  SWektor<double,3> srodek;
  MacierzOb orientacja; 
  
public:
  Bryla(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> & w1, MacierzOb & m1): IObiektRysowalny(Obiekt), srodek(w1), orientacja(m1){}
  virtual void rysuj() = 0;
  virtual ~Bryla(){}
  
  void ruch(SWektor<double,3> & w_ruchu)
  {
    Obiekt->erase_shape(index);
    srodek = srodek + (orientacja * w_ruchu);
    rysuj();
  };

  void obrot(double kat)
  {
    usun();
    orientacja.obrotz(kat);
  };
   
};
#endif
