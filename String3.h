
#ifndef STRING3_H
#define	STRING3_H


class String3 {
private:
	
public:
	StringBuffer* _str;
	String3 *next; // points to next object
	String3 *prev; //points to prev object
	String3();
	~String3();
	String3( String3&);
	String3(char*, int);
	void append(char);
	int length() const;
	char charAt(int) const;
};

#endif	/* STRING3_H */