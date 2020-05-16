#ifndef IOBIEKT_RYSOWALNY_HH
#define IOBIEKT_RYSOWALNY_HH
#include "Dr3D_gnuplot_api.hh"


class IObiektRysowalny {
protected:
  std::shared_ptr<drawNS::Draw3DAPI> Obiekt;
  double index; //zmienna do przechowywania indexu bryly, zeby moc uzyc metody erase
public:
  IObiektRysowalny(drawNS::Draw3DAPI * obiekt): Obiekt(obiekt){}
  virtual void rysuj() = 0;
  virtual ~IObiektRysowalny(){}
  void usun(){Obiekt->erase_shape(index);}
};
#endif
