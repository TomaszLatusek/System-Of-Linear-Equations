#include <iostream>
#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */

int main()
{
  // SystemOfLinearEquations system; // To tylko przykladowe definicje zmiennej
  Vector v1, v2;
  Matrix m;
  double d = 2.5;

  cout << endl
       << " Start programu " << endl
       << endl;

// cout << "Vector test" << endl;
// cin >> v1;
// cin >> v2;
// cout << "v1 + v2 = " << v1 + v2 << endl;
// cout << "v1 - v2 = " << v1 - v2 << endl;
// cout << "v1 * v2 = " << v1 * v2 << endl;
// cout << "v1 * 2,5 = " << v1 * d << endl;
// cout << "v1 / 2,5 = " << v1 / d << endl;
  cin >> m;
  cout << m;
}
