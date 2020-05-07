#include <iostream>
//#include "Prostopadloscian.hh"
#include "Bryla.hh"
#include "IObiektRysowalny.hh"
#include "Prostopadloscian.hh"
#include "Wektor.hh"
#include "Wektor3D.hh"

using namespace std;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != 'n');
}

int main(){
  
  drawNS::APIGnuPlot3D * O1 = new drawNS::APIGnuPlot3D(-10,10,-10,10,-10,10,-1);
  Wektor3D tab[8];
  Wektor3D srod;
  
  for(int i=0; i<8;i++)
    {
      cin >> tab[i];
    }
  
  Prostopadloscian pr(O1, tab, srod);
  pr.rysuj();

  cout << srod;
  
  wait4key();
  return 0;
}
