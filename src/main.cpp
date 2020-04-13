#include <iostream>
#include "Vector.hh"
#include "Matrix.hh"
#include "SystemOfLinearEquations.hh"

using namespace std;

int main()
{
  SystemOfLinearEquations system;

  cout << endl
       << " Start programu " << endl
       << endl;

  cin >> system;
  cout << system << endl;

  system.solve();            //wylicz uklad
  system.showSolution();     //pokaz wynik
  cout << endl;
  system.countErrorVector(); //oblicz blad
  system.showErrorVector();  //pokaz blad

  return 0;
}
