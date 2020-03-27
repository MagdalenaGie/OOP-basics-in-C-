/*
 * InfoSmartPtr.h
 *
 *  Created on: 18 mar 2020
 *      Author: mg992
 */

#ifndef INFOSMARTPTR_H_
#define INFOSMARTPTR_H_
#include <iostream>
#include "InfoClass.h"

struct InfoClass;

class InfoSmartPtr{
private:
	InfoClass *ptr;
	int* counter;
public:
	InfoSmartPtr(InfoClass*);
	~InfoSmartPtr();
	InfoClass& operator*()const;
	InfoSmartPtr& operator=(InfoSmartPtr&);
	InfoClass* operator->()const;
	void counter_up();
	void counter_down();
};

InfoSmartPtr::InfoSmartPtr(InfoClass* p){
	ptr = p;
	counter = new int(1);
}

InfoSmartPtr::~InfoSmartPtr(){
	if(*counter<=1){
		delete ptr;
		delete counter;
	}
}

InfoClass& InfoSmartPtr::operator*()const{
	return *ptr;
}

InfoSmartPtr& InfoSmartPtr::operator=(InfoSmartPtr& nowy){
	counter_down();
	delete this;
	ptr = nowy.ptr;
	counter = nowy.counter;
	nowy.counter_up();
	return *this;
}

void InfoSmartPtr::counter_up(){
	*counter = *counter +1;
}

void InfoSmartPtr::counter_down(){
	*counter = *counter -1;
}

InfoClass* InfoSmartPtr::operator->()const{
	return ptr;
}

#endif /* INFOSMARTPTR_H_ */
