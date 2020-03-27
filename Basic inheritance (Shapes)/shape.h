/*
 * shape.h
 *
 *  Created on: 25 lut 2020
 *      Author: mg992
 */

#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>

class Shape{
public:
	virtual void print(std::ostream &out) const{}
	virtual double area()const {return 0.0;}
	virtual ~Shape()=default;
	Shape()=default;
};

void print(const Shape & p);

#endif /* SHAPE_H_ */
