/*
 * TestClass.h
 *
 *  Created on: 3 mar 2020
 *      Author: mg992
 */

#ifndef TESTCLASS_H_
#define TESTCLASS_H_
#include <iostream>
#include <string>

struct TestClass{
	std::string _nazwa;
	TestClass(std::string nazwa): _nazwa(nazwa){std::cout<<".. Konstruuje TestClass " << _nazwa<<"\n";}
	~TestClass(){std::cout<<".. Usuwam  TestClass " << _nazwa << "\n";}
	std::string name()const{return _nazwa;}
};




#endif /* TESTCLASS_H_ */
