#include "StringBuffer.h"
#include "StringLink.h"
#include <memory>
#include <iostream>
using namespace std;

// default constructor
StringLink::StringLink()
{
	this->_str = new StringBuffer();
}

// destructor
StringLink::~StringLink()
{
	//decrement the refcount and only if it is =0, delete the buffer.
	if (--this->_str->_refcount < 1) {
		cout << "string" << endl;
		delete this->_str;
	}
}

// 1st instance of pointer
StringLink::StringLink(char* newString, int length) {
	char* chrPtr = new char[length];
	for (int i = 0; i < length; i++)
	{
		chrPtr[i] = newString[i];
	}
	this->_str = new StringBuffer(chrPtr, length);

	//Reference linking
	this->_str->_refcount = 1;
	this->nxt = this;
	this->prv = this;
}

// 2nd and so on Copy Constructor 
StringLink::StringLink(const StringLink& newString)
{
	this->_str = newString._str;

	/// here you left
	this->nxt = newString.nxt;
	this->prv = newString.prv;

	//this->itsOwn = true;
	//newString.itsOwn = false;
}