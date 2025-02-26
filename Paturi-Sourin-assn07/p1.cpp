#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;
typedef unsigned int uint;

void display(Matrix  m);

int main() {

  Matrix a(2,2);
  a.at(0,0) = 1;
  a.at(0,1) = 2;
  a.at(1,0) = 1;
  a.at(1,1) = 3;

  cout << a;
  
  Matrix b(2,1);
  b.at(0,0) = 3;
  b.at(1,0) = 2;

  cout << b;
  
  Matrix d (2,1);
  d.at(0,0) = 4;
  d.at(1,0) = 6;

  Matrix e = b - d;

  cout << e;

  Matrix f(2,2);
  f.at(0,0) = 2;
  f.at(0,1) = 4;
  f.at(1,0) = 6;
  f.at(1,1) = 8;

  Matrix g = f / 2.0;

  Matrix k = 2.0 / f;
  
  cout << "F: " << endl;
  cout << f;
  cout << g;
  k = g;
  cout << k;

  double pick = f(0,0);

  cout << "Picked number is: " << pick << endl;

  Matrix x = f * g;

  cout << x;
}

/*
void display(Matrix  m) {

  for(uint i  = 0; i < m.numRows(); i++) {

    cout << "[ ";
      
    for(uint j  = 0; j < m.numCols(); j++) {

      if(j != m.numCols()-1) {

	cout << m.at(i,j) << ", ";
      } else {
	cout << m.at(i,j) << " ";
      }
    }
    
    cout << "]" << endl;
  }
  cout << endl;

}

void display(const Matrix & m) {

  for(uint i  = 0; i < m.numRows(); i++) {

    cout << "[ ";
      
    for(uint j  = 0; j < m.numCols(); j++) {

      if(j != m.numCols()-1) {

	cout << m.at(i,j) << ", ";
      } else {
	cout << m.at(i,j) << " ";
      }
    }
    
    cout << "]" << endl;
  }
  cout << endl;
}
*/
