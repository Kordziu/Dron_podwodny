#include 'Wektor.hh'
#include 'Dr3D_gnuplot_api.hh'
#include <iostream>

using drawNS::Point3D;                                                          
using drawNS::APIGnuPlot3D;                                                     
using std::vector;
using std::cout;
using std::endl;

class prostopadloscian{

  prostopadloscian();
  prostopadloscian(SWektor <double,3> tab[8]);
public:
  rysuj_prostopadloscian();
};
