#ifndef __PAIR_H_
#define __PAIR_H_


#include <iostream>
#include <utility>
#include "BigInt.hpp"


using namespace std;


template<typename T>
struct Pair {
  T top;
  T bottom;

  Pair<T>() { top = 0; bottom = 1; };
  Pair<T>(T top, T bottom);
  Pair<T>(const Pair<T> & p);
  Pair<T> & operator=(const Pair<T> & right);
  bool operator==(const Pair<T> & right);
  Pair<T> & operator+(const Pair<T> & right);
  Pair<T> & operator*(const Pair<T> & right);
  Pair<T> & operator+=(const Pair<T> & right);

  T gcd(T a, T b);

};


#endif

