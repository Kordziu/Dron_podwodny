#include <iostream>
#include "Bryla.hh"
#include "IObiektRysowalny.hh"
#include "Prostopadloscian.hh"
#include "Wektor.hh"
#include "Dron.hh"

using namespace std;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != 'n');
}

void interfejs_drona()
{
  cout << endl << "wybierz opcję" << endl;
  cout << "r - ruch drona"<< endl;
  cout << "o - obrot drona" << endl;
  cout << "k - koniec programu" << endl;
}

int main()
{  
  drawNS::APIGnuPlot3D * Obiekt = new drawNS::APIGnuPlot3D(-20,20,-20,20,-20,20,-1);
  SWektor<double,3> tab[8];
  SWektor<double,3> srod; // domyslnie 0 0 0
  MacierzOb orient; // domyslnie jednostkowa
  char wybor;
  double droga;
  double kat;
  
  for(int i = 0; i < 8; i++)
    {
      cin >> tab[i];
    };
  Dron D(Obiekt, tab, srod, orient);
  D.rysuj();

  do
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
	cout << "Program zostanie zamknięty" <<endl;
      default:
	cerr << "Opcja spoza menu";
      }
    }while(wybor!='k');
  
return 0;
}

