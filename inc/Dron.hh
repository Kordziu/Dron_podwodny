#ifndef DRON_HH
#define DRON_HH

#include<iostream>
#include "Prostopadloscian.hh"

using namespace std;

class Dron : public Prostopadloscian{
public:
  Dron(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> *tab, SWektor<double,3> srodek, MacierzOb &m1): Prostopadloscian(Obiekt, tab, srodek, m1){};
  
  void ruch(double odleglosc, double kat)
  {
    double radian = (3.14 * kat) / 180;
    double t_ruchu[3]; //Tablica do wektora ruchu
    t_ruchu[2] = odleglosc * sin(radian); //Przesunięcie w kier x
    t_ruchu[1] = 0;                       //Przesunięcie w kier y
    t_ruchu[0] = odleglosc * cos(radian); //Przesunięcie w kier z
    SWektor<double, 3> w_ruchu(t_ruchu);
    
    w_ruchu = w_ruchu / 500;
    for(int i = 0; i < 500; i++)
      {
	Obiekt->erase_shape(index);
	srodek = srodek + (orientacja * w_ruchu);
	rysuj();
      }    
  };

  void obrot(double kat) //wokół osi OZ
  {   
    double dzielnik = abs(10*kat);
    double kat_podzielony;
    kat_podzielony = kat/dzielnik;
    for(int i = 0; i < dzielnik; i++)
      {
	Bryla::obrot(kat_podzielony);
      }
  };
  
};
#endif
