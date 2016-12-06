#include "StringBuffer.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor
StringBuffer::StringBuffer() {
    this->_strbuf = 0;
    this->_length = 0;
    this->_refcount = 1;
}

void StringBuffer::getStringBuf()
{
	cout << this->_strbuf;
}

//destructor
StringBuffer::~StringBuffer() {
    delete[] this->_strbuf;
}


//copy a const StringBuffer into this string

//Implements copied pointer as it takes input string copies it to a location in heap!
StringBuffer::StringBuffer(const StringBuffer& newString) {

    this->_strbuf = new char[newString.length()];
    this->_length = newString.length();
    //copy the passed string into internal buffer
    this->smartCopy(newString._strbuf, _length);
}

//copy a char* into your string #me implements copied pointer
StringBuffer::StringBuffer(char* newString, int length) {
	this->_strbuf = 0;
	this->_refcount = 0;

    _length = length;
    //delete[] _strbuf; 
	// Memory leak spotted
    this->_strbuf = new char[length];
	_strbuf = newString;
	
    //Should I delete the string passed by the user?
    //delete[] newString;

}

//make a smart copy of the StringBuffer into the called StringBuffer
void StringBuffer::smartCopy(StringBuffer* newString) {
    int shorterLength = 0;
    (this->_length < newString->_length) ? shorterLength = this->_length : shorterLength = newString->_length;
    int it = 0;
    while (it < shorterLength) {
        //*_strbuf++ = *(newString->_strbuf)++;
		_strbuf[it] = newString->_strbuf[it];
		it++;
    }
}

//make a smart copy of the char* into this string

void StringBuffer::smartCopy(char* newString, int length) {
    //(this->_length == length)?:this->_length=length;
    this->_length = length;
    int it = 0;
    while (it < length) {
        //*_strbuf++ = *newString++;
		this->_strbuf[it] = newString[it];
        it++;
    }
}
//make a smart copy of this string into the passed string
void StringBuffer::revSmartCopy(char* newString) 
{
    int it = 0;
    while (it < _length) {
        newString[it] = _strbuf[it];
        it++;
    }
}

void StringBuffer::reserve(int n) {
    if (_length < n) {
        int newlength = n; //max(_length*2,n);
        char* newbuf = new char[newlength];
        //copy contents of the stored string in the new buffer
		this->revSmartCopy(newbuf);
        //return stuff from the new buffer to the stored buffer
        delete this->_strbuf;
        this->_strbuf = newbuf;
        this->_length = newlength;
    } 
	else
	{
		
		cout << "length demanded is less than original length.";
	}
}

//append a character at the end of this String, which has already made a reservation
//Main Assumption: the length has been allocated but not yet utilized and the 
//length counter has not been increased.

void StringBuffer::append(char c) {
    this->_strbuf[this->_length - 1] = c;
}
//get length of the string

int StringBuffer::length() const {
    return this->_length;
}

//get character at index if it is less than length

char StringBuffer::charAt(int index) const {
    if (index < _length) {
        return _strbuf[index];
    } else {
        //throw new IndexOutOfBoundException();
		return '\0';
    }
}
