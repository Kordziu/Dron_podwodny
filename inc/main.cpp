#include <iostream>
#include <fstream>
#include "Bryla.hh"
#include "IObiektRysowalny.hh"
#include "Prostopadloscian.hh"
#include "Wektor.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"
#include "Przeszkoda_prosto.hh"

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
  SWektor<double,3> tab_prz[3][8];
  SWektor<double,3> tab_wir[12];
  SWektor<double,3> tab_woda[49];
  SWektor<double,3> tab_dno[49];
  SWektor<double,3> srod_drona[3]; // domyslnie 0 0 0
  SWektor<double,3> srod_przeszkod[3];
  MacierzOb orient; // domyslnie jednostkowa
  char wybor;
  int numer;
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

  // Wczytanie wektorów korpusów dronów i ich środków
  plik.open("data.dat");
  for(int i = 0; i < 8; i++)
    {
      plik >> tab[i];
    };
  for(int i = 0; i < 3; i++)
    {
      plik >> srod_drona[i];
    };
  // Wczytanie przeszkód
  for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 8; j++)
	{
	  plik >> tab_prz[i][j];
	};
    };
  for(int i = 0; i < 3; i ++)
    {
      plik >> srod_przeszkod[i];
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
  vector<shared_ptr<Dron>> nr_drona
  {
    make_shared<Dron>(Obiekt, tab, tab_wir, srod_drona[0], orient),
    make_shared<Dron>(Obiekt, tab, tab_wir, srod_drona[1], orient),
    make_shared<Dron>(Obiekt, tab, tab_wir, srod_drona[2], orient)
  };
  nr_drona[0]->rysuj();
  nr_drona[1]->rysuj();
  nr_drona[2]->rysuj();

  vector<shared_ptr<Przeszkoda_p>> nr_przeszkody
  {
    make_shared<Przeszkoda_p>(Obiekt, tab_prz[0], srod_przeszkod[0], orient),
      make_shared<Przeszkoda_p>(Obiekt, tab_prz[1], srod_przeszkod[1], orient),
      make_shared<Przeszkoda_p>(Obiekt, tab_prz[2], srod_przeszkod[2], orient)
      };
  nr_przeszkody[0]->rysuj();
  nr_przeszkody[1]->rysuj();
  nr_przeszkody[2]->rysuj();
  
	  while(wybor!='k' || numer!= 999)

	    {
	      cout << "Podaj numer drona, którym chcesz latać (0,1,2) lub wciśnij 999 aby zakończyć działanie programu\n";
	      cin >> numer;
	      if(numer != 999 )
		{
		  if(numer > -1 && numer < 3)
		    {
		      interfejs_drona();
		      cin >> wybor;
		      switch(wybor)
			{
			case 'r':
			  cout << "Podaj odleglosc na jaką ma polecieć dron: ";
			  cin >> droga;
			  cout << "\nPodaj kąt (w stopniach) pod jakim dron ma polecieć: ";
			  cin >> kat;
			  nr_drona[numer]->ruch(droga, kat);
			  break;
			case 'o':
			  cout << "Podaj kąt (w stopniach) o jaki ma się obrócić dron: ";
			  cin >> kat;
			  double dzielnik = abs(5*kat);

			  for(int i = 0; i < dzielnik; i++)
			    {
			      
			      nr_drona[numer]->obrot(kat/dzielnik);
			      for(int j = 0; j < 3; j++)
				{
				  if(nr_przeszkody[j]->czy_kolizja(*nr_drona[numer]))
				    {
				      break;
				    }
				}
			    }
			  break;
			case 'k':
			  cout << "Program zostanie zamknięty" << endl;
			  exit(1);
			  break;
			default:
			  cerr << "Opcja spoza menu";
			}
		    }
		  else
		    cout << "Nie ma takiego drona \n";
		}
	      else
		{
	        cout << "Program zostanie zamknięty" << endl;
	        exit(1);
		}
	    };
	  
	  return 0;
}


