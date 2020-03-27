/*
 * Bit.h
 *
 *  Created on: 3 mar 2020
 *      Author: mg992
 */

#ifndef BIT_H_
#define BIT_H_
#include <iostream>

class Bit{
friend class BitArray;
private:
	int _pozycja; //pozycja w bajcie
	unsigned char *_znak; //znak bitu
public:
	Bit(int pozycja, unsigned char *znak): _pozycja(pozycja), _znak(znak){}
	void operator=(bool)const;
	operator bool() const;
};


#endif /* BIT_H_ */
