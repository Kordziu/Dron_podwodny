#include <iostream>
//#include "Prostopadloscian.hh"
#include "Bryla.hh"
#include "IObiektRysowalny.hh"


using namespace std;

int main{
  drawNS::APIGnuPlot3D * O1 = new drawNS::APIGnuPlot3D(-10,10,-10,10,-10,10,1000);
  
  Bryla br(O1);
  br.rysuj();
  
  return 0;
}
