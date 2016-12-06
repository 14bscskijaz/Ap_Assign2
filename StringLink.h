/*
* File:
*
* Created on December 05, 2016
*
* Implements Owned pointers
*/

#ifndef STRING2_H
#define	STRING2_H

class StringLink {
private:
	//StringBuffer* itsPtr;
public:
	StringBuffer* _str;
	StringLink* nxt;
	StringLink* prv;
	StringLink();
	~StringLink();
	StringLink(const StringLink&);
	StringLink(char*, int);
	void append(char);
	int length() const;
	char charAt(int) const;
};

#endif	/* STRING2_H */
