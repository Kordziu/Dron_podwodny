#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

class Dron;

class Przeszkoda
{
public:
  virtual ~Przeszkoda() {}
  virtual void rysuj() = 0;
  virtual bool czy_kolizja(const Dron & dron)const = 0;
};

#endif
