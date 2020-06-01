#ifndef DNO_HH
#define DNO_HH
#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"

class Dno : public Plaszczyzna, public Przeszkoda
{
public:
  Dno(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> * tab): Plaszczyzna(Obiekt, tab){};
  
  bool czy_kolizja(const Dron & dron)const
  {
    for(int i = 0; i < 49; i++)
      {
	if((p[i] - dron.zwroc_srodek()).dlugosc() < dron.zwroc_promien())
	  {
	    cout << "Zatrzymanie - kolizja z dnem\n";
	    return true;
	  }
      }
    return false;
  }

  void rysuj()
     {
    index = Obiekt->draw_surface(vector<vector<drawNS::Point3D>> {
	{p[0],p[1],p[2],p[3],p[4],p[5],p[6]},
	{p[7],p[8],p[9],p[10],p[11],p[12],p[13]},
	{p[14],p[15],p[16],p[17],p[18],p[19],p[20]},
	{p[21],p[22],p[23],p[24],p[25],p[26],p[27]},
	{p[28],p[29],p[30],p[31],p[32],p[33],p[34]},
	{p[35],p[36],p[37],p[38],p[39],p[40],p[41]},
	{p[42],p[43],p[44],p[45],p[46],p[47],p[48]}
        //{p[48],p[49],p[50],p[51],p[52],p[53],p[54],p[55]},
        //{p[56],p[57],p[58],p[59],p[60],p[61],p[62],p[63]},
        //{p[64],p[65],p[66],p[67],p[68],p[69],p[70],p[71]},
	//{p[72],p[73],p[74],p[75],p[76],p[77],p[78],p[79]}
        }, "grey");
    
    Obiekt->redraw();
  };
  
};


#endif
