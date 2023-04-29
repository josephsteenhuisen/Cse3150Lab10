#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ranges>

#include "BigInt.hpp"
#include "split.h"
#include "SquareMatrix.h"
//#include "Pair.cpp" // contains a template


using namespace std;


ostream & operator<<(ostream & os, vector<vector<Pair<BigInt>>> & sm) {
  for (auto vv: sm) {
    for (auto v : vv) {
      os << v.top << "/" << v.bottom << " ";
    }
    os << endl;
  }  
  return os;
}


int main() {

  vector<vector<Pair<BigInt>>> matrix;
  
  ifstream file;
  file.open("data.squarematrix-two-rows.txt");

  string lineTop, lineBottom;;
  string s_rows, s_cols;

  while(getline(file,lineTop,'\n') && getline(file,lineBottom,'\n')) {
    if (lineTop != "") {
      vector<BigInt> vv_top    = split(lineTop, ' ');
      vector<BigInt> vv_bottom = split(lineBottom, ' ');
      vector<Pair<BigInt>> new_vector;
      for (auto top = vv_top.begin(), bottom = vv_bottom.begin() ; top != vv_top.end() ;
	 ++top, ++bottom) {
	      new_vector.push_back(Pair<BigInt>(*top,*bottom));		
	}
	matrix.push_back(new_vector);		
     }
  }

  cout << "Should be origonal: \n" << matrix << endl;
  
  SquareMatrix sm = SquareMatrix();

  vector<vector<Pair<BigInt>>> id_2x2 = sm.BuildIdentityMatrix(2);

  cout << "2x2 identity:\n" << id_2x2 << endl;

  vector<vector<Pair<BigInt>>> id_2x2a = sm.BuildIdentityMatrix(2);

  cout << "2x2a identity:\n" << id_2x2a << endl;

  vector<vector<Pair<BigInt>>> id_2x2_sq = sm.MatrixMult(id_2x2,id_2x2a);

  cout << "2x2 identity squared:\n" << id_2x2_sq << endl;

  
  return 0;
}

