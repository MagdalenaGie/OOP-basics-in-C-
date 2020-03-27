/*
 * circle.h
 *
 *  Created on: 10 lut 2020
 *      Author: mg992
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include "shape.h"

class Circle: public Shape{
private:
	int _r;
public:
	Circle();
	Circle(int);
	void print(std::ostream &out) const override;
	double area() const override;
};

#endif /* CIRCLE_H_ */
