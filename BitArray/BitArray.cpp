/*
 * BitArray.cpp
 *
 *  Created on: 3 mar 2020
 *      Author: mg992
 */

#include <iostream>
#include "BitArray.h"
#include "Bit.h"

BitArray::BitArray(const int n, const  bool b): _nofbits(n){
	int dlugosc;
	if(_nofbits%8==0)
		dlugosc=_nofbits/8;
	else
		dlugosc=_nofbits/8 + 1;

	_btab = new unsigned char(dlugosc);

	for(int i=0; i<static_cast<int>(_nofbits); i++){
		(*this)[i] = static_cast<unsigned char>(b);  //czemu tak? czemu z btab nie dzia³a?
	}
}

BitArray::~BitArray(){
	delete[] _btab;
}

Bit BitArray::operator[](int pos)const{
	return Bit(pos%8, _btab + pos/8);
}

void Bit::operator=(bool b)const{
	if(b == true){
		*_znak |= (1 << _pozycja);
	}
	else {
		*_znak &= ~(1 << _pozycja);
	}
}

Bit::operator bool() const{
	return (*_znak & (1 << _pozycja))!=0;
}

void BitArray::print()const{
	for(int i=_nofbits-1; i>=0; i--){
		std::cout << (*this)[i];
		if(i%8==0)
			std::cout << "<-" << i <<" ";
	}
}
