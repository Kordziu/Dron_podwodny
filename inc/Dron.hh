#ifndef DRON_HH
#define DRON_HH

#include <iostream>
#include "Prostopadloscian.hh"
#include "Wirnik.hh"
#include "Przeszkoda.hh"

using namespace std;

/*!
 * \file Dron.hh
 * Plik zawiera klasę oraz funkcje drona
 */

/*!
 * \brief Dron
 * Klasa reprezentuje drona złożonego z prostopadłościanu (korpusu) i dwóch graniastosłupów sześciokątnych (wirników)
 */
class Dron : public Prostopadloscian, public Przeszkoda{
protected:
  /*!
   * \brief Wirniki drona
   */
  double promien;
  Wirnik wirnik1;
  Wirnik wirnik2;
public:
  /*!
   * \brief Konstruktor drona
   * \param Obiekt - okno gnuplota (scena)
   * \param tab8 - tablica wierzchołków korpusu drona
   * \param tab12 - tablica wierzchołków wirników
   * \param srodek - srodek drona
   * \param m1 - macierz orientacji drona
   */
  Dron(drawNS::APIGnuPlot3D * Obiekt, SWektor<double,3> *tab8, SWektor<double,3> *tab12, SWektor<double,3> srodek, MacierzOb &m1): Prostopadloscian(Obiekt, tab8, srodek, m1), wirnik1(Obiekt, tab12, srodek, m1), wirnik2(Obiekt, tab12, srodek, m1)
  {
    promien = 5;
  };
  
  double zwroc_promien()const {return promien;};

  SWektor<double,3> zwroc_srodek()const {return srodek;};
  /*!
   * \brief Animowana funkcja ruchu
   * \param odleglosc - Odległość na jaką ma polecieć dron
   * \param kat = Kąt pod jakim ma polecieć dron (w stopniach)
   */
  void ruch(double odleglosc, double kat)
  {
    double radian = (3.14 * kat) / 180;
    double t_ruchu[3]; //Tablica do wektora ruchu
    double kat_wirnika = 15; //(3.14 * 15) / 180;
    t_ruchu[2] = odleglosc * sin(radian); //Przesunięcie w kier x
    t_ruchu[1] = 0;                       //Przesunięcie w kier y
    t_ruchu[0] = odleglosc * cos(radian); //Przesunięcie w kier z
    SWektor<double, 3> w_ruchu(t_ruchu);
    
    w_ruchu = w_ruchu / 200;
    //for(int i = 0; i < 200; i++)
    //{
	Obiekt->erase_shape(index);
	srodek = srodek + (orientacja * w_ruchu);
	wirnik1.usun();
	wirnik2.usun();
	wirnik1.obrot_wir(kat_wirnika); //Obrót wirnika wokół własnej osi
	wirnik2.obrot_wir(kat_wirnika); //Obrót wirnika wokół własnej osi

	rysuj();
	//}    
  };

  /*!
   * \brief Animowana funkcja obrotu drona
   * \param kat - Kąt o jaki ma obrócić się dron wokół osi OZ
   */
  void obrot(double kat) //wokół osi OZ
  {   
    
    double kat_wirnika = 15;
	wirnik1.usun();
	wirnik2.usun();
	wirnik1.obrot(kat); //Obrót wirnika razem z dronem
	wirnik2.obrot(kat); //Obrót wirnika razem z dronem
	wirnik1.obrot_wir(kat_wirnika); //Obrót wirnika wokół własnej osi
	wirnik2.obrot_wir(kat_wirnika); //Obrót wirnika wokół własnej osi
	Prostopadloscian::obrot(kat);
	rysuj();
  };

  /*!
   * \brief Funkcja odpowiadająca za rysowanie drona
   */
  
  void rysuj()
  {
    wirnik1.rysuj(srodek + orientacja * ((wierzcholki[0] + wierzcholki[4]) * 0.5)); //narysowanie wirnika ze środkiem na połowie długości tylnej krawędzi drona
    wirnik2.rysuj(srodek + orientacja * ((wierzcholki[3] + wierzcholki[7]) * 0.5)); //narysowanie wirnika ze środkiem na połowie długości tylnej krawędzi drona
    Prostopadloscian::rysuj();
  };
  
  bool czy_kolizja(const Dron & dron)const
  {
    if(srodek == dron.zwroc_srodek())
      {return false;}
    else
      {
	if((srodek - dron.zwroc_srodek()).dlugosc() < promien + dron.zwroc_promien())
	  {
	    cout << "Zatrzymanie - kolizja z dronem\n";
	    return true;
	  }
	return false;
      }
	return false;
      
  };
 
};
#endif
