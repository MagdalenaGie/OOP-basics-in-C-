/*
 * InfoClass.h
 *
 *  Created on: 18 mar 2020
 *      Author: mg992
 */

#ifndef INFOCLASS_H_
#define INFOCLASS_H_
#include <iostream>
#include <string>

struct InfoClass{
	std::string slowo;

	InfoClass(std::string);
	~InfoClass();
	std::string info()const;
	InfoClass* info(std::string);
};

InfoClass::InfoClass(std::string str): slowo(str){
	std::cout<<"++ Tworze obiekt InfoClass: info = "<<slowo<<std::endl;
}

InfoClass::~InfoClass(){
	std::cout<<"++ Usuwam obiekt InfoClass: info = "<<slowo<<std::endl;
}

std::string InfoClass::info()const{
	return "info = " + this->slowo;
}

InfoClass* InfoClass::info(std::string str){
	this->slowo = str;
	return this;
}

struct InfoSuperClass{
private:
	InfoClass element;
	int liczba;
public:
	InfoSuperClass(InfoClass&, int);
	~InfoSuperClass();
	std::string info()const;
};

InfoSuperClass::InfoSuperClass(InfoClass& el, int licz): element(el), liczba(licz){
}

InfoSuperClass::~InfoSuperClass(){
}

std::string InfoSuperClass::info()const{
	//return "info = " + this->slowo;
}

#endif /* INFOCLASS_H_ */
