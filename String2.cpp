#include "StringBuffer.h"
#include "String2.h"
#include <memory>
#include <iostream>
using namespace std;

// Implements Owned pointers

// Def Constructor
String2::String2()
{
	this->_str = new StringBuffer();
	itsOwn = true;
}

// Destructor
String2::~String2() {
	if (itsOwn) 
	{
		delete this->_str;
	}
	else
	{
		cout << "Can't delete!\n";
	}
}

// Copy Constructor implementing Ownership transfer
String2::String2(const String2& newString)
{
	this->_str = newString._str;
	this->itsOwn = true;
	newString.itsOwn = false;
	//Basically here ownership of string where newString points is transferred to a new object which also now points to that string!
}

// Copy a char* into your string...copies string from stack to heap and now the pointer which points to that heap location is the owner of that string.
String2::String2(char* newString, int length) {
	char* chrPtr = new char[length]; // points to new location of length equal to string passed
	for (int i = 0; i < length; i++)
	{ //copying to heap..
		chrPtr[i] = newString[i];
	}
	this->_str = new StringBuffer(chrPtr, length); //this object now points to chrPtr
	//Now this->_str is the owner!
	this->itsOwn = true;
}

void String2::append(char c) {
	// it allows append only to the owner.
	if (itsOwn) 
	{
		this->_str->reserve(this->_str->length() + 1);
		this->_str->append(c);
	}
	else 
	{
		cout << "Sorry this is not the owner so it can not append\n";
	}
}

//get length of the string
int String2::length() const {
	return this->_str->length();
}

char String2::charAt(int index) const {
	if (index < this->_str->length()) {
		return this->_str->charAt(index);
	}
	else {
		//throw new IndexOutOfBoundException();
		cout << "Index out of bound\n";
		return '\0';
	}
}