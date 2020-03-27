/*
 * SmartPointer.cpp
 *
 *  Created on: 3 mar 2020
 *      Author: mg992
 */

#include "SmartPointer.h"
#include <iostream>

SmartPointer::SmartPointer(TestClass *wsk){
	licznik = new int(1);
	wskaznik = wsk;
}

SmartPointer::SmartPointer(SmartPointer& ptr){
	(*(ptr.licznik))++;
	licznik = ptr.licznik;
	wskaznik = ptr.wskaznik;
}

SmartPointer::~SmartPointer(){
	(*licznik)--;
	if(licznik==0){
		delete licznik;
		delete &wskaznik;
		std::cout<<"f1";
	}
}

SmartPointer& SmartPointer::operator=(SmartPointer& nowy){
	if(this==&nowy)
		return *this;
	(*licznik)--;
	if(licznik==0){
		delete licznik;
		delete &wskaznik;
		std::cout<<"f2";
	}
	delete licznik;
	delete &wskaznik;
	(*(nowy.licznik))++;
	licznik = nowy.licznik;
	wskaznik = nowy.wskaznik;
	return *this;
}

TestClass& SmartPointer::operator*(){
	return *wskaznik;
}

TestClass* SmartPointer::operator->(){
	return wskaznik;
}

