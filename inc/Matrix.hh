#pragma once

#include "Size.hh"
#include <iostream>


class Matrix
{
  /* wyrazy macierzy kwadratowej o rozmiarze SIZE */
  double data[SIZE][SIZE];

public:
/* przeciazenia operatorow "strumieniowych" */
//nie jestem pewien czy to prawidlowa forma, ale jak dla mnie dziala
  friend std::istream &operator>>(std::istream &stream, Matrix &matrix);
  friend std::ostream &operator<<(std::ostream &stream, const Matrix &matrix);
};

