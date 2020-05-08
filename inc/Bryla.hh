#ifndef BRYLA_HH
#define BRYLA_HH
#include "IObiektRysowalny.hh"
//#include "Wektor3D.hh"
#include "MacierzOb.hh"

using std::vector;

class Bryla : public IObiektRysowalny { 
protected:
  SWektor<double,3> srodek;
  MacierzOb orientacja;
  double index; //zmienna do przechowywania indexu bryly, zeby moc uzyc metody erase
  
public:
  Bryla(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> & w1, MacierzOb & m1): IObiektRysowalny(Obiekt), srodek(w1), orientacja(m1), index(0){}
  virtual void rysuj() = 0;
  virtual ~Bryla(){}
  
  void ruch(SWektor<double,3> & przesuniecie)
  {
    Obiekt->erase_shape(index);
    srodek = srodek + (orientacja * przesuniecie);
    rysuj();
  };
  
  void obrot(double kat) //wokół osi OZ
  {
    Obiekt->erase_shape(index);
    MacierzOb tmp(orientacja); //kopia macierzy obrotu
    double radian = (3.14 * kat) / 180; //zamiana kata na radiany
    tmp[0][0] = cos(radian);
    tmp[0][1] = -sin(radian);
    tmp[1][0] = sin(radian);
    tmp[1][1] = cos(radian);
    tmp[2][2] = 1;
    orientacja = orientacja * tmp;
    rysuj();
  };

};
#endif
