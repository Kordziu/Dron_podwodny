#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include "Macierz.hh"

class MacierzOb: public Macierz<double,3> {
  public:
  MacierzOb(){tab[0][0] = 1; tab[1][1] = 1; tab[2][2] = 1;};

  //MacierzOb(const Macierz<double,3> & m){if(m.wyznacznik != 1 ||};
  
  MacierzOb operator = (const Macierz<double,3> m)
  {
    for(int i = 0; i<3; i++){
      tab[i] = m[i];
    }
    return *this;
  };

   void obrotz(double kat) //wokół osi OZ
  {
    MacierzOb tmp(*this); //kopia macierzy obrotu
    double radian = (3.14 * kat) / 180; //zamiana kata na radiany
    tmp[0][0] = cos(radian);
    tmp[0][1] = -sin(radian);
    tmp[1][0] = sin(radian);
    tmp[1][1] = cos(radian);
    tmp[2][2] = 1;
    *this = *this * tmp;
  };
  
   void obrotx(double kat) //wokół osi OX
  {
    MacierzOb tmp(*this);
    double radian = (3.14 * kat) / 180;
    tmp[0][0] = 1;
    tmp[1][1] = cos(radian);
    tmp[1][2] = -sin(radian);
    tmp[2][1] = sin(radian);
    tmp[2][2] = cos(radian);
    *this = *this * tmp;
  };

  void obroty(double kat) //wokół osi OY
  {
    MacierzOb tmp(*this);
    double radian = (3.14 * kat) / 180;
    tmp[0][0] = cos(radian);
    tmp[0][2] = sin(radian);
    tmp[1][1] = 1;
    tmp[2][0] = -sin(radian);
    tmp[2][2] = cos(radian);
    *this = *this * tmp;
  };

};

#endif
