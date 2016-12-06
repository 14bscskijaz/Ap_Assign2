#ifndef STRINGBUFFER_H
#define	STRINGBUFFER_H

class StringBuffer{
public :
    StringBuffer();
    ~StringBuffer();
    StringBuffer(const StringBuffer&);
    StringBuffer(char*,int);

    char charAt(int) const;
    int length() const;
	void smartCopy(StringBuffer*); // overrides original str with newString as much as it can
    void smartCopy(char*,int); // overrides original str till length of new string.
    void revSmartCopy(char* newString); // over writes user's str with original one.
    void reserve(int); //reserves the space equal to length of orignal string.
    void append(char); //appends a character at the end of the string it is called for.
    int _refcount; // is used to implement COW with reference counting. is always decreased when a destructor is called( when a pointer no longer points to that location).
	void getStringBuf();
private:
    char* _strbuf;
    int _length;
    
};

#endif	/* STRINGBUFFER_H */

