#include <iostream>
#include "Matrix.h"

using namespace std;
typedef unsigned int uint;

Matrix::Matrix(uint rows = 0, uint cols = 0) {

  rowCount = rows;
  colCount = cols;
  
  sheet = new double * [rowCount];
  for(uint i = 0; i < rowCount; i++) {
    sheet[i] = new double [colCount];

  }

  for(uint r = 0; r < rowCount; r++ ) {
    for(uint c = 0; c < colCount; c++) {
      sheet[r][c] = 0;
    }
  }
  
}

Matrix::Matrix(double** values, int w, int h) {
  
  for(int i = 0; i < w; i++) {
    for(int j = 0; j < h; j++) {
      sheet[w][h] = values[w][h];
    }
  }
  

}

Matrix::Matrix(const Matrix & m) : Matrix::Matrix(m.numRows(), m.numCols()) {
  
  for(uint i = 0; i < rowCount; i++) {
    for(uint j = 0; j < colCount; j++) {
      sheet[i][j] = m.at(i,j);

    }
  }
}

Matrix::~Matrix() {
  
  for(uint i = 0; i < rowCount; i++) {
    delete[] sheet[i];

  }
  delete[] sheet;
  
}

Matrix Matrix::add(double s) const {

  Matrix addMatrix(*this);
  for(uint i = 0; i < rowCount; i++) {
    for(uint j = 0; j < colCount; j++) {
      addMatrix.at(i,j) = addMatrix.at(i,j) + s;
    }
    
  }
  return addMatrix;


}


Matrix Matrix::add(const Matrix & m) const {

  Matrix addedMatrix(*this);
  for(uint i = 0; i < rowCount; i++) {
    for(uint j = 0; j < colCount; j++) {
      addedMatrix.at(i,j) = addedMatrix.at(i,j) + m.at(i,j);
    }
  }
  return addedMatrix;

}

Matrix Matrix::subtract(double s) const {

  Matrix subtractMatrix(*this);
  for(uint i = 0; i < rowCount; i++) {
    for(uint j = 0; j < colCount; j++) {
      subtractMatrix.at(i,j) = subtractMatrix.at(i,j) - s;

    }
  }
  return subtractMatrix;


}

Matrix Matrix::subtract(const Matrix & m) const {

  Matrix subtractedMatrix(*this);
  for(uint i = 0; i < rowCount; i++) {
    for(uint j = 0; j < colCount; j++) {
      subtractedMatrix.at(i,j) = subtractedMatrix.at(i,j) - m.at(i,j);
    }
  }
  return subtractedMatrix;
  
}

Matrix Matrix::multiply(double s) const {

  Matrix multiplyMatrix(*this);
  for(uint i = 0; i < rowCount; i++) {
    for(uint j = 0; j < colCount; j++) {
      multiplyMatrix.at(i,j) = multiplyMatrix.at(i,j) * s;
    }
  }
  return multiplyMatrix;


}

Matrix Matrix::multiply(const Matrix & m) const {

  if(this->colCount == m.numRows()) {

    Matrix multiMatrix(*this);
    double sum;

    for(uint i = 0; i < multiMatrix.numRows(); i++) {
      for(uint j = 0; j < multiMatrix.numCols(); j++) {
	sum = 0;

	for(uint k = 0; k < colCount; k++) {
	  sum = sum + at(i,k) * m.at(k,j);
	}

	multiMatrix.at(i, j) = sum;

      }
    }

    return multiMatrix;

  } else {
    Matrix multiMatrix(0,0);
    return multiMatrix;
  }
  
}

Matrix Matrix::divide(double s) const {

  Matrix divideMatrix(*this);
  for(uint i = 0; i < rowCount; i++) {
    for(uint j = 0; j < colCount; j++) {
      divideMatrix.at(i,j) = divideMatrix.at(i,j) / s;
    }
  }
  return divideMatrix;

}

Matrix Matrix::t() const {

  Matrix transMatrix(*this);
  for(uint i = 0; i < transMatrix.numRows(); i++) {
    for(uint j = 0; j < transMatrix.numCols(); j++) {
      transMatrix.at(j,i) = at(i,j);

    }
  }

  return transMatrix;


}

const uint Matrix::numRows() const {

  return this->rowCount; 

}

const uint Matrix::numCols() const {

  return this->colCount;

}

double & Matrix::at(uint row, uint col) {

  return this->sheet[row][col];


}

const double & Matrix::at (uint row, uint col) const {

  return this->sheet[row][col];

}

double& Matrix::operator()(uint row, uint col) {

  return this->at(row,col);

}

Matrix& Matrix::operator=(const Matrix & m) {

    
  for(uint i = 0; i < rowCount; i++) {
    delete[] sheet[i];

  }
  delete[] sheet;

  this->rowCount = m.numRows();
  this->colCount = m.numCols();

  this->sheet = new double*[this->rowCount];

  for(uint i = 0; i < this->rowCount; i++) {
    this->sheet[i] = new double [this->colCount];
    
    for(uint j = 0; j < this->colCount; j++) {
	this->at(i,j) = m.at(i,j);
      }

  }

  return *this;

}

Matrix operator+(const Matrix & m, double r) {

  Matrix addMatrix = m.add(r);
  return addMatrix;
}

Matrix operator+(double l, const Matrix & m) {

  Matrix addMatrix = m.add(l);
  return addMatrix;

}

Matrix operator+(const Matrix & m, const Matrix & n) {

  Matrix addMatrix = m.add(n);
  return addMatrix;
}

Matrix operator-(const Matrix & m, double r) {

  Matrix subMatrix = m.subtract(r);
  return subMatrix;
}

Matrix operator-(double l, const Matrix & m) {

  Matrix subMatrix = m.subtract(l);
  return subMatrix;
}

Matrix operator-(const Matrix & m, const Matrix & n) {

  Matrix subMatrix = m.subtract(n);
  return subMatrix;
}

Matrix operator*(const Matrix & m, double r) {

  Matrix mulMatrix = m.multiply(r);
  return mulMatrix;
}

Matrix operator*(double l, const Matrix & m) {

  Matrix mulMatrix = m.multiply(l);
  return mulMatrix;

}

Matrix operator*(const Matrix & m, const Matrix & n) {

  Matrix mulMatrix = m.multiply(n);
  return mulMatrix;
}

Matrix operator/(const Matrix & m, double r) {

  Matrix divMatrix = m.divide(r);
  
  if(r == 0) { 
    for(uint i = 0; i < m.numRows(); i++) {
      for(uint j = 0; j < m.numCols(); j++) {
	divMatrix.at(i,j) = m.at(i,j);

      }
    }
  }


  return divMatrix;

}
Matrix operator/(double l, const Matrix & m) {

  Matrix divMatrix(m.numRows(),m.numCols());

  bool containsZero = false;
  
  for(uint i = 0; i < m.numRows(); i++) {
    for(uint j = 0; j < m.numCols(); j++) {

      if(m.at(i,j) == 0) {
	containsZero = true;
	break;

      } else {

	divMatrix.at(i,j) = l / m.at(i,j);

      }
    } if(containsZero == true) {
      break;
    }
  }
   if(containsZero == true) {
      Matrix noChange(m);
      return noChange;

   } else {

      return divMatrix;
   }
  
}


ostream& operator<<(ostream& display, const Matrix & m) {

  for(uint i = 0; i < m.numRows(); i++) {
    display << "[ ";
 
      for(uint j = 0; j < m.numCols(); j++) {
	if(j != m.numCols()-1) {
	  display << m.at(i,j) << ", ";
	  
	} else {
	  display << m.at(i,j) << " ";
	  
	}
      }

    display << "]" << endl;
  }

  display << endl;

  return display;
}
