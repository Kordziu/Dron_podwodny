#ifndef DRON_HH
#define DRON_HH

#include<iostream>
#include "Prostopadloscian.hh"
#include "Wirnik.hh"

using namespace std;

class Dron : public Prostopadloscian{
protected:
  Wirnik wirnik1;
  Wirnik wirnik2;
public:
  Dron(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> *tab8, SWektor<double,3> *tab12, SWektor<double,3> srodek, MacierzOb &m1): Prostopadloscian(Obiekt, tab8, srodek, m1), wirnik1(Obiekt, tab12, srodek, m1), wirnik2(Obiekt, tab12, srodek, m1){};
  
  void ruch(double odleglosc, double kat)
  {
    double radian = (3.14 * kat) / 180;
    double t_ruchu[3]; //Tablica do wektora ruchu
    double kat_wirnika = 15; //(3.14 * 15) / 180;
    t_ruchu[2] = odleglosc * sin(radian); //Przesunięcie w kier x
    t_ruchu[1] = 0;                       //Przesunięcie w kier y
    t_ruchu[0] = odleglosc * cos(radian); //Przesunięcie w kier z
    SWektor<double, 3> w_ruchu(t_ruchu);
    
    w_ruchu = w_ruchu / 500;
    for(int i = 0; i < 500; i++)
      {
	Obiekt->erase_shape(index);
	srodek = srodek + (orientacja * w_ruchu);
	wirnik1.usun();
	wirnik2.usun();
	wirnik1.obrot_wir(kat_wirnika); //Obrót wirnika wokół własnej osi
	wirnik2.obrot_wir(kat_wirnika); //Obrót wirnika wokół własnej osi

	rysuj();
      }    
  };

  void obrot(double kat) //wokół osi OZ
  {   
    double dzielnik = abs(5*kat);
    double kat_podzielony;
    kat_podzielony = kat/dzielnik;
    for(int i = 0; i < dzielnik; i++)
      {
	wirnik1.usun();
	wirnik2.usun();
	wirnik1.obrot(kat_podzielony); //Obrót wirnika razem z dronem
	wirnik2.obrot(kat_podzielony); //Obrót wirnika razem z dronem
	Prostopadloscian::obrot(kat_podzielony);
	rysuj();
      }
  };

  void rysuj()
  {
    wirnik1.rysuj(srodek + orientacja * ((wierzcholki[0] + wierzcholki[4]) * 0.5)); //narysowanie wirnika ze środkiem na połowie długości tylnej krawędzi drona
    wirnik2.rysuj(srodek + orientacja * ((wierzcholki[3] + wierzcholki[7]) * 0.5)); //narysowanie wirnika ze środkiem na połowie długości tylnej krawędzi drona
    Prostopadloscian::rysuj();
  };
  
};
#endif
