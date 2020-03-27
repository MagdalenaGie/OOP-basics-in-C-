/*
 * triangle.cpp
 *
 *  Created on: 10 lut 2020
 *      Author: mg992
 */
#include "triangle.h"
#include <math.h>

Triangle::Triangle(): _a(0), _b(0), _c(0){}

Triangle::Triangle(int a, int b, int c): _a(a), _b(b), _c(c){}

void Triangle::print(std::ostream &out) const {
	out<<"Trójk¹t o bokach: "<< _a <<" " << _b <<" "<< _c << "\n";
}

double Triangle::area() const{
	double x=0.5 * (_a + _b + _c);
	return sqrt(x*(x-_a)*(x-_b)*(x-_c));
}


