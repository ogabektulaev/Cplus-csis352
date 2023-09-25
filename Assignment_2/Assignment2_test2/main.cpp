//Name: Ogabek	
//Due Date: 02.15.2023
//Class: CSIS 352
//Description: This program arranges the user entered integers to create minimum heap. It can return the top of the heap, remove the top of the heap, insert elements to the heap and destroys the heap.


#include <iostream>
#include <string>
#include "heapType.h"

namespace classHolder{  //namespace is used to contain heapType class object and other variables
	heapType <int> heap;
	int num;
	string empty;
}


using namespace std;

int main(){
	
	
	cout << "Enter 'quit' to exit the program." << endl;
	while(true){
		cout << "\nIs the heap empty? ";
		cin >> classHolder::empty;
		
		if(classHolder::empty == "Yes"){ 
			cout << "Enter a number, 0 to stop: ";
			cin >> classHolder::num;
			
			while(classHolder::num != 0){
				classHolder::heap.insert(classHolder::num);
				cin >> classHolder::num;
			}	
			
			cout << "Numbers have been added to the heap. " << endl;
			cout << "All elements in the heap: " << endl;
			classHolder::heap.dump();
			cout << endl << "\nThe top of the heap is: " << classHolder::heap.top();
			cout << endl << "The length of the heap is: " << classHolder::heap.length() << endl;
		}
		else if(classHolder::empty == "No"){
			cout << endl << "Emtying the heap...";
			classHolder::heap.dump();
			classHolder::heap.pop(); //pops the heapTop
			cout << endl << "The Heap after pop(): " ; 			
			classHolder::heap.dump();			
			cout << endl << "Heap is emptied by destroy() function!" << endl;
			classHolder::heap.destroy(); //destroys the heap
		}
		else if(classHolder::empty == "quit")
			return 0;
	}
	return 0;

}	
