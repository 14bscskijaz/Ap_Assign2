/*
* File:   main.cpp
*
* Created on February 16, 2016, 9:51 PM
*/

#include <cstdlib>
#include <iostream>
#include<cstring>
#include "StringBuffer.h"
#include "String.h"
#include "String2.h"
#include "String3.h"

using namespace std;

/*
*
*/
//In main I have tested all of the four pointers.
int main(int argc, char** argv) {
	
	//Implementing first pointer: Owned pointers
	cout << "..............Testing Owned pointers.................\n";
	char* hello = "hello";



	String2 ss2(hello, 5);
	cout << "ss2 owner:" << ss2.itsOwn << endl;
	String2 ss3(hello, 5);
	cout << "ss3 owner:" << ss3.itsOwn << endl;
	std::cout << "ss2 length = " << ss2.length() << std::endl;
	cout << hello << endl;
	//multiple references
	String2 ss(ss2);
	cout << "ss owner:" << ss.itsOwn << endl;
	cout << hello << endl;
	//output statements
	std::cout << "ss length = " << ss.length() << std::endl;
	std::cout << "new ss charAt 0 = " << ss.charAt(0) << std::endl;
	//Here i am checking ownership
	cout << "ss owns = " << ss.itsOwn << endl;
	cout << "ss2 owns = " << ss2.itsOwn << endl;
	cout << "ss3 owns = " << ss3.itsOwn << endl;

	//append a character
	ss2.append('w');

	//out<<hello<<endl;
	// hello = "bye";

	//Checking the correctness of append() function and ownership implementation:

	std::cout << "new ss2 charAt 0 = " << ss2.charAt(0) << std::endl;
	std::cout << "new ss charAt 1 = " << ss.charAt(1) << std::endl;
	std::cout << "new ss charAt 5 = " << ss.charAt(5) << std::endl;
	std::cout << "new ss2 charAt 5 = " << ss2.charAt(5) << std::endl;
	std::cout << "new ss3 charAt 5 = " << ss3.charAt(5) << std::endl;
	std::cout << "new ss length = " << ss.length() << std::endl;
	std::cout << "new ss2 length = " << ss2.length() << std::endl;


	ss.append('w');

	//out<<hello<<endl;


	// checking implementation of ownership and correctness of append
	std::cout << "new ss2 charAt 0 = " << ss2.charAt(0) << std::endl;
	std::cout << "new ss charAt 1 = " << ss.charAt(1) << std::endl;
	std::cout << "new ss charAt 5 = " << ss.charAt(5) << std::endl;
	std::cout << "new ss2 charAt 5 = " << ss2.charAt(5) << std::endl;
	std::cout << "new ss3 charAt 5 = " << ss3.charAt(5) << std::endl;
	std::cout << "new ss length = " << ss.length() << std::endl;
	std::cout << "new ss2 length = " << ss2.length() << std::endl;



	cout << "-------------------------------------------------------\n";
	cout << "..............Testing Referece linking...............\n";

	String3 s2(hello, 5);
	String3 s3(hello, 5);

	std::cout << "s2 length = " << ss2.length() << std::endl;
	cout << hello << endl;
	//multiple references
	String3 s(s2);
	
	//Checking next and prev pointer of s...it should result in s2 and s pointing to each other
	//thus s2 should be pointing to address of s.
	std::cout << "Next pointer of s2:  " << s2.next << std::endl;
	std::cout << "Previous pointer of s2:  " << s2.prev << std::endl;


	cout << hello << endl;
	//output statements
	std::cout << "new s length = " << s.length() << std::endl;
	std::cout << "new s2 length = " << s2.length() << std::endl;
	std::cout << "new s3 length = " << s3.length() << std::endl;

	//append a character
	cout << "***APPEND***" << endl;
	s2.append('w');

	//out<<hello<<endl;
	// hello = "bye";
	//Checking if after appending the string is detached from the linked list or not
	 //Well the correct behaviour will be if next and prev shows NULL(0000000) !

	std::cout << "Next pointer of s2: " << s2.next << std::endl;
	std::cout << "Previous pointer of s2: " << s2.prev << std::endl;

	//Checking append function()
	std::cout << "new s2 charAt 0 = " << s2.charAt(0) << std::endl;
	std::cout << "new s charAt 1 = " << s.charAt(1) << std::endl;
	std::cout << "new s charAt 1 = " << s.charAt(1) << std::endl;
	std::cout << "new s charAt 5 = " << s.charAt(5) << std::endl;
	std::cout << "new s2 charAt 5 = " << s2.charAt(5) << std::endl;
	std::cout << "new s3 charAt 5 = " << s3.charAt(5) << std::endl;
	std::cout << "new s length = " << s.length() << std::endl;
	std::cout << "new s2 length = " << s2.length() << std::endl;
	std::cout << "new s3 length = " << s3.length() << std::endl;

	system("pause");
	return 0;
}

