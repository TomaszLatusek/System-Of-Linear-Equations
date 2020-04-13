#pragma once

#include "Size.hh"
#include <iostream>


class Vector
{
  /* wspolrzedne wektora */
  double coordinates[SIZE];

public:
/* przeciazenia operatorow dzialan na wektorach */
  Vector operator+(Vector vec2) const;
  Vector operator-(Vector vec2) const;
  double operator*(Vector vec2) const;
  Vector operator*(double arg);
  Vector operator/(double arg);
/* przeciazenia nawiasow do indeksowania */
  const double &operator[](int index) const;
  double &operator[](int index);
/* przeciazenia operatorow "strumieniowych" */
  friend std::istream &operator>>(std::istream &stream, Vector &vec);
  friend std::ostream &operator<<(std::ostream &stream, const Vector &vec);
/* dlugosc wektora */
  double length() const;
};

