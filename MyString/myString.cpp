/*
 * myString.cpp
 *
 *  Created on: 25 lut 2020
 *      Author: mg992
 */

#include "myString.h"
#include <string.h>
#include <iostream>

MyString::MyString(){
    len=1;
    string = new char[len+1];
    string[0]=0;
}

MyString::MyString(const MyString &str){
    len= strlen(str.string);
    string = new char[len+1];
    strcpy(string, str.string);
}

MyString::MyString(const char* str){
	len= strlen(str);
    string = new char[strlen(str) +1];
    strcpy(string, str);
}

MyString::~MyString(){
    delete []string;
}

void MyString::print() const{
    std::cout << string << "\n";
}

char* MyString::get_s() const{
	return string;
}

int MyString::get_l() const{
	return len;
}

bool MyString::operator==(const MyString& str)const{
	if(strcmp(string, str.string))
		return false;
	else
		return true;
}

std::ostream& operator<<(std::ostream &out, const MyString& str){
	out<<str.string;
	return out;
}

MyString& MyString::operator=(const MyString &str){
	if(this==&str)
		return *this;
	len=strlen(str.string) + 1;
	delete[] string;
	string = new char[len+1];
	strcpy(string, str.string);
	return *this;
}

MyString MyString::operator+(const MyString &str)const{
	int new_len = len + str.len;
	char* new_str = new char[new_len+1];
	strcpy(new_str, string);
	strcat(new_str, str.string);
	MyString new_el(new_str);
	delete [] new_str;
	return new_el;
}

MyString MyString::operator+(const char znak)const{
	char* new_str = new char[len+2];
	strcpy(new_str, string);
	new_str[len] = znak;
	MyString new_el(new_str);
	delete [] new_str;
	return new_el;
}

MyString operator*(int x, const MyString& str ){
	int new_len=str.get_l() * x;
	char* new_str = new char[new_len + 1];
	for(int i=0; i<x; i++)
		strcat(new_str, str.get_s());
	MyString new_el(new_str);
	delete[] new_str;
	return new_el;
}

MyString MyString::operator*(int x)const{
	int new_len = len*x;
	char* new_str = new char[new_len + 1];
	for(int i=0; i<x; i++)
		strcat(new_str, string);
	MyString new_el(new_str);
	delete[] new_str;
	return new_el;
}

MyString operator+(const char* ch, const MyString& str){
	int new_len = strlen(ch) + str.get_l();
	char* new_str = new char[new_len +1];
	strcat(new_str, ch);
	strcat(new_str, str.get_s());
	MyString new_el(new_str);
	delete[] new_str;
	return new_el;
}

char& MyString::operator[](size_t n){
	return string[n];
}
