/*
 * SmartPointer.h
 *
 *  Created on: 3 mar 2020
 *      Author: mg992
 */

#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_
#include <iostream>
struct TestClass;

class SmartPointer{
private:
	TestClass *wskaznik;
	int* licznik;
public:
	SmartPointer(TestClass *);
	SmartPointer(SmartPointer&);
	~SmartPointer();
	SmartPointer& operator=(SmartPointer&);
	TestClass& operator*();
	TestClass* operator->();
};




#endif /* SMARTPOINTER_H_ */
