/*
 * BitArray.h
 *
 *  Created on: 3 mar 2020
 *      Author: mg992
 */

#ifndef BITARRAY_H_
#define BITARRAY_H_
#include <iostream>
#include "Bit.h"
class Bit;

class BitArray{
private:
	unsigned char *_btab;
	int _nofbits;
public:
	BitArray(const int, const bool b = false);
	~BitArray();
	Bit operator[](int)const;
	void print()const;
};


#endif /* BITARRAY_H_ */
