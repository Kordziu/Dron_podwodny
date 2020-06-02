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
    SWektor<double,3> tmp[8];
    // Sprawdzamy czy parametr Z środka drona mieści się między Z górnego i dolnego wierzchołka powiększonych o promień drona i analogicznie z parametrami X i Y
    for(int i = 0; i < 8; i++)
      {
	tmp[i] = srodek + wierzcholki[i];
      }
    if(dron.zwroc_srodek()[2] > tmp[0][2] - promien && dron.zwroc_srodek()[2] < tmp[4][2] + promien)
      {
	if(dron.zwroc_srodek()[1] > tmp[0][1] - promien && dron.zwroc_srodek()[1] < tmp[2][1] + promien)
	  {
	    if(dron.zwroc_srodek()[0] > tmp[0][0] - promien && dron.zwroc_srodek()[0] < tmp[1][0] + promien)
	      {
		cout << "Zatrzymanie - kolizja z klockiem\n";
		return true;
	      }
	  }
      }
    return false;
  };
  
};

#endif
