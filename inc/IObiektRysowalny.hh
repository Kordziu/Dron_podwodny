#ifndef IOBIEKT_RYSOWALNY_HH
#define IOBIEKT_RYSOWALNY_HH
#include "Dr3D_gnuplot_api.hh"


class IObiektRysowalny {
protected:
  std::shared_ptr<drawNS::Draw3DAPI> Obiekt;
public:
  IObiektRysowalny(drawNS::Draw3DAPI * obiekt): Obiekt(obiekt){}
  virtual void rysuj() = 0;
  virtual ~IObiektRysowalny(){}
};
#endif
