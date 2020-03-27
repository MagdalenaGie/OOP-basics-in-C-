/*
 * circle.cpp
 *
 *  Created on: 10 lut 2020
 *      Author: mg992
 */

#include "circle.h"

Circle::Circle(): _r(0){}

Circle::Circle(int r): _r(r){}

void Circle::print(std::ostream &out) const{
	out<<"Kolo o promieniu "<< _r <<"\n";
}

double Circle::area() const {
	return _r*_r*3.14;
}
