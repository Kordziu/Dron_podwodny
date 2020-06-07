#ifndef IOBIEKT_RYSOWALNY_HH
#define IOBIEKT_RYSOWALNY_HH
#include "Dr3D_gnuplot_api.hh"


class IObiektRysowalny {
protected:
  std::shared_ptr<drawNS::Draw3DAPI> Obiekt;
  double index; //zmienna do przechowywania indexu bryly, zeby moc uzyc metody erase
  static int liczba_obiektow;
  static int stworzone_obiekty;
public:
  IObiektRysowalny(drawNS::Draw3DAPI * obiekt): Obiekt(obiekt){liczba_obiektow++; stworzone_obiekty++;}
  IObiektRysowalny(IObiektRysowalny &o){liczba_obiektow++; stworzone_obiekty++;};
  static int zwroc_stworzone_obiekty(){return stworzone_obiekty;};
  static int zwroc_obiekty(){return liczba_obiektow;};
  virtual void rysuj() = 0;
  virtual ~IObiektRysowalny(){liczba_obiektow--;}
  void usun(){Obiekt->erase_shape(index);}
};
#endif
