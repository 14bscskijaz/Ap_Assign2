
#ifndef STRING2_H
#define	STRING2_H
//Implements owned pointer
class String2 {
private:

public:
	StringBuffer* _str;
	mutable bool itsOwn; //used in implementing ownership.
	String2(const String2&);
	String2();
	~String2();
	String2(char*, int);
	void append(char);
	int length() const;
	char charAt(int) const;
};

#endif	/* STRING2_H */