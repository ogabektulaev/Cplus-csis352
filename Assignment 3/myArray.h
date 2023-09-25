//be sure to use a namespace
//this is a TEMPLATED CLASS

#ifndef H_myArray
#define H_myArray

#include <iostream>
#include "extraExceptions.h"
using namespace std;

namespace nsArray{

	template <class val>
	class myArray {
		public:
		    myArray(int len); //constructor
		    myArray(const myArray<val>& otherArray); //copy constructor
		    ~myArray(); // destructor

		    int getSize();
		    void dump();

		    val& operator[](int index);
		    myArray<val>& operator=(const val& otherArray); //overloads the assignment operator
		private:
		    int length;
		    val *arr;
	};

	template <class val>
	int myArray<val>::getSize(){
		return length;
	}

	template <class val>
	void myArray<val>::dump(){
		for(int i = 0; i<length; i++){
		    cout << arr[i] << " ";
		}
		cout << endl;
	}

	//constructor
	template <class val>
	myArray<val>::myArray(int len){
		if(len < 0)
			throw bad_array_new_length();
		else if(len >= 1000)
			throw UniException("Error - the size of the array is too big, it should be less than 1000!");		

		length = len;
		arr = new val[length];
	}


	//destructor
	template <class val>
	myArray<val>::~myArray(){
		delete [] arr;
	}

	//copy constructor
	template <class val>
	myArray<val>::myArray(const myArray<val>& otherArray){

		length = otherArray.length;
		arr = new val[length];

		for(int i = 0; i<length; i++){
		    arr[i] = otherArray.arr[i];
		}

	}

	//assignment operator overloading
	template <class val>
	myArray<val>& myArray<val>::operator=(const val& otherArray){
		if(this != &otherArray){
		    delete [] arr;
		    length = otherArray.getSize();
		    arr = new val[length];

		    for(int i = 0; i<length; i++)
		        arr[i] = otherArray[i];
		}
		return *this;
	}


	//[] operator overloading
	template <class val>
	val& myArray<val>::operator[](int index){
		if(index<0 || index >= length)
			throw out_of_range("Error - Index must be less than the length of the array");
		return arr[index];
	}
}

#endif
