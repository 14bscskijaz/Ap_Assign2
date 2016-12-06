#include "StringBuffer.h"
#include "String3.h"
#include <memory>
#include <iostream>


using namespace std;
// default constructor
String3::String3()
{
	this->_str = new StringBuffer(); 
	this->next = NULL;
	this->prev = NULL;
}

// destructor
String3::~String3()
{
	//if only this object is pointing the string
	if (this->next == NULL)
		delete this->_str	;
	else
	{  //if more than one objects are pointing the string
		this->prev->next = this->next; 
		this->next->prev = this->prev;
		delete this->_str;
	}
}

//copy a const String into this string
String3::String3( String3& newString) {
	this->_str = newString._str;
	//if only newString is pointing to a string
	if (newString.next == NULL)
	{
		this->prev = &newString;
		newString.next = this;
		newString.prev = this;
		this->next = &newString;
	}
	else
	{ //if more than one objects are pointing to the string
		this->next = newString.next;
		this->prev = &newString;
		newString.next = this;
		newString.next->prev = this;
	
	}
}

//copy a char* into your string
String3::String3(char* newString, int length) {
	char* chrPtr = new char[length];
	//I have done this to ensure the string passed is copied to heap from stack to avoid error when destructor deletes it.
	for (int i = 0; i < length; i++)
	{
		chrPtr[i] = newString[i];
	}
	//this now points to a previously unpointed memory location in heap.
	this->_str = new StringBuffer(chrPtr, length);
	this->next = NULL;
	this->prev = NULL;
}


//Appends a character at the end of the string, if that string is pointed by a single pointer then writes it diectly using append() of StringBuffer()...
//If more than one pointer points then COW is implemented here: ! 

void String3::append(char c) {



	//    char* tempbuf = new char[this->_str->length()+1];  
	//    this->_str->revSmartCopy(tempbuf);
	if (this->next!=NULL) {

		//now as another pointer points here string is copied to a new memory location.

		// when more than one objects points to a string
		// now "this" object is removed from the circular linked list.
		auto_ptr<StringBuffer> newdata(new StringBuffer);
		newdata.get()->reserve(this->_str->length() + 1);
		newdata.get()->smartCopy(this->_str);
		this->prev->next = this->next;
		this->next->prev = this->prev;
		
		this->next = NULL;
		this->prev = NULL;

		//cout<<"length at newdata"<<newdata.get()->length()<<endl;
		//now split the object instances
		this->_str = newdata.release();

	}
	else {
		// if only this->(single pointer) is pointing than we can reserve memory directly
		this->_str->reserve(this->_str->length() + 1);
	}
	//copy the new character at the end of this string
	this->_str->append(c);
}

//get length of the string
int String3::length() const {
	return this->_str->length();
}

//get character at index if it is less than length
char String3::charAt(int index) const {
	if (index < this->_str->length()) {
		return this->_str->charAt(index);
	}
	else {
		//throw new IndexOutOfBoundException();
		cout << "Index out of bound\n";
		return '\0';
	}
}