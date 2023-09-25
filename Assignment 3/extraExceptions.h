#ifndef H_extraExceptions
#define H_extraExceptions

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class UniException : public exception{
	private:
		string message;
	public:
		UniException(string message) : message(message) {}
		
		const char *what() const throw() {
			return message.c_str();
		}
};



#endif
