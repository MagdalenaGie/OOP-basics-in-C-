#include "numbers.h"

polish::polish(int a):x(a){}

float polish::operator,(float b){
  while(b/10.>1)
    b/=10.;
  b/=10.;
  return x+b;
}
