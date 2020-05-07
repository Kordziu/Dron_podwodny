#ifndef BRYLA_HH
#define BRYLA_HH

using namespace std;
class Prostopadloscian : public Bryla {
protected:
  vector<vector<Wektor3D>> wierzcholki;

public:
  Prostopadloscian();
  Prostopadloscian(double x, double y, double z)
  {//vector<Wektor3D(x,0,0), Wektor3D(0,0,0), Wektor3D(x,y,0), Wektor3D(0,y,0)>
    for(int i=0; i <= 1; i++) {
     vector<Wektor3D> plaszczyzna;
     for (int j=0; j <= 1; j++){
       for (int k=0; k<=1; k++){
	 plaszczyzna.push_back(Wektor3D(i*x, j*y, k*z));
       }
     }
     wierzcholki.push_back(plaszczyzna);
    }
  }
  void rysuj();
};
#endif
