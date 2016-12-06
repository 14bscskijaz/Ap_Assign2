#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
// default constructor
String::String() 
{
    this->_str = new StringBuffer();
}

// destructor
String::~String() 
{
    //decrement the refcount and only if it is =0, delete the buffer.
    if (--this->_str->_refcount < 1) {
		cout << "string" << endl;
		delete this->_str;
    }
}

//copy a const String into this string
String::String(const String& newString) {
    this->_str = newString._str;

    //increment the refcount by 1
    ++this->_str->_refcount;
}

//copy a char* into your string
String::String(char* newString, int length) {
	char* chrPtr = new char[length];
	//i have done this to ensure the string passed iscopied to heap from stack to avoid error when destructor deletes it.
	for (int i = 0; i < length; i++)
	{
		chrPtr[i] = newString[i];
	}
    this->_str = new StringBuffer(chrPtr, length);
    //increment the refcount by 1
    this->_str->_refcount = 1;

}


//Appends a character at the end of the string, if that string is pointed by a single pointer then writes it diectly using append() of StringBuffer()...
//If more than one pointer points then COW is implemented here: ! 

void String::append(char c) {
	
	

    //    char* tempbuf = new char[this->_str->length()+1];  
    //    this->_str->revSmartCopy(tempbuf);
    if (this->_str->_refcount > 1) {

		//now as another pointer points here string is copied to a new memory location.

        //more than 1 reference to this string
        auto_ptr<StringBuffer> newdata(new StringBuffer);
        newdata.get()->reserve(this->_str->length() + 1);
        newdata.get()->smartCopy(this->_str);

        //decrement the reference count to this String as now pointer points to the new location, which has the copied string!
        --this->_str->_refcount;

        //cout<<"length at newdata"<<newdata.get()->length()<<endl;
        //now split the object instances
        this->_str = newdata.release();
    } else {
		// if only this->(single pointer) is pointing than we can reserve memory directly
        this->_str->reserve(this->_str->length() + 1);
    }
    //copy the new character at the end of this string
    this->_str->append(c);
}

//get length of the string
int String::length() const {
	return this->_str->length();
}

//get character at index if it is less than length
char String::charAt(int index) const {
    if (index < this->_str->length()) {
        return this->_str->charAt(index);
    } else {
        //throw new IndexOutOfBoundException();
		cout << "Index out of bound\n";
		return '\0';
    }
}