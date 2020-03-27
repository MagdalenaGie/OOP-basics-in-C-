/*
 * myString.h
 *
 *  Created on: 25 lut 2020
 *      Author: mg992
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>
#include <cstring>

class MyString{
private:
    char *string;
    int len;
public:
    MyString();
    MyString(const MyString&);
    MyString(const char*);
    ~MyString();
    void print() const;
    char* get_s() const;
    int get_l() const;
    bool operator==(const MyString&)const;
    MyString& operator=(const MyString&);
    MyString operator+(const MyString&)const;
    MyString operator+(const char)const;
    MyString operator*(int)const;
    char& operator[](size_t);

    friend std::ostream& operator<<(std::ostream &out, const MyString&);
};

MyString operator*(int x, const MyString& );
MyString operator+(const char*, const MyString&);
#endif /* MYSTRING_H_ */
