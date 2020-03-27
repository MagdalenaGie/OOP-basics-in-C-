/*
 * triangle.h
 *
 *  Created on: 10 lut 2020
 *      Author: mg992
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include "shape.h"

class Triangle: public Shape{
private:
	int _a;
	int _b;
	int _c;
public:
	Triangle();
	Triangle(int, int, int);
	void print(std::ostream &out) const override;
	double area() const override;
};

#endif /* TRIANGLE_H_ */
