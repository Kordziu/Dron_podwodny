#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

class Wektor3D : public SWektor<double,3> {

  /////////////// Zamiana Wektora na Point3D ///////////////
  operator drawNS::Point3D() const
  {
    return drawNS::Point3D(data[0], data[1], data[3]);
  };
};

#endif
