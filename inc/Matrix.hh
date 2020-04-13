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
  const double &operator()(int row, int column) const;
  double &operator()(int row, int column);
/* do wyciagania kolumn macierzy */
  Vector &operator[](int index);

/* przeciazenia operatorow "strumieniowych" */
  friend std::istream &operator>>(std::istream &stream, Matrix &matrix);
  friend std::ostream &operator<<(std::ostream &stream, const Matrix &matrix);

/* obliczanie wyznacznika macierzy */
  double determinant() const;
/* mnozenie macierzy przez wektor */
  Vector operator*(Vector vec) const;

};

