#include <iostream>
#include <string>
class ComplexNumber{
private:
  int _a;
  int _b;
  bool dynamic;
public:
  ComplexNumber();
  ComplexNumber(int, int);
  ~ComplexNumber();
  int get_a();
  int get_b();
  void set_dynamic();
  void* operator new(std::size_t);
  void operator delete(void *);
  std::string getdynamic(){if(dynamic) return "yes"; else return "no";}
  ComplexNumber* operator=(ComplexNumber*);
};

std::ostream& operator<<(std::ostream &out, ComplexNumber &x);