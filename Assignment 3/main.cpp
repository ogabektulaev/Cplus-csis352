//Name: Ogabek (jj0565yv)
//Due Date: 02.27.2023
//Class: CSIS 352

#include <iostream>
#include "myArray.h"

using namespace std;

int main(){

	int length1, length2, elem1;
	double elem2;	

	//creating array 1 int
	cout << "Creating first array of type int" << endl;
	cout << "Array initialized. Size: ";
	
	
	cin >> length1;
	nsArray::myArray <int> array1(length1);
	
	for(int i=0; i<length1; i++)
		array1[i] = 0;
	
	cout << "Array contents: ";
	array1.dump();
	
	cout << "Changing array numbers..." << endl;
	cout << "Array contents: ";

	int count = 0;

	while(count < length1){
		cin >> elem1;
		array1[count] = elem1;
		
		count++;
	}
	array1.dump();	
	cout << "Last item in the array is " << array1[length1-1] << endl;

	//creating array2 double
	cout << endl << "Creating second array of type double" << endl;
	cout << "Array initialized. Size: ";
	cin >> length2;
	nsArray::myArray <double> array2(length2);
	
	for(int i=0; i<length2; i++)
		array2[i] = 0.0;
	
	cout << "Array contents: ";
	array2.dump();
	
	cout << "Changing array numbers..." << endl;
	cout << "Array contents: ";
	
	count = 0;

	while(count < length2){
		cin >> elem2;
		array2[count] = elem2;
		count++;
	}
	array2.dump();	
	cout << "Last item in the array is " << array2[length2-1] << endl;
	
	cout << endl << "Creating third array, a copy of array 2" << endl;
	nsArray::myArray <double> array3(array2);
	cout << "Array contents: ";
	array3.dump();
		
	try{
		cout << endl << "Testing out of range exception with array3[100] = 100;" << endl;
		array3[100] = 100;
	}
	catch(out_of_range &e){
		cout << "\t" << e.what() << endl;
	}

	try{
		cout << endl << "Testing out invalid array length with myArray<double>(-5);" << endl;
		nsArray::myArray <double>(-5);
	}
	catch(bad_array_new_length){
		cout << "\t" << "Error - array length must be greater than zero" << endl;
	}
	try{
		cout << endl << "Testing out custom exception for big sized array (size<=1000);" << endl;
		nsArray::myArray <int> array3(1001);
	}
	catch(UniException &e){
		cout << "\t" <<e.what() << endl;
	} 
	return 0;
}
