#include "Pair.h"



template<typename T>
Pair<T>::Pair(T _top, T _bottom) : top(_top), bottom(_bottom) {
}

/*
  BigInt, bigint have gcd functions of their own
  
  This gcd function assumes the numerator and denominator are the same type  
 *
 */
template<typename T>
T Pair<T>::gcd(T a, T b) {
  const T zero = 0;
  if (b == zero) {
    return a;
  } else {
    return gcd(b, a % b);
  }
 }

template<typename T>
ostream & operator<<(ostream & os, Pair<T> p) {
  os << "<" << p.top << "/" << p.bottom << ">" << endl;
  return os;
}

template<typename T>
Pair<T>::Pair(const Pair<T> & p) {
  top = p.top;
  bottom = p.bottom;
}

template<typename T>
Pair<T> & Pair<T>::operator=(const Pair<T> & right) {
  top = right.top;
  bottom = right.bottom;

  return *this;
}
template<typename T>
Pair<T> & Pair<T>::operator*(const Pair<T> & right) {
  top *= right.top;
  bottom *= right.bottom;

  T g = gcd(top,bottom);
  top /= g;
  bottom /= g;

  return *this;
}

template<typename T>
Pair<T> & Pair<T>::operator+(const Pair<T> & right) {
  top = top* right.bottom + bottom* right.top;
  bottom = bottom * right.bottom;

  T g = gcd(top,bottom);
  top /= g;
  bottom /= g;
  
  return *this;
}

template<typename T>
Pair<T> & Pair<T>::operator+=(const Pair<T> & right) {
  top = top* right.bottom + bottom* right.top;
  bottom = bottom * right.bottom;

  T g = gcd(top,bottom);
  top /= g;
  bottom /= g;

  return *this;
}

template<typename T>
bool Pair<T>::operator==(const Pair<T> & right) {
  return top == right.top && bottom == right.bottom;
}



