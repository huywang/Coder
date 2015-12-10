#include "stdafx.h"
class A {
public:
  A(int i) {}
private:
  int i_;
};

class B : public A {
public:
  B(int i, int j) : A(i), j_(j){}
private:
  int j_;
};