#ifndef PRZESZKODA_PROSTO_HH
#define PRZESZKODA_PROSTO_HH

#include "Prostopadloscian.hh"
#include "Dron.hh"
#include "Przeszkoda.hh"

using namespace std;
class Przeszkoda_p : public Prostopadloscian, public Przeszkoda {
public:
  Przeszkoda_p(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> * tab, SWektor<double,3> & srodek, MacierzOb & m1): Prostopadloscian(Obiekt, tab, srodek, m1){}

  void rysuj() {Prostopadloscian::rysuj();}
  bool czy_kolizja(const Dron &dron)const
  {
    double promien = dron.zwroc_promien();
    //cout << "Promien: "<< promien << endl;
    //cout << (srodek - dron.zwroc_srodek()).dlugosc() << endl;
    if((srodek - dron.zwroc_srodek()).dlugosc() < promien)
      {
	cout << "Zatrzymanie - kolizja z klockiem\n";
	return true;
      }
    return false;
  };
  
};

#endif
