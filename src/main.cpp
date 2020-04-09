#include <iostream>
#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"

using namespace std;


int main()
{
  SystemOfLinearEquations system;
  Matrix m;

  cout << endl
       << " Start programu " << endl
       << endl;

  // cin >> system;
  // cout << system << endl;

  // system.solve();
  // system.showSolution();

  cin >> m;
  cout << m << endl;
  m[0][2] = 0;
  cout << m << endl;
}
