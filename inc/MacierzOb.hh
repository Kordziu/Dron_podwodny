#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include "Macierz.hh"

class MacierzOb: public Macierz<double,3> {
  public:
  MacierzOb(){tab[0][0] = 1; tab[1][1] = 1; tab[2][2] = 1;};
  
  MacierzOb operator = (const Macierz<double,3> m)
  {
    for(int i = 0; i<3; i++){
      tab[i] = m[i];
    }
    return *this;
  };
  
};

#endif
