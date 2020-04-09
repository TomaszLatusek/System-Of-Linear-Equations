#pragma once

#include "Size.hh"
#include <iostream>
#include "Vector.hh"


class Matrix
{
  /* macierz kwadratowa przedstawiona w postaci tablicy wektorow (kolumn)
   * SIZE wektorow SIZE-wymiarowych*/
  Vector data[SIZE];

public:
/* przeciazenia nawiasow do indeksowania */
  const Vector &operator[](int index) const;
  Vector &operator[](int index);

/* przeciazenia operatorow "strumieniowych" */
//nie jestem pewien czy to prawidlowa forma, ale jak dla mnie dziala
  friend std::istream &operator>>(std::istream &stream, Matrix &matrix);
  friend std::ostream &operator<<(std::ostream &stream, const Matrix &matrix);

/* obliczanie wyznacznika macierzy */
  double determinant() const;

};

