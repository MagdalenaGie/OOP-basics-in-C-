#include "complexNumber.h"

ComplexNumber::ComplexNumber(): _a(0), _b(0), dynamic(false){}

ComplexNumber::ComplexNumber(int a, int b): _a(a), _b(b), dynamic(false){
  std::cout<<"Constructing "<< a <<"+"<<b<<"i"<<std::endl;
}

ComplexNumber::~ComplexNumber(){
  std::cout<<"Deleting: "<< _a <<"+"<<_b<<"i"<<"\n";
  if(dynamic)
    delete this;
}

int ComplexNumber::get_a(){
  return _a;
}

int ComplexNumber::get_b(){
  return _b;
}

void ComplexNumber::set_dynamic(){
  dynamic=true;
}

std::ostream & operator<<(std::ostream &out, ComplexNumber& x){
  out<<x.get_a()<<"+"<<x.get_b()<<"i";
  return out;
}

void* ComplexNumber::operator new(std::size_t rozmiar){
  return std::malloc(rozmiar);
}

void ComplexNumber::operator delete(void *wsk){
  free(wsk);
}

ComplexNumber* ComplexNumber::operator=(ComplexNumber* nowy){
  nowy->dynamic = true;
  std::cout<<"used = \n";
  return nowy;
}