#include <iostream>
#include <fstream>
#include "Bryla.hh"
#include "IObiektRysowalny.hh"
#include "Prostopadloscian.hh"
#include "Wektor.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"

using namespace std;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != 'n');
}

void interfejs_drona()
{
  cout << "\nwybierz opcję" << endl;
  cout << "r - ruch drona"<< endl;
  cout << "o - obrot drona" << endl;
  cout << "k - koniec programu" << endl;
}

int main()
{
  drawNS::APIGnuPlot3D * Obiekt = new drawNS::APIGnuPlot3D(-30,30,-30,30,-30,35,-1);
  SWektor<double,3> tab[8];
  SWektor<double,3> tab_wir[12];
  SWektor<double,3> tab_woda[49];
  SWektor<double,3> tab_dno[49];
  SWektor<double,3> srod; // domyslnie 0 0 0
  MacierzOb orient; // domyslnie jednostkowa
  char wybor;
  double droga;
  double kat;
  ifstream plik;

  // Wczytanie wektorów dna
  plik.open("dno.dat");
  for(int i = 0; i < 49; i++)
    {
      plik >> tab_dno[i];
    };
  plik.close();
  // Wczytanie wektorów tafli wody
  plik.open("Woda.dat");
  for(int i = 0; i < 49; i++)
    {
      plik >> tab_woda[i];
    };
  plik.close();
  // Wczytanie wektorów korpusu drona
  plik.open("data.dat");
  for(int i = 0; i < 8; i++)
    {
      plik >> tab[i];
    };
  plik.close();
  // Wczytanie wektorów wirników
  plik.open("datawir.dat");
    for(int i = 0; i < 12; i++)
    {
      plik >> tab_wir[i];
    };
  plik.close();

  //Narysowanie dna, tafli wody i drona
  Plaszczyzna dno(Obiekt, tab_dno);
  Plaszczyzna woda(Obiekt,tab_woda);
  dno.rysuj();
  woda.rysuj();
  Dron D(Obiekt, tab, tab_wir, srod, orient);
  D.rysuj();
  
	  while(wybor!='k')
	    {
	      interfejs_drona();
	      cin >> wybor;
	      switch(wybor)
		{
		case 'r':
		  cout << "Podaj odleglosc na jaką ma polecieć dron: ";
		  cin >> droga;
		  cout << "\nPodaj kąt pod jakim dron ma polecieć: ";
		  cin >> kat;
		  D.ruch(droga, kat);
		  break;
		case 'o':
		  cout << "Podaj kąt o jaki ma się obrócić dron: ";
		  cin >> kat;
		  D.obrot(kat);
		  break;
		case 'k':
		  cout << "Program zostanie zamknięty" << endl;
		  exit(1);
		default:
		  cerr << "Opcja spoza menu";
		}
	    };
	  
	  return 0;
}


