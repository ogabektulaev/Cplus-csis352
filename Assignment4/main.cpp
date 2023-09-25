//Name: Ogabek	
//Due Date: 03.20.2023
//Class: CSIS 352
//Description: This program solves the Josephus problem by using STL, namespaces and exceptions


#include <iostream>
#include <list>
#include "josephus.h"
#include "exceptions.h"

using namespace std;

//namespace for storing variables
namespace nks{
	int n; // number of people
    int k = 2; // every 2nd person is eliminated
	int s; // starting position
	int survivor;
}


int main() {

	cout << "Enter the number of people: ";
	cin >> nks::n;
	cout << "Enter the position to start at: ";
	cin >> nks::s;

	try{
		Josephus josephus(nks::n, nks::k, nks::s);
		nks::survivor = josephus.findSurvivor();
		cout << endl << "[RESULT]: The survivor is at position " << nks::survivor << endl;
	}
	catch(UniException &e){
		cout << endl <<"[EXCEPTION]: " << e.what() << endl;
	} 
    return 0;
}
