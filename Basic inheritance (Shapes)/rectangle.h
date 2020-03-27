
#include <iostream>
#include "shape.h"

class Rectangle: public Shape{
private:
	int _a;
	int _b;
public:
	Rectangle();
	Rectangle(int, int);
	void print(std::ostream &out) const override;
	double area() const override;
};


