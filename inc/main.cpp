#include <iostream>
#include "Bryla.hh"
#include "IObiektRysowalny.hh"
#include "Prostopadloscian.hh"
#include "Wektor.hh"

using namespace std;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != 'n');
}

int main(){  
  drawNS::APIGnuPlot3D * O1 = new drawNS::APIGnuPlot3D(-10,10,-10,10,-10,10,-1);
  SWektor<double,3> tab[8];
  SWektor<double,3> srod;
  MacierzOb orient;
  
  double p[3]={3,3,3};
  SWektor<double,3> przesun(p);

  double kat = 45;
  
  for(int i=0; i<8;i++)
    {
      cin >> tab[i];
    }
  Prostopadloscian pr(O1, tab, srod, orient);
  pr.rysuj();
  wait4key();
  pr.ruch(przesun);
  wait4key();
  pr.obrot(kat);
  wait4key();
  pr.ruch(przesun);
  wait4key();
  return 0;
}

