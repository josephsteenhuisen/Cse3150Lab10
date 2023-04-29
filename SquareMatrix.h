#ifndef __MATRIX_H
#define __MATRIX_H

#include <iostream>
#include <vector>

#include "BigInt.hpp"
#include "Pair.cpp"

using namespace std;

/*
  All matrices are square!
 */



struct SquareMatrix {

  SquareMatrix();

  vector<vector<Pair<BigInt>>> BuildIdentityMatrix(int size);
  void zeroMatrix(vector<vector<Pair<BigInt>>> matrix, int s);
  //vector<vector<Pair<BigInt>>> matrix;

  vector<vector<Pair<BigInt>>> MatrixMult(vector<vector<Pair<BigInt>>> & left_matrix, 
                          vector<vector<Pair<BigInt>>> & right_matrix);
  void BuildVectorOfVectors(int rows_cols);
  vector<vector<Pair<BigInt>>> getVectorOfVectors(int rows_cols);
};


#endif
