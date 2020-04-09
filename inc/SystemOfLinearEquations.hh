#pragma once

#include <iostream>
#include "Vector.hh"
#include "Matrix.hh"
#include "Size.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class SystemOfLinearEquations
{
  Matrix matrix;
  Vector vector;
  Vector solution;

public:
/* przeciazenia operatorow "strumieniowych" */
friend std::istream &operator>>(std::istream &stream, 
                          SystemOfLinearEquations &system);
friend std::ostream &operator<<(std::ostream &stream,
                         const SystemOfLinearEquations &system);  
/* Metoda rozwiaujaca uklad rownan */
Vector solve() ;

void showSolution() const;
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */

