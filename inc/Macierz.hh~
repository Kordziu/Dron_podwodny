#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <iostream>

using namespace std;

template <typename Styp, int Swymiar>
class Macierz{
  SWektor<Styp, Swymiar> tab[Swymiar];

public:
  /////////////// Konstruktory ///////////////
  Macierz()
  {for (int i = 0; i < Swymiar; i++){tab[i] = SWektor<Styp, Swymiar>();}};
  Macierz(SWektor<Styp, Swymiar> *w1)
  {for(int i = 0; i < Swymiar; i++){tab[i] = w1[i];}}; 
  Macierz(const Macierz &m)
  {for(int i = 0; i < Swymiar; i++){tab[i] = m[i];}};

  /////////////// Transpozycja ///////////////
  Macierz transpozycja() const
  {
    SWektor<Styp, Swymiar> kolumna;
    Macierz temp;
      for(int i = 0; i < Swymiar; i++)
      {
        kolumna = zwroc_kolumne(i);
        temp[i] = kolumna;
      }
    return temp;
  };

  /////////////// Odwrotnosc ///////////////
  // const Macierz & odwrotnosc() const;
  //void odwrotnosc();
  
  /////////////// Macierz * Wektor ///////////////
  SWektor<Styp, Swymiar> operator * (const SWektor<Styp, Swymiar> w1) const
  {
    SWektor<Styp, Swymiar> wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        wynik[i] = tab[i] * w1;
      }
      return wynik; 
  };

  /////////////// Macierz * Macierz ///////////////
  Macierz operator * ( Macierz m1) const
  {
    Macierz wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        for(int j=0; j < Swymiar; j++)
	{
          wynik[i][j] = tab[i] * m1.zwroc_kolumne(j);
        }
      }
    return wynik;
  };
  
  /////////////// Macierz + Macierz ///////////////
  Macierz operator + (const Macierz m1) const
  {
    Macierz wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        for(int j = 0; j < Swymiar; j++)
	{
          wynik[i] = tab[i] + m1[i];
        }
      }
    return wynik;
  };
  
  /////////////// Macierz - Macierz ///////////////
  Macierz operator - (const Macierz m1) const
  {
    Macierz wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        for(int j = 0; j < Swymiar; j++)
        {
          wynik[i] = tab[i] - m1[i];
        }
      }
    return wynik;
  };
  
  /////////////// Macierz * liczba ///////////////
  Macierz operator * (const double liczba) const
  {
    Macierz wynik;
      for(int i = 0; i < Swymiar; i++)
      {
        wynik[i] = tab[i] * liczba;
      }
    return wynik;
  };
  
  /////////////// Przeciążenie operatorów == != ///////////////
  bool operator == (const Macierz & m1) const
  {
    for(int i = 0; i < Swymiar; i++)
    {
      if(tab[i] != m1[i])
      {
	return false;
      }
    }
    return true;
  };
  
  bool operator != (const Macierz & m1) const
  {
    if(*this == m1)
      {
        return false;
      }
    return true;
  };
  
  /////////////// Przeciążenia [] ///////////////
  const SWektor<Styp, Swymiar> & operator[] (int index) const
  {
    if (index < 0 || index >= Swymiar)
    {
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  };
  
  SWektor<Styp, Swymiar> & operator[] (int index) // M[2][0]-[Wektor][Element]
  {
    if (index < 0 || index >= Swymiar)
    {
      cerr << "Wartość spoza zakresu" << endl;
      exit(1);
    }
    return tab[index];
  };
  
  /////////////// Zwracanie i zmiana kolumny ///////////////
  SWektor<Styp, Swymiar> zwroc_kolumne(int nr_kolumny) const //dla wierszowej
  {
    SWektor<Styp, Swymiar> kolumna;
      for(int i = 0; i < Swymiar; i++)
      {
        kolumna[i] = tab[i][nr_kolumny];
      }
    return kolumna;
  };
  
  Macierz zmien_kolumne(int nr_kolumny, SWektor<Styp, Swymiar> nowa)
  {
    Macierz pom;
    pom = transpozycja();
    pom[nr_kolumny] = nowa;
    pom = pom.transpozycja();
    return pom;
  };
  
  //////////// Iloczyn liczb na przekątnej macierzy ////////////
  Styp przekatna() const
  {
    Styp wynik;
    wynik = 1;
      for(int i = 0; i < Swymiar; i++)
      {
        wynik = wynik * tab[i][i];
      }
    return wynik;	
  };

  /////////////// Wyznacznik z gaussa ///////////////
  Styp wyznacznik() const
  {
    int licznik = 0; //ile razy zamieniliśmy wiersze
    Macierz pom(*this); //stworzenie kopii żeby nie zmieniać obiektu
    Styp wynik;
    
    for(int i = 0; i < Swymiar - 1; i++)
      {
        for(int j = i+1; j < Swymiar; j++)
	  {
	    if(pom[i][i] != 0.0){
	      Styp val = pom[j][i] / pom[i][i];//zmienna do ustalenia wartości przez którą będziemy mnożyć wiersz który będzie odejmowany
	      pom[j] = pom[j] - pom[i] * val;//wyzerowanie punktu	
	    }
	    else
	      {
		for(int k = i + 1; k < Swymiar; k++)//szukanie zera
		  { 	
		    if(pom[k][i] != 0.0)//Jeśli nie jest zerem
		      {
			swap(pom[i], pom[k]); // zamień wiersze
			licznik++; //zwiększ licznik
			k = Swymiar; //wyjście z pętli
		      }
		  }
	      }
	  }
      }
	wynik = pom.przekatna(); //wyliczenie wyznacznika z wartości na przekątnej macierzy trójkątnej
    wynik = wynik * pow(-1, licznik%2); //jeśli licznik jest jest parzysty to nasz wyznacznik mnożymy przez -1^0 czyli *1 i nic się nie zmienia, jeśli jest nieparzysty to zmienia się znak wyznacznika

   return wynik;
  };

}; //koniec klasy

template<typename Styp, int Swymiar>
istream& operator >> (istream &is, Macierz<Styp, Swymiar> &m1)
{
  for(int i = 0; i < Swymiar; i++)
  {   
    is >> m1[i];
  }
  // m1.transpozycja();
  
  return is;
}

template<typename Styp, int Swymiar>
ostream& operator << (ostream &os, const Macierz<Styp, Swymiar> &m1)
{
  for(int i = 0; i < Swymiar; i++)
  {
    os << m1[i];
  }
  os << endl;
  return os;
}

#endif
