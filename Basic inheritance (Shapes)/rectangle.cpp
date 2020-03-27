/*
 * rectangle.cpp
 *
 *  Created on: 10 lut 2020
 *      Author: mg992
 */

#include "rectangle.h"

Rectangle::Rectangle(): _a(0), _b(0){}

Rectangle::Rectangle(int a, int b): _a(a), _b(b){}

void Rectangle::print(std::ostream &out) const {
	std::cout<<"Prostok¹t o bokach: "<< _a <<" " << _b << "\n";
}

double Rectangle::area() const{
	return _a*_b;
}



